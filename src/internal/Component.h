#pragma once

#include <string>
// #include "Scene.h"

#include "GameObject.h"

using namespace std;

//base component
class Component {
    public:
        string COMP_NAME; //for GetComponent
        GameObject* gameObject;
        
        virtual void Awake() {} //called on init
        virtual void Start() {} //called when all other components are inited
        virtual void Update() {} //called every frame
};