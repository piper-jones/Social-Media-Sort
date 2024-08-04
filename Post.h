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
    vector<Post> vector;
public:
    void mergeSort(std::vector<float>& arr);
    void quickSort(std::vector<float>& arr);
private:
    void mergeHelp(std::vector<float>& arr, int left, int right);
    void merge(std::vector<float>& arr, int left, int mid, int right);
    void quickHelp(std::vector<float>& arr, int low, int high);
    float partition(std::vector<float>& arr, int low, int high);
};

