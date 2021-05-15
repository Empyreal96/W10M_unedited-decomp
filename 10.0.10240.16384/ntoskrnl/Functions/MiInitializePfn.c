// MiInitializePfn 
 
int __fastcall MiInitializePfn(int a1, int *a2, unsigned int a3, char a4)
{
  int v5; // r3
  int v8; // r9
  int result; // r0
  int v10; // r1
  int v11; // r4
  int v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r2
  int v16; // lr
  unsigned __int8 *v17; // r1
  unsigned int v18; // r2
  unsigned __int8 *v19; // r0
  unsigned int v20; // r2
  unsigned int *v21; // r0
  unsigned int v22; // r4
  int v23; // r3
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned __int8 *v26; // r1
  unsigned int v27; // r2
  int v28; // r3
  unsigned int v29; // r2
  int v30; // r3
  unsigned int v31; // r2
  int v32; // r3
  unsigned int v33; // r2
  int v34; // [sp+0h] [bp-28h]
  int v35; // [sp+4h] [bp-24h]

  v5 = *a2;
  if ( (a4 & 4) != 0 )
    v5 = 32 * a3;
  *(_DWORD *)(a1 + 8) = v5;
  if ( (a4 & 2) != 0 )
    *(_DWORD *)(a1 + 20) |= 0x8000000u;
  v8 = 1;
  if ( a3 == 31 )
    return sub_50DDF0();
  if ( a3 >> 3 == 3 && (a3 & 7) != 0 )
  {
    v8 = 2;
  }
  else if ( a3 >> 3 == 1 )
  {
    v8 = 0;
  }
  *(_WORD *)(a1 + 16) = 1;
  if ( (a4 & 0x20) == 0 )
    *(_BYTE *)(a1 + 18) |= 0x10u;
  v10 = 3 * (*(_DWORD *)((((unsigned int)a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 20) & 0xFFF00000 | ((unsigned __int16)HIWORD(*(_DWORD *)((((unsigned int)a2 >> 10) & 0x3FFFFC)
                                                                                                 - 0x40000000)) >> 4);
  v11 = MmPfnDatabase + 8 * v10;
  v12 = __mrc(15, 0, 13, 0, 3);
  v13 = v12 & 0xFFFFFFC0;
  v14 = *(_DWORD *)((v12 & 0xFFFFFFC0) + 0x3C8);
  if ( (v14 & 0x100) != 0 )
  {
    v34 = (v14 >> 9) & 7;
  }
  else
  {
    v15 = (*(_DWORD *)((v12 & 0xFFFFFFC0) + 0x3C0) >> 12) & 7;
    v34 = (*(_DWORD *)(v13 + 960) >> 12) & 7;
    if ( (*(_DWORD *)(*(_DWORD *)(v13 + 336) + 192) & 0x100000) != 0 )
    {
      if ( v15 < 2 )
        LOBYTE(v34) = v15;
      else
        LOBYTE(v34) = 2;
    }
  }
  v16 = 17;
  v35 = 17;
  if ( (a4 & 1) == 0 )
  {
    if ( (a4 & 0x10) != 0 )
    {
      v17 = (unsigned __int8 *)(a1 + 15);
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 0x80, v17) );
      __dmb(0xBu);
      if ( v18 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v30 = *(_DWORD *)(a1 + 12);
            __dmb(0xBu);
          }
          while ( (v30 & 0x80000000) != 0 );
          do
            v31 = __ldrex(v17);
          while ( __strex(v31 | 0x80, v17) );
          __dmb(0xBu);
        }
        while ( v31 >> 7 );
      }
    }
    else
    {
      v16 = KfRaiseIrql(2);
      v35 = v16;
      v26 = (unsigned __int8 *)(a1 + 15);
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 | 0x80, v26) );
      __dmb(0xBu);
      if ( v27 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v32 = *(_DWORD *)(a1 + 12);
            __dmb(0xBu);
          }
          while ( (v32 & 0x80000000) != 0 );
          do
            v33 = __ldrex(v26);
          while ( __strex(v33 | 0x80, v26) );
          __dmb(0xBu);
        }
        while ( v33 >> 7 );
      }
    }
  }
  v19 = (unsigned __int8 *)(v11 + 15);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 | 0x80, v19) );
  __dmb(0xBu);
  if ( v20 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v28 = *(_DWORD *)(v11 + 12);
        __dmb(0xBu);
      }
      while ( (v28 & 0x80000000) != 0 );
      do
        v29 = __ldrex(v19);
      while ( __strex(v29 | 0x80, v19) );
      __dmb(0xBu);
    }
    while ( v29 >> 7 );
  }
  *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | (*(_DWORD *)(v11 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v21 = (unsigned int *)(v11 + 12);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 & 0x7FFFFFFF, v21) );
  if ( *(unsigned __int8 *)(a1 + 18) >> 6 != v8 )
  {
    MiChangePageAttribute(a1, v8, 1);
    v16 = v35;
  }
  v23 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 4) = a2;
  *(_DWORD *)(a1 + 12) = v23 & 0xC0000000 | 1;
  result = ((unsigned __int8)v34 ^ *(_BYTE *)(a1 + 19)) & 7 ^ *(unsigned __int8 *)(a1 + 19);
  *(_BYTE *)(a1 + 18) = *(_BYTE *)(a1 + 18) & 0xF8 | 6;
  *(_BYTE *)(a1 + 19) = result;
  if ( (a4 & 0x40) != 0 )
    *(_BYTE *)(a1 + 19) = result | 0x20;
  if ( (a4 & 1) == 0 )
  {
    __dmb(0xBu);
    v24 = (unsigned int *)(a1 + 12);
    if ( (a4 & 0x10) != 0 )
    {
      do
        result = __ldrex(v24);
      while ( __strex(result & 0x7FFFFFFF, v24) );
    }
    else
    {
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 & 0x7FFFFFFF, v24) );
      result = KfLowerIrql(v16);
    }
  }
  return result;
}
