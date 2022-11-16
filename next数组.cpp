void getNext(string T, int length, int next[])//¼ÆËãnextº¯ÊýÖµ

{

    int j = 0, k = -1;

    next[0] = -1;

    while (j < length)

    {



        if (k == -1 || T[j] == T[k])

            next[++j] = ++k;

        else

            k = next[k];

    }

}