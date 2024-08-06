#include <iostream>
#include <vector>
#include "gui.h"
#include "read.h"
#include "Post.h"



int main() {
    std::vector<Post> data;
    readFile(data);

    gui mediaMirror;
    mediaMirror.run();


    return 0;
}
