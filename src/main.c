#include <stc/csptr.h>
#include <stc/cstr.h>

typedef struct { cstr name, last; } Person;

Person* Person_make(Person* p, const char* name, const char* last) {
    p->name = cstr_from(name), p->last = cstr_from(last);
    return p;
}
void Person_del(Person* p) {
    printf("del: %s\n", p->name.str);
    c_del(cstr, &p->name, &p->last);
}

using_csptr(pe, Person, c_no_compare, Person_del);

int main() {
    csptr_pe p = csptr_pe_from(Person_make(c_new(Person), "John", "Smiths"));
    csptr_pe q = csptr_pe_clone(p); // share the pointer

    printf("%s %s. uses: %zu\n", q.get->name.str, q.get->last.str, *q.use_count);
    c_del(csptr_pe, &p);
}