// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Tilemap.h"

ACPP_Tilemap::ACPP_Tilemap()
{
	this->Width = 100;
	this->Height = 100;
	this->TileWidth = 100;
	this->TileHeight = 100;
	MapTiles.Init(nullptr, Width * Height);
	AttachmentRules = new FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
}

// Sets default values
ACPP_Tilemap::ACPP_Tilemap(int MaxWidth, int MaxHeight, float TileWidth,  float TileHeight)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MapTiles.Init(nullptr, Width * Height);
	this->Width = MaxWidth;
	this->Height = MaxHeight;
	this->TileWidth = TileWidth;
	this->TileHeight = TileHeight;
	AttachmentRules = new FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
}

// Called when the game starts or when spawned
void ACPP_Tilemap::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_Tilemap::PlaceTileInGrid(int XIndex, int YIndex, float HeightOffset, ACPP_Tile* Tile)
{
	FVector CurrentLocation = Tile->GetActorLocation();
	CurrentLocation += FVector(XIndex * (TileWidth + Spacing), YIndex * (TileHeight + Spacing), HeightOffset);
	Tile -> SetActorLocation(CurrentLocation);
}

// Called every frame
void ACPP_Tilemap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_Tilemap::AddTile(int XIndex, int YIndex, float HeightOffset, ACPP_Tile* Tile)
{
	ACPP_Tile* CurrentTile = MapTiles[XIndex + YIndex * Width];
	if(CurrentTile != nullptr)
	{
		CurrentTile -> Destroy();
	}
	Tile -> AttachToActor(this, *AttachmentRules);
	PlaceTileInGrid(XIndex, YIndex, HeightOffset, Tile);
	MapTiles[XIndex + YIndex * Width] = Tile;
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
	Tile->Destroy();
}

void ACPP_Tilemap::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

