// MiUpdatePrefetchPriority 
 
int __fastcall MiUpdatePrefetchPriority(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v5; // r7
  unsigned int v7; // r4
  int result; // r0
  int v9; // r4
  int v10; // r3
  int v11; // r3
  int v12; // r3
  int v13; // r6
  unsigned __int8 *v14; // r5
  unsigned int v15; // r2
  int v16; // r3
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r0
  int v20; // r0
  int v21; // r5
  unsigned __int8 *v22; // r0
  unsigned int v23; // r2
  int v24; // r3
  unsigned int v25; // r2
  int v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int varg_r1; // [sp+1Ch] [bp+Ch]
  int varg_r3; // [sp+24h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v5 = *(_DWORD *)(a1 + 40) & 7;
  if ( (a3 & 2) == 0 )
  {
    v9 = MmPfnDatabase + 24 * (a3 >> 12);
    v21 = KfRaiseIrql(2);
    v22 = (unsigned __int8 *)(v9 + 15);
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 | 0x80, v22) );
    __dmb(0xBu);
    if ( v23 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v24 = *(_DWORD *)(v9 + 12);
          __dmb(0xBu);
        }
        while ( (v24 & 0x80000000) != 0 );
        do
          v25 = __ldrex(v22);
        while ( __strex(v25 | 0x80, v22) );
        __dmb(0xBu);
      }
      while ( v25 >> 7 );
    }
    v13 = v21;
    if ( (*(_BYTE *)(v9 + 19) & 8) != 0 )
      v26 = 5;
    else
      v26 = *(_BYTE *)(v9 + 19) & 7;
    if ( v26 == v5 )
    {
      __dmb(0xBu);
      v27 = (unsigned int *)(v9 + 12);
      do
        v28 = __ldrex(v27);
      while ( __strex(v28 & 0x7FFFFFFF, v27) );
      v20 = v21;
      return KfLowerIrql(v20);
    }
LABEL_20:
    MiUpdatePfnPriority(v9, v5, 0);
    __dmb(0xBu);
    v18 = (unsigned int *)(v9 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    v20 = v13;
    return KfLowerIrql(v20);
  }
  v7 = a3 >> 12;
  result = MI_IS_PFN(a3 >> 12);
  if ( result )
  {
    result = 3 * v7;
    v9 = MmPfnDatabase + 24 * v7;
    v10 = *(_BYTE *)(v9 + 19) & 7;
    if ( (*(_BYTE *)(v9 + 19) & 8) != 0 )
      v10 = 5;
    if ( v10 != v5 )
    {
      if ( a4 )
      {
        v11 = *(_DWORD *)(a4 + 28);
      }
      else
      {
        if ( !*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 328) && !MEMORY[0xC0402124] )
        {
LABEL_14:
          v13 = KfRaiseIrql(2);
          v14 = (unsigned __int8 *)(v9 + 15);
          do
            v15 = __ldrex(v14);
          while ( __strex(v15 | 0x80, v14) );
          __dmb(0xBu);
          if ( v15 >> 7 )
          {
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v16 = *(_DWORD *)(v9 + 12);
                __dmb(0xBu);
              }
              while ( (v16 & 0x80000000) != 0 );
              do
                v17 = __ldrex(v14);
              while ( __strex(v17 | 0x80, v14) );
              __dmb(0xBu);
            }
            while ( v17 >> 7 );
          }
          goto LABEL_20;
        }
        result = (int)MiLocateAddress(a2);
        if ( !result )
          return result;
        v11 = *(_DWORD *)(result + 28);
      }
      v12 = v11 & 7;
      if ( v12 != 3 && v12 != 1 )
        goto LABEL_14;
    }
  }
  return result;
}
