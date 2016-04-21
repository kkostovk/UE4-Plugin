// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "InventoryPluginPrivatePCH.h"
#include "InventoryPluginEdMode.h"
#include "InventoryPluginEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"

const FEditorModeID FInventoryPluginEdMode::EM_InventoryPluginEdModeId = TEXT("EM_InventoryPluginEdMode");

FInventoryPluginEdMode::FInventoryPluginEdMode()
{

}

FInventoryPluginEdMode::~FInventoryPluginEdMode()
{

}

void FInventoryPluginEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FInventoryPluginEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FInventoryPluginEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FInventoryPluginEdMode::UsesToolkits() const
{
	return true;
}




