// MiInitializeTbFlushing 
 
int MiInitializeTbFlushing()
{
  int result; // r0
  int *v1; // r4
  int v2; // r7
  int v3; // r6
  int v4; // r8
  unsigned int i; // r7
  unsigned int v6; // r9
  unsigned int v7; // r10
  unsigned int v8; // r8
  int v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r4
  int v12; // r6
  int v13; // r1
  __int64 v14; // r0
  unsigned int v15; // kr00_4
  int v16; // r1
  int v17; // r6
  unsigned int v18; // r2
  int v19; // r4
  __int64 v20; // r0
  unsigned int v21; // kr18_4
  int v22; // r3
  int v23; // [sp+0h] [bp-E8h]
  unsigned int v24; // [sp+4h] [bp-E4h]
  unsigned int v25; // [sp+8h] [bp-E0h]
  unsigned __int64 v26; // [sp+Ch] [bp-DCh]
  int v27; // [sp+14h] [bp-D4h]
  int v28; // [sp+18h] [bp-D0h]
  __int64 v29; // [sp+1Ch] [bp-CCh]
  __int64 v30; // [sp+24h] [bp-C4h]
  int v31; // [sp+30h] [bp-B8h] BYREF
  char v32; // [sp+34h] [bp-B4h]
  char v33; // [sp+35h] [bp-B3h]
  int v34; // [sp+38h] [bp-B0h]
  int v35; // [sp+3Ch] [bp-ACh]
  int v36; // [sp+40h] [bp-A8h]
  int v37; // [sp+44h] [bp-A4h]

  v29 = 0i64;
  v26 = 0i64;
  result = MiReservePtes(&dword_634D58, 0x1000u);
  v1 = (int *)result;
  v25 = result;
  if ( result )
  {
    v35 = 0;
    v36 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 33;
    v37 = 0;
    v2 = 4096;
    v3 = result << 10;
    v4 = dword_681114 & 0xFEC | (dword_6348F4 << 12) | MiDetermineUserGlobalPteMask(result) | 0x13;
    do
    {
      if ( (unsigned int)v1 >= 0xC0000000 )
        return sub_969E28(2, 4095, 1070596096);
      *v1 = v4;
      v3 += 4096;
      ++v1;
      --v2;
    }
    while ( v2 );
    v23 = 0;
    v27 = 0;
    for ( i = 0; i < 0x1000; ++i )
    {
      v24 = 0;
      v6 = 0;
      v7 = 0;
      v8 = 0;
      v28 = 4;
      do
      {
        v9 = ReadTimeStampCounter();
        v11 = v10;
        v12 = v9;
        __dmb(0xFu);
        if ( i )
        {
          MiInsertTbFlushEntry((int)&v31, v25 << 10, i, 0);
          MiFlushTbList((unsigned int)&v31, v13);
        }
        else
        {
          KeFlushTb(0, 1);
        }
        __dmb(0xFu);
        LODWORD(v14) = ReadTimeStampCounter();
        v15 = v24;
        v24 += v14 - v12;
        v6 = (__PAIR64__(v6, v15) + v14 - __PAIR64__(v11, v12)) >> 32;
        LODWORD(v30) = ReadTimeStampCounter();
        HIDWORD(v30) = v16;
        __dmb(0xFu);
        v17 = 2048;
        v18 = v25 << 10;
        v19 = (v25 << 10) + 16773120;
        do
        {
          v18 += 4096;
          v19 -= 4096;
          --v17;
        }
        while ( v17 );
        __dmb(0xFu);
        LODWORD(v20) = ReadTimeStampCounter();
        v21 = v7 + v20 - v30;
        v8 = (__PAIR64__(v8, v7) + v20 - v30) >> 32;
        v7 = v21;
        --v28;
      }
      while ( v28 );
      if ( i )
      {
        if ( (__PAIR64__(v8, v21) >> 2) + __PAIR64__(v6 >> 2, (v6 << 30) | (v24 >> 2)) >= v26 + v29 )
        {
          v22 = v23;
          if ( !v23 )
            v27 = i - 1;
          ++v23;
          if ( v22 == 2 )
          {
            dword_63382C = v27;
            goto LABEL_22;
          }
        }
        else
        {
          v23 = 0;
        }
      }
      else
      {
        LODWORD(v29) = (v6 << 30) | (v24 >> 2);
        HIDWORD(v29) = v6 >> 2;
        v26 = __PAIR64__(v8, v21) >> 2;
      }
    }
    if ( v23 != 3 )
      dword_63382C = i;
LABEL_22:
    result = MiReleasePtes(&dword_634D58, v25, 0x1000u);
  }
  return result;
}
