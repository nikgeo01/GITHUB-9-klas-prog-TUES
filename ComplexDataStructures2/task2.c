#include <stdio.h>

typedef struct Node Node;

struct Node {
    char firstName[50];
    Node *father;
    Node *mother;
    char marriedto[50];
};

int main ()
{
    Node grandfather1 = {"Ivan", NULL, NULL, "Juliq"};
    Node grandmother1 = {"Juliq", NULL, NULL, "Ivan"};
    Node grandfather2 = {"Valeri", NULL, NULL, "Elena"};
    Node grandmother2 = {"Elena", NULL, NULL, "Valeri"};
    Node father = {"Borislav", &grandfather1, &grandmother1, "Emiliq"};
    Node mother = {"Emiliq", &grandfather2, &grandmother2, "Borislav"};
    Node me = {"Nikola", &father, &mother, ""};

    printf("My name is %s, my father is %s, my mother is %s, my grandfather is %s, my grandmother is %s, my grandfather is %s, my grandmother is %s", me.firstName, me.father->firstName, me.mother->firstName, me.father->father->firstName, me.father->mother->firstName, me.mother->father->firstName, me.mother->mother->firstName);

    return 0;
}
