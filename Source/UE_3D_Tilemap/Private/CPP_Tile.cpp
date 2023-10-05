// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_Tile.h"

ACPP_Tile::ACPP_Tile()
{
	this -> TileType = Hex;
}

// Sets default values
ACPP_Tile::ACPP_Tile(ETileType TileType)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this -> TileType = TileType;
}

// Called when the game starts or when spawned
void ACPP_Tile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACPP_Tile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

