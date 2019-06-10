 /* file: minunit.h */
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

#define describe(message)  static char * test_foo()
#define LAMBDA(c_) ({ c_ _;})
extern int tests_run;
