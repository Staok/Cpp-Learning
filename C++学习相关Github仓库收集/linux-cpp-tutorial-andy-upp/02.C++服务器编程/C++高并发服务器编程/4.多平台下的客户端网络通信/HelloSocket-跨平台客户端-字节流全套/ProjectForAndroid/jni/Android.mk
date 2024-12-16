# A simple test for the minimal standard C++ library
#

#指定LOCAL_PATH为当前mk文件所在目录
LOCAL_PATH := $(call my-dir)

#清除已设定值
include $(CLEAR_VARS)
#设定模块名称
LOCAL_MODULE := CppNet100
#包含的源代码文件
LOCAL_SRC_FILES := main.cpp
#包含头文件目录
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../depends/include

#编译为共享代码库\动态库 .so
include $(BUILD_SHARED_LIBRARY)

############
##编译为可执行程序
##include $(BUILD_EXECUTABLE)
##编译为静态库 .a
##include $(BUILD_STATIC_LIBRARY)