# Squiggly Lines

- what began as an attempt to draw random squiggly lines that don't intersect has now turned into
  seeing what cool generative art I can make based off of graphing math equations that randomly
  update themselves.

## TODO

### Line abstract base class

- create beforeUpdatePosition virtual function to accommodate derived
  classes which may wish to perform manipulations on the object before
  updating the start/end points

### QuadraticLine specific

- look into a better approach to making sure that amplitude isn't overly large for a quadratic
  function (currently hardcoded to 1/(50 +- 20))

### Anti-aliasing

- implement some form of anti-aliasing for lines (possibly xiaolin wu's algo?)
  - tried to adapt xiaolin wu's algo, but didn't really work well, implementation might
    just be janky

### Future Lines

- implement lines with degree > 2
- possibly introduce horizontal lines instead of strictly vertical lines (might require
  reworking of MathLine base class or additional base classes for lines which use
  x as independent variable)

### Future Shapes

- add ellipses, squares, etc.
- add filled versions of shapes

### Colors

- create code to randomly select from different colors rather than just making every third
  line the same color

### Brush

- make an abstracted brush class that takes in a formula or (x, y) coordinate and "brushes"
  the desired color onto screen (will allow different line widths, anti-aliasing techniques, etc. to be impl'd)

### Additional Considerations

- make random starting points for lines
- randomly add lines as program runs
- randomly remove lines as program runs
- randomly add shapes as program runs
- create code for detecting line collisions or forcing line collisions
