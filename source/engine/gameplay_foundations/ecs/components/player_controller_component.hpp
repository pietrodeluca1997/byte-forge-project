#pragma once

#include <glm.hpp>

#include <unordered_map>
#include <functional>

#include "platform/multimedia/input/input_keys.hpp"

namespace BFE::GameplayFoundations::ECS
{
    struct PlayerControllerComponent
    {
        std::unordered_map<Platform::Multimedia::Input::EInputKeys, std::function<void()>> inputActions;

        template <typename TCallbackClassType>
        void AddInputActionListener(Platform::Multimedia::Input::EInputKeys triggerKey, TCallbackClassType* instance, void (TCallbackClassType::*callback)())
        {
            inputActions[triggerKey] = std::bind(callback, instance);
        }
    };
}