#include "set_int.h"
#include "mintest/macros.h"

#define assert_empty(s) { test_assert(set_int_empty(s), "not empty"); }
#define assert_not_empty(s) { test_assert(!set_int_empty(s), "empty"); }
#define assert_full(s) { test_assert(set_int_full(s), "not full"); }
#define assert_not_full(s) { test_assert(!set_int_full(s), "full"); }
#define assert_insert(s, value) { set_int_insert(s, value); char str[50]; sprintf(str, "inserted %d but not there", value); test_assert(set_int_has(s, value), str); }
#define assert_remove(s, value) { set_int_remove(s, value); char str[50]; sprintf(str, "removed %d but still there", value); test_assert(!set_int_has(s, value), str); }


int capacity1_push_pop_push_pop(void) {
    set_int *s = set_int_new(1);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_push_pop_push_push_pop_pop(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_push_push_pop_push_pop_pop(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_push_push_pop_pop_push_pop(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_push_pop_push_push_push_pop_pop_pop(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_push_push_pop_push_push_pop_pop_pop(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_push_push_push_pop_push_pop_pop_pop(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_push_push_push_pop_pop_push_pop_pop(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_push_push_push_pop_pop_pop_push_pop(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity1_put_get_put_get(void) {
    set_int *s = set_int_new(1);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_put_get_put_put_get_get(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_put_put_get_put_get_get(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity2_put_put_get_get_put_get(void) {
    set_int *s = set_int_new(2);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_put_get_put_put_put_get_get_get(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_put_put_get_put_put_get_get_get(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_put_put_put_get_put_get_get_get(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_put_put_put_get_get_put_get_get(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


int capacity3_put_put_put_get_get_get_put_get(void) {
    set_int *s = set_int_new(3);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);
    assert_insert(s, 30);
    assert_not_empty(s);
    assert_full(s);

    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 10);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);
    assert_remove(s, 20);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 30);
    assert_empty(s);
    assert_not_full(s);

    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);
    assert_insert(s, 40);
    assert_not_empty(s);
    assert_not_full(s);

    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);
    assert_remove(s, 40);
    assert_empty(s);
    assert_not_full(s);

    set_int_delete(&s);
    return 1;
}


test_list = {
    TEST(capacity1_push_pop_push_pop),
    TEST(capacity2_push_pop_push_push_pop_pop),
    TEST(capacity2_push_push_pop_push_pop_pop),
    TEST(capacity2_push_push_pop_pop_push_pop),
    TEST(capacity3_push_pop_push_push_push_pop_pop_pop),
    TEST(capacity3_push_push_pop_push_push_pop_pop_pop),
    TEST(capacity3_push_push_push_pop_push_pop_pop_pop),
    TEST(capacity3_push_push_push_pop_pop_push_pop_pop),
    TEST(capacity3_push_push_push_pop_pop_pop_push_pop),
    TEST(capacity1_put_get_put_get),
    TEST(capacity2_put_get_put_put_get_get),
    TEST(capacity2_put_put_get_put_get_get),
    TEST(capacity2_put_put_get_get_put_get),
    TEST(capacity3_put_get_put_put_put_get_get_get),
    TEST(capacity3_put_put_get_put_put_get_get_get),
    TEST(capacity3_put_put_put_get_put_get_get_get),
    TEST(capacity3_put_put_put_get_get_put_get_get),
    TEST(capacity3_put_put_put_get_get_get_put_get),
};

#include "mintest/runner.h"
