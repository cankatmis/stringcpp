#include <iostream>

void Reverse(char string[]) {
	int i, j;
	char temp;
	for (j = 0; string[j] != '\0'; j++)
	{
	}
	j -= 1;
	for (i = 0; i < j; i++, j--)
	{
		//swap
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
	printf("%s\n", string);
}

void Palindrome(char string[]) {
	int i, j;
	for (j = 0; string[j] != '\0'; j++)
	{
		if (string[j] >= 'A' && string[j] <= 'Z')
		{
			string[j] += 32;
		}
	}
	j -= 1;
	for (i = 0; i < j; i++, j--)
	{
		if (string[i] != string[j]) {
			printf("Not a palindrome!\n");
			break;
		}
		else
		{
			printf("The word is palindrome!\n");
			break;
		}
	}
}

void Duplicate(char string[]) {
	int hashtable[26] = { 0 }; //Alphabet length of English language
	for (int i = 0; string[i] != '\0'; i++)
	{
		hashtable[string[i] - 97]++;
	}
	for (int j = 0; j < 26; j++)
	{
		if (hashtable[j] > 1)
		{
			printf("Duplicated element is %c.\n", j + 97);
			printf("Duplicate count is %d.\n", hashtable[j]);
		}
	}
}

//using bitwise operation and masking
void DuplicateBit(char string[]) {
	int h = 0, x = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		x = 1;
		x = x << (string[i] - 97);
		if ((h & x) > 0)
		{
			printf("%c is duplicate.\n", string[i]);
		}
		else
		{
			h = h | x;
		}
	}
}

void Anagram(char A[], char B[]) {
	char H[26] = { 0 };
	int i, j;
	for (i = 0; i < A[i] != '\0'; i++)
	{
		H[A[i] - 97]++;
	}
	for (j = 0; j < B[j] != '\0'; j++)
	{
		H[B[j] - 97]++;
	}
	if (i != j)
	{
		printf("Not an anagram due to the length.\n");
	}
	else {
		for (int z = 0; z < 26; z++)
		{
			if (H[z] == 0 || H[z] == 2)
			{
				printf("The words are anagram.\n");
				break;
			}
			else
			{
				printf("The words are NOT an anagram.\n");
				break;
			}
		}
	}
}

void Permutation(char S[], int k) {
	static int A[10] = { 0 };
	static char Res[10];
	int i;

	if (S[k] == '\0')
	{
		Res[k] = '\0';
		printf("%s ", Res);
	}
	else
	{
		for (i = 0; S[i] != '\0'; i++)
		{
			if (A[i] == 0)
			{
				Res[k] = S[i];
				A[i] = 1;
				Permutation(S, k + 1);
				A[i] = 0;
			}
		}
	}
}

int main()
{
	char ex[] = "abracadabra";
	Reverse(ex);

	char ex1[] = "Madam Im Adam";
	Palindrome(ex1);

	char ex2[] = "Macska";
	Duplicate(ex2);
	DuplicateBit(ex2);

	char anag[] = "verboser";
	char anag1[] = "observer";
	Anagram(anag, anag1);

	char perm[] = "ABC";
	Permutation(perm, 0);
}
