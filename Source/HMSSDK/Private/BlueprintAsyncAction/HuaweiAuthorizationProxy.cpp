// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HuaweiAuthorizationProxy.h"
#include "HMSCore.h"

UHuaweiAuthorizationProxy* UHuaweiAuthorizationProxy::HuaweiAuthorization()
{
	UHuaweiAuthorizationProxy* NewEvent = NewObject<UHuaweiAuthorizationProxy>();

	return NewEvent;
}

void UHuaweiAuthorizationProxy::Activate()
{
	Super::Activate();

	HuaweiAuthorizationHandle = FHMSCore::OnAuthorizationDelegate.AddUObject(this, &UHuaweiAuthorizationProxy::OnHuaweiAuthorizationResult);

	FHMSCore::Authorization();
}

void UHuaweiAuthorizationProxy::BeginDestroy()
{
	FHMSCore::OnAuthorizationDelegate.Remove(HuaweiAuthorizationHandle);

	Super::BeginDestroy();
}

void UHuaweiAuthorizationProxy::OnHuaweiAuthorizationResult(bool bSuccessful, int32 StatusCode, FAuthHuaweiId HuaweiAccount)
{
	FHMSCore::OnAuthorizationDelegate.Remove(HuaweiAuthorizationHandle);

	OnCompleted.Broadcast(bSuccessful, StatusCode, HuaweiAccount);

	SetReadyToDestroy();
}