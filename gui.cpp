#include "gui.h"
#include <iostream>
#include <algorithm>  // For std::shuffle
#include <random>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Dropdown.h"
#include "dataBox.h"
#include "Post.h"
#include "read.h"
#include "Rank.h"
using namespace sf;
using namespace std;
#include <cctype>

struct Response {
    std::string category;
};

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



void gui::drawBoxes() {
    window.draw(Options);
    window.draw(Merge);
    window.draw(Enter1);
    window.draw(Quick);
    window.draw(Enter2);
    window.draw(Random);
    window.draw(Randomizer);

}

void gui::optionContent() {
    Merge.setSize(sf::Vector2f(175,50));
    Merge.setPosition((25),(800));
    Merge.setFillColor(Color::Green);

    Enter1.setString("MergeSort");
    Enter1.setFont(font);
    Enter1.setPosition((60),(800));
    Enter1.setFillColor(Color::Black);
    Enter1.setCharacterSize(20);

    Quick.setSize(sf::Vector2f(175,50));
    Quick.setPosition((25),860);
    Quick.setFillColor(Color::Green);

    Enter2.setString("QuickSort");
    Enter2.setFont(font);
    Enter2.setPosition((60),(860));
    Enter2.setFillColor(Color::Black);
    Enter2.setCharacterSize(20);

    Random.setSize(sf::Vector2f(175,50));
    Random.setPosition(25,920);
    Random.setFillColor(Color::Black);

    Randomizer.setString("Randomize");
    Randomizer.setFont(font);
    Randomizer.setPosition(60,920);
    Randomizer.setFillColor(Color::White);
    Randomizer.setCharacterSize(20);
}

void gui::run(){
    //Set up Dropdown
    std::vector<std::string> options = { "Likes", "Comments", "Shares","Impressions", "Reach", "Engagement", "Age" };

    Dropdown sorting((25),(height/4), 175, 50,options,font, "Sort by:");

    std::vector<std::string> option2 = {"Any" ,"Linkedin", "Instagram", "Twitter", "Facebook"};
    Dropdown Platform((25),(height/2.5),175,50,option2,font,"Platform:");

    std::vector<std::string> option3 = {"Any", "Male", "Female"};
    Dropdown Gender((25),(480+ 60), 175,50, option3,font , "Gender:");

    std::vector<std::string> option4 = {"Any", "Positive", "Negative", "Neutral"};
    Dropdown Opinion((25),(480 + 120), 175,50, option4,font , "Opinion:");

    optionContent();



    std::vector<std::string> words;
    words.reserve(100);
    for (int i = 1; i <= 100; ++i) {
        words.push_back("Word" + std::to_string(i));
    }
    // Assuming 'allWords' is your original large vector of strings
    //vector<string> topWords(allWords.begin(), allWords.begin() + min(100, static_cast<int>(allWords.size())));
    dataBox rowsOfData(225, 150, 750, 1000, words, font);
    //make other boxes also 750 to get equal margins


    //Initialize Sort and data To be run
    Sort filters;
    readFile(filters.vector);
    //Ranking Box
    string Top = "Top 3 Posts";
    Rank rank(1000,650,750,475, Top,font);

    filters.sortBy("Likes", filters.vector, true);


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            //press X button in top right-closes program, does not lead to game window
            if (event.type == Event::Closed) {
                window.close(); }
            //Drop Box Detection
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sorting.update(mousePos, event);

            Platform.update(mousePos,event);
            Gender.update(mousePos,event);
            Opinion.update(mousePos,event);

            //Submission
            if(Merge.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (event.type == sf::Event::MouseButtonPressed && sorting.getSelectedIndex() >= 0) {

                    if(Platform.getSelectedIndex() >= 1) {
                    filters.filterOn("Platform", option2[Platform.getSelectedIndex()]);
                    }

                    if(Gender.getSelectedIndex() >= 1) {
                        filters.filterOn("Gender", option3[Gender.getSelectedIndex()]);
                    }

                    if(Opinion.getSelectedIndex() >= 1) {
                        filters.filterOn("Sentiment", option4[Opinion.getSelectedIndex()]);
                    }

                    filters.sortBy(options[sorting.getSelectedIndex()], filters.vector, true);
                    rank.UpdateRanking(filters.vector, options[sorting.getSelectedIndex()]);

                }
            }
            if(Quick.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                if (event.type == sf::Event::MouseButtonPressed  && sorting.getSelectedIndex() >= 1) {
                    if(Platform.getSelectedIndex() >= 1) {
                        filters.filterOn("Platform", option2[Platform.getSelectedIndex()]);
                    }
                    else {
                        filters.filterHandling();
                    }
                    if(Gender.getSelectedIndex() >= 1) {
                        filters.filterOn("Gender", option3[Gender.getSelectedIndex()]);
                    }
                    else {
                        filters.filterHandling();
                    }
                    if(Opinion.getSelectedIndex() >= 1) {
                        filters.filterOn("Sentiment", option4[Opinion.getSelectedIndex()]);
                    }
                    else {
                        filters.filterHandling();
                    }
                    filters.sortBy(options[sorting.getSelectedIndex()], filters.vector, false);
                    rank.UpdateRanking(filters.vector, options[sorting.getSelectedIndex()]);
                }
            }

            if(Random.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                std::random_device rd;
                std::mt19937 g(rd());

                // Shuffle the vector
                std::shuffle(filters.vector.begin(), filters.vector.end(), g);
            }

            /*if (event.type == Event::TextEntered) {
                redraw = true;
                // Only letters
                if (65 <= event.text.unicode && event.text.unicode <= 90
                    || 97 <= event.text.unicode && event.text.unicode <= 120) {
                    if (displayName.empty()) { //changes first to uppercase
                        displayName += toupper(static_cast<char>(event.text.unicode)); }
                    else if (!displayName.empty() && displayName.size() < 10) { //changes the rest to lowercase
                        displayName += tolower(static_cast<char>(event.text.unicode)); }
                }
                    // Backspace
                else if (event.text.unicode == 8) {
                    if (!displayName.empty()) {
                        displayName.pop_back();} }
                    //Enter key-continues to Game window
                else if (event.text.unicode == 13) {
                    finalUserName = displayName;
                    if (!displayName.empty()) {
                        welcome.close();
                    }
                    Enter = true;
                }
            }*/


            rowsOfData.handleEvent(event);  // Pass events to dataBox for scroll handling
        }

            window.clear(Color::Blue);
            setText();
            setOption();
            drawText();
            drawBoxes();

            Opinion.draw(window);
            Gender.draw(window);
            Platform.draw(window);
            sorting.draw(window);



            rank.Draw(window);
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