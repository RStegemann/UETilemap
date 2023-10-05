// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Tile.generated.h"

UENUM(BlueprintType)
enum ETileType
{
	Hex UMETA(DisplayName="Hex"),
	Square UMETA(DisplayName="Square")
};

UCLASS()
class UE_3D_TILEMAP_API ACPP_Tile : public AActor
{
	GENERATED_BODY()
	
public:
	ACPP_Tile();
	// Sets default values for this actor's properties
	ACPP_Tile(ETileType TileType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ETileType> TileType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
