#include <iostream>
#include <string>

using namespace std;

int isDNA(string sequence)
{
	//===================== Store String in Char Array ==================
	char sequence_array[1][100];
	strcpy_s(sequence_array[0], sequence.c_str());
	//================== Check for Input Error(s) =======================
	for (int x = 0; x < sequence.length(); x++)//Linear search
	{
		if (int(sequence_array[0][x]) != 65 && int(sequence_array[0][x]) != 97
			&& int(sequence_array[0][x]) != 84 && int(sequence_array[0][x]) != 116
			&& int(sequence_array[0][x]) != 67 && int(sequence_array[0][x]) != 99
			&& int(sequence_array[0][x]) != 71 && int(sequence_array[0][x]) != 103)// if NOT a,t,c,g,A,T,C,G
		{
			cout << "Please input correct DNA letter(a,t,c,g,A,T,C,G): " << "'" <<
				sequence_array[0][x] << "'" << " is NOT valid." << endl;
			return 0;
		}
	}
}
void findSubstrings(string sequence)
{
//===================== Store String in Char Array ==================
	char sequence_array[1][100];
	strcpy_s(sequence_array[0], sequence.c_str());

	cout << "All possible substrings: " << endl;
	cout << "==========================================" << endl;
//=============== Output Single A's ============
	int index[20];
	int counter = 0;
	for (int x = 0, y= 0; x < sequence.length(); x++)//starting at State 0; ending at Final State; cout all A's
	{
		if (int(sequence_array[0][x]) == 65 || int(sequence_array[0][x]) == 97)
		{
			cout << sequence_array[0][x] << endl;
			index[y] = x;//index all A's
			y++;
			counter++;
		}
	}
	if (index[0] < 0)
	{
		cout << "This DNA sequence does NOT have the required substring" << endl;
	}
//============= Output A(A+T+G+C)*A ===============
	for (int i = 1, s = 0; s < counter - 1; i++, s++)//Starting State(s = 0); State 1(i = 1); Final State(counter - 1); 
	{
		for (int j = i; j < counter; j++)//middle loop for (A+T+G+c)* (i = j)(j = i)
		{
			for (int x = index[s]; x <= index[j]; x++)//index = current State; Starting State(s); cout Starting State to State[j]
			{
				cout << sequence_array[0][x];//cout Array
			}
			cout << endl;
		}
	}
	cout << "==========================================" << endl;
}
int main()
{
	string sequence;
	cout << "Please input DNA sequence {a,t,c,g} or {A,T,C,G}: " << endl;
	cin >> sequence;
	cout << endl;

	char sequence_array[1][100];
	strcpy_s(sequence_array[0], sequence.c_str());

	isDNA(sequence);
	if (isDNA(sequence) != 0)
	{
		findSubstrings(sequence);
	}
	
	return 0;
	system("pause");
}
