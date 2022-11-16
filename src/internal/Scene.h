#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

#include "GameObject.h"
// #include "../components/Transform.h"

class Scene {
    public:
        string name;
        vector<GameObject*> children;

        Scene(string sceneName);

        void printRecur(vector<GameObject*> children, int depth);

        void print();
};