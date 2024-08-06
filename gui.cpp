#include "gui.h"
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Dropdown.h"
#include "dataBox.h"
using namespace sf;
using namespace std;
#include <cctype>


gui::gui(): window(VideoMode(1800, 1200), "Media Mirror") {
    width = 1800;
    height = 1200;
    loadFont();
    run(); }



void gui::loadFont(){
    if (!font.loadFromFile("files/font.ttf")) {
        cout << "Failed to load font" << endl;
    }
}
void gui::setText(){
    mainTitle.setFont(font);
    mainTitle.setString("Media Mirror");
    mainTitle.setCharacterSize(40);
    mainTitle.setFillColor(Color::White);
    mainTitle.setStyle(Text::Bold | Text::Underlined);

    FloatRect textRect = mainTitle.getLocalBounds();
    mainTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    mainTitle.setPosition(Vector2f(width / 2.0f, 75.0f));

    dataTitle.setFont(font);
    dataTitle.setString("Data:");
    dataTitle.setCharacterSize(20);
    dataTitle.setFillColor(Color::White);
    dataTitle.setStyle(Text::Bold);

    statsTitle.setFont(font);
    statsTitle.setString("Comparison Statistics");
    statsTitle.setCharacterSize(18);
    statsTitle.setFillColor(Color::Yellow);
    statsTitle.setStyle(Text::Bold);

    positionText(dataTitle, width, height, 75);
    positionText(statsTitle, width, height, 45);
}
void gui::positionText(Text &text, float x, float y, float scale){
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f((x/2), (y/2 - scale)));
}
void gui::drawText(){
    window.draw(mainTitle);
    window.draw(dataTitle);
    window.draw(statsTitle);
};

void gui::setOption() {
    Options.setSize(sf::Vector2f(175,550));
    Options.setPosition((25),(height/5));

    Options.setFillColor(Color::White);
}

void gui::optionContent() {

}

void gui::drawBoxes() {
    window.draw(Options);
}



void gui::run(){
    std::vector<std::string> options = { "Likes", "Comments", "Shares","Impressions", "Reach", "Engagement", "Age" };
    Dropdown sorting((25),(150), 175, 50,options,font);

    std::vector<std::string> words;
    words.reserve(100);
    for (int i = 1; i <= 100; ++i) {
        words.push_back("Word" + std::to_string(i));
    }
    // Assuming 'allWords' is your original large vector of strings
    //vector<string> topWords(allWords.begin(), allWords.begin() + min(100, static_cast<int>(allWords.size())));
    dataBox rowsOfData(225, 150, 750, 1000, words, font);
    //make other boxes also 750 to get equal margins

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            //press X button in top right-closes program, does not lead to game window
            if (event.type == Event::Closed) {
                window.close(); }
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sorting.update(mousePos, event);

            rowsOfData.handleEvent(event);  // Pass events to dataBox for scroll handling
        }

            window.clear(Color::Blue);
            setText();
            setOption();
            drawText();
            drawBoxes();
            sorting.draw(window);
            rowsOfData.draw(window);
            window.display();
    }
}



//Filters plan
/*
if filter button clicked && false
    check and make sure all filters in that category are false
       set corresponding category and choice bool to TRUE
if filter button clicked && true
        set category and choice bool to FALSE

run filterHandling();
*/


/*
 * if one of sort categories is picked:
 *
 * run sortBy function
 * run filter handling function
 * refresh gui
 *
 *
 * always preset to merge sort
 */


//if merge sort or quick sort clicked : reset bool, but sorting only runs from cateogories
//show time next to button when the program runs: