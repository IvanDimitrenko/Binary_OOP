#pragma once
#include"Header.h"

class Binary32;
	std::vector<bool> convert10in2(size_t numb);

class Binary32
{
private:
	size_t size = 32;
	std::vector <bool> bin;
public:

	void set_bin(std::vector <bool> bin)
	{
		if (this->bin.size() != 32)
		{
			this->bin.resize(this->size);
		}
		try
		{
			if (bin.size() > size)
			{
				throw "the length is too long";
			}
		}
		catch (const char* a)
		{
			std::cerr << a;
			return;
		}
		for (int i = 0, y = bin.size() - 1; i < bin.size(); y--, i++)
		{
			this->bin[size - 1 - i] = bin[y];
		}
	}


	Binary32()
	{
		this->bin.resize(this->size);
		cout << "DefConstructor >> \t" << this << endl;
	}

	Binary32(size_t number)
	{
		this->bin.resize(this->size);
		set_bin(convert10in2(number));
		cout << "NumbConstructor >> \t" << this << endl;
	}


	Binary32(std::vector <bool> bin)
	{
		set_bin(bin);
		cout << "Constructor >> \t" << this << endl;
	}


	~Binary32()
	{
		cout << "Destructor >> \t" << this << endl;
	};



	Binary32(const Binary32& other)
	{	
		set_bin(other.bin);	
	}


	Binary32(const Binary32&& other)
	{
		set_bin(other.bin);
	}



	Binary32& operator=(const Binary32& other)
	{
		this->bin.clear();
		set_bin(other.bin);
		return *this;
	}


	Binary32& operator=(const Binary32&& other)
	{
		this->bin.clear();
		set_bin(other.bin);
		return *this;
	}


	Binary32& operator=(std::vector<bool>&& bin)
	{
		this->bin.clear();
		this->bin = bin;
		bin.clear();
		return *this;
	}


	Binary32& operator=(std::vector<bool>& bin)
	{
		this->bin.clear();
		set_bin(bin);
		return *this;
	}



	void print() const
	{
		cout << endl << this << ":" << endl << "size >>\t" << bin.size() << endl << "bin >> ";
		for (int i = 0; i < this->bin.size(); i++)
		{
			if (i % 4 == 0 && i > 0)
			{
				cout << ' ';
			}
			cout << this->bin[i];
		}
		cout << endl << "DEX >> " << this->convert2in10();
	}



	unsigned long int convert2in10()const
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




size_t get_size()const
{
	return this->size;
}


std::vector<bool> get_bin()const
{
return this->bin;
}


bool operator [](const size_t index)const
{
	return this->bin[index];
}



};



std::vector<bool> convert10in2(size_t numb)
{

	size_t j = 0;
	size_t buff = numb;
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




Binary32 operator+(const Binary32& left, const Binary32& right)
{

	std::vector<bool>arr(32, 0);
	bool temp = 0;
	int i = left.get_size() - 1;


	// 3 XOR gate
	while (i)
	{
		//	(	1			1			0	)	 (	0			   1	)	(	 1			 0          1)
		if (((left[i] && right[i]) && !temp) || (((!left[i] && right[i]) || (left[i] && !right[i])) && temp))
		{
			arr[i] = 0;
			temp = 1;
		}
		//         (	0	     	1	)   (     1			0			  0   )    (	0			0			1)
		else if ((((!left[i] && right[i]) || (left[i] && !right[i])) && !temp) || ((!left[i] && !right[i]) && temp))
		{
			arr[i] = 1;
			temp = 0;
		}
		else if ((left[i] && right[i]) && temp)
		{
			arr[i] = 1;
			temp = 1;
		}
		else if ((!left[i] && !right[i]) && !temp)
		{
			arr[i] = 0;
		}
		i--;
	}
	return arr;

}

Binary32 operator-(const Binary32& left, const Binary32& right)
{

	std::vector<bool>arr(32, 0);
	bool temp = 0;
	int i = left.get_size() - 1;


	// 3 XOR gate
	while (i)
	{
		//	(	1			1			0	)	  (	   0			0			0  )		
		if (((left[i] && right[i]) && !temp) ||  ((!left[i] && !right[i]) && !temp) || (left[i] && ! right[i] )      )
		{
			arr[i] = 0;
			temp = 0;
		}
			//     (1			0			 0)
		else if ((left[i] && !right[i]) && !temp)
		{
			arr[i] = 1;
		}
		else if ((!left[i] && right[i]))
		{
			arr[i] = 1;
			temp = 1;
		}
		else if ((left[i] && right[i]) && temp) 
		{
			arr[i] = 1;
			temp = 1;
		}
		i--;
	}

	/*if (temp && i < 31)
	{
		arr[i - 1] = temp;
	}*/
	return arr;

}
std::ostream& operator<<(std::ostream& os, Binary32& obj)
{
	obj.print();
	cout << endl;
	return os;
}


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




