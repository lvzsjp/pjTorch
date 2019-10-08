# litTorchForXcode
how to make a libtorch for mac xcode IDE

在macOS的XCODE IDE构建pytorch的C++开发环境

1 在XCODE里创建Command Line Tool工程

2 设定Search Path
  例如： Header Search Path = /work/osdev/libtorch/include/**
       Library Search Path =  /work/osdev/libtorch/lib
       
3 修改math.h的头文件名
  include文件夹下面的caffe2下有两个头文件名称是math.h， 这与标准库的里
  cmath文件里的引用c标准库的math.h造成冲突，暂时解决办法是修改caffe2下的
  math.h文件的名称。（希望有大侠提出更好的解决办法）
  
4 添加libtorch里的类库
  注意，不要添加libtorch_python.dylib类库， 一旦添加会造成变量未定义错误
  具体原因不明。
