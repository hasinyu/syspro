#define MAX 24
#define START_ID 1401001

struct student {
    char name[MAX];
    id_t id;     // 학번 (환경에 따라 int 혹은 id_t)
    int score;
};
