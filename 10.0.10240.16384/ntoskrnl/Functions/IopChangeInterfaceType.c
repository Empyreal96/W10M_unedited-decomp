// IopChangeInterfaceType 
 
int __fastcall IopChangeInterfaceType(int a1, int **a2)
{
  int v2; // r4
  int v4; // r6
  unsigned int v5; // r5
  int i; // r1
  unsigned int v7; // r2
  int *v8; // r5
  int v9; // r6
  int v10; // r0
  int *v11; // r8
  unsigned int v12; // r6
  int *v13; // r2
  int v14; // r7
  int v15; // r0
  int *j; // r1
  int v17; // r2

  v2 = 0;
  if ( !a1 )
    return 0;
  v4 = PnpDefaultInterfaceType;
  if ( !*(_DWORD *)(a1 + 4) )
  {
    *(_DWORD *)(a1 + 4) = PnpDefaultInterfaceType;
    v2 = 1;
  }
  v5 = a1 + 32;
  for ( i = *(_DWORD *)(a1 + 28) - 1; i >= 0; --i )
  {
    v7 = v5 + 8;
    v5 += 8 + 32 * *(_DWORD *)(v5 + 4);
    while ( v7 < v5 )
    {
      if ( *(unsigned __int8 *)(v7 + 1) == 240 && !*(_DWORD *)(v7 + 8) )
      {
        *(_DWORD *)(v7 + 8) = v4;
        v2 = 1;
      }
      v7 += 32;
    }
  }
  if ( v2 )
  {
    v8 = *a2;
    if ( *a2 )
    {
      v9 = PnpDetermineResourceListSize(*a2);
      v10 = ExAllocatePoolWithTag(1, v9, 538996816);
      v11 = (int *)v10;
      if ( !v10 )
        return 0;
      memmove(v10, (int)v8, v9);
      v12 = 0;
      v13 = v11 + 1;
      if ( *v8 )
      {
        v14 = PnpDefaultInterfaceType;
        do
        {
          if ( !*v13 )
            *v13 = v14;
          v15 = v13[3];
          for ( j = v13 + 4; v15; --v15 )
          {
            v17 = 0;
            if ( *(_BYTE *)j == 5 )
              v17 = j[1];
            j = (int *)((char *)j + v17 + 16);
          }
          ++v12;
          v13 = j;
        }
        while ( v12 < *v8 );
      }
      *a2 = v11;
    }
  }
  return v2;
}
