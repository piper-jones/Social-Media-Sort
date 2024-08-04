#include "Post.h"
#include <iostream>
using namespace std;

//default constructor
Post::Post(){}
//parameterized constructor
Post::Post(string platform, int postID, string postType, string postContent,
           string timeStamp, float time, float likes, float comments, float shares,
           float impressions, float reach, float engagementRate, float audienceAge,
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
}

void Sort::mergeSort(std::vector<float> &arr) {
    if (arr.size() <= 1)
        return;
    mergeHelp(arr, 0,  arr.size() - 1);
}

void Sort::quickSort(std::vector<float> &arr) {
    if (arr.size() <= 1)
        return;
    quickHelp(arr, 0, arr.size() - 1);
}

void Sort::mergeHelp(std::vector<float> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeHelp(arr, left, mid);
        mergeHelp(arr, mid + 1, right);
    }
}

void Sort::merge(std::vector<float> &arr, int left, int mid, int right) {
    int sub1 = mid - left + 1;
    int sub2 = right - mid;
    std::vector<float> L(sub1), R(sub2);

    for (int i = 0; i < sub1; i++) {
        L[i] = arr[left + 1];
    }
    for (int j = 0; j < sub2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < sub1 && j < sub2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        }
        else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < sub1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < sub2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void Sort::quickHelp(std::vector<float> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickHelp(arr, low, pi);
        quickHelp(arr, pi + 1, high);
    }
}

float Sort::partition(std::vector<float> &arr, int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
