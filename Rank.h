#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Post.h"
using namespace sf;
using namespace std;
#include <cctype>


#ifndef SOCIAL_MEDIA_SORT_RANK_H
#define SOCIAL_MEDIA_SORT_RANK_H
class Rank {
private:
    RectangleShape Outer;
    RectangleShape Top1;
    RectangleShape Top2;
    RectangleShape Top3;

    Text First;
    Text Second;
    Text Third;
    Text Title;

    Text f;
    Text s;
    Text t;

    Text Gender1;
    Text Gender2;
    Text Gender3;

    Text Age;
    Text Age2;
    Text Age3;
public:
    Rank(float x, float y, float width, float height, const string &textContent, Font &font) {
        Outer.setPosition(x, y);
        Outer.setSize(Vector2f(width, height));
        Outer.setFillColor(Color::Red);
        Outer.setOutlineThickness(1);
        Outer.setOutlineColor(Color::Black);

        Title.setFont(font);
        Title.setString(textContent);
        Title.setCharacterSize(20);
        Title.setFillColor(Color::White);
        Title.setPosition(x + 300, y - 40);

        Top1.setPosition(x + 20, y + 30);
        Top1.setSize(Vector2f(width - 50, height / 4));
        Top1.setFillColor(Color::White);
        First.setPosition(x+20, y+30);
        First.setCharacterSize(20);
        First.setFillColor(Color::Black);
        First.setFont(font);
       f.setPosition(x+20, y+40);
        f.setCharacterSize(20);
        f.setFillColor(Color::Black);
        f.setFont(font);
        Gender1.setPosition(x+20, y+50);
        Gender1.setCharacterSize(20);
        Gender1.setFillColor(Color::Black);
        Gender1.setFont(font);
        Age.setPosition(x+20, y+70);
        Age.setCharacterSize(20);
        Age.setFillColor(Color::Black);
        Age.setFont(font);

        Top2.setPosition(x + 20, y + 180);
        Top2.setSize(Vector2f(width - 50, height / 4));
        Top2.setFillColor(Color::White);
        Second.setPosition(x+20, y+180);
        Second.setCharacterSize(20);
        Second.setFillColor(Color::Black);
        Second.setFont(font);
        s.setPosition(x+20, y+190);
        s.setCharacterSize(20);
        s.setFillColor(Color::Black);
        s.setFont(font);
        Gender2.setPosition(x+20, y+210);
        Gender2.setCharacterSize(20);
        Gender2.setFillColor(Color::Black);
        Gender2.setFont(font);
        Age2.setPosition(x+20, y+230);
        Age2.setCharacterSize(20);
        Age2.setFillColor(Color::Black);
        Age2.setFont(font);

        Top3.setPosition(x + 20, y + 330);
        Top3.setSize(Vector2f(width - 50, height / 4));
        Top3.setFillColor(Color::White);
        Third.setPosition(x+20, y+330);
        Third.setCharacterSize(20);
        Third.setFillColor(Color::Black);
        Third.setFont(font);
        t.setPosition(x+20, y+340);
        t.setCharacterSize(20);
        t.setFillColor(Color::Black);
        t.setFont(font);
        Gender3.setPosition(x+20, y+360);
        Gender3.setCharacterSize(20);
        Gender3.setFillColor(Color::Black);
        Gender3.setFont(font);
        Age3.setPosition(x+20, y+380);
        Age3.setCharacterSize(20);
        Age3.setFillColor(Color::Black);
        Age3.setFont(font);

    }

    void Draw(RenderWindow &window) {
        window.draw(Outer);
        window.draw(Title);
        window.draw(Top1);
        window.draw(Top2);
        window.draw(Top3);
        window.draw(First);
        window.draw(Second);
        window.draw(Third);
        window.draw(Gender1);
        window.draw(Gender2);
        window.draw(Gender3);
        window.draw(Age);
        window.draw(Age2);
        window.draw(Age3);


    };

    void UpdateRanking(vector<Post> data, string category) {
        std::vector<Post> filteredPosts;
        for (const auto& post : data) {
            if (post.display) {
                filteredPosts.push_back(post);
            }
        }


        if (category == "Time") {

        } else if (category == "Likes") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Likes: "  +  to_string(filteredPosts[filteredPosts.size()-1].likes));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Likes: " + to_string(filteredPosts[filteredPosts.size()-2].likes));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Likes: "  + to_string(filteredPosts[filteredPosts.size()-3].likes));

        } else if (category == "Comments") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Comments:" + to_string(filteredPosts[filteredPosts.size()-1].comments));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Comments: "  +to_string(filteredPosts[filteredPosts.size()-2].comments));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Comments: "  +to_string(filteredPosts[filteredPosts.size()-3].comments));

        } else if (category == "Shares") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Shares: "   +to_string(filteredPosts[filteredPosts.size()-1].shares));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Shares: " +to_string(filteredPosts[filteredPosts.size()-2].shares));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform +" Shares: "   +to_string(filteredPosts[filteredPosts.size()-3].shares));


        } else if (category == "Impressions") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Impressions: " +to_string(filteredPosts[filteredPosts.size()-1].impressions));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Impressions: "  +to_string(filteredPosts[filteredPosts.size()-2].impressions));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Impressions: "  +to_string(filteredPosts[filteredPosts.size()-3].impressions));


        } else if (category == "Reach") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Reach: "  +to_string(filteredPosts[filteredPosts.size()-1].impressions));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Reach: " + to_string(filteredPosts[filteredPosts.size()-2].impressions));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Reach: " +to_string(filteredPosts[filteredPosts.size()-3].impressions));


        } else if (category == "Engagement") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform +  " Engagement: "  +to_string(filteredPosts[filteredPosts.size()-1].engagementRate));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform+" Engagement: " +to_string(filteredPosts[filteredPosts.size()-2].engagementRate));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Engagement: " +to_string(filteredPosts[filteredPosts.size()-3].engagementRate));


        } else if (category == "Age") {
            First.setString(filteredPosts[filteredPosts.size()-1].platform + " Age: " +to_string(filteredPosts[filteredPosts.size()-1].audienceAge));
            Second.setString(filteredPosts[filteredPosts.size()-2].platform + " Age: " + filteredPosts[filteredPosts.size()-2].postContent + " "  +to_string(filteredPosts[filteredPosts.size()-2].audienceAge));
            Third.setString(filteredPosts[filteredPosts.size()-3].platform + " Age: " + filteredPosts[filteredPosts.size()-3].postContent + " "  +to_string(filteredPosts[filteredPosts.size()-3].audienceAge));


        }

        f.setString(filteredPosts[filteredPosts.size()-1].postID);
        s.setString(filteredPosts[filteredPosts.size()-2].postID);
        t.setString( filteredPosts[filteredPosts.size()-3].postID);
        Gender1.setString("Gender: " + filteredPosts[filteredPosts.size()-1].audienceGender );
        Gender2.setString("Gender: " +filteredPosts[filteredPosts.size()-2].audienceGender  );
        Gender3.setString("Gender: " +filteredPosts[filteredPosts.size()-3].audienceGender );
        Age.setString("Content: "+filteredPosts[filteredPosts.size()-1].postContent);
        Age2.setString("Content: "+filteredPosts[filteredPosts.size()-2].postContent);
        Age3.setString("Content: "+filteredPosts[filteredPosts.size()-3].postContent);


    };


};




#endif //SOCIAL_MEDIA_SORT_RANK_H
