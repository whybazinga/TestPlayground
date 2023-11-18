#include "TestPlaygroundEditor.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"

IMPLEMENT_GAME_MODULE(FTestPlaygroundEditorModule, MyGameEditor);

DEFINE_LOG_CATEGORY(ATPLogEditor)

#define LOCTEXT_NAMESPACE "MyGameEditor"

void FTestPlaygroundEditorModule::StartupModule()
{
	UE_LOG(ATPLogEditor, Warning, TEXT("TestPlaygroundEditor: Log Started"));
}

void FTestPlaygroundEditorModule::ShutdownModule()
{
	UE_LOG(ATPLogEditor, Warning, TEXT("TestPlaygroundEditor: Log Ended"));
}

#undef LOCTEXT_NAMESPACE
