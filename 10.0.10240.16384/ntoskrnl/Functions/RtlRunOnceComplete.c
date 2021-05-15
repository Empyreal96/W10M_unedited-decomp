// RtlRunOnceComplete 
 
int __fastcall RtlRunOnceComplete(int *a1, int a2, int a3, char a4)
{
  unsigned __int8 v5; // r2
  char v6; // r3
  int v7; // r1
  char v8; // r2
  unsigned int v9; // r4
  unsigned int v10; // r2
  unsigned int v12; // r2

  if ( (a2 & 0xFFFFFFF9) != 0 || ((a2 - 1) & a2) != 0 )
    return -1073741584;
  v5 = a4 & 0xFE | ((a2 & 2) == 0);
  v6 = (v5 ^ (2 * ((a2 & 4) == 0))) & 2 ^ v5;
  if ( a3 && ((((v5 ^ (unsigned __int8)(2 * ((a2 & 4) == 0))) & 2 ^ v5) & 2) == 0 || (a3 & 3) != 0) )
    return -1073741583;
  __pld(a1);
  v7 = *a1;
  if ( (v6 & 2) != 0 )
    v8 = 2;
  else
    v8 = 0;
  v9 = a3 & 0xFFFFFFFC | v8 & 3;
  if ( (*a1 & 3) == 1 )
  {
    if ( (v6 & 1) != 0 )
    {
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)a1);
      while ( __strex(v9, (unsigned int *)a1) );
      __dmb(0xBu);
      if ( (v10 & 3) == 1 )
      {
        if ( (v10 & 0xFFFFFFFC) != 0 )
          return sub_819778();
        return 0;
      }
      return -1073741734;
    }
    return -1073741584;
  }
  if ( (*a1 & 3) != 3 )
    return -1073741823;
  if ( (v6 & 1) != 0 )
    return -1073741584;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)a1);
  while ( v12 == v7 && __strex(v9, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( v12 == v7 )
    return 0;
  return -1073741771;
}
