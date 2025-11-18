# Copilot Instructions for leeetCodeByCpp

This is a LeetCode problem-solving repository using C++17. Each problem is implemented as a standalone solution with a `Solution` class.

## Architecture & Project Structure

- **`1_500/1_50/`**: Contains problems 1-50 from LeetCode (numbered files: `1_twoSum.cpp`, `2_addTwoNumbers.cpp`, etc.)
- **`Structure/`**: Shared data structures (e.g., `ListNode_1.h` for linked list problems)
- **`bin/`**: Compiled executable binaries and debug symbols
- **`.vscode/`**: Build, debug, and language server configuration

## Code Patterns & Conventions

### Solution Structure
Every problem follows this template:
```cpp
#include <necessary_headers>
using namespace std;

class Solution {
public:
    // Problem-specific method(s)
    // Example: vector<int> twoSum(vector<int>& nums, int target)
};

// Optional: main() function for local testing with hardcoded examples
int main() {
    // Test case implementation
    return 0;
}
```

### Key Patterns Observed
- **Header includes**: Common includes are `<vector>`, `<unordered_map>`, `<unordered_set>`, `<algorithm>`, `<iostream>`
- **Pass by reference**: Use `vector<int>&` for input parameters to avoid copying
- **Shared headers**: Include `ListNode_1.h` for linked list problems: `#include <ListNode_1.h>`
- **STL containers**: Heavy use of `unordered_map`, `unordered_set`, `vector`, and `stack`/`queue`

### Algorithm Techniques
- **Two-pointer technique**: See `15_threeSum.cpp` (sorted array, converging pointers)
- **Sliding window**: See `3_lengthOfLongestSubstring.cpp` (maintain window boundaries)
- **Hash maps**: See `1_twoSum.cpp` (store value→index for O(1) lookups)

## Build & Execution Workflow

### Build Tasks (VS Code)
Use **Ctrl+Shift+B** or run tasks via command palette:
- **"build current cpp file"**: Compile only (output to `bin/`)
- **"build and run current cpp file"** (default): Compile + execute

### Manual Build (Terminal)
```bash
clang++ -std=c++17 -g "${file}" -o "${workspaceFolder}/bin/${fileBasenameNoExtension}" -I "${workspaceFolder}/Structure"
```

### Debug
Press **F5** to start debugging (uses LLDB on macOS):
- Preconfigured launch targets in `.vscode/launch.json`
- Compiles with `-g` flag for debug symbols

## Development Conventions

- **C++ Standard**: Always compile with `-std=c++17`
- **Include paths**: Use `-I ${workspaceFolder}/Structure` for custom headers
- **Comments**: Include LeetCode problem statement and constraints in Chinese at file top
- **Return types**: Match LeetCode's exact signatures (e.g., `vector<vector<int>>`, `ListNode*`)
- **Compiler**: Use `clang++` (configured in tasks.json)

## Testing Approach

- Implement `main()` function within each `.cpp` file for local testing
- Use hardcoded test cases matching LeetCode examples
- Print results to verify correctness before submission

## File Header Format
```cpp
/* Problem_Number. Problem Title

Problem description in Chinese

*/
```

See `16_threeSumClosest.cpp` for example.
