#include<iostream>
#include<cstdlib>

using namespace std;

#define PORTION 3 //defines portion of grid to be 1/3
#define SIZE 100 //no grid larger than 100x100

class Grid{
    private:
        int array[SIZE][SIZE]; //2D array, default size
        int col;//column size
        int row;//row size
        int compare(int a, int b);
        /* used in AND to create bitwise & functionality */
        
    public:
        Grid(int incol, int inrow);
        /*Create 2D array to size X (col) by Y (row), initiate appropriate values 
        to 0 */
        int getCol();
        /* returns col size */
        int getRow();
        /* returns row size */
        int getVal(int incol, int inrow);
        /* returns value of a specific index */
        void print();
        /* interate over row and col to print grid in understandable order */
        void random();
        /* fill grid with 1/portion of 1 values in random locations */
        
        void AND(Grid a, Grid b);
        /* checks a and b are same dimensions. Compares every index using by and, 
        sets grid to result*/
};
Grid::Grid(int incol, int inrow){
    /*Create 2D array to size X (col) by Y (row), initiate appropriate values to 0 
    */
    col = incol;
    row = inrow;
    for (int i = 0; i<row ; i++) {      //iterate over row
        for (int j = 0; j<col; j++) {   //iterate over column
            array[i][j] = 0;
        }
    }
}
int Grid::getCol(){
    /* returns col size */
    return col;
}
int Grid::getRow(){
    /* returns row size */
    return row;
}
int Grid::getVal(int incol, int inrow){
    /* returns value of a specific index */
    return array[inrow][incol];
}
void Grid::print(){
    /* interate over row and col to print grid in understandable order */
    for (int y = 0; y<row ; y++) {
        for (int x = 0; x<col; x++) {
            cout << array[y][x] << " ";//access every value, print space
        }
        cout << endl; //print new line for new row
    }
    
}
void Grid::random(){
    /* fill grid with 1/portion of 1 values in random locations */
    int fill = (col*row)/PORTION;           //determine amount of 1s to place
    /*
    if (TEST){
        cout << "third of " << (col*row) << " is " << fill << endl;
    }
    */
    int index = 0;
    while (index<fill) {
        int rcol = rand() % col;            //random number for col index
        int rrow = rand() % row;
        if (1!=array[rrow][rcol]) {
            array[rrow][rcol] = 1;          //change value to 1
            index++;                        //one more filled, continue loop
        }                                   //if location already changed, do not 
        //iterate, try again.
    }
    
}
int Grid::compare(int a, int b){
    if ((1==a)&&(1==b)) {
        return 1;
    }else
        return 0;
}
void Grid::AND(Grid a, Grid b){
    /* checks a and b are same dimensions. Compares every index using by and, sets 
grid to result*/
    if ((a.getCol()!=b.getCol())||(a.getRow()!=b.getRow())){
        cout << "These grids are not the same dimensions, and cannot be compared";
        return;
    }else{
        col = a.getCol();           //this is redundant
        row = a.getRow();           //already assuming grid C created to the same 
//dimensions ***** TODO *******
        for (int y = 0; y<row ; y++) {
            for (int x = 0; x<col; x++) {
                array[y][x] = compare(a.getVal(x, y),b.getVal(x, y));
            }
        }
    }
    
}
class WaterVehicle{ //maybe will need :public grid?
    protected:
        int lenShip;
        int start; //probably needs to be array according to errors
        string orientation; //horizontal or vertical
        bool sunk;
    public:
        WaterVehicle();
        WaterVehicle(int l, int s, string o, bool u);
        int get_lenShip();
        int get_start();
        string get_orientation();
        bool get_sunk();
        void set_lenShip(int l);
        void set_start(int s);
        void set_orientation(string o);
        void set_sunk(bool u);
        
};

WaterVehicle::WaterVehicle(int l, int s, string o, bool u): lenShip(l), start(s), orientation(o), sunk(u){}
int WaterVehicle::get_lenShip(){
    return lenShip;
}
int WaterVehicle::get_start(){
    return start;
}
string WaterVehicle::get_orientation(){
    return orientation;
}
bool WaterVehicle::get_sunk(){
    return sunk;
}
void WaterVehicle::set_lenShip(int l){
    lenShip = l;
}
void WaterVehicle::set_start(int s){
    start = s;
}
void WaterVehicle::set_orientation(string o){
    orientation = o;
}
void WaterVehicle::set_sunk(bool u){
    sunk = u;
}
class Submarine: public WaterVehicle{
    private:
        int dive_depth;
        bool surfaced;
    public:
        Submarine();
        Submarine(int l, int s, string o, bool u, int d, bool r);
        int get_dive_depth();
        bool get_surfaced();
        void set_dive_depth(int d);
        void set_surfaced(bool r);

        bool torpedoHit(int torpedoLocation){
            int location = get_start();
            int length = get_lenShip();
            if ((torpedoLocation<(start+lenShip))&& (torpedoLocation>(start-lenShip))){
                return true;
            }
        }
        
        void operator =(Submarine &sm){
            dive_depth = sm.get_dive_depth();
            surfaced = sm.get_surfaced();
            set_lenShip(sm.get_lenShip());
            set_start(sm.get_start());
            set_orientation(sm.get_orientation());
            set_sunk(sm.get_sunk());
        }

};
Submarine::Submarine(int l, int s, string o, bool u, int d, bool r): WaterVehicle(l, s, o, u){}
int Submarine::get_dive_depth(){
    return dive_depth;
}
bool Submarine::get_surfaced(){
    return surfaced;
}
void Submarine::set_dive_depth(int d){
    dive_depth = d;
}
void Submarine::set_surfaced(bool r){
    surfaced = r;
}




// ###################################CLASS DEFINITION 
//ENDS################################
int main() {
    srand(time(NULL));      //seed rand for different values each time
    
    int x=10,y=10; //creates 10x10 grid
    int depth, lenShip, start;
    string orientation;
    bool sunk = false;
    bool surface = false;

    cout << "Enter ship length in integer: ";
    cin >> lenShip;
    cout << "Enter starting location in integer: ";
    cin >> start;
    cout << "Enter orientaiton such as h for horizontal and v for vertical: ";
    cin >> orientation;
    cout << "Enter ship depth: ";
    cin >> depth;
    cout << "Enter if surfaced or not as true or false: ";
    cin >> surface;

    Submarine sm1(lenShip, start, orientation, sunk, depth, surface);
    Submarine sm2 = sm1;
    
    //15 random shots put into array and then printed between 100 spots since grid is 10x10
    int shotsFired[15];
    for(int i=0; i< 15; i++){
        int shotAt = rand()%99;
        while(shotAt >= start && shotAt <= start-lenShip){
            cout << "No hit at location "<< shotAt<<endl;
            shotAt = rand()%99;
        }
        cout << "Shots fired at location:  "<< shotAt<<endl;
        shotsFired[i] = shotAt;

    }
    //using sm2 and get should use hierarchy to get data
    cout << "Submarine 2's length is: " << sm2.get_lenShip() << endl;
    cout << "Submarine 2's starting location is: " << sm2.get_start() << endl;
    cout << "Submarine 2's orientation is: " << sm2.get_orientation() << endl;
    cout << "Submarine 2 sunk? " << sm2.get_sunk() << endl;
    cout << "Submarine 2's dive depth is: " << sm2.get_dive_depth() << endl;
    cout << "Submarine surfaced? " << sm2.get_surfaced() << endl;
    /*
    for(int i = 0; i < 15; i++){
        cout << shotsFired[i]<< " ";
    }
    */
    
    


    Grid a(x,y);//init A
    a.random(); //rand A
    cout << "Grid A" <<endl;
    a.print();
    /*
    Grid b(x,y);//init B
    b.random();//rand B
    cout << "Grid B" <<endl;
    b.print();
    
    Grid c(x,y);//init C
    c.AND(a,b); //AND c
    cout << "Grid C" <<endl;
    c.print();
    */
    //demo AND with error handling
    return 0;
}