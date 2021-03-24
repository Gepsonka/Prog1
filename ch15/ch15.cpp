#include "Simple_window.h"
#include "Graph.h"
#include <cmath>



/*
    g++ week2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

double slope_(double x){return x/2;}


int main(){
    
    Simple_window win {Point{100,100},600,600,"ch15 Funtion graphs"};

    int origo_x=win.x_max()/2;
    int origo_y=win.y_max()/2;

    int n_points=400;
    int x_scale=20,y_scale=20;
    int rmin=-10,rmax=11;

    Axis ax {Axis::x,Point{100,origo_y},400,20,"1==20 pixels"};
    ax.set_color(Color::red);
    win.attach(ax);

    Axis ay {Axis::y,Point{origo_x,win.y_max()-100},400,20,"1==20 pixels"};
    ay.set_color(Color::red);
    win.attach(ay);

    Function slope {slope_,rmin,rmax,Point{origo_x,origo_y},n_points,x_scale,y_scale};
    win.attach(slope);

    Text slope_txt {Point{100,win.y_max()-220},"x/2"};
    win.attach(slope_txt);

    Function square {[](auto x){return x*x;},rmin,rmax,Point{origo_x,origo_y},n_points,x_scale,y_scale};
    win.attach(square);

    Function cosine {[](auto x){return cos(x);},rmin,rmax,Point{origo_x,origo_y},n_points,x_scale,y_scale};
    cosine.set_color(Color::blue);
    win.attach(cosine);

    Function sloping_cos {[](auto x){return cos(x)+slope_(x);},rmin,rmax,Point{origo_x,origo_y},n_points,x_scale,y_scale};
    win.attach(sloping_cos);


    win.wait_for_button();

}