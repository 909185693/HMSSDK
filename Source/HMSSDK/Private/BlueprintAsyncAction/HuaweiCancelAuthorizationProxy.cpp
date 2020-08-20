// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "HuaweiCancelAuthorizationProxy.h"
#include "HMSCore.h"

UHuaweiCancelAuthorizationProxy* UHuaweiCancelAuthorizationProxy::HuaweiCancelAuthorization()
{
	UHuaweiCancelAuthorizationProxy* NewEvent = NewObject<UHuaweiCancelAuthorizationProxy>();

	return NewEvent;
}

void UHuaweiCancelAuthorizationProxy::Activate()
{
	Super::Activate();

	HuaweiCancelAuthorizationHandle = FHMSCore::OnCancelAuthorizationDelegate.AddUObject(this, &UHuaweiCancelAuthorizationProxy::OnHuaweiCancelAuthorizationResult);

	FHMSCore::CancelAuthorization();
}

void UHuaweiCancelAuthorizationProxy::BeginDestroy()
{
	FHMSCore::OnCancelAuthorizationDelegate.Remove(HuaweiCancelAuthorizationHandle);

	Super::BeginDestroy();
}

void UHuaweiCancelAuthorizationProxy::OnHuaweiCancelAuthorizationResult(bool bSuccessful, int32 StatusCode)
{
	FHMSCore::OnCancelAuthorizationDelegate.Remove(HuaweiCancelAuthorizationHandle);

	OnCompleted.Broadcast(bSuccessful, StatusCode);

	SetReadyToDestroy();
}