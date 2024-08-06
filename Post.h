#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Post {
public:
    //Comparison attributes
    //Comparison attributes
    string platform;
    string postID;
    string postType;
    string postContent;
    string timeStamp;
    //Using time stamp to assign time:
    float time;
    int likes;
    int comments;
    int shares;
    int impressions;
    int reach;
    float engagementRate;
    int audienceAge;
    string audienceGender;
    string location;
    string audienceInterests;
    //skipped campaign ID here
    string sentiment;
    //skipped influence ID here
    bool display;

    //default constructor
    Post();
    //parameterized constructor
    Post(string platform, string postID, string postType, string postContent,
         string timeStamp, float time, int likes, int comments, int shares,
         int impressions, int reach, float engagementRate, int audienceAge,
         string audienceGender, string location, string audienceInterests, string sentiment);
};

class Sort {
public:
    vector<Post> vector;

    //filter types
    bool Platforms = false;
    bool Gender = false;
    bool Sentiment = false;
    //filter subcategories
    map<string, bool> platformOptions = {};
    map<string, bool> genderOptions = {};
    map<string, bool> sentimentOptions = {};
    //filter functions
    void filterOn(string category, string choice);
    void filterHandling();

    //Searchable ones- consider implementing later:
    //Post Content, Audience Interest, Location

    //sorting stuff
    bool mergeSort = true;
    void sortBy(string category);
};

