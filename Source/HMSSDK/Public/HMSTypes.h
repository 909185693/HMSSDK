// Copyright 2018 CQUnreal, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HMSTypes.generated.h"


USTRUCT(BlueprintType)
struct FAuthHuaweiId
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString UID;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString OpenId;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString DisplayName;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString PhotoUriString;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString AccessToken;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	int32 Status;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	int32 Gender;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString ServiceCountryCode;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString CountryCode;

	//FSet<Scope> grantedScopes;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString ServerAuthCode;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString UnionId;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString Email;

	//FSet<Scope> extensionScopes = new HashSet();

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString IdToken;
	
	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	int32 ExpirationTimeSecs;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString GivenName;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString FamilyName;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	FString AgeRange;

	UPROPERTY(BlueprintReadWrite, Category = Huawei)
	int32 HomeZone;
};