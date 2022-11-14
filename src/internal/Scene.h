#pragma once

#include <string>
#include <vector>
#include <map>

#include "GameObject.h"

class Scene;

extern Scene* currentScene;

class Scene {
    public:
        string name;
        vector<GameObject*> gameObjects;

        Scene(string sceneName) {
            name = sceneName;
            currentScene = this;
        }
};