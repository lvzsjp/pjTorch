//
//  main.cpp
//  dcgan
//
//  Created by RO on 2019/10/07.
//  Copyright © 2019 RO. All rights reserved.
//

#include <iostream>
#include <torch/torch.h>

////////////////////////////////////////////////////////////////////////
struct Net : torch::nn::Module {
  Net(int64_t N, int64_t M)
      : linear(register_module("linear", torch::nn::Linear(N, M))) {
    another_bias = register_parameter("b", torch::randn(M));
  }
  torch::Tensor forward(torch::Tensor input) {
    return linear(input) + another_bias;
  }
  torch::nn::Linear linear;
  torch::Tensor another_bias;
};
void testNet()
{
    Net net(4, 5);
    for (const auto& p : net.parameters()) {
      std::cout << p << std::endl;
    }
}
////////////////////////////////////////////////////////////////////////

void getStart()
{
    //Construct a 5x3 matrix, uninitialized:
    std::cout << "5x3 matrix, uninitialized:" << std::endl;
    torch::Tensor a = torch::empty({5,3});
    std::cout << a << std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
    
    //Construct a randomly initialized matrix:
    a = torch::randn({5,3});
    std::cout << "5x3 matrix, randomly initialized:" << std::endl;
    std::cout << a << std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
    
    //Construct a matrix filled zeros and of dtype long:
    auto option = torch::TensorOptions().dtype(torch::kI64);
    std::cout << "5x3 matrix, filled zeros and of dtype long:" << std::endl;
    a = torch::zeros({5,3}, option);
    std::cout << a << std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
    
    //Construct a tensor directly from data:
    std::cout << "tensor directly from data:" << std::endl;
//    auto stdArray = std::array<std::array<float, 5>, 5>{
//        1.0, 2.0, 3.0, 4.0, 5.0,
//        1.0, 2.0, 3.0, 4.0, 5.0,
//        1.0, 2.0, 3.0, 4.0, 5.0,
//        1.0, 2.0, 3.0, 4.0, 5.0,
//        1.0, 2.0, 3.0, 4.0, 5.0
//    };
    auto array = at::ArrayRef<float>({10,11,13});
    a = torch::tensor(array);
    std::cout << a << std::endl;
    std::cout <<std::endl;
    std::cout <<std::endl;
    
    //根据已有的tensor建立新的tensor
    a = torch::ones({5,3}, torch::TensorOptions().dtype(torch::kDouble));
    std::cout << a <<std::endl;
    torch::Tensor b = torch::randn_like(a, torch::TensorOptions().dtype(torch::kDouble));
    std::cout << b <<std::endl;
    
    //print size
    std::cout << a.sizes() << std::endl;
    std::cout << a.size(0) << std::endl;
    std::cout << a.size(1) << std::endl;
    
    //运算
    torch::Tensor c;
    c = a + b;
    std::cout << c + 1 << std::endl;
    
    c = torch::empty({5,3}, torch::TensorOptions().dtype(torch::kDouble));
    torch::add_out(c, a, b);
    std::cout << c << std::endl;
    std::cout << std::endl << std::endl;
    
    c = a - b;
    std::cout << c << std::endl;
    std::cout << a * b << std::endl;
    std::cout << a / b << std::endl;
    
    
    std::cout << c.slice() << std::endl;
}

int main(int argc, const char * argv[]) {
    
    
    getStart();

    return 0;
}
