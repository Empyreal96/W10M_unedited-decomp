// KiIdleLoop 
 
void __noreturn KiIdleLoop()
{
  int v0; // r4
  int v1; // r6
  unsigned int v2; // r1
  int v3; // r5
  unsigned __int64 *v4; // r2
  unsigned __int64 v5; // kr00_8
  unsigned __int64 v6; // r0
  __int64 v7; // r2
  __int64 v8; // r0
  unsigned __int64 *v9; // r9
  unsigned __int64 v10; // r2

  while ( 1 )
  {
    v0 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    __yield();
    __enable_irq();
    __disable_irq();
    if ( (*(_BYTE *)(v0 + 1756) & 0x3F) != 0 )
      KiRetireDpcList(v0);
    if ( *(_BYTE *)(v0 + 1753) )
    {
      *(_BYTE *)(v0 + 1753) = 0;
      __enable_irq();
      KiQuantumEnd();
      __disable_irq();
    }
    *(_BYTE *)(v0 + 2) = 1;
    __dmb(0xBu);
    if ( *(_DWORD *)(v0 + 8) )
    {
      *(_BYTE *)(v0 + 2) = 0;
      __enable_irq();
      v1 = *(_DWORD *)(v0 + 12);
      __dmb(0xFu);
      while ( 1 )
      {
        do
          v2 = __ldrex((unsigned int *)v0);
        while ( __strex(1u, (unsigned int *)(v0 + 24)) == 1 );
        if ( !v2 )
          break;
        __yield();
      }
      __dmb(0xFu);
      v3 = *(_DWORD *)(v0 + 8);
      *(_DWORD *)(v0 + 8) = 0;
      if ( v3 == v1 )
      {
        __dmb(0xFu);
        *(_DWORD *)(v0 + 24) = 0;
      }
      else
      {
        __disable_irq();
        ++*(_BYTE *)(v0 + 16);
        v4 = (unsigned __int64 *)(v0 + 2416);
        do
        {
          v5 = __ldrexd(v4);
          v6 = __PAIR64__(HIDWORD(v5), __mrc(15, 0, 9, 13, 0));
          if ( ((v5 ^ v6) & 0x80000000) != 0i64 )
            HIDWORD(v6) = HIDWORD(v5) + ((unsigned int)v5 >> 31);
        }
        while ( __strexd(v6, v4) );
        v7 = *(_QWORD *)(v0 + 2376);
        *(_QWORD *)(v0 + 2376) = v6;
        v8 = v6 - v7;
        v9 = (unsigned __int64 *)(v1 + 48);
        do
          v10 = __ldrexd(v9);
        while ( __strexd(v10 + v8, v9) == 1 );
        __enable_irq();
        *(_DWORD *)(v0 + 4) = v3;
        *(_BYTE *)(v3 + 132) = 2;
        __dmb(0xFu);
        *(_DWORD *)(v0 + 24) = 0;
LABEL_22:
        if ( v3 == v1 )
          __fastfail(0x1Eu);
        SwapContext(v1, v3, 1, v0);
      }
    }
    else if ( *(_BYTE *)(v0 + 1755) )
    {
      *(_BYTE *)(v0 + 2) = 0;
      __enable_irq();
      v3 = KiIdleSchedule(v0);
      v1 = *(_DWORD *)(v0 + 12);
      if ( v3 )
        goto LABEL_22;
    }
    else
    {
      if ( (*(_BYTE *)(v0 + 1756) & 0x3F) == 0 )
      {
        __mcr(15, 0, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFF0 | 2, 13, 0, 3);
        PoIdle(v0);
        __enable_irq();
      }
      *(_BYTE *)(v0 + 2) = 0;
    }
  }
}
