#pragma once
#include <iostream>
using namespace std;


class Post {
public:
    int postID;
    string postType;
    string postContent;
    string timeStamp;
    string date;
    string weekdayType;
    string time;
    string timePeriod;
    int likes;
    int comments;
    int shares;
    int impressions;
    int reach;
    int engagementRate;
    int audienceAge;
    string ageGroup;
    string audienceGender;
    string location;
    string continent;
    string audienceInterests;
    //skipped campaign ID here
    string sentiment;
    //skipped influence ID here

    //default constructor
    Post();
    //parameterized constructor
    Post(int postID, string postType, string postContent, string timeStamp, string date, string weekdayType,
         string time, string timePeriod, int likes, int comments, int shares, int impressions, int reach,
         int engagementRate, int audienceAge, string ageGroup, string audienceGender, string location,
         string continent, string audienceInterests, string sentiment);
};


