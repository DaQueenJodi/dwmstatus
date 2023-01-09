
#define SHCMD(cmd)                                                             \
  { "/bin/sh", "-c", cmd, NULL }

static const char datecmd[] = "date";
static const char hostnamecmd[] = "hostname";
static const char ramcmd[] = "free -h | awk 'FNR == 2 {print $3 \" / \"$2}'";
#define seperator " | "

#define SECONDS(n) (1 * 1000)
#define MINUTES(n) (SECONDS(n) * 60)

// {prefix, command, ms_interval}
static const Module modules[] = {
    {NULL, hostnamecmd, 0},
    {NULL, datecmd, SECONDS(1)},
    {"RAM: ", ramcmd, MINUTES(1.5)},
};
