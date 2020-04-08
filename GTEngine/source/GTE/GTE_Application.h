/******************************************************************************/
/*!
  \project GTEngine
  \file    GTE_Application.h
  \author  Gabrielle Tan Suan Choo
  \brief
    Application interface for uses who wish to create their program using this
    engine. Also defines how the application is mainly run, with some available
    customisations that the clients can make.

    All content (C) 2020 DigiPen (SINGAPORE) Corporation, all rights reserved.
    Reproduction or disclosure of this file or its contents without the prior
    written consent of DigiPen Institute of Technology is prohibited.
*/
/******************************************************************************/
#pragma once

#include "GTE_Core.h"
#include "GTE_AppState.h"
#include <Windows.h> // DWORD, BOOL

namespace GTE
{

    class GTE_API Application
    {
    public:

        Application();
        virtual ~Application() = default;

        static Application* Get();

        void Run();
        void Pause();
        void Quit();

        virtual bool IsEditor() const;

    protected:

        virtual void Setup()   {};                                              // Called once at the beginning of Run
        virtual void Destroy() {};                                              // Called once at the end of Run

        virtual void PreLoad()     {};
        virtual void PostLoad()    {};
        virtual void PreInit()     {};
        virtual void PostInit()    {};
        virtual void PreUpdate()   {};
        virtual void PostUpdate()  {};
        virtual void PreCleanup()  {};
        virtual void PostCleanup() {};
        virtual void PreUnload()   {};
        virtual void PostUnload()  {};

        // ---------------------------------------------------------------------
        // Events

        virtual BOOL ControlHandler(DWORD event_code);                          // Handles the events from the console application, can be defined by user

    private:

        static Application* _application_instance;

        //Engine   _engine;
        AppState _app_state = AppState::Load;
        bool     _is_paused = false;

        void Load();
        void Init();
        void Update();
        void Cleanup();
        void Unload();

        static BOOL ControlHandlerWrapper(DWORD event_code);                    // static wrapper to call virtual control handler
    };

    GTE_API Application* CreateApplication();                                   // Defined by client
    GTE_API void         DestroyApplication(Application* app);                  // Defined by client

}