#include "GUI.h"
#include <iostream>

//    g++ week2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`


using namespace Graph_lib;

struct LineWin : Window
{
    LineWin(Point xy, int width, int height, const string &win_title);
    Open_polyline op;
    Menu color_menu;
    Menu style_menu;

    static void cb_red(Address, Address);
    static void cb_blue(Address, Address);
    static void cb_black(Address, Address);

    void red_pressed();
    void blue_pressed();
    void black_pressed();

    void color_btn_pressed();
    void color_chosed();


    void solid_pressed();
    void dotted_pressed();

    void line_style_btn_pressed();
    void line_style_chosed();


    bool wait_for_button();

private:
    Button next_btn;

    Button exit;

    Button color_button;
    Button line_style_button;

    In_box nx;
    In_box ny;

    Out_box xy_out;

    void change_color(Color c);
    void change_line_style(Line_style lns);
    

    void next();
    void quit();
};

LineWin::LineWin(Point xy, int width, int height, const string& win_title)
    :Window{xy,width,height,win_title},
    next_btn{Point{x_max()-150,0}, 70, 20, "Next point",
        [](Address, Address pw) {reference_to<LineWin>(pw).next();}},
    exit{Point{x_max()-70,0}, 70, 20, "Quit",
        [](Address, Address pw) {reference_to<LineWin>(pw).quit();}},
    nx{Point{250,0}, 50, 20, "next x:"},
    ny{Point{350,0}, 50, 20, "next y:"},
    xy_out{Point{100,0}, 100, 20, "current (x,y):"},
    color_menu{Point{x_max()-70, 50},70,20,Menu::vertical,"color"},
    color_button{Point{x_max()-70,50}, 70, 20,"Choose color",
    [](Address,Address pw){reference_to<LineWin>(pw).color_btn_pressed();}},
    style_menu{Point{x_max()-70, 150},70,20,Menu::vertical,"style"},
    line_style_button{Point{x_max()-70,150}, 70, 20, "Choose style",
        [](Address,Address pw){reference_to<LineWin>(pw).line_style_btn_pressed();}}
        {
            attach(next_btn);
            attach(exit);
            attach(nx);
            attach(ny);
            attach(xy_out);
            attach(op);
            color_menu.attach(new Button{Point{0,0},0,0,"red",
                [](Address,Address pw){reference_to<LineWin>(pw).red_pressed();}});
            color_menu.attach(new Button{Point{0,0},0,0,"blue",
                [](Address,Address pw){reference_to<LineWin>(pw).blue_pressed();}});
            color_menu.attach(new Button{Point{0,0},0,0,"black",
                [](Address,Address pw){reference_to<LineWin>(pw).black_pressed();}});
            style_menu.attach(new Button{Point{0,0},0,0,"solid",
                [](Address,Address pw){reference_to<LineWin>(pw).solid_pressed();}});
            style_menu.attach(new Button{Point{0,0},0,0,"dotted",
                [](Address,Address pw){reference_to<LineWin>(pw).dotted_pressed();}});
            attach(color_menu);
            attach(color_button);
            attach(style_menu);
            attach(line_style_button);
            color_menu.hide();
            color_button.show();
            style_menu.hide();
            line_style_button.show();
        }

        void LineWin::quit()
        {
            hide();
        }

void LineWin::next()
{
    int x = nx.get_int();
    int y = ny.get_int();
    op.add(Point{x, y});
    ostringstream strs;
    strs << "(" << x << "," << y << ")";
    xy_out.put(strs.str());
    redraw();
}

void LineWin::change_color(Color c){
    op.set_color(c);
}

void LineWin::change_line_style(Line_style lns){
    op.set_style(lns);
}


void LineWin::red_pressed(){
    change_color(Color::red);
    color_menu.hide();
    color_button.show();
    redraw();

}

void LineWin::blue_pressed(){
    change_color(Color::blue);
    color_menu.hide();
    color_button.show();
    redraw();

}

void LineWin::black_pressed(){
    change_color(Color::black);
    color_menu.hide();
    color_button.show();
    redraw();

}

void LineWin::solid_pressed(){
    change_line_style(Line_style::dash);
    style_menu.hide();
    line_style_button.show();
    redraw();
}

void LineWin::dotted_pressed(){
    change_line_style(Line_style::dot);
    style_menu.hide();
    line_style_button.show();
    redraw();
}



void LineWin::color_btn_pressed(){
    color_menu.show();
    color_button.hide();
}

void LineWin::line_style_btn_pressed(){
    style_menu.show();
    line_style_button.hide();
}

int main()
{
    try {
        LineWin win {Point{100,100},600,400,"lines"};
        return gui_main();
    }
    catch(exception& e) {
        cerr << "exception: " << e.what() << '\n';
        return 1;
    }
}