// KdpSearchPhysicalPage 
 
int __fastcall KdpSearchPhysicalPage(unsigned int a1, unsigned int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v5; // r1
  int v6; // r4
  int v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r3
  int v10; // r3
  int v11; // r3
  int v12; // r3
  char v13; // r3
  BOOL v14; // r9
  char v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r4
  unsigned int v18; // r6
  unsigned int v19; // r3
  int v20; // r2
  int v21; // r1
  unsigned int v22; // r3
  int v23; // r3
  int v24; // r3
  int v25; // r3
  unsigned int v28; // [sp+Ch] [bp-34h] BYREF
  unsigned int v29; // [sp+10h] [bp-30h]
  int v30; // [sp+14h] [bp-2Ch]
  unsigned int v31; // [sp+18h] [bp-28h] BYREF
  unsigned int v32; // [sp+1Ch] [bp-24h]
  int v33; // [sp+20h] [bp-20h]

  v29 = a2;
  v30 = a4;
  v5 = a1;
  v6 = KdpSearchPfnValue;
  v32 = a3;
  v7 = 0;
  __dmb(0xBu);
  if ( v6 )
  {
    v32 = a5 | 2;
    v8 = 0;
    while ( 1 )
    {
      if ( MmDbgCopyMemory(v8 + (v5 << 12), (v8 + __PAIR64__(v5 >> 20, v5 << 12)) >> 32, (int)&v31, 4u, 4u) >= 0
        && v31 >> 12 == v29 )
      {
        v9 = KdpSearchPageHitIndex;
        __dmb(0xBu);
        if ( v9 < 0x1000 )
        {
          v10 = KdpSearchPageHitIndex;
          __dmb(0xBu);
          KdpSearchPageHits[v10] = a1;
          v11 = KdpSearchPageHitIndex;
          __dmb(0xBu);
          KdpSearchPageHitOffsets[v11] = v8;
          v12 = KdpSearchPageHitIndex + 1;
          __dmb(0xBu);
          KdpSearchPageHitIndex = v12;
        }
        if ( (v30 & 1) == 0 )
          break;
      }
      v8 += 4;
      if ( v8 >= 0x1000 )
        return v7;
      v5 = a1;
    }
    return 1;
  }
  v28 = 0;
  v13 = KdpSearchInProgress;
  __dmb(0xBu);
  v14 = (v13 & 2) != 0;
  v15 = KdpSearchInProgress;
  __dmb(0xBu);
  if ( (v15 & 0x3C) == 0 )
  {
    v17 = 4;
LABEL_14:
    v18 = 0;
    v33 = a5 | 2;
    while ( 1 )
    {
      if ( MmDbgCopyMemory(v18 + (v5 << 12), (v18 + __PAIR64__(v5 >> 20, v5 << 12)) >> 32, (int)&v28, v17, 0) >= 0 )
      {
        if ( v28 >= v29 && v28 <= v32 )
          goto LABEL_24;
        if ( !v14 )
        {
          v19 = v28 ^ v29;
          v20 = 0;
          v21 = 32;
          do
          {
            if ( (v19 & 1) != 0 )
              ++v20;
            v19 >>= 1;
            --v21;
          }
          while ( v21 );
          if ( v20 == 1 )
          {
LABEL_24:
            v22 = KdpSearchPageHitIndex;
            __dmb(0xBu);
            if ( v22 < 0x1000 )
            {
              v23 = KdpSearchPageHitIndex;
              __dmb(0xBu);
              KdpSearchPageHits[v23] = a1;
              v24 = KdpSearchPageHitIndex;
              __dmb(0xBu);
              KdpSearchPageHitOffsets[v24] = v18;
              v25 = KdpSearchPageHitIndex + 1;
              __dmb(0xBu);
              KdpSearchPageHitIndex = v25;
            }
            if ( (v30 & 1) == 0 )
              return 1;
          }
        }
      }
      v18 += v17;
      if ( v18 >= 0x1000 )
        return v7;
      v5 = a1;
    }
  }
  v16 = KdpSearchInProgress;
  __dmb(0xBu);
  v17 = (v16 >> 2) & 0xF;
  if ( v17 <= 4 )
    goto LABEL_14;
  return 0;
}
