#include <iostream>
#include "classes.h"
int main() {
    dataManger dm;
    vector<client> x;
    dm.get_all_client(x);
    for(client c : x){
        cout << c.get_name() << endl;
    }

    return 0;
}
