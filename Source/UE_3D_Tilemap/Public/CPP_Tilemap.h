// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Tile.h"
#include "GameFramework/Actor.h"
#include "CPP_Tilemap.generated.h"

UCLASS(Blueprintable)
class UE_3D_TILEMAP_API ACPP_Tilemap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Tilemap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	TArray<ACPP_Tile*> MapTiles;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Height;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TileSize;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AddTile(int XIndex, int YIndex, ACPP_Tile* Tile);
	virtual ACPP_Tile* GetTile(int XIndex, int YIndex);
	virtual void RemoveTile(int XIndex, int YIndex);
	virtual void RemoveTile(ACPP_Tile* Tile);
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
