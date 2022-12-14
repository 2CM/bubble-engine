#pragma once

#include "../internal/Component.h"
#include "../internal/GameObject.h"
#include "../internal/Scene.h"

#include "../math.h"

class Transform : public Component {
    public:
        Vector3 position;
        vector<Transform*> children;
        Transform* parent;
        int childCount = 0;

        void Start() {}

        void translate(Vector3 translation) {
            position = position + translation;
        }

        void SetParent(Transform* p) {
            vector<GameObject*> sibs;

            if(parent == nullptr) {
                sibs = gameObject->scene->children;
            } else {
                for(auto i : parent->children) {
                    sibs.push_back(i->gameObject);
                }
            }

            for(int i = 0; i < sibs.size(); i++) {

                if(sibs.at(i) == this->gameObject) {
                    cout << "found it" << endl;

                    //remove from parent (either nullptr or Transform*)
                    if(parent == nullptr) {
                        this->gameObject->scene->children.erase(this->gameObject->scene->children.begin()+i);
                    } else {
                        parent->children.erase(parent->children.begin()+i);
                        parent->childCount--;
                    }
                }
            }            

            parent = p;

            p->children.push_back(this);
            p->childCount++;
        }

        //finds a child by index
        Transform* GetChild(int index) {
            return children.at(index);
        }

        //finds a child by name and returns it
        Transform* Find(string name) {
            for(auto i : children) {
                if(i->gameObject->name == name) {
                    return i;
                }
            }

            return;
        }
};