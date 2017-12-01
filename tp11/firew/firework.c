/* This SDL program simulates and draws firework.
 *
 * It contains two types of firework rockets.
 * The "exploding" falls apart to random directions, the "flower"
 * falls apart in a symmetrical way and the pieces explode
 * one more time in a little while.
 *
 *
 * The singly linked list is handled like we learned.
 * For easier handling there is a sentinel element at the beginning.
 *
 *  - the sentinel ensures that the head pointer does not change
 *  - it is all the same where the new element is inserted (no visible
 *    difference), the new element is inserted after the actually
 *    processed one.
 *  - because of the deletion inchworming is necessary.
  */

#include <stdlib.h>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

/*change 1 to 0 in the next line to remove statistics*/
#define STATISTICS 1

/*change 1 to 0 in the next line to make the application run in a window*/
#define FULLSCREEN 1

/* typical global variable: every function may access the screen */
SDL_Surface *screen;
TTF_Font *font;

enum Type { exploding, flower, flower_fragment, fading };
typedef struct Point {
    enum Type type;
    double x, y;        /* position */
    double vx, vy;      /* velocity */
    unsigned char r, g, b; /* colour */
    double lifetime;  /* time until explosion or deletion */

    struct Point *next;    /* in the list */
} Point;


/* generally */
Point *new_point(double x, double y, double vx, double vy) {
    Point *np = (Point *) malloc(sizeof(Point));
    np->x = x;
    np->y = y;
    np->vx = vx;
    np->vy = vy;
    np->next = NULL;

    /* this part reduces the intensity of at most 2 rgb (red, green, blue) components. */
    /* the trick is that the random value is in the 0...6 range; not in the 0...7 range */
    /* this way 111 is excluded from the generated 3 bit random values */
    int remove = rand()%7;
    np->r = remove&1 ? 128 : rand()%32+224;
    np->g = remove&2 ? 128 : rand()%32+224;
    np->b = remove&4 ? 128 : rand()%32+224;
    return np;
}


/* the usual fireworks */
Point *new_exploding() {
    Point *np = new_point(rand()%(screen->w/2)+screen->w/4, screen->h, rand()%40-20, -(rand()%40+80));
    np->lifetime = rand()%5+6;
    np->type = exploding;
    return np;
}


/* this is another expoding type with different parameters */
Point *new_flower_fragment(double x, double y, double vx, double vy, unsigned char r, unsigned char g, unsigned char b) {
    Point *np = new_point(x, y, vx, vy);
    np->lifetime = 1.5+rand()%10/30.0;
    np->type = flower_fragment;
    np->r = r;
    np->g = g;
    np->b = b;
    return np;
}


/* explodes to a flower */
Point *new_flower() {
    Point *np = new_exploding();
    np->type = flower;
    return np;
}


/* fading away */
Point *new_fading(double x, double y, unsigned char r, unsigned char g, unsigned char b) {
    Point *np = new_point(x, y, rand()%60-30, rand()%60-30);
    np->lifetime = 3+rand()%10/10.0;
    np->type = fading;
    np->r = r;
    np->g = g;
    np->b = b;
    return np;
}


/* inserts the "what" element after "behind" element. */
void insert(Point *behind, Point *what) {
    what->next = behind->next;
    behind->next = what;
}


/* "simulates" the points in the list for delta_t time step */
void simulate(Point *list, double delta_t) {
    const double g = 9.81;
    Point *iter, *prev, *nxt;
    int i;

    /* for each point: move, explode */
    prev = list;
    iter = list->next;
    while (iter!=NULL) {
        iter->lifetime -= delta_t;
        if (iter->lifetime < 0) {
            switch (iter->type) {
                case exploding:
                    for (i = 0; i < 30; i++)
                        insert(iter, new_fading(iter->x, iter->y, iter->r, iter->g, iter->b));
                    break;
                case flower:
                    for (i=0; i<10; i++) {
                        /* along a circle; angle=i/max*2pi */
                        double ang = i/10.0*2*3.141592;
                        double vx = cos(ang)*(rand()%10+80), vy=sin(ang)*(rand()%10+80);
                        insert(iter, new_flower_fragment(iter->x, iter->y, vx, vy, iter->r, iter->g, iter->b));
                    }
                    break;
                case flower_fragment:
                    for (i = 0; i < 20; i++)
                        insert(iter, new_fading(iter->x, iter->y, iter->r, iter->g, iter->b));
                    break;
                case fading:
                    break;
            }

            prev->next = iter->next;  /* unchain the one to delete */
            nxt = iter->next;      /* needed for the loop */
            free(iter);                 /* as iter gets deleted! */
        } else {
            iter->x += iter->vx*delta_t;
            iter->y += iter->vy*delta_t;
            iter->vy += g*delta_t;
            /* a little fading */
            if (iter->type == fading) {
                if (iter->r > 4) iter->r -= 4;
                if (iter->g > 4) iter->g -= 4;
                if (iter->b > 4) iter->b -= 4;
            }
            prev = iter;
            nxt = iter->next;
        }

        iter = nxt;
    }

    /* draw */
    boxRGBA(screen, 0, 0, screen->w-1, screen->h-1, 0, 0, 0, 255);
    for (iter = list->next, i = 0; iter != NULL; iter = iter->next, i++) {
        filledCircleRGBA(screen, iter->x, iter->y, 3, iter->r, iter->g, iter->b, 255);
        aacircleRGBA(screen, iter->x, iter->y, 3, iter->r, iter->g, iter->b, 255);
    }
#if STATISTICS
    /* this part prints the max. and the actual number of points */
    if (font) {
        SDL_Surface *text;
        char num[30];
        static int max;
        if(i>max)
            max=i;
        SDL_Color white = {255, 255, 255};

        sprintf(num, "max:%d act:%d",max, i);
        text = TTF_RenderUTF8_Solid(font, num, white);
        SDL_BlitSurface(text, NULL, screen, NULL);
        SDL_FreeSurface(text);
    }
#endif
    SDL_Flip(screen);
}


/* timing function */
Uint32 timing(Uint32 ms, void* param) {
    SDL_Event ev;
    ev.type = SDL_USEREVENT;
    SDL_PushEvent(&ev);
    return ms;   /* more waiting */
}


int main(int argc, char *argv[]) {
    SDL_TimerID id;
    bool quit;
    Point *list;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
#if FULLSCREEN
    screen = SDL_SetVideoMode(1024, 768, 0, SDL_ANYFORMAT | SDL_FULLSCREEN);
#else
    screen = SDL_SetVideoMode(800, 600, 0, SDL_ANYFORMAT);
#endif
    if (!screen) {
        fprintf(stderr, "Could not open window!\n");
        exit(1);
    }
    srand(time(0));

#if STATISTICS
    TTF_Init();
    font = TTF_OpenFont("LiberationSerif-Regular.ttf", 48);
#endif

    /* sentinel */
    list = (Point*) malloc(sizeof(Point));
    /* put something in the list */
    list->next = new_exploding();
    list->next->next = NULL;

    id = SDL_AddTimer(20, timing, NULL);
    quit = false;
    while (!quit) {
        SDL_WaitEvent(&event);

        switch (event.type) {
            /* the timing function generates this event */
            case SDL_USEREVENT:
                simulate(list, 0.075);
                if (rand() % 30 == 0)
                    insert(list, rand()%5 == 0 ? new_flower() : new_exploding());
                break;

            case SDL_QUIT:
            case SDL_KEYDOWN:
                quit = true;
                break;
        }
    }
    SDL_RemoveTimer(id);

    /* delete the list */
    while (list != NULL) {
        Point *nxt = list->next;
        free(list);
        list = nxt;
    }
#if STATISTICS
    if (font)
        TTF_CloseFont(font);
#endif

    SDL_Quit();
    return 0;
}
