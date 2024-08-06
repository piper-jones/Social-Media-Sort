#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class gui {
public:
    gui();
    void run();
    bool redraw = true;

private:
    RenderWindow window;
    float width;
    float height;
    Text mainTitle;
    Text dataTitle;
    Text statsTitle;
    Text topResultstitle;
    Text Enter1;
    Text Enter2;
    Font font;
    void loadFont();
    void setText();
    void positionText(Text &text, float x, float y, float scale);
    void drawText();

    RectangleShape Options;
    RectangleShape Merge;
    RectangleShape Quick;
    void setOption();
    void drawBoxes();
    void optionContent();


};