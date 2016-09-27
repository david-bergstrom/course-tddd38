#include<variant>

// This example won't compile as no compiler currently support std::variant :(

struct State {
    struct Alive {

    };

    struct Dead {

    };

    std::variant<Alive, Dead> state;
};
