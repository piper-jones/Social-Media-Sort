#ifndef SOCIAL_MEDIA_SORT_POST_H
#define SOCIAL_MEDIA_SORT_POST_H

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
    void sortBy(const string& category, std::vector<Post>& vector, bool useMerge);
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
private:
    void mergeSort(std::vector<Post>& arr, function<bool(const Post&, const Post&)> comp);
    void quickSort(std::vector<Post>& arr, function<bool(const Post&, const Post&)> comp);
    void mergeHelp(std::vector<Post>& arr, int left, int right, function<bool(const Post&, const Post&)> comp);
    void merge(std::vector<Post>& arr, int left, int mid, int right, function<bool(const Post&, const Post&)> comp);
    void quickHelp(std::vector<Post>& arr, int low, int high, function<bool(const Post&, const Post&)> comp);
    int partition(std::vector<Post>& arr, int low, int high, function<bool(const Post&, const Post&)> comp);
};

#endif //SOCIAL_MEDIA_SORT_POST_H