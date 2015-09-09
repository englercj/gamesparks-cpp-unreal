// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class GameSparks : ModuleRules
{
	public GameSparks(TargetInfo Target)
	{
		//Private Paths
        PrivateIncludePaths.AddRange(new string[] { 
			"GameSparks/Private"
		});

        PublicDependencyModuleNames.AddRange(
			new string[] { 
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore",
				"RHI",
                "OnlineSubsystemUtils"
			}
		);

        AddGameSparksSDK(Target);
       
        PrivateDependencyModuleNames.Add("GameSparks");

        DynamicallyLoadedModuleNames.Add("Json");
        PublicIncludePathModuleNames.Add("Json");

        PCHUsage = PCHUsageMode.NoSharedPCHs;
	}

    private string ModulePath
    {
        get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    }

    private string GameSparksPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "..", "GameSparksBaseSDK")); }
    }

    private void AddGameSparksSDK(TargetInfo Target)
    {
        AddPublicIncludePath(Path.Combine(GameSparksPath, "include"));
        AddPublicIncludePath(Path.Combine(GameSparksPath, "dependencies", "eastl", "include"));

        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "cjson"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "eastl", "src"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "easywsclient"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "google"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "hmac"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "dependencies", "openssl", "include"));

        switch (Target.Platform)
        {
            case UnrealTargetPlatform.Win32:
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libVSWin32", "libeay32.lib"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libVSWin32", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Win64:
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libVSWin64", "libeay32.lib"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libVSWin64", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Android:
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libAndroid", "arm", "libcrypto.a"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libAndroid", "arm", "libssl.a"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libAndroid", "x86", "libcrypto.a"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libAndroid", "x86", "libssl.a"));
                break;
            case UnrealTargetPlatform.IOS:
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libIOS", "libcrypto.a"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libIOS", "libssl.a"));
                AddLibrary("c++");
                break;
            case UnrealTargetPlatform.Mac:
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libOSX", "libcrypto.a"));
                AddLibrary(Path.Combine(GameSparksPath, "dependencies", "openssl", "libOSX", "libssl.a"));
                break;
            case UnrealTargetPlatform.XboxOne:
            case UnrealTargetPlatform.PS4:
            case UnrealTargetPlatform.WinRT:
            case UnrealTargetPlatform.WinRT_ARM:
            case UnrealTargetPlatform.HTML5:
            case UnrealTargetPlatform.Linux:
            default:
                throw new NotImplementedException("This target platform is not configured for GameSparks SDK: " + Target.Platform.ToString());
        }

    }

    private void AddPublicIncludePath(string path)
    {
        PublicIncludePaths.Add(path);
        Console.WriteLine("Adding \"" + path + "\" as public include path.");
    }

    private void AddLibrary(string locationOfLibFile)
    {
        Console.WriteLine("Adding \"" + locationOfLibFile + "\" as additional library for linking (private).");
        PublicAdditionalLibraries.Add(locationOfLibFile);
    }
}
