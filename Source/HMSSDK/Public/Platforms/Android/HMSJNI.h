// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#if PLATFORM_ANDROID

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"



// ��Ϊ��Ȩ�ӿ�
void huaweiAuthorization();

// ��Ϊȡ����Ȩ�ӿ�
void huaweiCancelAuthorization();

// ��Ϊ��Ȩ���
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeHuaweiAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode, jobject huaweiAccount);

// ��Ϊȡ����Ȩ���
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeHuaweiCancelAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode);
#endif
