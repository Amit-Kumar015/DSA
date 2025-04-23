#include <iostream>
#include <string>
#include <cmath>
#include <memory>
using namespace std;

struct Position {
    int x, y;
    Position(string pos) {
        x = pos[0] - 'a';      
        y = pos[1] - '1';     
    }
};

class Piece {
public:
    virtual bool isValidMove(Position from, Position to) = 0;
    virtual ~Piece() {}
};

struct Move {
    string name;
    string from;
    string to;

    void display() const {
        cout << "Last move: " << name << " from " << from << " to " << to << endl;
    }
};

class Pawn : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        return (from.x == to.x && (to.y - from.y == 1));
    }
};

class Knight : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        int dx = abs(to.x - from.x);
        int dy = abs(to.y - from.y);
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
};

class Bishop : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        return abs(to.x - from.x) == abs(to.y - from.y);
    }
};

class Rook : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        return (from.x == to.x || from.y == to.y);
    }
};

class Queen : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        return (from.x == to.x || from.y == to.y || 
        abs(to.x - from.x) == abs(to.y - from.y));
    }
};

class King : public Piece {
public:
    bool isValidMove(Position from, Position to) override {
        return abs(to.x - from.x) <= 1 && abs(to.y - from.y) <= 1;
    }
};

unique_ptr<Piece> createPiece(const string& name) {
    if (name == "Pawn") return make_unique<Pawn>();
    if (name == "Knight") return make_unique<Knight>();
    if (name == "Bishop") return make_unique<Bishop>();
    if (name == "Rook") return make_unique<Rook>();
    if (name == "Queen") return make_unique<Queen>();
    if (name == "King") return make_unique<King>();
    return nullptr;
}

int main() {
    string name, fromStr, toStr;
    Move lastMove;
    bool hasLastMove = false;
    cout << "Enter move: ";
    cin >> name >> fromStr >> toStr;

    auto piece = createPiece(name);
    if (!piece) {
        cout << "Invalid piece name.\n";
        return 1;
    }

    Position from(fromStr), to(toStr);
    if (piece->isValidMove(from, to)) {
        cout << "Valid move\n";
        lastMove = {name, fromStr, toStr};
        hasLastMove = true;
    } else {
        cout << "Invalid move\n";
    }

    if (hasLastMove){
        lastMove.display();
    }
    else{
        cout << "No move has been made yet.\n";
    }
    return 0;
}
