#include "Colour.h"
#include "Display.h"
#include "Matrix.h"
#include "Vector.h"
#include "transforms.h"
#include "utility.h"

#include <cmath>
#include <vector>


int main () {

  Display display(800,600, 50);

  display.update();
  display.wait(0.5);

  std::vector<Vector> square;

  square.push_back(point2D(1,1));
  square.push_back(point2D(1,-1));
  square.push_back(point2D(-1,-1));
  square.push_back(point2D(-1,1));

  display.draw(square, red);
  display.update();
  display.wait(0.5);

  Matrix T1 = translate(2,1)*scale(0.5);
  display.draw(T1*square, yellow);
  display.update();
  display.wait(0.5);

  Matrix T2 = scale(0.5)*translate(2,1);
  display.draw(T2*square, cyan);
  display.update();
  display.wait(2);

  return 0;
}
