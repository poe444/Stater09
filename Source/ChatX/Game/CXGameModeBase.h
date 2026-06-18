// CXGameModeBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CXGameModeBase.generated.h"

class ACXPlayerController;

/**
 *
 */
UCLASS()
class CHATX_API ACXGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	FString GenerateSecretNumber();
	FString JudgeResult(const FString& InSecretNumberString, const FString& InGuessNumberString);
	FString SecretNumberString;
	TArray<TObjectPtr<ACXPlayerController>> AllPlayerControllers;
	bool IsGuessNumberString(const FString& InNumberString);



public:
	virtual void BeginPlay() override;
	virtual void OnPostLogin(AController* NewPlayer) override;

public:
	void PrintChatMessageString(ACXPlayerController* InChattingPlayerController, const FString& InChatMessageString);
	void IncreaseGuessCount(ACXPlayerController* InChattingPlayerController);
	void ResetGame();
	void JudgeGame(ACXPlayerController* InChattingPlayerController, int InStrikeCount);

};
