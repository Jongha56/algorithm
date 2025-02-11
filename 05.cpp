// 스킬트리
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> skillmap;
    for (int i = 0; i < skill.length(); ++i)
        skillmap[skill[i]] = i + 1;
    
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        int count = 1;
        bool check = true;
        for (int j = 0; j < skill_trees[i].length(); ++j)
        {
            char currSkill = skill_trees[i][j];
            int currSkillNum = skillmap[currSkill];
            if (count < currSkillNum)
            {
                check = false;
                break;
            }
            else if (count == currSkillNum)
                count++;
        }
        if (check)
            answer++;
    }
    
    return answer;
}
