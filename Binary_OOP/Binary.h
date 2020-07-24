#pragma once
#include"Header.h"


class Binary;
std::ostream& operator<<(std::ostream& os, Binary& obj);
std::vector<bool> convert10in2(unsigned long long int numb);

class Binary
{
private:
	std::vector<bool>bin;

public:
	Binary() {};
	Binary(const Binary& other)
	{
		this->bin = other.bin;	
	}
	Binary(const Binary&& other)
	{
		this->bin = other.bin;
	}
	Binary(std::vector<bool> bin)
	{
		this->bin = bin;
	}
	Binary(unsigned long long int number)
	{
		this->bin = convert10in2(number);
	}

	Binary& operator=(const Binary& other)
	{
		this->bin.clear();
		this->bin = other.bin;
		return *this;
	}
	Binary& operator=(const Binary&& other)
	{
		this->bin.clear();
		this->bin = bin;
		
		return *this;
	}
	Binary& operator=(std::vector<bool> && bin)
	{
		this->bin.clear();
		this->bin = bin;
		bin.clear();
		return *this;
	}

	~Binary()
	{
		this->bin.clear();
	}

	void set_bin()
	{
		size_t size;
		cout << "enter size of array: "; cin >> size;
		if (size > 64) size = 64;
		this->bin.resize(size);
		bool bit;
		for (size_t i = 0; i < this->bin.size(); i++)
		{
			cout << "enter bin[" << i << "] = "; cin >> bit;
			this->bin[i] = bit;
		}
	}
	bool operator [] (int i) const
	{
		return this->bin[i];
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
		cout << endl << "DEX >> " << this->convert2in10();
		
	}

	unsigned long long int convert2in10()const
	{
		unsigned long long int number = 0;
		for (int i = bin.size() - 1, j = 0; j < bin.size(); j++, i--)
		{
			if (this->bin[j]) {
				number += pow(2, i);
			}
		}
		return number;
	}

	Binary operator+(const Binary& left)const
	{
		Binary temp(convert10in2(this->convert2in10() + left.convert2in10()));
		return temp;
	}
	Binary operator-(const Binary& left)const
	{
		Binary temp(convert10in2(this->convert2in10() - left.convert2in10()));
		return temp;
	}
	Binary operator*(const Binary& left)const
	{
		Binary temp(convert10in2(this->convert2in10() * left.convert2in10()));
		return temp;
	}
	Binary operator/(const Binary& left)const
	{
		Binary temp(convert10in2(this->convert2in10() / left.convert2in10()));
		return temp;
	}

	std::vector<bool> operator~()const
	{
		std::vector <bool>arr(this->bin.size());
		for (int i = 0; i < this->bin.size(); i++)
		{
			arr[i] = !this->bin[i];
		}
		return arr;
	}
	std::vector<bool> get_bin()const
	{
		return this->bin;
	}
};

std::ostream& operator<<(std::ostream& os, Binary& obj)
{
	obj.print();
	return os;
}
std::vector<bool> convert10in2(unsigned long long int numb)
{
	unsigned long long int j = 0;
	unsigned long long int buff = numb;
	while (buff > 0)
	{
		buff /= 2;
		j++;
	}
	bool bit;
	std::vector<bool> bin(j--);
	while (numb > 0)
	{
		bin[j] = numb % 2;
	//	cout << endl << "bin[" << j << "] = " << bin[j];
		j--;
		numb /= 2;
	}
	return bin;
}
std::vector<bool> power( Binary left,  Binary right)
{
	std::vector<bool> bin = convert10in2(pow(left.convert2in10(), right.convert2in10()));
	return bin;	
}
std::vector<bool> operator ^(const Binary& left, const Binary& right)
{
	std::vector<bool> arr;
	left.get_bin().size() > right.get_bin().size() ? arr = left.get_bin() : arr = right.get_bin();

	for (size_t i = 0; i < left.get_bin().size() && i < right.get_bin().size(); i++)
	{
		if ((!left[i] && !right[i]) || (left[i] && right[i]))
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
		return arr;
}
std::vector<bool> operator |(const Binary& left, const Binary& right)
{
	std::vector<bool> arr;
	left.get_bin().size() > right.get_bin().size() ? arr = left.get_bin() : arr = right.get_bin();

	for (size_t i = 0; i < left.get_bin().size() && i < right.get_bin().size(); i++)
	{
		if (!left[i] && !right[i])
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	
	}
	return arr;
}
std::vector<bool> operator &(const Binary& left, const Binary& right)
{
	std::vector<bool> arr;
	left.get_bin().size() > right.get_bin().size() ? arr = left.get_bin() : arr = right.get_bin();

	for (size_t i = 0; i < left.get_bin().size() && i < right.get_bin().size(); i++)
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
}

