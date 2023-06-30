// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModularCharacter.generated.h"

UCLASS()
class FIRSTTPS_API AModularCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AModularCharacter();
	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*
	 * Modular Art Stuff
	 */

#if WITH_EDITOR
public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAnimInstance> AnimInstance;
private:	
	void SetupModularStuff();
	void SetupMasterComponents();
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Gloves;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* ShirtPatches;


	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Pants;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Boots;


	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Balaclava;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Hat;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* HatPatches;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Glasses;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Headphones;


	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Helmet;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* HelmetPreset;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* HelmetPatches;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* NVG;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Visor;


	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Vest;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* TacticalGroin;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Pouch;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* VestPreset;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* Speaker;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* VestPatches;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* TacticalShoulders;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* TacticalShouldersPatch;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* WarBelt;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* DropPouch;
	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* WarBeltPreset;

private:	
	void SetupAnimInstance();
	


	
	
	
};



