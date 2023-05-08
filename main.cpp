#include <iostream>
#include "tests.h"
#include "Repo.h"
#include "Service.h"
#include "Ui.h"
int main() {
   test_all();
   Repo r;
   Service s(r);
   Ui ui(s);
   ui.run_menu();
    return 0;
}
