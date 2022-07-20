# Squiggly Lines

- what began as an attempt to draw random squiggly lines that don't intersect has now turned into
  seeing what cool generative art I can make based off of graphing math equations that randomly
  update themselves.

## TODO

### clean up MathLine/QudraticLine code

- likely need to turn MathLine into a (possibly abstract) base class and create
  a class specifically for linear graphing (which is currently the default behavior
  provided in MathLine which QuadraticLine overrides)
- create beforeUpdatePosition virtual function to accommodate derived
  classes which may wish to perform manipulations on the object before
  updating the start/end points

### QuadraticLine specific

- look into a better approach to making sure that amplitude isn't overly large for a quadratic
  function (currently hardcoded to 1/(50 +- 20))

### Anti-aliasing

- implement some form of anti-aliasing for lines (possibly xialon wu's algo?)

### Future Lines

- implement lines with degree > 2
- possibly introduce horizontal lines instead of strictly vertical lines (might require
  reworking of MathLine base class or additional base classes for lines which use
  x as independent variable)

### Future Shapes

- add circles, ellipses, squares, etc.

### Colors

- create code to randomly select from different colors rather than just making every third
  line the same color

### Additional Considerations

- make random starting points for lines
- randomly add lines as program runs
- randomly remove lines as program runs
- create code for detecting line collisions or forcing line collisions
