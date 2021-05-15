// MiReplenishBitMap 
 
int __fastcall MiReplenishBitMap(unsigned int *a1, int a2, int a3)
{
  int v3; // r8
  unsigned int *v4; // r10
  unsigned int v5; // r4
  unsigned int v6; // r7
  unsigned int v7; // r1
  int v8; // r3
  unsigned int v9; // r5
  unsigned int v10; // r6
  int v11; // r1
  unsigned int *v12; // r5
  unsigned int v13; // r0
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r4
  int v17; // r3
  unsigned int v18; // r5
  unsigned int v19; // r9
  unsigned int v20; // r6
  int v21; // r8
  unsigned int v22; // lr
  unsigned int v23; // r2
  int *v24; // r1
  int *v25; // r0
  int *v26; // r1
  int v27; // t1
  int v28; // r1
  int v31; // r3
  unsigned int v32; // r2
  int *v33; // r0
  int *v34; // r5
  int *v35; // r0
  int v36; // t1
  int v37; // r4
  int v38; // r0
  unsigned int v39; // r1
  int v40; // r2
  unsigned int v41; // r0
  unsigned int v42; // r3
  int v43; // t1
  int v44; // r9
  unsigned int v45; // r3
  unsigned int v46; // r6
  unsigned int v47; // r4
  unsigned int v48; // r0
  unsigned int v49; // r1
  unsigned int v50; // r2
  int *v51; // r5
  int *v52; // r7
  int v53; // r3
  int v54; // r3
  unsigned int v55; // r3
  int *v56; // r5
  int v57; // t1
  int v58; // r0
  unsigned int *v59; // [sp+8h] [bp-C8h]
  int v61; // [sp+10h] [bp-C0h]
  unsigned int v62; // [sp+14h] [bp-BCh]
  int v63; // [sp+18h] [bp-B8h] BYREF
  char v64; // [sp+1Ch] [bp-B4h]
  char v65; // [sp+1Dh] [bp-B3h]
  int v66; // [sp+20h] [bp-B0h]
  int v67; // [sp+24h] [bp-ACh]
  int v68; // [sp+28h] [bp-A8h]
  int v69; // [sp+2Ch] [bp-A4h]

  v59 = a1;
  v61 = 0;
  v3 = a2;
  v4 = a1;
  if ( a3 != 1 )
    goto LABEL_2;
  v67 = 0;
  v68 = 0;
  v63 = 0;
  v64 = 0;
  v65 = 0;
  v66 = 33;
  v69 = 0;
  __dmb(0xFu);
  v44 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  while ( 1 )
  {
    v45 = v59[2];
    v46 = *(_DWORD *)(v45 + 4 * v3);
    v47 = v45 + 4 * v3;
    if ( (v46 & 4) != 0 )
      v48 = 1;
    else
      v48 = *(_DWORD *)(v47 + 4) >> 13;
    v49 = v3 + v48 - 1;
    if ( v49 >= *v59 )
LABEL_95:
      JUMPOUT(0x51711C);
    if ( v48 <= 1 )
    {
      if ( v48 != 1 )
        goto LABEL_95;
      v53 = (*(unsigned __int8 *)((v3 >> 3) + v59[1]) >> (v3 & 7)) & 1;
      goto LABEL_68;
    }
    v50 = v59[1];
    v51 = (int *)(v50 + 4 * ((unsigned int)v3 >> 5));
    v52 = (int *)(v50 + 4 * (v49 >> 5));
    if ( v51 == v52 )
    {
      if ( (*v51 & (0xFFFFFFFF >> (32 - v48) << (v3 & 0x1F))) != 0xFFFFFFFF >> (32 - v48) << (v3 & 0x1F) )
        goto LABEL_87;
      v53 = 1;
      goto LABEL_68;
    }
    v57 = *v51;
    v56 = v51 + 1;
    if ( (v57 & (-1 << (v3 & 0x1F))) != -1 << (v3 & 0x1F) )
      goto LABEL_95;
    if ( v56 != v52 )
      return sub_51710C();
    if ( (*v56 & (0xFFFFFFFF >> (31 - (v49 & 0x1F)))) != 0xFFFFFFFF >> (31 - (v49 & 0x1F)) )
    {
LABEL_87:
      v53 = 0;
      goto LABEL_68;
    }
    v53 = 1;
LABEL_68:
    if ( !v53 )
      goto LABEL_95;
    MiInsertTbFlushEntry(&v63, v47 << 10, v48);
    if ( MiFlushTbListEarly(&v63, 1) != 1
      || (__dmb(0xFu), v54 = KiTbFlushTimeStamp, __dmb(0xBu), v55 = (v54 - v44) & 0xFFFFF, v55 <= 2)
      && ((v44 & 1) != 0 || v55 < 2) )
    {
      v3 = v46 >> 13;
      if ( v46 >> 13 )
        continue;
    }
    if ( v67 )
      MiFlushTbList(&v63);
    v4 = v59;
    v3 = a2;
    while ( 1 )
    {
LABEL_2:
      v5 = v4[2] + 4 * v3;
      v62 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 4) != 0 )
        v6 = 1;
      else
        v6 = *(_DWORD *)(v5 + 4) >> 13;
      v7 = v3 + v6 - 1;
      if ( v7 >= *v4 )
        goto LABEL_94;
      if ( v6 > 1 )
      {
        v32 = v4[1];
        v33 = (int *)(v32 + 4 * ((unsigned int)v3 >> 5));
        v34 = (int *)(v32 + 4 * (v7 >> 5));
        if ( v33 == v34 )
        {
          if ( (*v33 & (0xFFFFFFFF >> (32 - v6) << (v3 & 0x1F))) == 0xFFFFFFFF >> (32 - v6) << (v3 & 0x1F) )
          {
            v8 = 1;
            goto LABEL_8;
          }
        }
        else
        {
          v36 = *v33;
          v35 = v33 + 1;
          if ( (v36 & (-1 << (v3 & 0x1F))) != -1 << (v3 & 0x1F) )
            goto LABEL_94;
          if ( v35 != v34 )
          {
            while ( 1 )
            {
              v43 = *v35++;
              if ( v43 != -1 )
                break;
              if ( v35 == v34 )
                goto LABEL_42;
            }
LABEL_94:
            KeBugCheckEx(218, 1284, v5);
          }
LABEL_42:
          if ( (*v35 & (0xFFFFFFFF >> (31 - (v7 & 0x1F)))) == 0xFFFFFFFF >> (31 - (v7 & 0x1F)) )
          {
            v8 = 1;
            goto LABEL_8;
          }
        }
        v8 = 0;
      }
      else
      {
        if ( v6 != 1 )
          goto LABEL_94;
        v8 = (*(unsigned __int8 *)((v3 >> 3) + v4[1]) >> (v3 & 7)) & 1;
      }
LABEL_8:
      if ( !v8 )
        goto LABEL_94;
      v9 = v5 + 0x40000000;
      v10 = v6;
      do
      {
        if ( v9 > 0x3FFFFF )
        {
          *(_DWORD *)v5 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v5 = 0;
          if ( v5 >= 0xC0300000 && v5 <= 0xC0300FFF )
          {
            v58 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v58, v58 + 4 * (v5 & 0xFFF), 0);
          }
        }
        v5 += 4;
        v9 += 4;
        --v10;
      }
      while ( v10 );
      v11 = v3 & 0x1F;
      v12 = (unsigned int *)(v4[1] + 4 * ((unsigned int)v3 >> 5));
      v13 = v6;
      if ( v11 + v6 > 0x20 )
      {
        if ( (v3 & 0x1F) != 0 )
        {
          v37 = 32 - v11;
          __dmb(0xBu);
          v38 = ~(((1 << (32 - v11)) - 1) << v11);
          do
            v39 = __ldrex(v12);
          while ( __strex(v39 & v38, v12) );
          __dmb(0xBu);
          v13 = v6 - v37;
          ++v12;
        }
        if ( v13 >= 0x20 )
        {
          v42 = v13 >> 5;
          do
          {
            v13 -= 32;
            --v42;
            *v12++ = 0;
          }
          while ( v42 );
        }
        if ( v13 )
        {
          __dmb(0xBu);
          v40 = ~((1 << v13) - 1);
          do
            v41 = __ldrex(v12);
          while ( __strex(v41 & v40, v12) );
          goto LABEL_17;
        }
      }
      else
      {
        if ( v6 != 32 )
        {
          __dmb(0xBu);
          v14 = ~(((1 << v6) - 1) << v11);
          do
            v15 = __ldrex(v12);
          while ( __strex(v15 & v14, v12) );
LABEL_17:
          __dmb(0xBu);
          goto LABEL_18;
        }
        *v12 = 0;
      }
LABEL_18:
      v16 = 1024;
      if ( (v4[3] & 4) != 0 )
        v16 = 64;
      v17 = (v16 + v3 + v6 - 1) & ~(v16 - 1);
      v18 = v3 & ~(v16 - 1);
      v19 = v17 - v18;
      v20 = 0;
      if ( v17 != v18 )
      {
        v21 = v16 - 1;
        do
        {
          v22 = v21 + v18;
          if ( v21 + v18 < *v4 )
          {
            v23 = v4[1];
            v24 = (int *)(v23 + 4 * (v18 >> 5));
            v25 = (int *)(v23 + 4 * (v22 >> 5));
            if ( v24 == v25 )
            {
              if ( (*v24 & (0xFFFFFFFF >> (32 - v16) << (v18 & 0x1F))) == 0 )
                goto LABEL_32;
              goto LABEL_86;
            }
            v27 = *v24;
            v26 = v24 + 1;
            if ( (v27 & (-1 << (v18 & 0x1F))) == 0 )
            {
              while ( v26 != v25 )
              {
                if ( *v26++ )
                  goto LABEL_25;
              }
              if ( (*v26 & (0xFFFFFFFF >> (31 - (v22 & 0x1F)))) == 0 )
              {
LABEL_32:
                v31 = 1;
                goto LABEL_33;
              }
LABEL_86:
              v31 = 0;
LABEL_33:
              if ( v31 == 1 && RtlInterlockedSetClearRun(v4, v18, v16) == 1 )
                MiReturnSystemPtes(v4, v18, v16, 0);
              goto LABEL_25;
            }
          }
LABEL_25:
          v20 += v16;
          v18 += v16;
        }
        while ( v20 < v19 );
      }
      v3 = v62 >> 13;
      v28 = v61 + v6;
      v61 += v6;
      if ( !(v62 >> 13) )
        return v28;
    }
  }
}
