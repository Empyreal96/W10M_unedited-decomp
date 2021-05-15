// IopCombineLegacyResources 
 
_DWORD *__fastcall IopCombineLegacyResources(int a1)
{
  int v1; // r4
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r6
  int *v5; // r0
  _DWORD *v6; // r0
  int v7; // r8
  int v8; // r6
  int v9; // r0
  int v10; // r7

  v1 = a1;
  v2 = 0;
  v3 = 0;
  v4 = a1;
  if ( a1 )
  {
    do
    {
      v5 = *(int **)(v4 + 284);
      if ( v5 )
        v3 += PnpDetermineResourceListSize(v5);
      v4 = *(_DWORD *)(v4 + 356);
    }
    while ( v4 );
    if ( v3 )
    {
      v6 = (_DWORD *)ExAllocatePoolWithTag(1, v3, 538996816);
      v2 = v6;
      if ( v6 )
      {
        *v6 = 0;
        v7 = (int)(v6 + 1);
        do
        {
          v8 = *(_DWORD *)(v1 + 284);
          if ( v8 )
          {
            v9 = PnpDetermineResourceListSize(*(int **)(v1 + 284));
            if ( v9 )
            {
              v10 = v9 - 4;
              memmove(v7, v8 + 4, v9 - 4);
              v7 += v10;
              *v2 += **(_DWORD **)(v1 + 284);
            }
          }
          v1 = *(_DWORD *)(v1 + 356);
        }
        while ( v1 );
      }
    }
  }
  return v2;
}
