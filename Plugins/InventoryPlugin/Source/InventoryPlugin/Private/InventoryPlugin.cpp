// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "InventoryPluginPrivatePCH.h"
#include "InventoryPluginEdMode.h"

#define LOCTEXT_NAMESPACE "FInventoryPluginModule"

void FInventoryPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FInventoryPluginEdMode>(FInventoryPluginEdMode::EM_InventoryPluginEdModeId, LOCTEXT("InventoryPluginEdModeName", "InventoryPluginEdMode"), FSlateIcon(), true);
}

void FInventoryPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FInventoryPluginEdMode::EM_InventoryPluginEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInventoryPluginModule, InventoryPlugin)