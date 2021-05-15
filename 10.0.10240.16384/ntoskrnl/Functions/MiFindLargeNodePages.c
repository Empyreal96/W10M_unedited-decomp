// MiFindLargeNodePages 
 
int __fastcall MiFindLargeNodePages(int a1, unsigned int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r5
  unsigned __int16 *v7; // r4
  unsigned __int16 *v8; // r9
  char v9; // r2
  unsigned int i; // r6
  int v11; // r1
  int v12; // r5
  int v13; // lr
  int v14; // r1
  unsigned int v15; // r8
  unsigned int *v16; // r6
  int v17; // r2
  unsigned int v18; // r0
  int v19; // r2
  unsigned int v20; // r0
  int result; // r0
  int v22; // r4
  int v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r3
  int v26; // r2
  unsigned int v27; // r0
  int v28; // r6
  int v29; // r4
  int v30; // r7
  unsigned __int8 *v31; // r3
  unsigned int v32; // r1
  unsigned __int8 *v33; // r1
  int v34; // r3
  unsigned int v35; // r2
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // [sp+0h] [bp-28h]

  v4 = a2;
  if ( a2 >= (unsigned __int16)KeNumberNodes )
  {
    v4 = *((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C)) + 682);
    v7 = (unsigned __int16 *)(dword_6337E4 + 2 * (unsigned __int16)KeNumberNodes * v4);
    v8 = &v7[(unsigned __int16)KeNumberNodes];
  }
  else
  {
    v7 = 0;
    v8 = 0;
  }
  v9 = byte_6337F5;
  v38 = 0;
  for ( i = v4 << byte_6337F5; ; i = *v7 << byte_6337F5 )
  {
    v11 = i >> v9;
    if ( (a3 & 1) != 0 )
    {
      v12 = MiUnlinkNodeLargePage(a1, v11, 1, 1);
      if ( v12 )
        goto LABEL_7;
    }
    else
    {
      v12 = MiUnlinkNodeLargePage(a1, v11, 1, 0);
      if ( v12 )
        goto LABEL_11;
    }
    v14 = i >> byte_6337F5;
    if ( (a3 & 1) != 0 )
      break;
    v12 = MiUnlinkNodeLargePage(a1, v14, 1, 1);
    if ( v12 )
    {
LABEL_7:
      v13 = 128;
      v38 = 128;
      goto LABEL_12;
    }
LABEL_17:
    if ( !v7 )
      return -1073741801;
    if ( ++v7 == v8 )
      return -1073741801;
    v9 = byte_6337F5;
  }
  v12 = MiUnlinkNodeLargePage(a1, v14, 1, 0);
  if ( !v12 )
    goto LABEL_17;
LABEL_11:
  v13 = 0;
LABEL_12:
  v15 = (v12 - MmPfnDatabase) / 24;
  v16 = (unsigned int *)(dword_634C94 + 4 * (v15 >> 15));
  v17 = (v15 >> 10) & 0x1F;
  LOBYTE(v18) = 1;
  if ( (unsigned int)(v17 + 1) <= 0x20 )
  {
    __dmb(0xBu);
    v19 = 1 << v17;
    do
      v20 = __ldrex(v16);
    while ( __strex(v20 | v19, v16) );
    goto LABEL_30;
  }
  if ( !v17 )
    goto LABEL_28;
  v22 = 32 - v17;
  __dmb(0xBu);
  v23 = ((1 << (32 - v17)) - 1) << v17;
  do
    v24 = __ldrex(v16);
  while ( __strex(v24 | v23, v16) );
  __dmb(0xBu);
  v18 = 1 - v22;
  ++v16;
  if ( (unsigned int)(1 - v22) >= 0x20 )
  {
    v25 = v18 >> 5;
    do
    {
      v18 -= 32;
      *v16++ = -1;
      --v25;
    }
    while ( v25 );
  }
  if ( v18 )
  {
LABEL_28:
    __dmb(0xBu);
    v26 = (1 << v18) - 1;
    do
      v27 = __ldrex(v16);
    while ( __strex(v27 | v26, v16) );
LABEL_30:
    __dmb(0xBu);
  }
  if ( (a3 & 0x200000) != 0 )
    v28 = 2;
  else
    v28 = 1;
  v29 = 1024;
  do
  {
    *(_DWORD *)(v12 + 8) = v13;
    if ( (a3 & 0x40000000) != 0 )
    {
      v30 = KfRaiseIrql(2);
      v31 = (unsigned __int8 *)(v12 + 15);
      do
        v32 = __ldrex(v31);
      while ( __strex(v32 | 0x80, v31) );
      __dmb(0xBu);
      if ( v32 >> 7 )
      {
        v33 = (unsigned __int8 *)(v12 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v34 = *(_DWORD *)(v12 + 12);
            __dmb(0xBu);
          }
          while ( v34 < 0 );
          do
            v35 = __ldrex(v33);
          while ( __strex(v35 | 0x80, v33) );
          __dmb(0xBu);
        }
        while ( v35 >> 7 );
      }
      *(_DWORD *)(v12 + 20) &= 0xFFF00000;
      *(_BYTE *)(v12 + 18) = *(_BYTE *)(v12 + 18) & 0xF8 | 5;
      __dmb(0xBu);
      v36 = (unsigned int *)(v12 + 12);
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 & 0x7FFFFFFF, v36) );
      KfLowerIrql(v30);
    }
    else
    {
      *(_DWORD *)v12 = 0;
      *(_DWORD *)(v12 + 20) &= 0xF7FFFFFF;
      MiSetPfnOwnedAndActive(v12, -4, 1, v28);
    }
    v13 = v38;
    v12 += 24;
    --v29;
  }
  while ( v29 );
  result = 0;
  *a4 = v15;
  return result;
}
