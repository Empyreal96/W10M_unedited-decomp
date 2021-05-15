// RtlGetElementGenericTableAvl 
 
_DWORD *__fastcall RtlGetElementGenericTableAvl(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // r1
  unsigned int v5; // r2
  _DWORD *v6; // r0
  _DWORD *i; // r3
  unsigned int v9; // r6
  _DWORD *k; // r3
  int v11; // r7
  unsigned int v12; // r6
  _DWORD *j; // r3

  v4 = a1[6];
  v5 = a1[5];
  v6 = (_DWORD *)a1[4];
  if ( a2 == -1 || a2 + 1 > v4 )
    return 0;
  if ( !v6 )
  {
    v6 = (_DWORD *)a1[2];
    for ( i = (_DWORD *)v6[1]; i; i = (_DWORD *)i[1] )
      v6 = i;
    v5 = 0;
    a1[4] = v6;
    a1[5] = 0;
  }
  if ( v5 != a2 )
  {
    if ( v5 <= a2 )
    {
      v11 = v4 - a2 - 1;
      v12 = a2 - v5;
      if ( a2 - v5 > v4 - a2 )
      {
        v6 = (_DWORD *)a1[2];
        for ( j = (_DWORD *)v6[2]; j; j = (_DWORD *)j[2] )
          v6 = j;
        if ( v4 - a2 != 1 )
        {
          do
          {
            v6 = RealPredecessor(v6);
            --v11;
          }
          while ( v11 );
        }
      }
      else
      {
        for ( ; v12; --v12 )
          v6 = RealSuccessor(v6);
      }
    }
    else if ( a2 < v5 >> 1 )
    {
      v6 = (_DWORD *)a1[2];
      for ( k = (_DWORD *)v6[1]; k; k = (_DWORD *)k[1] )
        v6 = k;
      for ( ; a2; --a2 )
        v6 = RealSuccessor(v6);
    }
    else
    {
      v9 = v5 - a2;
      if ( v5 != a2 )
      {
        do
        {
          v6 = RealPredecessor(v6);
          --v9;
        }
        while ( v9 );
      }
    }
    a1[4] = v6;
    a1[5] = a2;
  }
  return v6 + 4;
}
