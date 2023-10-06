// Fill out your copyright notice in the Description page of Project Settings.


#include "ACPP_HexTilemap.h"

ACPP_HexTilemap::ACPP_HexTilemap()
{
}

void ACPP_HexTilemap::PlaceTileInGrid(int XIndex, int YIndex, float HeightOffset, ACPP_Tile* Tile)
{
	FVector CurrentLocation = Tile->GetActorLocation();
	CurrentLocation.X += TileWidth * (XIndex + Spacing);
	CurrentLocation.Y += (TileHeight) * (YIndex + Spacing) + (XIndex % 2 * TileHeight/2);
	CurrentLocation.Z += HeightOffset;
	Tile -> SetActorLocation(CurrentLocation);
}
