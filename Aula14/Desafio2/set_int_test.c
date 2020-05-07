#include "set_int.h"
#include "mintest/macros.h"

#define assert_empty(s) { test_assert(set_int_empty(s), "not empty"); }
#define assert_not_empty(s) { test_assert(!set_int_empty(s), "empty"); }
#define assert_insert(s, value) { set_int_insert(s, value); char str[50]; sprintf(str, "inserted %d but not there", value); test_assert(set_int_has(s, value), str); }
#define assert_remove(s, value) { set_int_remove(s, value); char str[50]; sprintf(str, "removed %d but still there", value); test_assert(!set_int_has(s, value), str); }


int push_pop_push_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_remove(s, 20);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_pop_push_push_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_remove(s, 20);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_pop_push_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_pop_pop_push_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_remove(s, 30);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_pop_push_push_push_pop_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_remove(s, 40);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_remove(s, 20);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_pop_push_push_pop_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_remove(s, 40);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_push_pop_push_pop_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_remove(s, 40);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_push_pop_pop_push_pop_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_remove(s, 40);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int push_push_push_pop_pop_pop_push_pop(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_get_put_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_remove(s, 20);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_get_put_put_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_remove(s, 30);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_get_put_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_remove(s, 30);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_get_get_put_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_remove(s, 20);
    assert_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_remove(s, 30);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_get_put_put_put_get_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_remove(s, 10);
    assert_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_get_put_put_get_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_put_get_put_get_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_put_get_get_put_get_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_remove(s, 30);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


int put_put_put_get_get_get_put_get(void) {
    set_int *s = set_int_new();
    assert_empty(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_insert(s, 10);
    assert_not_empty(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_insert(s, 20);
    assert_not_empty(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_insert(s, 30);
    assert_not_empty(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_remove(s, 10);
    assert_not_empty(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_remove(s, 20);
    assert_not_empty(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_remove(s, 30);
    assert_empty(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_insert(s, 40);
    assert_not_empty(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_remove(s, 40);
    assert_empty(s);

    set_int_delete(&s);
    return 1;
}


test_list = {
    TEST(push_pop_push_pop),
    TEST(push_pop_push_push_pop_pop),
    TEST(push_push_pop_push_pop_pop),
    TEST(push_push_pop_pop_push_pop),
    TEST(push_pop_push_push_push_pop_pop_pop),
    TEST(push_push_pop_push_push_pop_pop_pop),
    TEST(push_push_push_pop_push_pop_pop_pop),
    TEST(push_push_push_pop_pop_push_pop_pop),
    TEST(push_push_push_pop_pop_pop_push_pop),
    TEST(put_get_put_get),
    TEST(put_get_put_put_get_get),
    TEST(put_put_get_put_get_get),
    TEST(put_put_get_get_put_get),
    TEST(put_get_put_put_put_get_get_get),
    TEST(put_put_get_put_put_get_get_get),
    TEST(put_put_put_get_put_get_get_get),
    TEST(put_put_put_get_get_put_get_get),
    TEST(put_put_put_get_get_get_put_get),
};

#include "mintest/runner.h"
