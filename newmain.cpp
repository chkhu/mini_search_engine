#include "porter2_stemmer.h"
#include <cstring>
#include <fstream>
#include <io.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
/*
 * TO BE REPLACED
 */

class word_info
{

    int count;
    vector<pair<string, int>> address; // 

public:
    void countpp()
    {
        count++;
    }
    void addresspp(string addr, int id)
    {
        address.emplace_back(make_pair(addr, id));
    }
    void print()
    {
        cout << "The total number is " << count << "." << endl;
        cout << "Show more details?(y/n)";
        string y_n;
        cin >> y_n;
        if (y_n == "y")
        {
            cout << "FILE ADDRESS\t\t\tID IN FILE" << endl;
            for (auto it : address)
            {
                cout << it.first << "\t" << it.second << endl;
            }
        }
    }
};

// store the word
unordered_map<string, class word_info> hash_table;
// store the stop_word
vector<string>stop_word;

/*
 * Usage: stem the word 
 */

string stemming(string word)
{
    Porter2Stemmer::trim(word);
    Porter2Stemmer::stem(word);
    return word;
}
/*
 * Function: transform()
 * Usage: select the word from special characters and numbers.
 *        change all words into lowercase words.
 */
string transform(string word) 
{
    string temp = word;
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = tolower(temp[i]);
    }
    while ((temp[temp.length() - 1] > 'z' || temp[temp.length() - 1] < 'a') && (temp.length() > 1) && (temp[temp.length() - 1] > '9' || temp[temp.length() - 1] < '0'))
    {
        temp.erase(temp.size() - 1, 1);
    }
    temp = stemming(temp);
    return temp;
}

/*
 * Function: add_stop_word()
 * Usage: add the stop word into the stop word list.
 */
void add_stop_word()
{

    ifstream f;
    f.open("word.txt", ios::in);

    int stop_f;
    string word;

    while (!f.eof()) {
        f >> word;
        stop_word.push_back(word);
    }

    f.close();
}

/*
 * Function: is_stop_word()
 * Usage: judge whether the word is a stop word.
 */
int is_stop_word(string word) 
{
    int yes = 0;
    for (auto i : stop_word)
    {
        if (word == i) 
        {
            yes = 1;
            break;
        }
    }
    return yes;
}

/*
 * Function: analysis()
 * Usage: analysis every word from the file and add it into the hash_table
 */
void analysis(string file)
{
    ifstream infile;
    infile.open(file, ios::in);
    if (!infile.is_open())
    {
        return;
    }
    string temp;
    int id = 0;
    while (infile >> temp)
    {
        id++;
        temp = transform(temp);
        if (!is_stop_word(temp))
        {
            hash_table[temp].countpp();
            hash_table[temp].addresspp(file, id);
        }
    }
    infile.close();
}

/*
 * Function: getFiles()
 * Usage: read all sub files under the parent file.
 */
void getFiles(string path, vector<string>& files)
{
    long long hFile = 0;
    struct _finddata_t fileinfo;
    string pathp;
    if ((hFile = _findfirst(pathp.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {
                    getFiles(pathp.assign(path).append("//").append(fileinfo.name), files);
                }
            }
            else
            {
                string filestr = fileinfo.name;
                files.push_back(pathp.assign(path).append("//").append(filestr));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

int main()
{
    cout << "Please wait for the program to run." << endl;

    add_stop_word();                                                

    string basedir = "text_source";
    vector<string> files;

    getFiles(basedir, files);
    int filenum = files.size();

    for (int i = 0; i < filenum; i++)
    {
        analysis(files[i]);
    }

    string prompt_info = "Press 1 to inquire, 2 to exit :";     // select the choice
    cout << prompt_info;

    int choice;
    cin >> choice;

    string q_word;

    while (choice == 1)
    {
        cout << "Enter the word please :";
        cin >> q_word;
        q_word = transform(q_word);
        if (!(hash_table.find(q_word) == hash_table.end()))
        {
            hash_table[q_word].print();
        }
        else if (is_stop_word(q_word))
        {
            cout << "The word is a stop word." << endl;
        }
        else
        {
            cout << "The inquiry result is empty." << endl;
        }
        cout << prompt_info;
        cin >> choice;
    }
    return 0;
}
