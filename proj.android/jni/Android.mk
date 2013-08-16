LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/baselayer/CStartGame.cpp \
                   ../../Classes/baselayer/CMission.cpp \
                   ../../Classes/baselayer/ExitDialog.cpp \
                   ../../Classes/baselayer/DialogLayer.cpp \
                   ../../Classes/baselayer/CSetDialog.cpp \
                   ../../Classes/baselayer/CMainScene.cpp \
                   ../../Classes/baselayer/CWellSprite.cpp \
                   ../../Classes/baselayer/CWallData.cpp \
                   ../../Classes/HelloWorldScene.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
