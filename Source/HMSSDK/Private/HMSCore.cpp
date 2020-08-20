// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HMSCore.h"
#if PLATFORM_ANDROID
#include "Platforms/Android/HMSJNI.h"
#endif

FHuaweiAuthorizationDelegate FHMSCore::OnAuthorizationDelegate;
FHuaweiCancelAuthorizationDelegate FHMSCore::OnCancelAuthorizationDelegate;

void FHMSCore::Authorization()
{
#if PLATFORM_ANDROID
	huaweiAuthorization();
#else
	OnAuthorizationDelegate.Broadcast(false, INVALID_STATUS_CODE, FAuthHuaweiId());
#endif
}

void FHMSCore::CancelAuthorization()
{
#if PLATFORM_ANDROID
	huaweiCancelAuthorization();
#else
	OnCancelAuthorizationDelegate.Broadcast(false, INVALID_STATUS_CODE);
#endif
}
