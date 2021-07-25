// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SoundNotifyState.generated.h"

/**
 * Child class of the UAnimNotifyState. Used to add sound properties
 * to the animations.
 * 
 * Author: Laurence Malata
 */
UCLASS()
class ASSIGNMENT_1_API USoundNotifyState : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:

    // The animation is starting
    virtual void NotifyBegin(USkeletalMeshComponent* MeshComp,
        UAnimSequenceBase* Animation,
        float TotalDuration) override;

    // The animation stoped
    virtual void NotifyEnd(USkeletalMeshComponent* MeshComp,
        UAnimSequenceBase* Animation) override;

public:

    // Sound to Play
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PushAnimation")
        USoundBase* m_SoundToPlay;

    // The audio player
    UPROPERTY(BlueprintReadWrite, Category = "PushAnimation")
        UAudioComponent* m_AudioComponent;
};

