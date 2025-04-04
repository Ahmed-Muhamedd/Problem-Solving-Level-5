#pragma once
#include <string>
#include<iostream>
#include <vector>
using namespace std;


class clsString
{
private:

	string _Value;

public:

	clsString() {
		_Value = "";
	}

	clsString(string Value) {
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;


	static short CountWords(string S1) {
		string Del = " ";
		short Pos = 0;
		short Counter = 0;
		string Word;

		while ((Pos = S1.find(Del)) != std::string::npos) {
			Word = S1.substr(0, Pos);

			if (Word != " ")
				Counter++;

			S1.erase(0, Pos + Del.length());
		}

		if (S1 != " ")
			Counter++;


		return Counter;
	}

	short CountWords() {
		return CountWords(_Value);
	}

	static void PrintFirstLetter(string S1) {
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++) {
			//Ahmmed 
			if (S1[i] != ' ' && IsFirstLetter)
				cout << S1[i] << " ";

			IsFirstLetter = S1[i] == ' ' ? true : false;
		}
	}

	void PrintFirstLetter() {
		 PrintFirstLetter(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1) {
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++) {
			
			if (S1[i] != ' ' && IsFirstLetter)
				 S1[i] = toupper(S1[i]);

			IsFirstLetter = S1[i] == ' ' ? true : false;
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord() {
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1) {
		bool IsFirstLetter = true;
		for (short i = 0; i < S1.length(); i++) {
			//Ahmmed 
			if (S1[i] != ' ' && IsFirstLetter)
				S1[i] = tolower(S1[i]);

			IsFirstLetter = S1[i] == ' ' ? true : false;
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord() {
	_Value =  	LowerFirstLetterOfEachWord(_Value);
	}


	static string UpperAllLetters(string S1) {
		for (short i = 0; i < S1.length(); i++)
			S1[i] = toupper(S1[i]);
	return S1;
	}

	void UpperAllLetters() {
		_Value =  UpperAllLetters(_Value);
	}


	static string LowerAllLetters(string S1) {
		for (short i = 0; i < S1.length(); i++)
			S1[i] = tolower(S1[i]);
		return S1;
	}

	void LowerAllLetters() {
		_Value = LowerAllLetters(_Value);
	}

	static char InvertCharacterCase(char Ch) {
		return isupper(Ch) ? tolower(Ch) : toupper(Ch);
	}

	static string InvertLetters(string S1) {
		for (short i = 0; i < S1.length(); i++) {
			S1[i] = InvertCharacterCase(S1[i]);
		}
		return S1;
	}

	void InvertLetters() {
		_Value = InvertLetters(_Value);
	}

	static short StringLength(string S1) {
		return S1.length();
	}

	short StringLength() {
		return _Value.length();
	}

	static short CountCapitalLetters(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++) {
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static short CounteSmallLetters(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++) {
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CounteSmallLetters() {
		return CounteSmallLetters(_Value);
	}

	static short CountCharacterInString(string S1, char Ch) {
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {
			if (S1[i] == Ch)
				Counter++;
		}
		return Counter;
	}

	short CountCharacterInString(char Ch) {
		return CountCharacterInString(_Value , Ch);
	}


	static short CountCharacterInStringCase(string S1, char Ch , bool MatchCase = true) {
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {
			if (MatchCase) {
			if (S1[i] == Ch)
				Counter++;
			}
			else {
				if(tolower(S1[i]) == tolower(Ch))
					Counter++;
			}

		}
		return Counter;
	}

	short CountCharacterInStringCase(char Ch , bool MatchCase) {
		return CountCharacterInStringCase(_Value, Ch , MatchCase);
	}

	static bool IsVowel(char Ch) {
		char CH = tolower(Ch);
		return CH == 'a' || CH == 'e' || CH == 'o' || CH == 'u' || CH == 'i';
	}

	static short CountVowel(string S1) {
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountVowel() {
		return CountVowel(_Value);
	}

	static void PrintVowelsInString(string S1) {
		for (short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				cout << S1[i] <<  " ";
		}
	}

	void PrintVowelsInString() {
		PrintVowelsInString(_Value);
	}

	static void PrintEachWord(string S1) {
		string Del = " ";
		short Pos = 0;
		short Counter = 0;
		string Word;

		while ((Pos = S1.find(Del)) != std::string::npos) {
			Word = S1.substr(0, Pos);

			if (Word != " ")
				cout << Word << endl;

			S1.erase(0, Pos + Del.length());
		}

		if (S1 != " ")
			cout << S1;
	}

	void PrintEachWord() {
		PrintEachWord(_Value);
	}

	static vector<string> Split(string S1, string Del = " ") {
		vector <string> vString;
		short Pos = 0;
		string Word;

		while ((Pos = S1.find(Del)) != std::string::npos) {
			Word = S1.substr(0, Pos);

			if (Word != "")
				vString.push_back(Word);

			S1.erase(0, Pos + Del.length());
		}

		if (S1 != "")
			vString.push_back(S1);

	return vString;
	}

	vector<string> Split() {
		return Split(_Value );
	}

	static string TrimLeft(string S1) {
		for (short i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ')
				return S1.substr(i, S1.length() - i );
		}
		return "";
	}

	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1) {

		for (short i = S1.length() - 1; i >= 0; i--) {

			if (S1[i] != ' ')
				return S1.substr(0, i + 1);

		}
		return "";

	}

	void TrimRight() {
		_Value =  TrimRight(_Value);
	}

	static string Trim(string S1) {
		return TrimLeft(TrimRight(S1));
	}

	void Trim() {
		_Value = Trim(_Value);
	}

	static string Join(vector<string>& vString, string Del = " ") {
		string Word = "";

		for (string& S : vString) {
			Word += S + Del;
		}
		return Word.substr(0, Word.length() - Del.length());
	}

	static string Join(string Arr[], short Length ,string Del = " ") {
		string Word = "";

		for (short i = 0; i < Length; i++) {
			Word += Arr[i] + Del;
		}
		return Word.substr(0, Word.length() - Del.length());
	}

	static string ReverseString(string S1) {
		vector<string> vString = Split(S1);
		string sString = "";
		vector<string>::iterator itr = vString.end();

		while (itr != vString.begin()) {
			itr--;

			sString += *itr + " ";

		}
		return sString.substr(0, sString.length() - 1);

	}

	void ReverseString() {
		_Value = ReverseString(_Value);
	}

	static string ReplaceWordInStringWithReplace(string S1, string Replace, string ReplaceT0) {
		short Pos = S1.find(Replace);

		while (Pos != std::string::npos) {
			S1 = S1.replace(Pos, Replace.length(), ReplaceT0);
			Pos = S1.find(Replace);
		}
		return S1;
	}
	
	void ReplaceWordInStringWithReplace(string Replace, string RepalceTo) {
		_Value = ReplaceWordInStringWithReplace(_Value, Replace, RepalceTo);
	}

	static string ReplaceWordInStringWithCustom(string S1, string Replace, string ReplaceTo, bool MatchCase = true) {
		vector<string> vString = Split(S1 );

		for (string& S : vString) {
			if (MatchCase) {
				if (S == Replace)
					S = ReplaceTo;
			}
			else {
				if(LowerAllLetters(S) == LowerAllLetters(Replace))
					S = ReplaceTo;
			}
		}
		return Join(vString);
	}

	void ReplaceWordInStringWithCustom(string Replace, string RepalceTo , bool MatchCase = true) {
		_Value = ReplaceWordInStringWithCustom(_Value, Replace, RepalceTo , MatchCase);
	}

	static string RemoveAllPanctuations(string S1) {
		string Word = "";
		for (short i = 0; i < S1.length(); i++) {
			if (!ispunct(S1[i]))
				Word += S1[i];
		}
		return Word;
	}

	void RemoveAllPanctuations() {
		_Value = RemoveAllPanctuations(_Value);
	}
};

