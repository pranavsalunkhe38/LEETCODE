// LC: 2069 Walking Robot Simulation Ii
// Title: Walking Robot Simulation Ii
// Difficulty: Medium
// Date: 07 April 2026

#include <bits/stdc++.h>
using namespace std;

class Robot {
    int width, height;
    int total;
    int x,y;
    int dir;
    int steps;
    int east,west,north,south;
    vector<string> news = {"North","East","South","West"};
    
    public:
    Robot(int width, int height): width(width),height(height),x(0),y(0),dir(1),steps(0){
     total = 2*(height-1) + 2*(width-1) ;  
     east = width-1;
     north = height - 1;
     west = width-1;
     south = height-1;
    }
    
    void step(int num) {
        steps += num;
        steps = steps % total;
        if(steps == 0) steps = total;


        if(steps <= east){
            dir = 1;
            x = steps;
            y = 0;
        }else if(steps <= east+north){
            x = width - 1;
            y = steps - east;
            dir = 0;
        }else if(steps <= (east+north+west)){
            dir = 3;
            y = north;
            x = west - (steps - (east+north));
        }else{
            dir = 2;
            x = 0;
            y = south - (steps - (east+west+north));
        }

    }
    
    vector<int> getPos() {

        return{x,y};
        
    }
    
    string getDir() {

        return news[dir];        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */




 /*
 class Robot {
private:
    bool moved = false;
    int idx = 0;
    vector<pair<int, int>> pos;
    vector<int> dir;
    unordered_map<int, string> to_dir = {
        {0, "East"}, {1, "North"}, {2, "West"}, {3, "South"}};

public:
    Robot(int width, int height) {
        for (int i = 0; i < width; ++i) {
            pos.emplace_back(i, 0);
            dir.emplace_back(0);
        }
        for (int i = 1; i < height; ++i) {
            pos.emplace_back(width - 1, i);
            dir.emplace_back(1);
        }
        for (int i = width - 2; i >= 0; --i) {
            pos.emplace_back(i, height - 1);
            dir.emplace_back(2);
        }
        for (int i = height - 2; i > 0; --i) {
            pos.emplace_back(0, i);
            dir.emplace_back(3);
        }
        dir[0] = 3;
    }

    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }

    vector<int> getPos() { return {pos[idx].first, pos[idx].second}; }

    string getDir() {
        if (!moved) {
            return "East";
        }
        return to_dir[dir[idx]];
    }
};
 */