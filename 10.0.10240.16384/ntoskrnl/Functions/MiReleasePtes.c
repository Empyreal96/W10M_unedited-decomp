// MiReleasePtes 
 
int __fastcall MiReleasePtes(int *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // r7
  int *v4; // r6
  unsigned int v5; // r4
  int result; // r0
  unsigned int v7; // lr
  int v8; // r9
  unsigned int v9; // r1
  unsigned int v10; // r3
  int v11; // r0
  int v12; // r3
  unsigned int v13; // r5
  unsigned int v14; // r4
  int v15; // r2
  int *v16; // r0
  int *v17; // r5
  int *v18; // r0
  int v19; // r3
  int v20; // r3
  unsigned int v21; // r5
  unsigned int v22; // r10
  int v23; // r6
  unsigned int v24; // r8
  int v25; // r0
  unsigned int *v26; // r5
  unsigned int v27; // r1
  int v28; // r4
  int v29; // r0
  unsigned int v30; // r1
  unsigned int v31; // r3
  unsigned int v32; // r4
  int v33; // r0
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r4
  int v37; // t1
  int v38; // r0
  int v39; // r0
  int v40; // r3
  int v41; // [sp+8h] [bp-D0h]
  unsigned int v42; // [sp+Ch] [bp-CCh]
  unsigned int v43; // [sp+10h] [bp-C8h]
  int v44; // [sp+14h] [bp-C4h]
  int v46; // [sp+20h] [bp-B8h] BYREF
  char v47; // [sp+24h] [bp-B4h]
  char v48; // [sp+25h] [bp-B3h]
  int v49; // [sp+28h] [bp-B0h]
  int v50; // [sp+2Ch] [bp-ACh]
  int v51; // [sp+30h] [bp-A8h]
  int v52; // [sp+34h] [bp-A4h]

  v3 = a3;
  v4 = a1;
  v5 = a2;
  if ( a1 == &dword_634D58 && (dword_681258 & 2) != 0 )
    return sub_54249C();
  v7 = a3;
  v43 = a3;
  v8 = (int)(a2 - a1[2]) >> 2;
  v42 = v8;
  if ( (a1[3] & 4) != 0 )
  {
    v8 = (unsigned int)v8 >> 4;
    v7 = a3 >> 4;
    v42 = v8;
    v43 = a3 >> 4;
  }
  if ( a3 < 0x400 || a1 != &dword_634D58 )
  {
    v9 = v7 + v8 - 1;
    v10 = *a1;
    v11 = 0;
    v41 = 0;
    if ( v9 >= v10 )
      goto LABEL_76;
    if ( v7 <= 1 )
    {
      if ( v7 != 1 )
        goto LABEL_76;
      v12 = (*(unsigned __int8 *)((v8 >> 3) + v4[1]) >> (v8 & 7)) & 1;
      goto LABEL_11;
    }
    v15 = v4[1];
    v16 = (int *)(v15 + 4 * ((unsigned int)v8 >> 5));
    v17 = (int *)(v15 + 4 * (v9 >> 5));
    if ( v16 == v17 )
    {
      if ( (*v16 & (0xFFFFFFFF >> (32 - v7) << (v8 & 0x1F))) == 0xFFFFFFFF >> (32 - v7) << (v8 & 0x1F) )
      {
        v12 = 1;
LABEL_25:
        v11 = 0;
        goto LABEL_11;
      }
    }
    else
    {
      if ( (*v16 & (-1 << (v8 & 0x1F))) != -1 << (v8 & 0x1F) )
        goto LABEL_76;
      v18 = v16 + 1;
      while ( v18 != v17 )
      {
        v37 = *v18++;
        if ( v37 != -1 )
          goto LABEL_76;
      }
      if ( (*v18 & (0xFFFFFFFF >> (31 - (v9 & 0x1F)))) == 0xFFFFFFFF >> (31 - (v9 & 0x1F)) )
      {
        v12 = 1;
        v11 = 0;
LABEL_11:
        if ( v12 )
          goto LABEL_12;
LABEL_76:
        KeBugCheckEx(218, 770, v5 << 10);
      }
    }
    v12 = 0;
    goto LABEL_25;
  }
  v11 = 1;
  v41 = 1;
LABEL_12:
  if ( v3 )
  {
    v13 = v3;
    do
    {
      if ( v5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v5 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v5 = 0;
        if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
        {
          v38 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v38, (_DWORD *)(v38 + 4 * (v5 & 0xFFF)), 0);
        }
      }
      v5 += 4;
      --v13;
    }
    while ( v13 );
    v7 = v43;
    v11 = v41;
  }
  v14 = v5 - 4 * v3;
  if ( v11 )
  {
    v24 = v42;
    goto LABEL_53;
  }
  if ( (v4[3] & 1) == 0 || (result = MiInsertCachedPte(v4, v14, v3), result != 1) )
  {
    __dmb(0xFu);
    v19 = KiTbFlushTimeStamp;
    __dmb(0xBu);
    v20 = v19 << 12;
    v44 = v20;
    if ( v3 )
    {
      v21 = v14 + 0x40000000;
      v22 = v3;
      v23 = v20;
      do
      {
        if ( v21 > 0x3FFFFF )
        {
          *(_DWORD *)v14 = v23;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v14 = v23;
          if ( v14 >= 0xC0300000 && v14 <= 0xC0300FFF )
          {
            v39 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v39, (_DWORD *)(v39 + 4 * (v14 & 0xFFF)), v23);
          }
        }
        v14 += 4;
        v21 += 4;
        --v22;
      }
      while ( v22 );
      v20 = v44;
      v4 = a1;
    }
    if ( (v20 & 0xFFFFF000) == 0 )
    {
      if ( (v4[3] & 2) != 0 )
        v40 = 0;
      else
        v40 = 2;
      v46 = v40;
      v47 = 0;
      v48 = 0;
      v51 = 0;
      v49 = 33;
      v50 = 0;
      v52 = 0;
      MiInsertTbFlushEntry(&v46, (v14 - 4 * v3) << 10, v3);
      MiFlushTbList(&v46);
    }
    v24 = v42;
    v7 = v43;
    v25 = v42 & 0x1F;
    v26 = (unsigned int *)(v4[1] + 4 * (v42 >> 5));
    v27 = v43;
    if ( v25 + v43 > 0x20 )
    {
      if ( (v42 & 0x1F) != 0 )
      {
        v28 = 32 - v25;
        __dmb(0xBu);
        v29 = ~(((1 << (32 - v25)) - 1) << v25);
        do
          v30 = __ldrex(v26);
        while ( __strex(v30 & v29, v26) );
        __dmb(0xBu);
        v27 = v43 - v28;
        ++v26;
      }
      if ( v27 >= 0x20 )
      {
        v31 = v27 >> 5;
        do
        {
          v27 -= 32;
          --v31;
          *v26++ = 0;
        }
        while ( v31 );
      }
      if ( !v27 )
        goto LABEL_53;
      __dmb(0xBu);
      do
        v32 = __ldrex(v26);
      while ( __strex(v32 & ~((1 << v27) - 1), v26) );
      goto LABEL_52;
    }
    if ( v43 != 32 )
    {
      __dmb(0xBu);
      v33 = ~(((1 << v43) - 1) << v25);
      do
        v34 = __ldrex(v26);
      while ( __strex(v34 & v33, v26) );
LABEL_52:
      __dmb(0xBu);
      goto LABEL_53;
    }
    *v26 = 0;
LABEL_53:
    v35 = (unsigned int *)(v4 + 12);
    do
      v36 = __ldrex(v35);
    while ( __strex(v36 + v7, v35) );
    if ( v41 == 1 )
      result = MiReturnSystemPtes(v4, v24, (v3 + 1023) & 0xFFFFFC00, 1);
    else
      result = MiAttemptCoalesce(v4, v24, v7);
  }
  return result;
}
