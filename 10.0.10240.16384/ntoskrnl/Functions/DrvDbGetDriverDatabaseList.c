// DrvDbGetDriverDatabaseList 
 
int __fastcall DrvDbGetDriverDatabaseList(_DWORD *a1, int (__fastcall *a2)(_DWORD, int, int), int a3, _WORD *a4, unsigned int a5, unsigned int *a6)
{
  int (__fastcall *v6)(_DWORD, int, int); // lr
  int v7; // r1
  int v9; // r6
  int **v10; // r4
  int **v11; // r10
  int v12; // r0
  int v13; // r2
  int v14; // r9
  unsigned int v15; // r3
  int v17; // [sp+8h] [bp-30h]

  v6 = a2;
  v7 = 0;
  v17 = 0;
  v9 = 0;
  *a6 = 0;
  if ( a5 )
    *a4 = 0;
  v10 = (int **)a1[3];
  v11 = (int **)(a1 + 3);
  if ( v10 != a1 + 3 )
  {
    do
    {
      if ( !v6 || (v12 = v6(*a1, (int)v10[3], 6), v7 = v17, v12) )
      {
        v13 = (*((unsigned __int16 *)v10 + 4) >> 1) + 1;
        *a6 += v13;
        if ( a4 )
        {
          v14 = v7 + v13;
          if ( v7 + v13 < a5 )
          {
            RtlStringCchCopyExW(&a4[v17], a5 - v7, v10[3], 0, 0, 2304);
            v7 = v14;
            v17 = v14;
          }
        }
      }
      v10 = (int **)*v10;
      v6 = a2;
    }
    while ( v10 != v11 );
    v9 = 0;
  }
  v15 = *a6 + 1;
  *a6 = v15;
  if ( !a4 || v15 > a5 )
    return -1073741789;
  a4[v15 - 1] = 0;
  return v9;
}
