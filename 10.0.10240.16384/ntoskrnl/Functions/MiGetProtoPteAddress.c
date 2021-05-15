// MiGetProtoPteAddress 
 
int __fastcall MiGetProtoPteAddress(_DWORD *a1, int a2, char a3, unsigned int **a4)
{
  int v5; // r7
  char v7; // lr
  unsigned int *v8; // r4
  unsigned int v9; // r8
  unsigned int v10; // r0
  unsigned int v11; // r5
  int v12; // kr10_4
  int v13; // r3
  int v14; // r1
  unsigned int v16; // r3
  unsigned int v17; // r2
  unsigned int v18; // kr18_4
  unsigned int v19; // r2
  unsigned int *v20; // r0
  unsigned int v21; // r7
  unsigned int v22; // r8
  int v23; // r0
  unsigned int *v24; // r6
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r0
  unsigned int v29; // [sp+Ch] [bp-2Ch]
  unsigned __int64 v30[5]; // [sp+10h] [bp-28h] BYREF

  v5 = a1[3];
  v7 = a3;
  if ( ((a1[7] & 7) != 2 || (*(_DWORD *)(*(_DWORD *)a1[11] + 28) & 0x4000000) == 0)
    && (a1[13] - a1[12]) >> 2 >= (unsigned int)(a2 - v5)
    && (a3 & 8) == 0 )
  {
    *a4 = (unsigned int *)a1[11];
    return a1[12] + 4 * (a2 - v5);
  }
  *a4 = 0;
  v8 = (unsigned int *)a1[11];
  v9 = *v8;
  v12 = ((int)(a1[12] - v8[1]) >> 2) + a2 - v5;
  v10 = (__PAIR64__((int)(a1[12] - v8[1]) >> 31, (int)(a1[12] - v8[1]) >> 2) + (unsigned int)(a2 - v5)) >> 32;
  v11 = v12;
  v13 = *(_DWORD *)(*v8 + 32);
  v29 = *v8;
  v30[0] = __PAIR64__(v10, v12);
  if ( v13 )
  {
    v14 = a1[7];
    if ( (v14 & 0x40000) != 0 )
      return sub_536708();
    v16 = v8[7];
    v17 = 0;
    if ( __PAIR64__(v10, v12) >= v16 )
    {
      do
      {
        v8 = (unsigned int *)v8[2];
        v18 = v11 - v16;
        v10 = (__PAIR64__(v10, v11) - v16) >> 32;
        v11 -= v16;
        ++v17;
        if ( !v8 )
          break;
        v16 = v8[7];
      }
      while ( __PAIR64__(v10, v18) >= v16 );
      if ( v17 > 0x10 && (*(_DWORD *)(v9 + 28) & 0x20) == 0 )
      {
        if ( (v7 & 1) != 0 )
        {
          a1[7] = v14 | 0x40000;
        }
        else
        {
          v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v22 = KeGetCurrentIrql(v10);
          if ( v22 < 2 )
            --*(_WORD *)(v21 + 310);
          v23 = MiTryLockVad(v21, a1);
          if ( v23 == 1 )
          {
            a1[7] |= 0x40000u;
            v24 = a1 + 6;
            *(_BYTE *)(v21 + 968) &= 0x7Fu;
            __dmb(0xBu);
            do
              v25 = __ldrex(v24);
            while ( __strex(v25 - 1, v24) );
            if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
              ExfTryToWakePushLock(v24);
            v23 = KeAbPostRelease((unsigned int)v24);
          }
          if ( v22 < 2 )
          {
            v26 = *(_WORD *)(v21 + 310) + 1;
            *(_WORD *)(v21 + 310) = v26;
            if ( !v26 && *(_DWORD *)(v21 + 100) != v21 + 100 )
              KiCheckForKernelApcDelivery(v23);
          }
          v7 = a3;
          v9 = v29;
        }
      }
    }
    if ( v8 )
    {
      v19 = v8[1];
      *a4 = v8;
      goto LABEL_14;
    }
    return 0;
  }
  v20 = MiLocatePagefileSubsection(v8, (int)v30);
  v8 = v20;
  if ( !v20 )
    return 0;
  *a4 = v20;
  v19 = v20[1];
  if ( !v19 )
    return 0;
  v11 = v30[0];
  v7 = a3;
LABEL_14:
  if ( (*((_WORD *)v8 + 9) & 2) != 0 && (*(_DWORD *)(v9 + 28) & 0x4000000) != 0 && (v7 & 4) == 0 )
  {
    v27 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    v19 = *(_DWORD *)(MiGetSharedProtos(v9, v27, v8) + 16);
  }
  return v19 + 4 * v11;
}
