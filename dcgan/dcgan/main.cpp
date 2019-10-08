//
//  main.cpp
//  dcgan
//
//  Created by panotech on 2019/10/07.
//  Copyright © 2019 panotech. All rights reserved.
//

#include <iostream>
#include <torch/torch.h>

int main(int argc, const char * argv[]) {
    auto a = torch::eye(4);
    std::cout << a << std::endl;
    return 0;
}
