#pragma once

#include <string>
#include <vector>
#include <map>

#include "Component.h"
#include "Scene.h"

Scene* currentScene;

using namespace std;

class GameObject {
    public:
        string name;
        vector<Component*> components; //all components
        map<string, int> typeToIndexMap; //map from component index -> index
        string tag;
        Scene* scene;

        template <typename T>
        T AddComponent() {
            components.push_back(new T());
            components[components.size()-1]->COMP_NAME = typeid(T).name();
            components[components.size()-1]->gameObject = this;
            components[components.size()-1]->Awake();

            typeToIndexMap.insert({ typeid(T).name(), components.size()-1 });

            return *(T*)(components[components.size()-1]);
        }
        
        template <class T>
        T GetComponent() {
            // cout << typeid(T).name() << " | ";
            // cout << components[0]->COMP_NAME << endl;

            int compIndex = typeToIndexMap[typeid(T).name()];

            return *(T*)(components[compIndex]);
        }

        void StartAll() {
            for(Component* i : components) {
                i->Start();
            }
        }

        void addToScene() {
            currentScene->gameObjects.push_back(this);
            scene = currentScene;
        }

        GameObject(string goName) {
            name = goName;
            addToScene();
        }
};
