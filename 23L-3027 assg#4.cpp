
//name : eishal fatima 
//roll.no : 23L-3027
//section: BSSE-1A

#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

//function to find imperfect palindrome

void imPerfect_Palindrome(char arr[], int length)
{
	int count = 0;
	int track = length - 1;
	for (int i = 0; i < track; i++)
	{
		if (arr[i] != arr[track])
		{
			count++;
		}
		track--;
	}
	if (count == 1)
	{
		cout << "yes, the word IS an imperfect palindrome" << endl;
	}
	else
		cout << "no, the word is NOT an imperfect palindrome" << endl;
}


// function to check if both char arrays contain the same letters, irrespective of the sequence

int checkfor_SameLetters(char arr1[], char arr2[])
{
	int length1 = strlen(arr1);
	int length2 = strlen(arr2);


	if (length1 > length2 || length1 == length2)
	{
		int count = 0;
		for (int i = 0; i < length1 + 1; i++)
		{
			for (int j = 0; j < length1 + 1; j++)
			{
				if (arr1[i] == arr2[j])
				{
					count++;  //keep track of matched letters
					break;
				}

			}
		}
		if (count == length1 + 1)  //condition if all the letters matched
		{
			return true;
		}
		else
			return false;
	}

	if (length1 < length2)
	{
		int count = 0;
		for (int i = 0; i < length2 + 1; i++)
		{
			for (int j = 0; j < length2 + 1; j++)
			{
				if (arr1[i] == arr2[j])
				{
					count++;  //keep track of matched letters
					break;
				}

			}
		}
		if (count == length2 + 1)  //condition if all the letters matched
		{
			return true;
		}
		else
			return false;
	}
}


//Function to find super anagrams

void SuperAnagrams(char arr1[], char arr2[])
{
	int length1 = strlen(arr1);
	int length2 = strlen(arr2);

	int freq_array[26] = { 0 };

	for (int i = 0; i < length1; i++)
	{
		freq_array[arr1[i] - 'a']++;
	}
	for (int j = 0; j < length2; j++)
	{
		freq_array[arr2[j] - 'a']--;
	}
	int acc_freqDIFF = 0;
	for (int k = 0; k < 26; k++)
	{
		acc_freqDIFF = acc_freqDIFF + freq_array[k];
	}

	if (acc_freqDIFF <= 2)
	{
		cout << "yes, the two words ARE each other's anagrams." << endl;
	}
	else
		cout << "no, the two words are NOT each other's anagrams." << endl;
}




int main()

{
	const int size = 21;
	char array1[size];
	char array2[size];

	ifstream input("PFfile.txt");

	while (input >> array1 >> array2)
	{

		imPerfect_Palindrome(array1, strlen(array1));
		imPerfect_Palindrome(array2, strlen(array2));

		if (strlen(array1) == strlen(array2))
		{
			cout << "the two words have equal no. of letters " << endl;

			checkfor_SameLetters(array1, array2);
			if (checkfor_SameLetters(array1, array2) == true)
			{
				cout << "yes the two words are anagrams " << endl;
			}
			else if (checkfor_SameLetters(array1, array2) == false)
				cout << "no, the two words are not each other's super anagrams." << endl;
		}
		else if (strlen(array1) != strlen(array2))
		{
			checkfor_SameLetters(array1, array2);
			if (checkfor_SameLetters(array1, array2) == true)
			{
				SuperAnagrams(array1, array2);
			}

		}
		cout << endl;
	}
	input.close();

	return 0;
}
