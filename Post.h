#pragma once
#include <iostream>
#include <vector>
using namespace std;



class Post {
public:
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

    //default constructor
    Post();
    //parameterized constructor
    Post(string platform, string postID, string postType, string postContent,
         string timeStamp, float time, int likes, int comments, int shares,
         int impressions, int reach, float engagementRate, int audienceAge,
         string audienceGender, string location, string audienceInterests, string sentiment);
};

class Sort {
    vector<Post> vector;
};

