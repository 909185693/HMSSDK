// Copyright 2018 CQUnreal, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintAsyncActionBase.h"
#include "HuaweiCancelAuthorizationProxy.generated.h"


UCLASS()
class UHuaweiCancelAuthorizationProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHuaweiCancelAuthorizationReply, bool, bWasSuccessful, int32, StatusCode);
	UPROPERTY(BlueprintAssignable) FHuaweiCancelAuthorizationReply OnCompleted;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = HMSSDK))
	static UHuaweiCancelAuthorizationProxy* HuaweiCancelAuthorization();

	virtual void Activate() override;
	virtual void BeginDestroy() override;

private:
	FDelegateHandle HuaweiCancelAuthorizationHandle;

	void OnHuaweiCancelAuthorizationResult(bool bSuccessful, int32 StatusCode);
};