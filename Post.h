#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Post {
public:
    string platform;
    int postID;
    string postType;
    string postContent;
    string timeStamp;
    //Using time stamp to assign time:
    float time;
    float likes;
    float comments;
    float shares;
    float impressions;
    float reach;
    float engagementRate;
    float audienceAge;
    string audienceGender;
    string location;
    string audienceInterests;
    //skipped campaign ID here
    string sentiment;
    //skipped influence ID here

    //default constructor
    Post();
    //parameterized constructor
    Post(string platform, int postID, string postType, string postContent,
         string timeStamp, float time, float likes, float comments, float shares,
         float impressions, float reach, float engagementRate, float audienceAge,
         string audienceGender, string location, string audienceInterests, string sentiment);
};

class Sort {
public:
    void sortBy(const string& category, vector<Post>& vector, bool useMerge);
private:
    void mergeSort(vector<Post>& arr, function<bool(const Post&, const Post&)> comp);
    void quickSort(vector<Post>& arr, function<bool(const Post&, const Post&)> comp);
    void mergeHelp(vector<Post>& arr, int left, int right, function<bool(const Post&, const Post&)> comp);
    void merge(vector<Post>& arr, int left, int mid, int right, function<bool(const Post&, const Post&)> comp);
    void quickHelp(vector<Post>& arr, int low, int high, function<bool(const Post&, const Post&)> comp);
    int partition(vector<Post>& arr, int low, int high, function<bool(const Post&, const Post&)> comp);
};

