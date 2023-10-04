// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Tilemap.h"

// Sets default values
ACPP_Tilemap::ACPP_Tilemap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MapTiles.Init(nullptr, Width * Height);
}

// Called when the game starts or when spawned
void ACPP_Tilemap::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_Tilemap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Tilemap::AddTile(int XIndex, int YIndex, ACPP_Tile* Tile)
{
	ACPP_Tile* CurrentTile = MapTiles[XIndex + YIndex * Width];
	if(CurrentTile)
	{
		CurrentTile -> Destroy();
	}
	MapTiles[XIndex + YIndex * XIndex] = Tile;
}

ACPP_Tile* ACPP_Tilemap::GetTile(int XIndex, int YIndex)
{
	return MapTiles[XIndex + YIndex * Width];
}

void ACPP_Tilemap::RemoveTile(int XIndex, int YIndex)
{
	MapTiles[XIndex + YIndex * Width]->Destroy();
}

void ACPP_Tilemap::RemoveTile(ACPP_Tile* Tile)
{
	MapTiles.Remove(Tile);
	Destroy(Tile);
}

void ACPP_Tilemap::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

