// MiRelockProtoPoolPage 
 
int __fastcall MiRelockProtoPoolPage(int a1, _BYTE *a2)
{
  int v4; // r8
  unsigned __int8 *v5; // r7
  unsigned int v6; // r2
  _DWORD *v7; // r5
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int v11; // r0
  unsigned int v12; // r2
  unsigned int *v13; // r9
  unsigned int v14; // r1
  __int16 v15; // r3
  __int16 v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // r3
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r3
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r2

  if ( a2 )
  {
    v11 = KfRaiseIrql(2);
    v4 = v11;
    v5 = (unsigned __int8 *)(a1 + 15);
    do
      v12 = __ldrex(v5);
    while ( __strex(v12 | 0x80, v5) );
    __dmb(0xBu);
    if ( v12 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v21 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( (v21 & 0x80000000) != 0 );
        do
          v22 = __ldrex(v5);
        while ( __strex(v22 | 0x80, v5) );
        __dmb(0xBu);
      }
      while ( v22 >> 7 );
    }
    *a2 = v11;
  }
  else
  {
    v4 = 17;
    v5 = (unsigned __int8 *)(a1 + 15);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x80, v5) );
    __dmb(0xBu);
    if ( v6 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v23 = *(_DWORD *)(a1 + 12);
          __dmb(0xBu);
        }
        while ( (v23 & 0x80000000) != 0 );
        do
          v24 = __ldrex(v5);
        while ( __strex(v24 | 0x80, v5) );
        __dmb(0xBu);
      }
      while ( v24 >> 7 );
    }
  }
  MiAddLockedPageCharge(a1, 1);
  v7 = (_DWORD *)(*(_DWORD *)(a1 + 4) | 0x80000000);
  if ( (*(_BYTE *)(a1 + 18) & 0x20) != 0 )
  {
    v13 = (unsigned int *)(a1 + 12);
    do
    {
      __dmb(0xBu);
      if ( v4 == 17 )
      {
        do
          v20 = __ldrex(v13);
        while ( __strex(v20 & 0x7FFFFFFF, v13) );
      }
      else
      {
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 & 0x7FFFFFFF, v13) );
        KfLowerIrql(v4);
      }
      v15 = *(_WORD *)(a1 + 18);
      __dmb(0xBu);
      if ( (v15 & 0x20) != 0 )
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v16 = *(_WORD *)(a1 + 18);
          __dmb(0xBu);
        }
        while ( (v16 & 0x20) != 0 );
      }
      KfRaiseIrql(2);
      do
        v17 = __ldrex(v5);
      while ( __strex(v17 | 0x80, v5) );
      __dmb(0xBu);
      if ( v17 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v18 = *v13;
            __dmb(0xBu);
          }
          while ( (v18 & 0x80000000) != 0 );
          do
            v19 = __ldrex(v5);
          while ( __strex(v19 | 0x80, v5) );
          __dmb(0xBu);
        }
        while ( v19 >> 7 );
      }
    }
    while ( (*(_BYTE *)(a1 + 18) & 0x20) != 0 );
  }
  *(_BYTE *)(a1 + 18) |= 0x20u;
  if ( (*(_DWORD *)(a1 + 12) & 0x40000000) == 0 && (*v7 & 0x10) == 0 )
    return sub_54492C();
  __dmb(0xBu);
  v9 = (unsigned int *)(a1 + 12);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 & 0x7FFFFFFF, v9) );
  return a1;
}
