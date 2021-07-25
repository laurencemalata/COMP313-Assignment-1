#include "SoundNotifyState.h"
#include "Components/AudioComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

void USoundNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
    // Sound starts to play.
    if (m_SoundToPlay) {
        m_AudioComponent = UGameplayStatics::SpawnSoundAttached(
            m_SoundToPlay, MeshComp, NAME_None,
            FVector(ForceInit), EAttachLocation::KeepRelativeOffset,
            true
        );
    }
}

void USoundNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    // Sound stops playing
    if (m_AudioComponent)
    {
        m_AudioComponent->Stop();
        m_AudioComponent = NULL;
    }
}
