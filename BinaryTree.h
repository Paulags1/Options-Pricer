#pragma once
#include <iostream>
#include <vector>

template<class T>

class BinaryTree
{
private:
	int _depth;
	std::vector<std::vector<T>> _tree;

public:
	BinaryTree();
	BinaryTree(int depth);
	~BinaryTree();
	void display();
	void setDepth(int);
	int getDepth() const;
	void setNode(int, int, T);
	T getNode(int, int) const;
	bool getExercise(int, int) const;
	void setBool(int, int, bool);
};


template<class T>
BinaryTree<T>::BinaryTree() : _depth(10)
{
	for (int n = 0; n <= _depth; n++)
	{
		std::vector<T> step;
		for (int i = 0; i <= n; i++)
		{
			step.push_back(0);
		}
		_tree.push_back(step);
		step.clear();
	}

	for (int n = 0; n < _depth; n++)
	{
		for (int i = 0; i <= n; i++)
		{
			_tree[n][i] = 0;
		}
	}
}

template<class T>
BinaryTree<T>::BinaryTree(int depth) : _depth(depth)
{
	for (int n = 0; n <= _depth; n++)
	{
		std::vector<T> step;
		for (int i = 0; i <= n; i++)
		{
			step.push_back(0);
		}
		_tree.push_back(step);
		step.clear();
	}

	for (int n = 0; n < _depth; n++)
	{
		for (int i = 0; i <= n; i++)
		{
			_tree[n][i] = 0;
		}
	}
}

template<class T>
BinaryTree<T>::~BinaryTree()
{

}

template<class T>
void BinaryTree<T>::display()
{
	std::cout << std::endl;
	for (size_t n = 0; n < _tree.size(); n++)
	{
		for (size_t i = 0; i < _tree[n].size(); i++)
		{
			std::cout << _tree[n][i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<class T>
void BinaryTree<T>::setDepth(int N)
{
	if (N < _depth)
	{
		for (size_t n = _tree.size() - 1; n > N; n--)
		{
			_tree.pop_back();
		}
		_depth = N;
	}
	else
	{
		for (int n = _depth + 1; n <= N; n++)
		{
			std::vector<T> step;
			for (int i = 0; i <= n; i++)
			{
				step.push_back(0);
			}
			_tree.push_back(step);
			step.clear();
		}
	}

}

template<class T>
int BinaryTree<T>::getDepth() const
{
	return _depth;
}

template<class T>
void BinaryTree<T>::setNode(int n, int i, T k)
{
	_tree[n][i] = k;
}

template<class T>
T BinaryTree<T>::getNode(int n, int i) const
{
	return _tree[n][i];
}


template<class T>
bool BinaryTree<T>::getExercise(int n, int i) const
{
	return _tree[n][i];
}

template<class T>
void BinaryTree<T>::setBool(int n, int i, bool b)
{
	_tree[n][i] = b;
}
