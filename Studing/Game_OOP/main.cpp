#include "./Iterator/Iterator.h"
#include "./Field/Field.h"

int main()
{
    Field a(10,20);
    int e[2] = {0,1};
    int o[2] = {9,15};
    a.EnterOut(e,o);
    a.render_field();

    return 0;
}
