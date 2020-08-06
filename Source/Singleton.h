#pragma once

template<class T>
class Singleton {
private:
	static T* m_Instance;
public:
	static T* GetInstance();
	static void DestroyInstance();
};

template<class T>
T* Singleton<T>::m_Instance = nullptr;

template<class T>
T* Singleton<T>::GetInstance() {
	if (!m_Instance) {
		m_Instance = new T();
	}
	return m_Instance;
}

template<class T>
void Singleton<T>::DestroyInstance() {
	if (m_Instance) {
		delete m_Instance;
		m_Instance = nullptr;
	}
}