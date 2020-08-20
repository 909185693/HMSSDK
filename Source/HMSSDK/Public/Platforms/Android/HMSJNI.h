// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#if PLATFORM_ANDROID

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"



// 华为授权接口
void huaweiAuthorization();

// 华为取消授权接口
void huaweiCancelAuthorization();

// 华为授权结果
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeHuaweiAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode, jobject huaweiAccount);

// 华为取消授权结果
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeHuaweiCancelAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode);
#endif
