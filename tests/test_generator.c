#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct test_hist{
    int head;
    int tail;
    int headpos;
    int nhits;
    int hpage;
    int* dat;
};

int main()
{
    int k,m,n,page;


    scanf("%d%d%d",&k,&m,&n);

    struct test_hist *cache = (struct test_hist *) calloc(m, sizeof(struct test_hist));

    for (int j=0;j<m;j++)
    {

        cache[j].dat=(int *) calloc(k, sizeof(int));
        cache[j].head=-1;
        cache[j].tail=-1;

    }

    for (int i=0;i<n;i++)
    {
        scanf("%d",&page);

        int delset=1;

        int todel;

        int todellru;

        int mintime=INT_MAX;

        int minhead=INT_MAX;

        int countlk=0;
        for (int j=0;j<m;j++)
        {
            if (cache[j].head==-1)
            {
                countlk++;
                if (cache[j].tail < mintime)
                {
                    mintime=cache[j].tail;
                    todellru=j;
                }

            }
        }
        if (countlk>=2)
        {
            todel=todellru;
        }
        else
        {
            for (int j=0;j<m;j++)
            {
                if (cache[j].head <= minhead)
                {
                    todel=j;
                    minhead=cache[j].head;
                }
            }
        }

        for (int j=0;j<m;j++)
        {
            if (cache[j].hpage==page)
            {
                delset=0;
                cache[j].nhits++;
                cache[j].tail=i;
                if (cache[j].nhits<=k)
                {

                    cache[j].dat[cache[j].nhits-1]=i;

                }
                if (cache[j].nhits==k)
                {

                    cache[j].head=cache[j].dat[0];
                    cache[j].headpos=0;

                }
                if (cache[j].nhits>k)
                {
                    cache[j].dat[cache[j].headpos]=i;

                    if (cache[j].headpos<k-1)
                    {
                        cache[j].headpos++;
                    }
                    else
                    {
                        cache[j].headpos=0;
                    }

                }

                cache[j].head=cache[j].dat[cache[j].headpos];

            }
        }

        if (delset==1)
        {
            cache[todel].hpage=page;
            cache[todel].nhits=1;
            cache[todel].dat[0]=i;
            cache[todel].tail=i;
            if(k>1)
            {
            cache[todel].head=-1;
            }
            else
            {
            cache[todel].head=i;
            }
            for (int j=1;j<k;j++)
    {

        cache[todel].dat[j]=0;
    }
            printf("0");


        }
        else
        {
            printf("1");
        }
    }
    for (int j=0;j<m;j++)
    {

        printf("%d",cache[j].hpage);
    }
for (int j=0;j<m;j++)
    {

        free(cache[j].dat);

    }
free(cache);
}

