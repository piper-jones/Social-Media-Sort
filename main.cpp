#include <iostream>
#include "Post.h"
#include "read.h"

int main() {
    vector<Post> data;
    readFile(data);

    cout<< data.size();
    return 0;
}
