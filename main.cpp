#include <iostream>
#include <memory>
#include <vector>

#include "graph.hpp"
#include "lines/linearLine.hpp"
#include "lines/quadraticLine.hpp"
#include "shapes/circle.hpp"
#include "shapes/rectangle.hpp"

static int const Width = 500;
static int const Height = 500;
static int const MaxColor = 255;
static int const NumLines = 30;
// static int const NumColors = 3;

int main() {
    // seed random generator
    srand(time(NULL));

    Graph graph(Width - 1, Height - 1);
    ImageSettings is(Width - 1, Height - 1, 20, 50);

    std::cout << "P3\n";
    std::cout << Width << ' ' << Height << '\n';
    std::cout << MaxColor << "\n";

    Color const defaultColor = Black;
    ColorRow colorRow(Width, defaultColor);
    // std::vector<Line> lines;

    std::vector<std::unique_ptr<Line>> lines;

    int const segment = (Width / NumLines);

    // create math lines
    for (int i = 0; i < NumLines; ++i) {
        // const int mod = i % NumColors;
        Point2 const startingPoint((segment * i) + segment / 2, 0);
        // Color color;
        // if (mod == 0) {
        //     color = Red;
        // } else if (mod == 1) {
        //     color = Green;
        // } else {
        //     color = Blue;
        // }
        Color color(rand() % 256, rand() % 256, rand() % 256);
        lines.emplace_back(
            std::make_unique<QuadraticLine>(startingPoint, color));
    }

    Circle::GraphPoint point1(0.5, 0.5);
    Rectangle::GraphPoint topLeft(0.2, 0.2);
    Rectangle::GraphPoint bottomRight(0.8, 0.8);
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_unique<Circle>(graph, Green, point1, 0.2));
    shapes.emplace_back(
        std::make_unique<Rectangle>(graph, Blue, topLeft, bottomRight));

    for (int i = 0; i < Height; i += is.changeInY()) {
        // update line on each iteration
        int count = 0;
        for (auto& l : lines) {
            l->updateNextPoint(is);
            ++count;
        }

        int curMaxY = std::min(i + is.changeInY(), Height);
        for (int j = i; j < curMaxY; ++j) {
            // color each line in the row
            for (auto& l : lines) {
                l->colorRowForLine(j, colorRow, is);
            }

            // color the shapes
            for (auto& s : shapes) {
                s->colorRowForShape(j, colorRow, is);
            }

            // draw each color in the row
            for (auto const& c : colorRow) {
                std::cout << c.toPPMLine();
            }
            // clear for next row
            resetColorRow(colorRow, defaultColor);
            // update position of each line for the next row
            // for (auto& l : lines) {
            //     l.updatePointAndColorNextRow(colorRow, lines, defaultColor);
            // }
        }
    }
}