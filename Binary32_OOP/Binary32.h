#pragma once
#include"Header.h"

class Binary32
{
private:
	size_t size = 32;
	std::vector <bool> bin{};
public:
	Binary32()
	{
		cout << "DefConstructor >> \t" << this << endl;
	}
	Binary32(std::vector <bool> bin)
	{
		this->bin = bin;
		cout << "Constructor >> \t" << this << endl;
	}
	~Binary32()
	{
		cout << "Destructor >> \t" << this << endl;
	};
	Binary32 & operator=(const Binary32& other)
	{
		this->bin.clear();
		this->bin = other.bin;
		return *this;
	}
	Binary32& operator=(const Binary32&& other)
	{
		this->bin.clear();
		this->bin = bin;

		return *this;
	}
	Binary32& operator=(std::vector<bool>&& bin)
	{
		this->bin.clear();
		this->bin = bin;
		bin.clear();
		return *this;
	}
	Binary32(const Binary32& other)
	{
		this->bin = other.bin;
	}
	Binary32(const Binary32&& other)
	{
		this->bin = other.bin;
	}
	void print() const
	{
		cout << endl << this << ":" << endl << "size >>\t" << bin.size() << endl << "bin >> ";
		for (int i = 0; i < this->bin.size(); i++)
		{
			if (i % 8 == 4)
			{
				cout << ' ';
			}
			cout << this->bin[i];
		}
	}

};
/*
std::vector<bool> operator &(const Binary32& left, const Binary32& right)
{
	std::vector<bool> arr;
	for (size_t i = 0;; i++)
	{
		if (left[i] && right[i])
		{
			arr[i] = 1;
		}
		else
		{
			arr[i] = 0;
		}
	}
	return arr;
}*/




