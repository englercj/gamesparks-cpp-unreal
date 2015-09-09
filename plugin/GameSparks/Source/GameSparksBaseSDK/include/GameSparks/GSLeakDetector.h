// Copyright 2015 GameSparks Ltd 2015, Inc. All Rights Reserved.
#ifndef GSLeakDetector_h__
#define GSLeakDetector_h__

#pragma once

#include <GameSparks/gsstl.h>

#undef GS_USE_LEAK_DETECTOR
//#define GS_USE_LEAK_DETECTOR 1

#if defined(GS_USE_LEAK_DETECTOR) && !defined(DOXYGEN)
namespace GameSparks {
    namespace Util
    {
        namespace LeakDetector
        {
            struct LeakedObjectDetectorBase
            {
                LeakedObjectDetectorBase()
                {
                    getAliveObjects().insert(this);
                }
                
                virtual ~LeakedObjectDetectorBase()
                {
                    getAliveObjects().erase(this);
                }
                
                virtual const char* getLeakedObjectClassName() const = 0;
                
                typedef gsstl::set<LeakedObjectDetectorBase*> AliveObjects;
                static AliveObjects& getAliveObjects()
                {
                    static AliveObjects aliveObjects;
                    return aliveObjects;
                }
                
                static gsstl::string getLeakedClasses()
                {
                    gsstl::string ret;
                    
                    for(AliveObjects::iterator i=getAliveObjects().begin(); i!=getAliveObjects().end(); ++i)
                    {
                        ret += gsstl::string("Leaked: ") + (*i)->getLeakedObjectClassName() + "\n";
                    }
                    
                    return ret;
                }
                
                static void Cleanup()
                {
                    getAliveObjects().clear();
                }
            };
            
            template <typename OwnerClass>
            struct LeakedObjectDetector : public LeakedObjectDetectorBase
            {
                virtual const char* getLeakedObjectClassName() const
                {
                    return OwnerClass::getLeakedObjectClassName();
                }
            };
        }
    }
}

#   define GS_LEAK_DETECTOR(OwnerClass) \
        friend struct GameSparks::Util::LeakDetector::LeakedObjectDetector<OwnerClass>; \
        static const char* getLeakedObjectClassName() { return #OwnerClass; } \
        GameSparks::Util::LeakDetector::LeakedObjectDetector<OwnerClass> _gs_leak_detector_;
#else
#   define GS_LEAK_DETECTOR(OwnerClass)
#endif /* GS_USE_LEAK_DETECTOR */

#endif // GSLeakDetector_h__
