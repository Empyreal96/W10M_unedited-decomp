// HvpIsFreeNeighbor 
 
int __fastcall HvpIsFreeNeighbor(int a1, _DWORD *a2, int *a3, int **a4, int a5)
{
  int *i; // r6
  unsigned int v8; // r4
  int *v10; // r3
  int v11; // r3

  i = (int *)((char *)a3 + *a3);
  v8 = a2[2];
  *a4 = 0;
  if ( (char *)i - (char *)a2 < v8 && *i > 0 )
  {
    *a4 = i;
  }
  else
  {
    for ( i = a2 + 8; ; i = v10 )
    {
      while ( 1 )
      {
        if ( i >= a3 )
          return 0;
        v11 = *i;
        if ( *i > 0 )
          break;
        i = (int *)((char *)i - v11);
      }
      v10 = (int *)((char *)i + v11);
      if ( v10 == a3 )
        break;
    }
    *a4 = i;
    if ( a5 != 1 && !HvpMarkCellDirty(a1, (char *)i + a2[1] - (_DWORD)a2, 1, 0) )
      return 0;
  }
  HvpDelistFreeCell(a1, (char *)i + a2[1] + (a5 << 31) - (_DWORD)a2, a5);
  return 1;
}
