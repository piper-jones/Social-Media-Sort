#include "Post.h"
#include <iostream>
using namespace std;

//Post default constructor
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
    this->time = 0;
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

    this->display = false;
}




void Sort::filterOn(string category, string choice){
    if (category == "Platform"){
        for (Post post: vector) {
            if (post.platform != choice)
                post.display = false;
        }
    }
    if (category == "Gender"){
        for (Post post: vector) {
            if (post.audienceGender != choice)
                post.display = false;
        }
    }
    if (category == "Sentiment"){
        for (Post post: vector) {
            if (post.sentiment != choice)
                post.display = false;
        }
    }
}

void Sort::filterHandling(){
    //set all display true
    for (Post post: vector)
        post.display = true;

    //check what filters are on and if they are, turn them on
    if (Platforms) {
        for (const auto& pair : platformOptions) {
            if (pair.second)
                filterOn("Platform", pair.first);
        }
    }
    if (Gender) {
        for (const auto& pair : genderOptions) {
            if (pair.second)
                filterOn("Gender", pair.first);
        }
    }
    if (Sentiment) {
        for (const auto& pair : sentimentOptions) {
            if (pair.second)
                filterOn("Sentiment", pair.first);
        }
    }
}

void Sort::sortBy(string category) {
    //fix how vector is called
    /*if (mergeSort) {
        if (category == "Time")
            mergeSort(vector, &Post::time);
        else if (category == "Likes")
            mergeSort(vector, &Post::likes);
        else if (category == "Comments")
            mergeSort(vector, &Post::comments);
        else if (category == "Shares")
            mergeSort(vector, &Post::shares);
        else if (category == "Impressions")
            mergeSort(vector, &Post::impressions);
        else if (category == "Reach")
            mergeSort(vector, &Post::reach);
        else if (category == "Engagement Rate")
            mergeSort(vector, &Post::engagementRate);
        else if (category == "Audience Age")
            mergeSort(vector, &Post::audienceAge);
    }
    else {
        if (category == "Time")
            quickSort(vector, &Post::time);
        else if (category == "Likes")
            quickSort(vector, &Post::likes);
        else if (category == "Comments")
            quickSort(vector, &Post::comments);
        else if (category == "Shares")
            quickSort(vector, &Post::shares);
        else if (category == "Impressions")
            quickSort(vector, &Post::impressions);
        else if (category == "Reach")
            quickSort(vector, &Post::reach);
        else if (category == "Engagement Rate")
            quickSort(vector, &Post::engagementRate);
        else if (category == "Audience Age")
            quickSort(vector, &Post::audienceAge);
    }*/
}

/*
 * logic for changing sort parameter
 *
 * sort(vector, int Post::*chosenAttribute) {
 * vector[i].*chosenAttribute //how to call to the attribute
 * }
 *
 * how to run the attribute into the parameter line:
 * sort(vectorName, &Post::attributeName)
 */

