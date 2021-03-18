#include "Simple_window.h"
#include "Graph.h"

/*
    g++ week2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/


double square(double x) {return x*x;}

int main(){

    Simple_window win {Point{100,100},600,400,"My window"};

    Rectangle rect {Point{10,10},50,70};
    rect.set_color(Color::blue);
    rect.set_fill_color(Color::red);
    //win.attach(rect);

    Polygon p;
    p.add(Point{200,100});
    p.add(Point{200,200});
    p.add(Point{250,150});
    p.set_color(Color::black);
    p.set_fill_color(Color::black);
    //win.attach(p);

    Axis ax {Axis::x,Point{100,300},300,10,"x"};
    ax.set_color(Color::dark_cyan);
    //win.attach(ax);

    Axis ay {Axis::y,Point{100,300},250,4,"y"};
    ax.set_color(Color::dark_green);
    ax.label.set_color(Color::dark_green);
    //win.attach(ay);

    Function sq {square,0,10,Point{100,300},1000,20,20};
    sq.set_color(Color::dark_cyan);
    // 1000:used points, 20,20:y*20,x*20;
    //win.attach(sq);


    Closed_polyline poly;
    poly.add(Point{50,50});
    poly.add(Point{50,100});
    poly.add(Point{100,100});
    poly.add(Point{100,50});
    poly.set_style(Line_style(Line_style::dashdot,3));
    poly.set_fill_color(Color::dark_yellow);
    //win.attach(poly);

    Text t {Point{300,300},"coco"};
    t.set_color(Color::blue);
    t.set_font_size(40);
    t.set_font(Font::helvetica_bold);
    //win.attach(t);

    Image im {Point{300,300},"badge.jpg"};
    //win.attach(im);

    Circle cir {Point{200,200},40};
    cir.set_fill_color(Color::cyan);
    //win.attach(cir);

    Ellipse el {Point{200,200},75,25};
    el.set_fill_color(Color::dark_magenta);
    //win.attach(el);





    win.wait_for_button();
}