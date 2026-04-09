class Robot {
public:
    int w, h;
    int currX, currY;
    int facing; // 0=N,1=E,2=S,3=W

    Robot(int width, int height) {
        w = width;
        h = height;
        currX = 0;
        currY = 0;
        facing = 1; // East
    }
    
    void step(int num) {
        if (w == 1 || h == 1) return; // edge case

        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;
        if (num == 0) {
            if (currY == 0 && currX == 0) {
                facing = 0;
                
            } return;
        }

        while (num > 0) {
            if (facing == 1) { // East
                int move = min(num, w - 1 - currX);
                currX += move;
                num -= move;
                if (num > 0) facing = 2; // turn North
            }
            else if (facing == 2) { // North
                int move = min(num, h - 1 - currY);
                currY += move;
                num -= move;
                if (num > 0) facing = 3; // turn West
            }
            else if (facing == 3) { // West
                int move = min(num, currX);
                currX -= move;
                num -= move;
                if (num > 0) facing = 0; // turn South
            }
            else { // South
                int move = min(num, currY);
                currY -= move;
                num -= move;
                if (num > 0) facing = 1; // turn East
            }
        }
    }
    
    vector<int> getPos() {
        return {currX, currY};
    }
    
    string getDir() {
        if (facing == 0) return "South";
        if (facing == 1) return "East";
        if (facing == 2) return "North";
        return "West";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */