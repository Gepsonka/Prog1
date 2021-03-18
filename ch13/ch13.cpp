#include "Simple_window.h"
#include "Graph.h"


/*
    g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

int main(){

    Simple_window win {Point{100,100},800,1000,"ch13"};

    Lines l;
    for(int i=1;i<=8;i++){
        l.add(Point{i*100,0},Point{i*100,800});
    }
    for(int i=1;i<=8;i++){
        l.add(Point{0,i*100},Point{800,i*100});
    }
    win.attach(l);

    Vector_ref<Rectangle> rects;

    for(int i=0;i<8;i++){
        rects.push_back(new Rectangle{Point{i*100,i*100},100,100});
    }

    for (int i=0;i!=8;i++){
        rects[i].set_fill_color(Color::red);
        win.attach(rects[i]);
    }

    Vector_ref<Image> ims;

    ims.push_back(new Image{Point{400,0},"badge.jpg"});
    ims.push_back(new Image{Point{200,600},"badge.jpg"});
    ims.push_back(new Image{Point{0,600},"badge.jpg"});

    for (int i=0;i<3;i++){
        ims[i].set_mask(Point{100,100},200,200);
        win.attach(ims[i]);
    }
    


    win.wait_for_button();
}