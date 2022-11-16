#include "GameObject.h"

GameObject::GameObject(string name) {
    this->name = name;

    // this->AddComponent<Transform>();

    addToScene();
}

template <typename T>
T* GameObject::AddComponent() {
    components.push_back(new T());
    components[components.size()-1]->COMP_NAME = typeid(T).name();
    components[components.size()-1]->gameObject = this;
    components[components.size()-1]->Awake();

    typeToIndexMap.insert({ typeid(T).name(), components.size()-1 });

    return (T*)(components[components.size()-1]);
}

template <class T>
T* GameObject::GetComponent() {
    // cout << typeid(T).name() << " | ";
    // cout << components[0]->COMP_NAME << endl;

    int compIndex = typeToIndexMap[typeid(T).name()];

    // cout << compIndex << ", " << components.size() << endl;

    return (T*)(components[compIndex]);
}

void GameObject::StartAll() {
    for(Component* i : components) {
        i->Start();
    }
}

void GameObject::addToScene() {
    currentScene->children.push_back(this);
    scene = currentScene;
}