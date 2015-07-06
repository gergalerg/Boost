#include <iostream>

struct obj {
    int id;
};

size_t obj_size() {
    return sizeof(struct obj);
}

int obj_setid(struct obj *o, int i) {
    if (o == NULL) return -1;
    o->id = i;
    return 0;
}

int obj_getid(struct obj *o, int *i) 
{
    if (o == NULL || i == NULL) return -1;
    *i = o->id;
    return *i;
}

int main()
{
    obj herb;
    obj_setid(&herb, 33);
    int *pj = 0; 
    std::cout << obj_size() << std::endl;
    std::cout << obj_getid(&herb, pj) << std::endl;
    return 0;
}

