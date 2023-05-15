#include <iostream>
#include <vector>
#include <random>
#include <stack>
#include <tuple>

// Constants for maze dimensions
const int WIDTH = 10;
const int HEIGHT = 10;

// Cell states
enum class CellState {
    WALL,
    PATH
};

// Maze class
class Maze {
public:
    Maze(int width, int height) : width_(width), height_(height) {
        // Initialize maze grid with walls
        grid_.resize(width * height, CellState::WALL);
    }

    void generate() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(0, 3);

        // Start at the top-left corner
        int startX = 0;
        int startY = 0;

        std::stack<std::pair<int, int>> stack;
        stack.push(std::make_pair(startX, startY));

        while (!stack.empty()) {
            int x, y;
            std::tie(x, y) = stack.top();
            stack.pop();

            // Mark current cell as path
            grid_[y * width_ + x] = CellState::PATH;

            // Get random neighboring cells
            std::vector<int> neighbors = getNeighbors(x, y);

            while (!neighbors.empty()) {
                int randomIndex = dist(rng) % neighbors.size();
                int nx = x + dx[neighbors[randomIndex]];
                int ny = y + dy[neighbors[randomIndex]];

                if (isValid(nx, ny)) {
                    if (grid_[ny * width_ + nx] == CellState::WALL) {
                        // Remove wall between current cell and chosen neighbor
                        grid_[(y + ny) / 2 * width_ + (x + nx) / 2] = CellState::PATH;
                        stack.push(std::make_pair(nx, ny));
                    }
                }

                neighbors.erase(neighbors.begin() + randomIndex);
            }
        }
    }

    void print() const {
        for (int y = 0; y < height_; ++y) {
            for (int x = 0; x < width_; ++x) {
                std::cout << (grid_[y * width_ + x] == CellState::WALL ? "#" : " ");
            }
            std::cout << std::endl;
        }
    }

private:
    int width_;
    int height_;
    std::vector<CellState> grid_;

    // Offsets for getting neighboring cells
    const int dx[4] = {0, 0, -1, 1};
    const int dy[4] = {-1, 1, 0, 0};

    std::vector<int> getNeighbors(int x, int y) const {
        std::vector<int> neighbors;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && grid_[ny * width_ + nx] == CellState::WALL) {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }

    bool isValid(int x, int y) const {
        return x >= 0 && x < width_ && y >= 0 && y < height_;
    }
};

int main() {
    Maze maze(WIDTH, HEIGHT);
    maze.generate();
    maze.print();

    return 0;
}

