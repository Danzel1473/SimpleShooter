// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfScene.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"
#include "ShooterAIController.h"

UBTService_PlayerLocationIfScene::UBTService_PlayerLocationIfScene()
{
    NodeName = "Update Player Location";
}

void UBTService_PlayerLocationIfScene::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if(PlayerPawn == nullptr) return;
    if(OwnerComp.GetAIOwner() == nullptr) return;

    if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)){
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn); 
    } else{
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    }
}
