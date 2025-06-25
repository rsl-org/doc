#include <rsl/doc>

namespace foo {
    inline int c(){ return 3; }
    
    namespace bar {
        extern char c;
    }

    namespace bar {
        struct Foo{};
    }

    template<typename T>
    struct Foo{};

    template<typename T>
    void baz(){}
}

ENABLE_DOCS(foo)
