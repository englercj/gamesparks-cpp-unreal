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

        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "GameSparks"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "cjson"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "easywsclient"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "google"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "hmac"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src", "mbedtls"));
        PrivateIncludePaths.Add(Path.Combine(GameSparksPath, "src"));

        switch (Target.Platform)
        {
            case UnrealTargetPlatform.Win32:
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libVSWin32", "libeay32.lib"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libVSWin32", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Win64:
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libVSWin64", "libeay32.lib"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libVSWin64", "ssleay32.lib"));
                break;
            case UnrealTargetPlatform.Android:
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libAndroid", "arm", "libcrypto.a"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libAndroid", "arm", "libssl.a"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libAndroid", "x86", "libcrypto.a"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libAndroid", "x86", "libssl.a"));
                break;
            case UnrealTargetPlatform.IOS:
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libIOS", "libcrypto.a"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libIOS", "libssl.a"));
                AddLibrary("c++");
                break;
            case UnrealTargetPlatform.Mac:
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libOSX", "libcrypto.a"));
                //AddLibrary(Path.Combine(GameSparksPath, "lib", "openssl", "libOSX", "libssl.a"));
                break;
            case UnrealTargetPlatform.PS4:
                break;
            case UnrealTargetPlatform.XboxOne:
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

