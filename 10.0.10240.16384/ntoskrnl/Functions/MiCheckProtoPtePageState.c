// MiCheckProtoPtePageState 
 
int __fastcall MiCheckProtoPtePageState(unsigned int a1, _BYTE *a2)
{
  int v2; // r7
  unsigned int v5; // r4
  int v6; // r5
  int v7; // r0
  int v8; // lr
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  int v11; // r3
  int result; // r0
  int v13; // r6
  unsigned int *v14; // r4
  unsigned int *v15; // r2
  unsigned int v16; // r4
  unsigned int *v17; // r7
  unsigned __int8 *v18; // r8
  unsigned int v19; // r1
  __int16 v20; // r3
  __int16 v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int v24; // r2
  unsigned __int8 *v25; // r1
  int v26; // r3
  unsigned int v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r1

  v2 = (a1 >> 10) & 0x3FFFFC;
  while ( 1 )
  {
    do
    {
      v5 = *(_DWORD *)(v2 - 0x40000000);
      if ( (v5 & 2) != 0 )
      {
        if ( (v5 & 0x100) != 0 )
          goto LABEL_42;
      }
      else if ( (v5 & 0x400) != 0 || (v5 & 0x800) == 0 )
      {
        result = 0;
        goto LABEL_43;
      }
    }
    while ( !MI_IS_PFN(v5 >> 12) );
    v6 = MmPfnDatabase + 24 * (v5 >> 12);
    v7 = KfRaiseIrql(2);
    v8 = v7;
    v9 = (unsigned __int8 *)(v6 + 15);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
    {
      v25 = (unsigned __int8 *)(v6 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v26 = *(_DWORD *)(v6 + 12);
          __dmb(0xBu);
        }
        while ( (v26 & 0x80000000) != 0 );
        do
          v27 = __ldrex(v25);
        while ( __strex(v27 | 0x80, v25) );
        __dmb(0xBu);
      }
      while ( v27 >> 7 );
    }
    v11 = *(_DWORD *)(v2 - 0x40000000);
    *a2 = v7;
    if ( v11 != v5 )
      return sub_543E14();
    if ( (v11 & 2) != 0 )
      break;
    if ( (*(_BYTE *)(v6 + 18) & 7u) < 6 )
      goto LABEL_39;
    __dmb(0xBu);
    v30 = (unsigned int *)(v6 + 12);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0x7FFFFFFF, v30) );
    KfLowerIrql(v8);
    MmAccessFault(1, a1, 0, 0);
  }
  if ( (*(_DWORD *)(v6 + 12) & 0x3FFFFFFF) == 1 )
  {
LABEL_39:
    __dmb(0xBu);
    v28 = (unsigned int *)(v6 + 12);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 & 0x7FFFFFFF, v28) );
    KfLowerIrql(v8);
LABEL_42:
    result = 0;
LABEL_43:
    *a2 = 17;
    return result;
  }
  MiAddLockedPageCharge(v6, 1);
  v13 = (unsigned __int8)*a2;
  v14 = (unsigned int *)(*(_DWORD *)(v6 + 4) | 0x80000000);
  if ( (*(_BYTE *)(v6 + 18) & 0x20) != 0 )
  {
    v17 = (unsigned int *)(v6 + 12);
    v18 = (unsigned __int8 *)(v6 + 15);
    do
    {
      __dmb(0xBu);
      if ( v13 == 17 )
      {
        do
          v32 = __ldrex(v17);
        while ( __strex(v32 & 0x7FFFFFFF, v17) );
      }
      else
      {
        do
          v19 = __ldrex(v17);
        while ( __strex(v19 & 0x7FFFFFFF, v17) );
        KfLowerIrql(v13);
      }
      v20 = *(_WORD *)(v6 + 18);
      __dmb(0xBu);
      if ( (v20 & 0x20) != 0 )
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v21 = *(_WORD *)(v6 + 18);
          __dmb(0xBu);
        }
        while ( (v21 & 0x20) != 0 );
      }
      KfRaiseIrql(2);
      do
        v22 = __ldrex(v18);
      while ( __strex(v22 | 0x80, v18) );
      __dmb(0xBu);
      if ( v22 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *v17;
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v18);
          while ( __strex(v24 | 0x80, v18) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
      }
    }
    while ( (*(_BYTE *)(v6 + 18) & 0x20) != 0 );
  }
  *(_BYTE *)(v6 + 18) |= 0x20u;
  if ( (*(_DWORD *)(v6 + 12) & 0x40000000) == 0 && (*v14 & 0x10) == 0 )
    MI_WRITE_VALID_PTE_VOLATILE(v14, 1);
  __dmb(0xBu);
  v15 = (unsigned int *)(v6 + 12);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 & 0x7FFFFFFF, v15) );
  return v6;
}
