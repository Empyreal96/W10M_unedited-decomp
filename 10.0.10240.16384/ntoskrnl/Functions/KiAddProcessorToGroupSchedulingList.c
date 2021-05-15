// KiAddProcessorToGroupSchedulingList 
 
int __fastcall KiAddProcessorToGroupSchedulingList(int result, _DWORD *a2, int a3)
{
  _DWORD *v4; // r4
  int v5; // r8
  int v6; // r9
  int v7; // r7
  int **v8; // r1
  int *v9; // r2

  v4 = (_DWORD *)*a2;
  v5 = result;
  if ( (_DWORD *)*a2 != a2 )
  {
    v6 = 248 * a3 + 200;
    v7 = result + 1984;
    do
    {
      v8 = *(int ***)(v7 + 4);
      result = (int)(v4 - 10);
      v9 = (_DWORD *)((char *)v4 + v6 - 40);
      *v9 = v7;
      v9[1] = (int)v8;
      if ( *v8 != (int *)v7 )
        __fastfail(3u);
      *v8 = v9;
      *(_DWORD *)(v7 + 4) = v9;
      if ( (_DWORD *)v4[3] != v4 + 3 )
        result = KiAddProcessorToGroupSchedulingList(v5);
      v4 = (_DWORD *)*v4;
    }
    while ( v4 != a2 );
  }
  return result;
}
