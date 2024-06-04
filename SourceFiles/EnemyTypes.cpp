#include "EnemyTypes.hpp"

// storing textures here
Animation batAnimation = Animation("..\\Resourses\\Animations\\bat.png", 27, {AnimationState("move", 4, true) ,AnimationState("attack", 7, false), AnimationState("hit", 5, false), AnimationState("death", 11, false)});