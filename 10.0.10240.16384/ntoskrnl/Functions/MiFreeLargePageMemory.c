// MiFreeLargePageMemory 
 
int __fastcall MiFreeLargePageMemory(unsigned int a1)
{
  unsigned int v1; // r6
  int v2; // r7
  unsigned int v3; // r8
  unsigned int v4; // r5
  unsigned __int8 *v5; // r3
  unsigned int v6; // r1
  unsigned __int8 *v7; // r1
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r2
  char v11; // r3
  int v12; // r3
  int v13; // r1
  char v14; // r2
  int v15; // r3
  char v16; // r1
  unsigned int v17; // r0
  int v18; // r2
  unsigned int v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r4
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int *v25; // r4
  unsigned __int8 *v26; // r1
  unsigned int v27; // r2
  unsigned int v28; // r3
  unsigned int v29; // r1
  unsigned __int8 *v30; // r1
  unsigned int v31; // r2
  int v32; // r3
  int v33; // r2
  int v34; // r3
  unsigned int v36; // [sp+4h] [bp-24h]
  int v37; // [sp+8h] [bp-20h]

  v36 = a1 + 1023;
  v1 = a1 + 1023;
  v2 = 0;
  v3 = 0;
  v4 = MmPfnDatabase + 24 * (a1 + 1023);
  v37 = KfRaiseIrql(2);
  do
  {
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
        while ( (v8 & 0x80000000) != 0 );
        do
          v9 = __ldrex(v7);
        while ( __strex(v9 | 0x80, v7) );
        __dmb(0xBu);
      }
      while ( v9 >> 7 );
    }
    v10 = *(_DWORD *)(v4 + 20) & 0xF7FFFFFF;
    v11 = *(_BYTE *)(v4 + 18);
    *(_DWORD *)(v4 + 20) = v10;
    if ( (v11 & 7) == 5 )
      ++*(_WORD *)(v4 + 16);
    v12 = *(_DWORD *)(v4 + 12);
    if ( (v12 & 0x40000000) == 0 )
      *(_DWORD *)(v4 + 12) = v12 | 0x40000000;
    if ( (v10 & 0x7000000) == 50331648 )
      MiClearPfnImageVerified(v4, 12, v10, 50331648);
    if ( *(_WORD *)(v4 + 16) != 2
      || (v13 = *(unsigned __int8 *)(v4 + 18), (v13 & 0xFFFFFFC0) != 64)
      || (v14 = *(_BYTE *)(v4 + 19), (v14 & 0x40) != 0) )
    {
      if ( !v3 )
      {
        __dmb(0xBu);
        v23 = (unsigned int *)(v4 + 12);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 & 0x7FFFFFFF, v23) );
        v3 = v4;
        v1 = v36;
        v4 = MmPfnDatabase + 24 * v36;
        if ( v4 > v3 )
        {
          v25 = (unsigned int *)(v4 + 12);
          v2 += (v4 - v3 - 1) / 0x18 + 1;
          do
          {
            v26 = (unsigned __int8 *)v25 + 3;
            do
              v27 = __ldrex(v26);
            while ( __strex(v27 | 0x80, v26) );
            while ( 1 )
            {
              __dmb(0xBu);
              if ( !(v27 >> 7) )
                break;
              do
              {
                __dmb(0xAu);
                __yield();
                v28 = *v25;
                __dmb(0xBu);
              }
              while ( (v28 & 0x80000000) != 0 );
              do
                v27 = __ldrex(v26);
              while ( __strex(v27 | 0x80, v26) );
            }
            *(_DWORD *)(v4 + 20) &= 0xFFF00000;
            MiInsertPageInFreeOrZeroedList(v1, 2);
            __dmb(0xBu);
            do
              v29 = __ldrex(v25);
            while ( __strex(v29 & 0x7FFFFFFF, v25) );
            v4 -= 24;
            --v1;
            v25 -= 6;
          }
          while ( v4 > v3 );
        }
        v30 = (unsigned __int8 *)(v4 + 15);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 | 0x80, v30) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v31 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
            v32 = *(_DWORD *)(v4 + 12);
            __dmb(0xBu);
          }
          while ( (v32 & 0x80000000) != 0 );
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 | 0x80, v30) );
        }
      }
LABEL_47:
      v33 = (unsigned __int16)(*(_WORD *)(v4 + 16) - 2);
      v34 = *(_DWORD *)(v4 + 12);
      *(_WORD *)(v4 + 16) = v33;
      *(_DWORD *)(v4 + 12) = v34 & 0xC0000000;
      if ( v33 )
      {
        *(_BYTE *)(v4 + 18) |= 7u;
      }
      else
      {
        MiPfnReferenceCountIsZero(v4, v1);
        ++v2;
      }
      goto LABEL_23;
    }
    if ( v3 )
      goto LABEL_47;
    v15 = *(_DWORD *)(v4 + 12);
    v16 = v13 & 0xEF;
    *(_WORD *)(v4 + 16) = 0;
    v17 = v15 & 0xC0000000;
    LOBYTE(v15) = v14 & 0xF8;
    v18 = *(_DWORD *)(v4 + 20);
    *(_BYTE *)(v4 + 19) = v15;
    *(_DWORD *)(v4 + 12) = v17;
    *(_BYTE *)(v4 + 18) = v16;
    if ( (v18 & 0x7000000) == 0x1000000 )
      *(_DWORD *)(v4 + 20) = v18 & 0xF8FFFFFF;
    v19 = *(_DWORD *)(v4 + 20) & 0xFFF00000 | 0xFFFFE;
    *(_BYTE *)(v4 + 18) = v16 & 0xF8 | 1;
    *(_DWORD *)(v4 + 12) = v17 & 0xBFFFFFFF;
    *(_DWORD *)(v4 + 20) = v19;
    *(_DWORD *)(v4 + 4) = 0;
    if ( v1 == a1 )
    {
      MiInsertLargePageInNodeList(v1, 0x400u, 1, a1);
      v2 = 1024;
    }
LABEL_23:
    __dmb(0xBu);
    v20 = (unsigned int *)(v4 + 12);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 & 0x7FFFFFFF, v20) );
    --v1;
    v4 -= 24;
  }
  while ( v1 >= a1 );
  KfLowerIrql(v37);
  return v2;
}
