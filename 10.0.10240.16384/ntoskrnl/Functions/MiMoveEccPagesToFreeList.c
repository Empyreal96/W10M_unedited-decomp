// MiMoveEccPagesToFreeList 
 
int __fastcall MiMoveEccPagesToFreeList(unsigned int a1, unsigned int a2)
{
  unsigned int v3; // r5
  int v4; // r7
  int v5; // r4
  unsigned int *v6; // r6
  int v7; // r10
  unsigned __int8 *v8; // r3
  unsigned int v9; // r1
  unsigned int v10; // r2
  unsigned int v11; // r3
  unsigned int v12; // r1

  v3 = a1;
  v4 = 0;
  v5 = MmPfnDatabase + 24 * a1;
  if ( a1 < a2 )
  {
    v6 = (unsigned int *)(v5 + 12);
    do
    {
      if ( MI_IS_PFN(v3) )
      {
        v7 = KfRaiseIrql(2);
        v8 = (unsigned __int8 *)(v5 + 15);
        do
        {
          v9 = __ldrex(v8);
          v10 = __strex(v9 | 0x80, v8);
        }
        while ( v10 );
        __dmb(0xBu);
        if ( v9 >> 7 )
        {
          v9 = (unsigned int)v6 + 3;
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v11 = *v6;
              __dmb(0xBu);
            }
            while ( (v11 & 0x80000000) != 0 );
            do
              v10 = __ldrex((unsigned __int8 *)v9);
            while ( __strex(v10 | 0x80, (unsigned __int8 *)v9) );
            __dmb(0xBu);
          }
          while ( v10 >> 7 );
        }
        if ( (*(_BYTE *)(v5 + 19) & 0x40) != 0 )
        {
          *(_BYTE *)(v5 + 19) &= 0x3Fu;
          if ( (*(_DWORD *)(v5 + 4) | 0x80000000) == -4 && (*(_BYTE *)(v5 + 18) & 7) == 5 )
          {
            MiUnlinkPageFromBadList(v5, v9, v10, 5);
            *(_DWORD *)(v5 + 12) |= 0x40000000u;
            MiInsertPageInFreeOrZeroedList(v3, 2);
          }
          ++v4;
        }
        __dmb(0xBu);
        do
          v12 = __ldrex(v6);
        while ( __strex(v12 & 0x7FFFFFFF, v6) );
        KfLowerIrql(v7);
      }
      ++v3;
      v5 += 24;
      v6 += 6;
    }
    while ( v3 < a2 );
  }
  return v4;
}
