
#include "Scene.hpp"

Scene::~Scene(){
    for (int i=0;i<sceneObjects.size();i++)
    {
        delete sceneObjects[i];
    }
    sceneObjects.clear();
}


void Scene::render(Camera* camera){
	//renders all objects in the scene - calls each render function for the corresponding object
    for (int i=0;i<sceneObjects.size();i++)
    {
        sceneObjects[i]->render(camera);
    }
}

void Scene::addObject(Object *object){
    sceneObjects.push_back(object);
    
}

