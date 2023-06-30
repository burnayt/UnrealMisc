// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstTPS/Character/ModularCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AModularCharacter::AModularCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

	SetupModularStuff();	
}

// Called when the game starts or when spawned
void AModularCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AModularCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AModularCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AModularCharacter::SetupModularStuff()
{	
	Gloves = CreateDefaultSubobject<USkeletalMeshComponent>("Gloves");	
	ShirtPatches = CreateDefaultSubobject<USkeletalMeshComponent>("ShirtPatches");

	Gloves->SetupAttachment(GetMesh());
	ShirtPatches->SetupAttachment(GetMesh());
	
	
	Pants = CreateDefaultSubobject<USkeletalMeshComponent>("Pants");	
	Boots = CreateDefaultSubobject<USkeletalMeshComponent>("Boots");

	Pants->SetupAttachment(GetRootComponent());
	Boots->SetupAttachment(Pants);
	

	Balaclava = CreateDefaultSubobject<USkeletalMeshComponent>("Balaclava");	
	Hat = CreateDefaultSubobject<USkeletalMeshComponent>("Hat");
	HatPatches = CreateDefaultSubobject<USkeletalMeshComponent>("HatPatches");	
	Glasses = CreateDefaultSubobject<USkeletalMeshComponent>("Glasses");	
	Headphones = CreateDefaultSubobject<USkeletalMeshComponent>("Headphones");

	Balaclava->SetupAttachment(GetRootComponent());
	Hat->SetupAttachment(Balaclava);
	HatPatches->SetupAttachment(Hat);
	Glasses->SetupAttachment(Balaclava);
	Headphones->SetupAttachment(Balaclava);
	

	Helmet = CreateDefaultSubobject<USkeletalMeshComponent>("Helmet");	
	HelmetPreset = CreateDefaultSubobject<USkeletalMeshComponent>("HelmetPreset");	
	HelmetPatches = CreateDefaultSubobject<USkeletalMeshComponent>("HelmetPatches");	
	NVG = CreateDefaultSubobject<USkeletalMeshComponent>("NVG");	
	Visor= CreateDefaultSubobject<USkeletalMeshComponent>("Visor");

	Helmet->SetupAttachment(GetRootComponent());
	HelmetPreset->SetupAttachment(Helmet);
	HelmetPatches->SetupAttachment(Helmet);
	NVG->SetupAttachment(Helmet);
	Visor->SetupAttachment(Helmet);

	
	Vest = CreateDefaultSubobject<USkeletalMeshComponent>("Vest");	
	TacticalGroin  = CreateDefaultSubobject<USkeletalMeshComponent>("TacticalGroin");	
	Pouch =  CreateDefaultSubobject<UStaticMeshComponent>("Pouch");	
	VestPreset = CreateDefaultSubobject<USkeletalMeshComponent>("VestPreset");	
	Speaker = CreateDefaultSubobject<USkeletalMeshComponent>("Speaker");	
	VestPatches = CreateDefaultSubobject<USkeletalMeshComponent>("VestPatches");

	Vest->SetupAttachment(GetRootComponent());
	TacticalGroin->SetupAttachment(Vest, FName(TEXT("Spine_Socket")));	
	Pouch->SetupAttachment(TacticalGroin, "PouchSocket");
	VestPreset->SetupAttachment(Vest);
	Speaker->SetupAttachment(Vest);
	VestPatches->SetupAttachment(Vest);
	
	
	TacticalShoulders = CreateDefaultSubobject<USkeletalMeshComponent>("TacticalShoulders");	
	TacticalShouldersPatch = CreateDefaultSubobject<USkeletalMeshComponent>("TacticalShouldersPatch");

	TacticalShoulders->SetupAttachment(GetRootComponent());
	TacticalShouldersPatch->SetupAttachment(TacticalShoulders);

	
	WarBelt = CreateDefaultSubobject<USkeletalMeshComponent>("WarBelt");	
	DropPouch = CreateDefaultSubobject<USkeletalMeshComponent>("DropPouch");	
	WarBeltPreset = CreateDefaultSubobject<USkeletalMeshComponent>("WarBeltPreset");
	
	WarBelt->SetupAttachment(GetRootComponent());
	DropPouch->SetupAttachment(WarBelt, "Spine_Socket");
	WarBeltPreset->SetupAttachment(WarBelt);

	// SETUP POSITIONS AND ROTATIONS
	GetMesh()->SetRelativeLocation(FVector(0,0,-90));
	GetMesh()->SetRelativeRotation(FRotator(0,270,0));

	Pants->SetRelativeLocation(FVector(0,0,-90));
	Pants->SetRelativeRotation(FRotator(0,270,0));

	Balaclava->SetRelativeLocation(FVector(0,0,-90));
	Balaclava->SetRelativeRotation(FRotator(0,270,0));

	Helmet->SetRelativeLocation(FVector(0,0,-90));
	Helmet->SetRelativeRotation(FRotator(0,270,0));

	Vest->SetRelativeLocation(FVector(0,0,-90));
	Vest->SetRelativeRotation(FRotator(0,270,0));

	TacticalGroin->SetRelativeLocation(FVector(-109, 50, 0));
	TacticalGroin->SetRelativeRotation(FRotator(270, 0, 335));

	TacticalShoulders->SetRelativeLocation(FVector(0,0,-90));
	TacticalShoulders->SetRelativeRotation(FRotator(0,270,0));

	WarBelt->SetRelativeLocation(FVector(0,0,-90));
	WarBelt->SetRelativeRotation(FRotator(0,270,0));

	DropPouch->SetRelativeLocation(FVector(-106,5,-2));
	DropPouch->SetRelativeRotation(FRotator(270,0,0));
	
}

void AModularCharacter::SetupMasterComponents()
{	
	ShirtPatches->SetMasterPoseComponent(GetMesh());
	Gloves->SetMasterPoseComponent(GetMesh());

	Boots->SetMasterPoseComponent(Pants);

	Headphones->SetMasterPoseComponent(Balaclava);
	Glasses->SetMasterPoseComponent(Balaclava);
	Hat->SetMasterPoseComponent(Balaclava);
	HatPatches->SetMasterPoseComponent(Balaclava);

	HelmetPatches->SetMasterPoseComponent(Helmet);
	Visor->SetMasterPoseComponent(Helmet);;
	NVG->SetMasterPoseComponent(Helmet);
	HelmetPreset->SetMasterPoseComponent(Helmet);

	VestPreset->SetMasterPoseComponent(Vest);
	Speaker->SetMasterPoseComponent(Vest);
	VestPatches->SetMasterPoseComponent(Vest);

	TacticalShouldersPatch->SetMasterPoseComponent(TacticalShoulders);

	WarBeltPreset->SetMasterPoseComponent(WarBelt);	
}

void AModularCharacter::SetupAnimInstance()
{ 
	if (AnimInstance)
	{		
		GetMesh()->SetAnimClass(AnimInstance);
		Pants->SetAnimClass(AnimInstance);
		Balaclava->SetAnimClass(AnimInstance);
		Helmet->SetAnimClass(AnimInstance);
		Vest->SetAnimClass(AnimInstance);
		TacticalShoulders->SetAnimClass(AnimInstance);
		WarBelt->SetAnimClass(AnimInstance);
		SetupMasterComponents();
	}
}
#if WITH_EDITOR
void AModularCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	
	if (PropertyChangedEvent.GetPropertyName() =="AnimInstance" && AnimInstance)
	{
		SetupAnimInstance();
	}
	
}
#endif

