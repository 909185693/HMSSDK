// Copyright 2018 CQUnreal, Inc. All Rights Reserved.

#pragma once

#include "HMSTypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "HuaweiAuthorizationProxy.generated.h"


UCLASS()
class UHuaweiAuthorizationProxy : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHuaweiAuthorizationReply, bool, bWasSuccessful, int32, StatusCode, FAuthHuaweiId, HuaweiAccount);
	UPROPERTY(BlueprintAssignable) FHuaweiAuthorizationReply OnCompleted;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", Category = HMSSDK))
	static UHuaweiAuthorizationProxy* HuaweiAuthorization();

	virtual void Activate() override;
	virtual void BeginDestroy() override;

private:
	FDelegateHandle HuaweiAuthorizationHandle;

	void OnHuaweiAuthorizationResult(bool bSuccessful, int32 StatusCode, FAuthHuaweiId HuaweiAccount);
};