# A simple test for the minimal standard C++ library
#

#ָ��LOCAL_PATHΪ��ǰmk�ļ�����Ŀ¼
LOCAL_PATH := $(call my-dir)

#������趨ֵ
include $(CLEAR_VARS)
#�趨ģ������
LOCAL_MODULE := CppNet100
#������Դ�����ļ�
LOCAL_SRC_FILES := main.cpp
#����ͷ�ļ�Ŀ¼
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../depends/include

#����Ϊ��������\��̬�� .so
include $(BUILD_SHARED_LIBRARY)

############
##����Ϊ��ִ�г���
##include $(BUILD_EXECUTABLE)
##����Ϊ��̬�� .a
##include $(BUILD_STATIC_LIBRARY)