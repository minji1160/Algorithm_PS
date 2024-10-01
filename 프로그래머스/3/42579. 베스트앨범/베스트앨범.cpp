#include <string>
#include <vector>
//#include <unordered_map>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
/*
1. 장르별 합산 및 정렬
2. 장르 내 횟수 정렬
*/

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

bool cmp2(const pair<int, int>& left, const pair<int, int>& right)
	{
		if (left.first == right.first) {
			return left.second < right.second;
		}
		else {
			return left.first > right.first;
		}
	}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string ,int> genres_cnt;
    map<string, vector<pair<int, int>>> music;
    for(int i = 0; i < genres.size(); i++){
        genres_cnt[genres[i]] += plays[i];
        music[genres[i]].push_back(make_pair(plays[i], i));
    }
    vector<pair<string, int>> genres_sort(genres_cnt.begin(), genres_cnt.end());
    sort(genres_sort.begin(), genres_sort.end(), cmp);
    for(auto genre : genres_sort){
        vector<pair<int, int>> music_sort(music[genre.first].begin(), music[genre.first].end());
    sort(music_sort.begin(), music_sort.end(), cmp2);
        if(music_sort.size() == 1){
            answer.push_back(music_sort[0].second);
        }
        else{
            int cnt = 0;
             for(auto mu : music_sort){
                answer.push_back(mu.second);
                cnt++;
                if(cnt == 2) break;
            }
        }
    }
    return answer;
}