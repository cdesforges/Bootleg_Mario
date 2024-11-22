cmake_minimum_required(VERSION 3.29)
project(Bootleg_Mario)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bootleg_Mario main.cpp
        Components/Platform/PlatformModel.cpp
        Components/Platform/PlatformModel.h
        Components/PhysicsSprite/PhysicsModel.cpp
        Components/PhysicsSprite/PhysicsModel.h
        Components/PhysicsSprite/SpriteView.cpp
        Components/PhysicsSprite/SpriteView.h
        Collision/Collision.cpp
        Collision/Collision.h
        States/State.h
        States/StateManager.cpp
        States/StateManager.h
        States/MainGameState.cpp
        States/MainGameState.h
        Components/Component.h
        Components/Player/Player.cpp
        Components/Player/Player.h
        Components/Platform/Platform.cpp
        Components/Platform/Platform.h
        Components/Platform/PlatformView.cpp
        Components/Platform/PlatformView.h
        Components/Platform/PlatformController.cpp
        Components/Platform/PlatformController.h
        KeyboardControls/PlayerControls.h
        Components/PhysicsSprite/PhysicsSpriteController.cpp
        Components/PhysicsSprite/PhysicsSpriteController.h
        Components/PhysicsSprite/PhysicsSprite.cpp
        Components/PhysicsSprite/PhysicsSprite.h
        States/MenuState.cpp
        States/MenuState.h
        Game.cpp
        Game.h
        Collision/Collidable.h
        Components/Platform/Platform.cpp
        Components/Platform/Platform.h
        Components/Platform/PlatformModel.cpp
        Components/Platform/PlatformModel.h
        Components/Platform/PlatformView.cpp
        Components/Platform/PlatformView.h
        Components/Wall/Wall.cpp
        Components/Wall/Wall.h
        GameLogic/Gravity.h
        Animation/Animation.cpp
        Animation/Animation.h
        TextureManager/TextureManager.cpp
        TextureManager/TextureManager.h
        Components/PhysicsSprite/PhysicsSpriteType.h
        Animation/AnimationData.h
        KeyboardControls/KeyboardControllable.h
        Animation/AnimationType.h
        Components/BackGround/Background.cpp
        Components/BackGround/Background.h
        Components/SpecialBlock/SpecialBlock.h
        Components/SpecialBlock/SpecialBlock.cpp
        Components/Pipe/Pipe.cpp
        Components/Pipe/Pipe.h
        Components/Block/Block.h
        Components/Block/Block.cpp
        GameLogic/Friction.h
        GameLogic/AirResistance.h
        GameLogic/Force.cpp
        GameLogic/Force.h
)

target_link_libraries(Bootleg_Mario sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
