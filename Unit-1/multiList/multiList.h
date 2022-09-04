
typedef struct sudentNode
{
    char name[51];
    struct studentNode *nextStud;
}STUD_ND;

typedef struct subNode
{
    char sub[21];
    struct subNode* nextSub;
    STUD_ND* students;
}SUB_ND;

typedef struct multiList
{
    SUB_ND* subs;
}MLIST;



void initList(MLIST*);
int createSubs(MLIST*);
int createStuds(SUB_ND*);

SUB_ND* insertSub(MLIST*, char*);
int insertStud(SUB_ND*, char*);

int dispSubs(MLIST*);
int dispStuds(SUB_ND*);
