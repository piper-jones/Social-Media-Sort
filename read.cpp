#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include "Post.h"

using namespace std;

vector<Post> readFile(vector<Post> &data) {
    string file_path = "../social_media_engagement_data.csv";

    // Open the file
    std::ifstream file(file_path);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return data;
    }
    
    std::string line;

    // Read the header line (optional, if you want to skip headers)
    std::getline(file, line);
    std::cout << "Headers: " << line << std::endl;

    // Read each line of the file
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;


        // Parse each cell in the line
        // Variables to store data for each column
        std::string platform;
        int post_id;
        std::string post_type;
        std::string post_content;
        std::string post_timestamp;
        int likes;
        int comments;
        int shares;
        int impressions;
        int reach;
        float engagement_rate;
        int audience_age;
        std::string audience_gender;
        std::string audience_location;
        std::string audience_interests;
        std::string campaign_id;
        std::string sentiment;
        std::string influencer_id;

        // Reading in the Columns
        std::getline(ss, platform, ',');
        std::getline(ss, cell, ','); post_id = std::stoi(cell);
        std::getline(ss, post_type, ',');
        std::getline(ss, post_content, ',');
        std::getline(ss, post_timestamp, ',');
        std::getline(ss, cell, ','); likes = std::stoi(cell);
        std::getline(ss, cell, ','); comments = std::stoi(cell);
        std::getline(ss, cell, ','); shares = std::stoi(cell);
        std::getline(ss, cell, ','); impressions = std::stoi(cell);
        std::getline(ss, cell, ','); reach = std::stoi(cell);
        std::getline(ss, cell, ','); engagement_rate = std::stof(cell);
        std::getline(ss, cell, ','); audience_age = std::stoi(cell);
        std::getline(ss, audience_gender, ',');
        std::getline(ss, audience_location, ',');
        std::getline(ss, audience_interests, ',');
        std::getline(ss, campaign_id, ',');
        std::getline(ss, sentiment, ',');
        std::getline(ss, influencer_id, ',');

        string temp = post_timestamp;
        temp.erase(std::remove(temp.begin(), temp.end(), ':'), temp.end());


        data.push_back(Post(platform,post_id,post_type,post_content, post_timestamp, stof(temp),likes, comments,shares,impressions,reach,engagement_rate,audience_age, audience_gender,audience_location,audience_interests,sentiment));
    }
}

