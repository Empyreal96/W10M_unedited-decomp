// MiPurgeZeroList 
 
void MiPurgeZeroList()
{
  unsigned int v0; // r9
  int v1; // r6
  unsigned int i; // r3
  int v3; // r4
  int v4; // r5
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned __int8 *v7; // r1
  int v8; // r3
  unsigned int v9; // r2
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int v12; // [sp+0h] [bp-20h]

  v0 = 0;
  v1 = dword_63FB00;
  for ( i = dword_633818; v0 < i; v1 += 20 )
  {
    v3 = *(_DWORD *)(v1 + 8);
    if ( v3 != 0xFFFFF )
    {
      do
      {
        v4 = MmPfnDatabase + 24 * v3;
        v12 = KfRaiseIrql(2);
        v5 = (unsigned __int8 *)(v4 + 15);
        do
          v6 = __ldrex(v5);
        while ( __strex(v6 | 0x80, v5) );
        __dmb(0xBu);
        if ( v6 >> 7 )
        {
          v7 = (unsigned __int8 *)(v4 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v8 = *(_DWORD *)(v4 + 12);
              __dmb(0xBu);
            }
            while ( v8 < 0 );
            do
              v9 = __ldrex(v7);
            while ( __strex(v9 | 0x80, v7) );
            __dmb(0xBu);
          }
          while ( v9 >> 7 );
        }
        if ( (*(_BYTE *)(v4 + 18) & 7) == 0 && (*(_DWORD *)(v4 + 20) & 0xFFFFF) != 1048574 )
        {
          MiUnlinkFreeOrZeroedPage(v3, 0);
          MiInsertPageInFreeOrZeroedList(v3, 2);
        }
        __dmb(0xBu);
        v10 = (unsigned int *)(v4 + 12);
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 & 0x7FFFFFFF, v10) );
        KfLowerIrql(v12);
        v3 = *(_DWORD *)(v1 + 8);
      }
      while ( v3 != 0xFFFFF );
      i = dword_633818;
    }
    ++v0;
  }
  byte_634378 = 0;
}
