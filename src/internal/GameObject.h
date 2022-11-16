#pragma once

// #include "Component.h"
// #include "Scene.h"

class Component;
class Scene;

// Scene* currentScene;

class GameObject {
    public:
        string name;
        vector<Component*> components; //all components
        map<string, int> typeToIndexMap; //map from component index -> index
        string tag;
        Scene* scene;

        GameObject(string name);

        /*
        Adds a component to the GameObject
        */
        template <typename T>
        T* AddComponent();
        
        /*
        Gets a component from the GameObject
        */
        template <class T>
        T* GetComponent();
        
        void StartAll();

        void addToScene();
};
