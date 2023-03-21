#include "stemmer/porter2_stemmer.h"
#include <cstring>
#include <fstream>
#include <io.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class word_info
{

    int count;
    vector<pair<string, int>> address; // TO BE REPLACED

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

unordered_map<string, class word_info> hash_table; // TO BE REPLACED
string stop_word[] = {"he", "they", "o"};

string stemming(string word)
{
    Porter2Stemmer::trim(word);
    Porter2Stemmer::stem(word);
    return word;
}
/*
需求：
1. 去掉末尾的标点符号
2. 大小写转换
3. 词形变换
返回变化后的单词
*/
string transform(string word) // TO BE COMPLETED
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

/*需求：判断是否为stop word，是则返回1，不是返回0*/
int is_stop_word(string word) // TO BE COMPLETED
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

/*统计分析文件中的所有单词*/
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

/*读取文件夹下的所有文件的文件路径及文件名*/
void getFiles(string path, vector<string> &files)
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
    string basedir = "text_source";
    vector<string> files;
    getFiles(basedir, files);
    int filenum = files.size();
    for (int i = 0; i < filenum; i++)
    {
        analysis(files[i]);
    }
    string prompt_info = "Press 1 to inquire, 2 to exit :";
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
