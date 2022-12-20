char garbage;
int width ;
int height  ;
char map_arr[100000] ;
char game_setting[1000] ;
char wall ;
char character ;
char deathblock ;
char solidblock ;
char moveblock ;
char up ;
char down ;
char left ;
char right ;
char target ;
char exit_t ;
char object ;
int attack ;
int raindb ;
int my_time ;
void frain(int number);
int * raindb_coord;
void rain_alloc(int number , int col);
int win_check(void);  // games with target
struct put_sth{
    char keyboard ;
    char death ;
    int counter ;
};

struct opp_creator{
    char shape ;
    char target ;

};

struct rpoint_creator{
    char shape ;
    int point ;
    int number ;

};

struct put_sth put ;
struct opp_creator opp ;
struct rpoint_creator rpoint ;
int where_is_opp[100];
int opp_counter;
int where_is_character ;

void get_time();
void get_character();
void get_down();
void get_left();
void get_up();
void get_right();
void get_deathblock();
void get_wall();
void get_object();
void get_opp();
void get_attack();
void get_put();
void get_raindb();
void get_solidblock();
void get_target();
void get_rpoint();
void get_exit();
void get_moveblock();
