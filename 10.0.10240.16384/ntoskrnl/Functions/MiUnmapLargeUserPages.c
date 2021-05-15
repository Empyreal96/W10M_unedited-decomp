// MiUnmapLargeUserPages 
 
int __fastcall MiUnmapLargeUserPages(_DWORD *a1)
{
  int v1; // r1
  unsigned int v2; // r6
  unsigned int v3; // r7
  unsigned int v4; // r5
  unsigned int v5; // r8
  int v6; // r10
  int v7; // r0
  int v8; // r7
  unsigned int v9; // r6
  unsigned int v10; // r8
  int v11; // r0
  unsigned int *v12; // lr
  int v13; // r2
  unsigned int v14; // r0
  int v15; // r2
  unsigned int v16; // r0
  int v17; // r4
  int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r3
  int v21; // r2
  unsigned int v22; // r0
  int v23; // r3
  int v25; // [sp+0h] [bp-C0h]
  unsigned int v26; // [sp+4h] [bp-BCh]
  int v27; // [sp+8h] [bp-B8h] BYREF
  char v28; // [sp+Ch] [bp-B4h]
  char v29; // [sp+Dh] [bp-B3h]
  int v30; // [sp+10h] [bp-B0h]
  int v31; // [sp+14h] [bp-ACh]
  int v32; // [sp+18h] [bp-A8h]
  int v33; // [sp+1Ch] [bp-A4h]

  v1 = 4095;
  v2 = a1[3] << 12;
  v3 = (a1[4] << 12) | 0xFFF;
  v4 = ((v2 >> 20) & 0xFFC) - 1070596096;
  v5 = ((v3 >> 20) & 0xFFC) - 1070596096;
  v26 = v5;
  if ( (a1[7] & 7) == 7 )
  {
    v6 = 0;
  }
  else
  {
    v6 = 1;
    if ( (dword_682604 & 1) != 0 )
    {
      v7 = MiInitPerfMemoryFlags(0, 13);
      MiLogPerfMemoryRangeEvent(
        v2,
        *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
        v7,
        (int)(v3 - v2 + 1) >> 12);
      v1 = 4095;
    }
  }
  v31 = 0;
  v27 = 1;
  v28 = 0;
  v29 = 0;
  v32 = 0;
  v30 = 33;
  v8 = 0xFFFFF;
  v33 = 0;
  v25 = ((v2 >> 20) & 0xFFC) - 1070596096;
  if ( v4 <= v5 )
  {
    v9 = (v2 >> 20) & 0xFFC;
    while ( 1 )
    {
      v10 = *(_DWORD *)v4 >> 12;
      if ( v9 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v4 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v4 = 0;
        if ( v9 <= 0xFFF )
        {
          v11 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v11, (_DWORD *)(v11 + 4 * (v4 & 0xFFF)), 0);
        }
      }
      MiInsertTbFlushEntry((int)&v27, v4 << 20, 1, 1);
      if ( v6 != 1 )
        goto LABEL_27;
      v12 = (unsigned int *)(dword_634C94 + 4 * (v10 >> 15));
      v13 = (v10 >> 10) & 0x1F;
      LOBYTE(v14) = 1;
      if ( (unsigned int)(v13 + 1) > 0x20 )
      {
        if ( v13 )
        {
          v17 = 32 - v13;
          __dmb(0xBu);
          v18 = ~(((1 << (32 - v13)) - 1) << v13);
          do
            v19 = __ldrex(v12);
          while ( __strex(v19 & v18, v12) );
          __dmb(0xBu);
          v14 = 1 - v17;
          ++v12;
          if ( (unsigned int)(1 - v17) >= 0x20 )
          {
            v20 = v14 >> 5;
            do
            {
              v14 -= 32;
              --v20;
              *v12++ = 0;
            }
            while ( v20 );
          }
          if ( !v14 )
            goto LABEL_26;
        }
        __dmb(0xBu);
        v21 = ~((1 << v14) - 1);
        do
          v22 = __ldrex(v12);
        while ( __strex(v22 & v21, v12) );
      }
      else
      {
        __dmb(0xBu);
        v15 = ~(1 << v13);
        do
          v16 = __ldrex(v12);
        while ( __strex(v16 & v15, v12) );
      }
      __dmb(0xBu);
LABEL_26:
      v23 = MmPfnDatabase;
      *(_DWORD *)(MmPfnDatabase + 24 * v10) = v8;
      v8 = v23 + 24 * v10;
LABEL_27:
      v4 += 4;
      v9 += 4;
      if ( v4 > v26 )
      {
        MiInsertTbFlushEntry((int)&v27, v25 << 10, ((int)(v4 - v25 - 4) >> 2) + 1, 0);
        break;
      }
    }
  }
  MiFlushTbList((unsigned int)&v27, v1);
  return v8;
}
