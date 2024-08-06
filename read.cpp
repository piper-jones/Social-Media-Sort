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
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "Failed to open the file: " << file_path << endl;
        return data;
    }

    string line;

    // Read the header line (optional)
    if (!getline(file, line)) {
        cerr << "Failed to read the header line." << endl;
        return data;
    }


    // Read each line of the file
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;

        // Variables to store data for each column
        string platform;
        string post_id;
        string post_type;
        string post_content;
        string post_timestamp;
        int likes = 0;
        int comments = 0;
        int shares = 0;
        int impressions = 0;
        int reach = 0;
        float engagement_rate = 0.0;
        int audience_age = 0;
        string audience_gender;
        string audience_location;
        string audience_interests;
        string campaign_id;
        string sentiment;
        string influencer_id;

        try {
            // Reading in the Columns
            getline(ss, platform, ',');
            getline(ss, post_id, ',');
            getline(ss, post_type, ',');
            getline(ss, post_content, ',');
            getline(ss, post_timestamp, ',');
            getline(ss, cell, ','); likes = stoi(cell);
            getline(ss, cell, ','); comments = stoi(cell);
            getline(ss, cell, ','); shares = stoi(cell);
            getline(ss, cell, ','); impressions = stoi(cell);
            getline(ss, cell, ','); reach = stoi(cell);
            getline(ss, cell, ','); engagement_rate = stof(cell);
            getline(ss, cell, ','); audience_age = stoi(cell);
            getline(ss, audience_gender, ',');
            getline(ss, audience_location, ',');
            getline(ss, audience_interests, ',');
            getline(ss, campaign_id, ',');
            getline(ss, sentiment, ',');
            getline(ss, influencer_id, ',');

            string temp = post_timestamp;
            temp.erase(remove(temp.begin(), temp.end(), ':'), temp.end());

            data.push_back(Post(platform, post_id, post_type, post_content, post_timestamp, stof(temp), likes, comments, shares, impressions, reach, engagement_rate, audience_age, audience_gender, audience_location, audience_interests, sentiment));
        } catch (const std::exception& e) {
            cerr << "Error parsing line: " << line << "\nException: " << e.what() << endl;
            // Optionally continue to the next line
            continue;
        }
    }

    return data;
}