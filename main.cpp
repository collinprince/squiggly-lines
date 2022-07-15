#include <iostream>
#include <vector>

#include "color.hpp"
#include "line.hpp"

static int const Width = 500;
static int const Height = 500;
static int const MaxColor = 255;
static int const NumLines = 30;
static int const NumColors = 3;

int main() {
    // seed random generator
    srand(time(NULL));

    std::cout << "P3\n";
    std::cout << Width << ' ' << Height << '\n';
    std::cout << MaxColor << "\n";

    Color const defaultColor = White;
    ColorRow colorRow(Width, defaultColor);
    std::vector<Line> lines;

    int const segment = (Width / NumLines);

    // create lines
    for (int i = 0; i < NumLines; ++i) {
        const int mod = i % NumColors;
        Point2 const startingPoint((segment * i) + segment / 2, 0);
        Color color;
        if (mod == 0) {
            color = Red;
        } else if (mod == 1) {
            color = Green;
        } else {
            color = Blue;
        }
        lines.emplace_back(startingPoint, color, Width - 1, Height - 1);
    }

    for (int i = 0; i < Height; ++i) {
        // draw each color in the row
        for (auto const& c : colorRow) {
            std::cout << c.toPPMLine();
        }
        // clear for next row
        resetColorRow(colorRow, defaultColor);
        // update position of each line for the next row
        for (auto& l : lines) {
            l.updatePointAndColorNextRow(colorRow, lines, defaultColor);
        }
    }
}