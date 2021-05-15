// KiRemoveBoostThread 
 
int __fastcall KiRemoveBoostThread(int a1, int a2)
{
  unsigned int *v5; // r6
  unsigned int v6; // r2
  int v7; // r0
  int v8; // r2
  int v9; // r10
  int v10; // r7
  unsigned int v11; // r3
  int v12; // r8
  unsigned int *v13; // r9
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r10
  int v17; // r2
  int v18; // r1
  char v19; // r2
  signed int v20; // r3
  int v21; // r2
  int v22; // r1
  char v23; // r3
  int v24; // [sp+0h] [bp-20h]

  if ( !*(_BYTE *)(a2 + 348) )
    return (char)(*(_BYTE *)(a2 + 123) + 1);
  v5 = (unsigned int *)(a2 + 44);
  while ( 1 )
  {
    do
      v6 = __ldrex(v5);
    while ( __strex(1u, v5) );
    __dmb(0xBu);
    if ( !v6 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v5 );
  }
  v7 = *(unsigned __int8 *)(a2 + 348);
  v8 = *(char *)(a2 + 123);
  v9 = v8;
  v24 = v8;
  if ( (v7 & 0xF) != 0 )
    return sub_50C20C();
  if ( (v7 & 0xFFFFFFF0) != 0 )
  {
    v10 = (char)(v8 - (*(_BYTE *)(a2 + 348) >> 4));
    v11 = *(_DWORD *)(a2 + 800);
    *(_BYTE *)(a2 + 348) = 0;
    if ( v11 )
    {
      v20 = 31 - __clz(v11);
      if ( v10 < v20 )
        v10 = (char)v20;
    }
    if ( v10 != v8 )
    {
      v12 = 0;
      v13 = (unsigned int *)(a1 + 24);
      while ( 1 )
      {
        do
          v14 = __ldrex(v13);
        while ( __strex(1u, v13) );
        __dmb(0xBu);
        if ( !v14 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v13 );
      }
      if ( !*(_DWORD *)(a1 + 8) )
      {
        v15 = KiSelectReadyThreadEx(a1, a2, 1);
        v16 = v15;
        if ( v15 )
        {
          if ( (*(_BYTE *)(v15 + 2) & 4) != 0 )
          {
            if ( *(char *)(v15 + 123) < 16
              && *(_DWORD *)(v15 + 68)
              && (v21 = *(_DWORD *)(v15 + 68)) != 0
              && (v22 = *(_DWORD *)(a1 + 2352) + v21) != 0
              && KiGetThreadEffectiveRankNonZero(v15, v22, 0) )
            {
              v23 = 1;
            }
            else
            {
              v23 = *(_BYTE *)(v16 + 123);
            }
            v19 = v23;
          }
          else
          {
            v19 = *(_BYTE *)(v15 + 123);
          }
          **(_BYTE **)(a1 + 28) = v19;
          *(_DWORD *)(a1 + 8) = v16;
          *(_BYTE *)(v16 + 132) = 3;
        }
        else
        {
          v12 = 1;
        }
        v9 = v24;
      }
      KiAbProcessThreadPriorityModification(a2, v10, 1);
      *(_BYTE *)(a2 + 123) = v10;
      if ( v12 )
      {
        if ( (*(_BYTE *)(a2 + 2) & 4) != 0 )
        {
          if ( v10 < 16
            && *(_DWORD *)(a2 + 68)
            && (v17 = *(_DWORD *)(a2 + 68)) != 0
            && (v18 = *(_DWORD *)(a1 + 2352) + v17) != 0
            && KiGetThreadEffectiveRankNonZero(a2, v18, 0) )
          {
            LOBYTE(v10) = 1;
          }
          else
          {
            LOBYTE(v10) = *(_BYTE *)(a2 + 123);
          }
        }
        **(_BYTE **)(a1 + 28) = v10;
      }
      __dmb(0xBu);
      *v13 = 0;
    }
  }
  else
  {
    v9 = (char)(v8 + 1);
  }
  __dmb(0xBu);
  *v5 = 0;
  return v9;
}
