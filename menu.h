char chosen_map[100];
char chosen_game[100];
char player_name[100];
void clrscr(void);
void delay(float number_of_seconds);
void main_menu(void);
void new_acc(void);
void exitt(void);
void records(void);
void default_games(void);
void about(void);
void dir(char *filename);
void find_the_sign(void);
char *shrink_filename(char *filename , int size_line);
void hangman(char * word);
void veri_first_page(void);
struct node{
    struct node * next;
    char * data;
};

struct node * add(struct node * head , char * data);
struct node * find(struct node * head , int i);
