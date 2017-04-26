#include "Colour.h"
#include "Display.h"
#include "Matrix.h"
#include "Vector.h"
#include "transforms.h"
#include "utility.h" 

#include <cmath>
#include <vector>


int main () {
 //creates a display object: width, height, size of each unit (pixels)
 //800 x 600 window where every 50 pixels corresponds to one unit. 
 // origin in middle of window. X-axis -8 to 8, Y-axis -6 to 6. 
  Display display(800,600, 50);
  
  //to view changes 
  display.update();
  display.wait(0.5); //program will pause 

  std::vector<Vector> square;
  std::vector<Vector> sq2;
  std::vector<Vector> line; 
  std::vector<Vector> triangle; 
  

//function point2D creates a homogenous Vector given x and y values 
//Creates a square of 4 points, draws it, then draws some transformed versions. 
//Transforms are 3x3 matrices 
 /* square.push_back(point2D(1,1));
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

  Matrix T2 = scale(2)*translate(-3,0);
  display.draw(T2*square, cyan);
  display.update();
  display.wait(0.5);
  
  
  display.draw(point2D(-3,2), green); 
  display.update();
  display.wait(0.5);  */
  
  line.push_back(point2D(-1,2));
  line.push_back(point2D(3,-1));
  display.draw(line, Colour(255,128,0)); 
  display.update();
  display.wait(0.5); 
  
  triangle.push_back(point2D(2,2));
  triangle.push_back(point2D(0,0));
  triangle.push_back(point2D(1,-1));
  display.draw(triangle, white);
  display.update();
  display.wait(0.5);
  
  Matrix T2 = scale(2)*translate(-3,0);
  display.draw(T2*triangle, white);
  display.update();
  display.wait(0.5);
  
  display.draw(rotate(45)*triangle, white);
  display.update();
  display.wait(0.5);
  
  sq2.push_back(point2D(2,2));
  sq2.push_back(point2D(-2,2));
  sq2.push_back(point2D(-2,-2));
  sq2.push_back(point2D(2,-2));
  display.draw(sq2, red);
  display.update();
  display.wait(0.5);
  
  Matrix T3 = shearX(1) * shearY(0.5);
  display.draw(T3 * sq2, yellow);
  display.update();
  display.wait(0.5);
  
  int a = 30;
  Matrix T4 = shearX(-tan(a/2)) * shearY(sin(a)) * shearX(-tan(a/2));
  display.draw(T4 * sq2, blue);
  display.update();
  display.wait(0.5);
  
  
  //Sequence of lines 
  for(int x=-7; x<=7; x++){
  	std::vector<Vector> lines; 
  	lines.push_back(point2D(x,-1));
  	lines.push_back(point2D(x,1));
    Matrix T5 = translate(x,0) * rotate(10*x) * translate(-x,0);
  	display.draw(T5*lines, Colour(128+(15*x), 128-(15*x), 0));
  	display.update();
  	display.wait(0.5);   
  }
  return 0;
}
