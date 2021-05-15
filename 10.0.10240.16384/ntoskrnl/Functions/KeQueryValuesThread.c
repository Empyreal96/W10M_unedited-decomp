// KeQueryValuesThread 
 
int __fastcall KeQueryValuesThread(int a1, int a2)
{
  char v4; // r7
  int v5; // r10
  unsigned int *v6; // lr
  unsigned int v7; // r2
  _DWORD *v8; // r0
  unsigned int *v9; // r1
  int v10; // r6
  unsigned int v11; // r3
  int result; // r0
  int v13; // r3
  unsigned int *v14; // r7
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r3
  unsigned int *v19; // r9
  unsigned int v20; // r2
  unsigned int *v21; // r8
  unsigned int v22; // r2
  _DWORD *v23; // [sp+4h] [bp-24h]
  int v24; // [sp+4h] [bp-24h]

  *(_DWORD *)a2 = 0;
  v4 = 0;
  v5 = KfRaiseIrql(2);
  v6 = (unsigned int *)(a1 + 44);
  while ( 1 )
  {
    do
      v7 = __ldrex(v6);
    while ( __strex(1u, v6) );
    __dmb(0xBu);
    if ( !v7 )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v6 );
  }
  if ( *(_UNKNOWN **)(a1 + 336) == &KiInitialProcess )
  {
    LOBYTE(v10) = *(_BYTE *)(a1 + 132);
    *(_BYTE *)(a2 + 6) = 1;
    goto LABEL_14;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = 0;
          v9 = 0;
          v10 = *(unsigned __int8 *)(a1 + 132);
          if ( v10 == 5 )
          {
            v11 = *(_BYTE *)(a1 + 72) & 7;
            if ( v11 == 1 || v11 >= 3 && v11 <= 6 )
              goto LABEL_7;
            v10 = 2;
            goto LABEL_17;
          }
          if ( v10 != 2 )
            break;
LABEL_17:
          v13 = *(_DWORD *)(a1 + 328);
          if ( (v13 & 0x80000000) == 0 )
          {
            v8 = *(&KiProcessorBlock + v13);
            v23 = v8 + 6;
            v14 = v8 + 6;
            while ( 1 )
            {
              do
                v15 = __ldrex(v14);
              while ( __strex(1u, v14) );
              __dmb(0xBu);
              if ( !v15 )
                break;
              do
              {
                __dmb(0xAu);
                __yield();
              }
              while ( *v14 );
            }
            if ( a1 == v8[1] )
              goto LABEL_7;
            goto LABEL_22;
          }
        }
        if ( v10 == 1 )
          break;
        if ( v10 != 3 )
          goto LABEL_7;
        v18 = *(_DWORD *)(a1 + 328);
        if ( (v18 & 0x80000000) == 0 )
        {
          v8 = *(&KiProcessorBlock + v18);
          v23 = v8 + 6;
          v19 = v8 + 6;
          while ( 1 )
          {
            do
              v20 = __ldrex(v19);
            while ( __strex(1u, v19) );
            __dmb(0xBu);
            if ( !v20 )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
            }
            while ( *v19 );
          }
          if ( a1 == v8[2] )
            goto LABEL_7;
          if ( *(_BYTE *)(a1 + 132) == 3 && *(_DWORD *)(a1 + 328) == v18 )
            sub_52F45C();
LABEL_22:
          __dmb(0xBu);
          *v23 = 0;
        }
      }
      v16 = *(_DWORD *)(a1 + 328);
      v24 = v16;
      if ( (v16 & 0x80000000) != 0 )
        break;
      v8 = *(&KiProcessorBlock + v16);
      v21 = v8 + 6;
      while ( 1 )
      {
        do
          v22 = __ldrex(v21);
        while ( __strex(1u, v21) );
        __dmb(0xBu);
        if ( !v22 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v21 );
      }
      if ( *(_BYTE *)(a1 + 132) == 1 && *(_DWORD *)(a1 + 328) == v24 )
        goto LABEL_7;
      __dmb(0xBu);
      v8[6] = 0;
    }
    v9 = (unsigned int *)*((_DWORD *)*(&KiProcessorBlock + v16) + 865);
    while ( 1 )
    {
      do
        v17 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( !v17 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v9 );
    }
    if ( *(_BYTE *)(a1 + 132) == 1 && *(_DWORD *)(a1 + 328) == v16 )
      break;
    __dmb(0xBu);
    *v9 = 0;
  }
  v8 = 0;
LABEL_7:
  *(_DWORD *)a2 = *(_DWORD *)(a1 + 304);
  if ( v8 )
  {
    __dmb(0xBu);
    v8[6] = 0;
  }
  if ( v9 )
  {
    __dmb(0xBu);
    *v9 = 0;
  }
  v4 = *(_BYTE *)(a1 + 395);
  *(_BYTE *)(a2 + 6) = *(_BYTE *)(a1 + 123);
  if ( v10 == 5 && (*(_BYTE *)(a1 + 72) & 7) == 4 )
    v4 = 5;
LABEL_14:
  *(_BYTE *)(a2 + 7) = *(_BYTE *)(a1 + 347);
  __dmb(0xBu);
  *v6 = 0;
  result = KfLowerIrql(v5);
  *(_BYTE *)(a2 + 5) = v4;
  *(_BYTE *)(a2 + 4) = v10;
  return result;
}
