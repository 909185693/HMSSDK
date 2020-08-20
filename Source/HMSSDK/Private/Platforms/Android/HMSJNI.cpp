// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Platforms/Android/HMSJNI.h"
#include "HMSCore.h"

#if PLATFORM_ANDROID

void huaweiAuthorization()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID MethonId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "huaweiAuthorization", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, MethonId);
	}
}

void huaweiCancelAuthorization()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		static jmethodID MethonId = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "huaweiCancelAuthorization", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, MethonId);
	}
}

void Java_com_epicgames_ue4_GameActivity_nativeHuaweiAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode, jobject huaweiAccount)
{
	FAuthHuaweiId authHuaweiId;

	//jclass clazz = LocalJNIEnv->FindClass("com/huawei/hms/support/hwid/result/AuthHuaweiId");

	// openId
	//jmethodID openIdMethonId = FJavaWrapper::FindMethod(LocalJNIEnv, clazz, "getOpenId", "()V", false);
	//jstring openId = (jstring)FJavaWrapper::CallObjectMethod(LocalJNIEnv, huaweiAccount, openIdMethonId);
	//authHuaweiId.OpenId = UTF8_TO_TCHAR((const char*)LocalJNIEnv->GetStringUTFChars(openId, 0));

	// gender
	//jmethodID GenderMethonId = FJavaWrapper::FindMethod(LocalJNIEnv, clazz, "getGender", "()V", false);
	//authHuaweiId.Gender = FJavaWrapper::CallIntMethod(LocalJNIEnv, huaweiAccount, GenderMethonId);

	FHMSCore::OnAuthorizationDelegate.Broadcast((bool)bSuccessful, (int32)statusCode, authHuaweiId);
}

void Java_com_epicgames_ue4_GameActivity_nativeHuaweiCancelAuthorizationResult(JNIEnv * LocalJNIEnv, jobject LocalThiz, jboolean bSuccessful, jint statusCode)
{
	FHMSCore::OnCancelAuthorizationDelegate.Broadcast((bool)bSuccessful, (int32)statusCode);
}

#endif