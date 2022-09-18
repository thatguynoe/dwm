/* See LICENSE file for copyright and license details. */

#define TERMINAL "st"

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 1;        /* horizontal padding for statusbar */
static const int vertpadbar         = 2;        /* vertical padding for statusbar */
static const char *fonts[]          = { "monospace:size=10", "Joy Pixels:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = { TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = { TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = { TERMINAL, "-n", "spzoom", "-g", "60x17", "-e", "xzoom", NULL };
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm",      spcmd1},
    {"spcalc",      spcmd2},
    {"spzoom",      spcmd3},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class     instance  title                    tags mask   isfloating  isterminal  noswallow  monitor */
    { "Gimp",    NULL,     NULL,                    0,          1,          0,           0,        -1 },
    { "Firefox", NULL,     NULL,                    0,          0,          0,          -1,        -1 },
    { NULL,      NULL,     "Picture-in-Picture",    0,          1,          0,           0,        -1 },
    { TERMINAL,  NULL,     NULL,                    0,          0,          1,           0,        -1 },
    { NULL,      NULL,     "Event Tester",          0,          0,          0,           1,        -1 }, /* xev */
    { NULL,      "spterm", NULL,                    SPTAG(0),   1,          1,           0,        -1 },
    { NULL,      "spcalc", NULL,                    SPTAG(1),   1,          1,           0,        -1 },
    { NULL,      "spzoom", NULL,                    SPTAG(2),   1,          1,           0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1               /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "[D]",      deck },    /* master on the left, slaves stacked on the right */
    { "[M]",      monocle }, /* all windows on top of each other */
    { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
    { MOD,                          XK_j,     ACTION##stack,  {.i = INC(+1) } }, \
    { MOD,                          XK_k,     ACTION##stack,  {.i = INC(-1) } }, \
    { MOD,                          XK_v,     ACTION##stack,  {.i = 0 } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const Key keys[] = {
    /* modifier                     key                         function        argument */
    STACKKEYS(MODKEY,                                           focus)
    STACKKEYS(MODKEY|ShiftMask,                                 push)
    { MODKEY,                       XK_p,                       spawn,          {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return,                  spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,                       togglebar,      {0} },
    { MODKEY,                       XK_i,                       incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,                       incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_s,                       togglesticky,   {0} },
    { MODKEY,                       XK_h,                       setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,                       setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return,                  zoom,           {0} },
    { MODKEY,                       XK_Tab,                     view,           {0} },
    { MODKEY|ShiftMask,             XK_c,                       killclient,     {0} },
    { MODKEY,                       XK_t,                       setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,                       setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,                       setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_u,                       setlayout,      {.v = &layouts[3]} },    /* deck */
    { MODKEY,                       XK_space,                   setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,                   togglefloating, {0} },
    { MODKEY,                       XK_f,                       togglefullscr,  {0} },
    { MODKEY,                       XK_z,                       incrgaps,       {.i = +3 } },
    { MODKEY,                       XK_x,                       incrgaps,       {.i = -3 } },
    { MODKEY,                       XK_0,                       view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,                       tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,                   focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,                  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,                   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,                  tagmon,         {.i = +1 } },
    { MODKEY,                       XK_apostrophe,              togglescratch,  {.ui = 1} },
    { MODKEY|ShiftMask,             XK_Return,                  togglescratch,  {.ui = 0} },
    TAGKEYS(                        XK_1,                                       0)
    TAGKEYS(                        XK_2,                                       1)
    TAGKEYS(                        XK_3,                                       2)
    TAGKEYS(                        XK_4,                                       3)
    TAGKEYS(                        XK_5,                                       4)
    TAGKEYS(                        XK_6,                                       5)
    TAGKEYS(                        XK_7,                                       6)
    TAGKEYS(                        XK_8,                                       7)
    TAGKEYS(                        XK_9,                                       8)
    { MODKEY|ShiftMask,             XK_q,                       quit,           {0} },
    { MODKEY,                       XK_F2,                      togglescratch,  {.ui = 2} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

