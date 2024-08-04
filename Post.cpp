#include "Post.h"
#include <iostream>
using namespace std;

//default constructor
Post::Post(){}
//parameterized constructor
Post::Post(int postID, string postType, string postContent, string timeStamp, string date, string weekdayType,
           string time, string timePeriod, int likes, int comments, int shares, int impressions, int reach,
           int engagementRate, int audienceAge, string ageGroup, string audienceGender, string location,
           string continent, string audienceInterests, string sentiment){
    this->postID = postID;
    this->postType = postType;
    this->postContent = postContent;
    this->timeStamp = timeStamp;
    this->date = date;
    this->weekdayType = weekdayType;
    this->time = time;
    this->timePeriod = timePeriod;
    this->likes = likes;
    this->comments = comments;
    this->shares = shares;
    this-> impressions = impressions;
    this->reach = reach;
    this->engagementRate = engagementRate;
    this->audienceAge = audienceAge;
    this->ageGroup = ageGroup;
    this->audienceGender = audienceGender;
    this->location = location;
    this->continent = continent;
    this->audienceInterests = audienceInterests;
    this->sentiment = sentiment;
}