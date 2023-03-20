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
    void print() // TO BE COMPLETED
    {
    }
};

unordered_map<string, class word_info> hash_table; // TO BE REPLACED

int is_stop_word(string word) // TO BE COMPLETED
{
}
string transform(string word) // TO BE COMPLETED
{
}
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
        if (!is_stop_word(temp))
        {
            temp = transform(temp);
            hash_table[temp].countpp();
            hash_table[temp].addresspp(file, id);
        }
    }
}
void getFiles(string path, vector<string> &files)
{
    long hFile = 0;
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
    string prompt_info = "Press 1 to inquiry, 2 to exit :";
    cout << prompt_info;
    int choice;
    cin >> choice;
    string q_word;
    while (choice == 1)
    {
        cin >> q_word;
        q_word = transform(q_word);
        if (!(hash_table.find(q_word) == hash_table.end()))
        {
            hash_table[q_word].print();
        }
    }
    return 0;
}
