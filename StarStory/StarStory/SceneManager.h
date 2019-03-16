#pragma once

class SceneBase;

class SceneManager {

public:
	void Init();
	void Update();
	void AddGameObject();

private:
	SceneBase* scene;


};