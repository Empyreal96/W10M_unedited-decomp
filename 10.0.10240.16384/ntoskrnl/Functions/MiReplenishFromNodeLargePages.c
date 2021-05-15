// MiReplenishFromNodeLargePages 
 
int __fastcall MiReplenishFromNodeLargePages(int a1, char a2, int a3)
{
  int v3; // r4
  int v4; // r2
  int v6; // r6
  int v7; // r7
  int v8; // r8
  int v9; // r4
  int v10; // r6
  unsigned __int8 *v11; // r5
  unsigned int v12; // r2
  char v13; // r3
  unsigned int *v14; // r2
  unsigned int v15; // r0
  unsigned __int8 *v16; // r5
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  int v20; // r3
  unsigned int v21; // r2
  int v22; // [sp+4h] [bp-2Ch]
  int v23; // [sp+8h] [bp-28h]
  int v24; // [sp+Ch] [bp-24h]

  v3 = a3;
  v4 = *(_DWORD *)(a1 + 24) + 104 * a3;
  v22 = v3;
  v23 = a1;
  v24 = v4;
  if ( (a2 & 2) != 0 )
    return sub_54FF54();
  v6 = 0;
  v7 = 0;
  v8 = 1;
  while ( *(_DWORD *)(v4 + 8 * (v8 + 1)) == v4 + 8 * (v8 + 1) )
  {
LABEL_5:
    if ( *(_DWORD *)(v24 + 8 * (v7 + 1)) != v24 + 8 * (v7 + 1) )
    {
      v9 = MiUnlinkNodeLargePage(a1, v3, 0, 0);
      if ( v9 )
      {
        v10 = KfRaiseIrql(2);
        v16 = (unsigned __int8 *)(v9 + 15);
        do
          v17 = __ldrex(v16);
        while ( __strex(v17 | 0x80, v16) );
        __dmb(0xBu);
        if ( v17 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v18 = *(_DWORD *)(v9 + 12);
              __dmb(0xBu);
            }
            while ( (v18 & 0x80000000) != 0 );
            do
              v19 = __ldrex(v16);
            while ( __strex(v19 | 0x80, v16) );
            __dmb(0xBu);
          }
          while ( v19 >> 7 );
        }
        v13 = *(_BYTE *)(v9 + 18);
        goto LABEL_13;
      }
    }
    ++v6;
    v7 += 2;
    v8 += 2;
    if ( v6 > 1 )
      return 0;
    v3 = v22;
    a1 = v23;
    v4 = v24;
  }
  v9 = MiUnlinkNodeLargePage(a1, v3, 0, 1);
  if ( !v9 )
  {
    v3 = v22;
    a1 = v23;
    goto LABEL_5;
  }
  v10 = KfRaiseIrql(2);
  v11 = (unsigned __int8 *)(v9 + 15);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 | 0x80, v11) );
  __dmb(0xBu);
  if ( v12 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v20 = *(_DWORD *)(v9 + 12);
        __dmb(0xBu);
      }
      while ( (v20 & 0x80000000) != 0 );
      do
        v21 = __ldrex(v11);
      while ( __strex(v21 | 0x80, v11) );
      __dmb(0xBu);
    }
    while ( v21 >> 7 );
  }
  v13 = *(_BYTE *)(v9 + 18) ^ 1;
LABEL_13:
  *(_BYTE *)(v9 + 18) ^= v13 & 7;
  __dmb(0xBu);
  v14 = (unsigned int *)(v9 + 12);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 & 0x7FFFFFFF, v14) );
  KfLowerIrql(v10);
  return v9;
}
