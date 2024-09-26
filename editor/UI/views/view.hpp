#pragma once

#include "multimedia_layer.hpp"

namespace BFE::UI::Views 
{
    class IView 
    {
        protected:
            const uint8_t& windowID;

            IView(Multimedia::MultimediaRegistry& multimediaRegistry, Multimedia::ApplicationWindowData&& applicationWindowData) : windowID(multimediaRegistry.CreateApplicationWindow(std::move(applicationWindowData))) {}

        public:            
            virtual void PreRender() = 0;
    };
}