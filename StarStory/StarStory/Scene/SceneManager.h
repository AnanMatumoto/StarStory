#pragma once

class SceneBase;

class SceneManager {

public:

	SceneManager();
	void Init();
	void Update();
	void AddGameObject();
	~SceneManager(){}
private:
	SceneBase* scene;


};