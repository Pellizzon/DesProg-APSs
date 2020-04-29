#include "queue_int.h"
#include "mintest/macros.h"

#define assert_empty(q) { test_assert(queue_int_empty(q), "not empty"); }
#define assert_not_empty(q) { test_assert(!queue_int_empty(q), "empty"); }
#define assert_get(q, expected) { int actual = queue_int_get(q); char str[50]; sprintf(str, "got %d but expected %d", actual, expected); test_assert(actual == expected, str); }


int put_get_put_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_get_put_put_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_get_put_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_get_get_put_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_get_put_put_put_get_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    queue_int_put(q, 40);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_not_empty(q);

    assert_get(q, 40);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_get_put_put_get_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    queue_int_put(q, 40);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_not_empty(q);

    assert_get(q, 40);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_put_get_put_get_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 40);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_not_empty(q);

    assert_get(q, 40);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_put_get_get_put_get_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 40);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_not_empty(q);

    assert_get(q, 40);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


int put_put_put_get_get_get_put_get(void) {
    queue_int *q = queue_int_new();
    assert_empty(q);

    queue_int_put(q, 10);
    assert_not_empty(q);

    queue_int_put(q, 20);
    assert_not_empty(q);

    queue_int_put(q, 30);
    assert_not_empty(q);

    assert_get(q, 10);
    assert_not_empty(q);

    assert_get(q, 20);
    assert_not_empty(q);

    assert_get(q, 30);
    assert_empty(q);

    queue_int_put(q, 40);
    assert_not_empty(q);

    assert_get(q, 40);
    assert_empty(q);

    queue_int_delete(&q);
    return 1;
}


test_list = {
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
