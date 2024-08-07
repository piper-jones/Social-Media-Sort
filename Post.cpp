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


    this->display = true;
}





void Sort::setActiveFilter(const string& category, const string& choice) {
    if (category == "Platform") {
        // Reset all platform filters
        for (auto& pair : platformOptions) {
            pair.second = false;
        }
        // Activate the selected platform filter
        platformOptions[choice] = true;
        Platforms = true; // Indicate that at least one platform filter is active
    } else if (category == "Gender") {
        for (auto& pair : genderOptions) {
            pair.second = false;
        }
        genderOptions[choice] = true;
        Gender = true; // Indicate that at least one gender filter is active
    } else if (category == "Sentiment") {
        for (auto& pair : sentimentOptions) {
            pair.second = false;
        }
        sentimentOptions[choice] = true;
        Sentiment = true; // Indicate that at least one sentiment filter is active
    }

    filterHandling(); // Apply filters after setting the new active filter

}

void Sort::filterHandling() {
    for (Post& post : vector) {
        post.display = true;  // Reset display status before applying filters
    }

    if (Platforms) {
        for (const auto& pair : platformOptions) {
            if (pair.second) {
                filterOn("Platform", pair.first);
            }
        }
    }
    if (Gender) {
        for (const auto& pair : genderOptions) {
            if (pair.second) {
                filterOn("Gender", pair.first);
            }
        }
    }
    if (Sentiment) {
        for (const auto& pair : sentimentOptions) {
            if (pair.second) {
                filterOn("Sentiment", pair.first);
            }
        }
    }
}

void Sort::filterOn(string category, string choice) {
    for (Post& post : vector) {
        if ((category == "Platform" && post.platform != choice) ||
            (category == "Gender" && post.audienceGender != choice) ||
            (category == "Sentiment" && post.sentiment != choice)) {
            post.display = false;
        }
    }
}

Sort::Sort(){}

// takes in the category, data, and which sort to use (if bool is true, use merge)
void Sort::sortBy(const string &category, std::vector<Post> &vector, bool useMerge) {
    //(lines 32 - 72) compares two objects of the given parameter and returns a true if the first object should come before the second when sorted
    function<bool(const Post&, const Post&)> comp;
    if (category == "Time") {
        comp = [](const Post& a, const Post& b) {
            return a.time < b.time;
        };
    }
    else if (category == "Likes") {
        comp = [](const Post& a, const Post& b) {
            return a.likes < b.likes;
        };
    }
    else if (category == "Comments") {
        comp = [](const Post& a, const Post& b) {
            return a.comments < b.comments;
        };
    }
    else if (category == "Shares") {
        comp = [](const Post& a, const Post& b) {
            return a.shares < b.shares;
        };
    }
    else if (category == "Impressions") {
        comp = [](const Post& a, const Post& b) {
            return a.impressions < b.impressions;
        };
    }
    else if (category == "Reach") {
        comp = [](const Post& a, const Post& b) {
            return a.reach < b.reach;
        };
    }
    else if (category == "Engagement") {
        comp = [](const Post& a, const Post& b) {
            return a.engagementRate < b.engagementRate;
        };
    }
    else if (category == "Age") {
        comp = [](const Post& a, const Post& b) {
            return a.audienceAge < b.audienceAge;
        };
    }

    // if useMerge is true, use merge sort, else use quick sort
    if (useMerge) {
        mergeSort(vector, comp);
    }
    else {
        quickSort(vector, comp);
    }
}
// takes in the array to be sorted and the compared data
void Sort::mergeSort(std::vector<Post> &arr, function<bool(const Post&, const Post&)> comp) {
    mergeHelp(arr, 0,  arr.size() - 1, comp);
}

// recursively divides the array into two arrays then calls the merge function
void Sort::mergeHelp(std::vector<Post> &arr, int left, int right, function<bool(const Post&, const Post&)> comp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeHelp(arr, left, mid, comp);
        mergeHelp(arr, mid + 1, right, comp);
        merge(arr, left, mid, right, comp);
    }
}

// merges the divided arrays in sorted order
void Sort::merge(std::vector<Post> &arr, int left, int mid, int right, function<bool(const Post&, const Post&)> comp) {
    if (!comp) {
        std::cerr << "Comparison function is not initialized!" << std::endl;
        return;
    }
    else {

        int sub1 = mid - left + 1;
        int sub2 = right - mid;
        std::vector<Post> L(sub1), R(sub2);

        for (int i = 0; i < sub1; i++) {
            L[i] = arr[left + i];
        }
        for (int j = 0; j < sub2; j++) {
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = left;
        while (i < sub1 && j < sub2) {
            if (comp(L[i], R[j])) {
                arr[k++] = L[i++];
            }
            else {
                arr[k++] = R[j++];
            }
        }

        while (i < sub1) {
            arr[k++] = L[i++];
        }

        while (j < sub2) {
            arr[k++] = R[j++];
        }
    }

}

// takes in the array to be sorted and the compared data
void Sort::quickSort(std::vector<Post> &arr, function<bool(const Post&, const Post&)> comp) {
    quickHelp(arr, 0, arr.size() - 1, comp);
}

// makes the last element the pivot, if a value is less than the pivot, move it to the left of i (i + 1 will eventually become the new pivot position)
int Sort::partition(std::vector<Post> &arr, int low, int high, function<bool(const Post&, const Post&)> comp) {
    Post pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (comp(arr[j], pivot)) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// recursively calls itself until all values are sorted
void Sort::quickHelp(std::vector<Post> &arr, int low, int high, function<bool(const Post&, const Post&)> comp) {
    if (low < high) {
        int part = partition(arr, low, high, comp);
        quickHelp(arr, low, part - 1, comp);
        quickHelp(arr, part + 1, high, comp);
    }
}

