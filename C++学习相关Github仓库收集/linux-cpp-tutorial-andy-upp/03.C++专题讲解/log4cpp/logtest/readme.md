如何编译安装log4cpp

下载代码
官网log4cpp下载 或者git下载
git clone https://git.code.sf.net/p/log4cpp/codegit log4cpp-codegit


编译安装
cd log4cpp-codegit/  
./autogen.sh  
./configure  
make
make check
make install
安装完成后，头文件在/usr/local/include/log4cpp， 库文件在/usr/local/lib下。


