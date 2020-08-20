// Copyright 2018 CQUnreal, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HMSTypes.h"


#define INVALID_STATUS_CODE -1

DECLARE_MULTICAST_DELEGATE_ThreeParams(FHuaweiAuthorizationDelegate, bool, /*bSuccessful*/ int32, /*StatusCode*/ FAuthHuaweiId /*HuaweiAccount*/);
DECLARE_MULTICAST_DELEGATE_TwoParams(FHuaweiCancelAuthorizationDelegate, bool, /*bSuccessful*/ int32 /*StatusCode*/);

class FHMSCore
{
public:
	static void Authorization();
	static void CancelAuthorization();

public:
	static FHuaweiAuthorizationDelegate OnAuthorizationDelegate;
	static FHuaweiCancelAuthorizationDelegate OnCancelAuthorizationDelegate;
};