// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class PLAYGROUND_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AGhost> GhostClass;
private:
	void MoveForward(float value);
	void MoveRight(float value);
	void RotateCamera(float value); 
	void StartRecording();
	void StopRecording();

	TArray<FTransform> RecordedTransforms;
	FTimerHandle TH_RecordingTimer;
	bool bIsRecording = false;
	// ** Values ** //
	float MovementSpeed = 2;
	float MaxRecordedTime = 10.f;



};
