#include "Post.h"
#include <iostream>
using namespace std;

//default constructor
Post::Post(){}
//parameterized constructor
Post::Post(string platform, string postID, string postType, string postContent,
           string timeStamp, float time, int likes, int comments, int shares,
           int impressions, int reach, float engagementRate, int audienceAge,
           string audienceGender, string location, string audienceInterests, string sentiment){
    this->platform = platform;
    this->postID = postID;
    this->postType = postType;
    this->postContent = postContent;
    this->timeStamp = timeStamp;
    this->time = time;
    this->comments = comments;
    this->shares = shares;
    this-> impressions = impressions;
    this->reach = reach;
    this->engagementRate = engagementRate;
    this->audienceAge = audienceAge;
    this->audienceGender = audienceGender;
    this->location = location;
    this->audienceInterests = audienceInterests;
    this->sentiment = sentiment;
    this->likes = likes;
}