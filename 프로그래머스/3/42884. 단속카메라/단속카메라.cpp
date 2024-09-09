#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    /*
    겹치는 부분만 저장
    다음이랑 또 겹치면 더 짧게 저장하고, 겹치는 부분이 없으면 새로 저장
    마지막 까지 보고, 카메라 배열의 크기 출력
    */
    for(auto route : routes){
        if(route[0] > route[1]){
            int temp = route[0];
            route[0] = route[1];
            route[1] = temp;
        }
    }
    sort(routes.begin(), routes.end());
    vector<pair<int, int>> cams;
    cams.push_back(make_pair(routes[0][0], routes[0][1]));
    for(auto route : routes){
        bool flag = true;
        int route_s = route[0];
        int route_d = route[1];
        for(int i = 0; i < cams.size(); i++){
            int cam_s = cams[i].first;
            int cam_d = cams[i].second;
            if(route_s >= cam_s && route_s <= cam_d){
                cams[i].first = max(cam_s, route_s);
                cams[i].second = min(cam_d, route_d);
                flag = false;
                continue;
            }
        }
        if(flag){
            cams.push_back(make_pair(route_s, route_d));
        }
    }
    answer = cams.size();
    return answer;
}