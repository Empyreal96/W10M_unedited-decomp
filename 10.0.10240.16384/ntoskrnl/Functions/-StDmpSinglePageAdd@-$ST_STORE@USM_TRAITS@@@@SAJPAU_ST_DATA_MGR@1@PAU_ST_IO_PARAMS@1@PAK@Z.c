// -StDmpSinglePageAdd@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_IO_PARAMS@1@PAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmpSinglePageAdd(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v5; // r1
  int v6; // r3
  int v7; // r0
  int v8; // r3
  int v9; // r3
  unsigned int v10; // r1
  int v11; // r4
  int v12; // r2
  unsigned int *v13; // r4
  unsigned int v14; // r1
  int v15; // r0
  __int16 v16; // r3
  int v17; // r10
  int v18; // r8
  int v19; // r3
  unsigned int v20; // r7
  unsigned int v21; // r2
  unsigned int v22; // r3
  int v23; // r5
  int v24; // r0
  unsigned int v25; // r3
  int v26; // lr
  _DWORD *v27; // r10
  int v28; // r2
  int v29; // r5
  __int64 v30; // kr00_8
  int v31; // r0
  int v32; // r5
  int v33; // r6
  unsigned int v34; // r2
  unsigned __int8 *v35; // r8
  int v36; // r0
  int v37; // r6
  unsigned int v38; // r2
  int v39; // r3
  int v40; // r0
  int v41; // r4
  int v42; // r5
  unsigned int v43; // r2
  unsigned __int8 *v44; // r8
  int v45; // r0
  int v46; // r5
  unsigned int v47; // r2
  int v48; // r3
  int v50; // [sp+0h] [bp-78h]
  int v51; // [sp+4h] [bp-74h]
  unsigned int v52; // [sp+18h] [bp-60h] BYREF
  unsigned int v53; // [sp+20h] [bp-58h] BYREF
  int v54; // [sp+24h] [bp-54h]
  int *v55; // [sp+28h] [bp-50h] BYREF
  int v56; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int v57; // [sp+30h] [bp-48h]
  int v58; // [sp+38h] [bp-40h] BYREF
  int v59; // [sp+3Ch] [bp-3Ch]
  unsigned int v60; // [sp+40h] [bp-38h]
  int v61; // [sp+44h] [bp-34h]
  int v62[12]; // [sp+48h] [bp-30h] BYREF

  v5 = *a2 & 7;
  v6 = *(unsigned __int8 *)(a1 + 72);
  v53 = (unsigned int)a3;
  v7 = v6;
  if ( v6 )
    v8 = 1;
  else
    v8 = 8;
  if ( v8 - 1 < v5 )
  {
    if ( v7 )
      v9 = 1;
    else
      v9 = 8;
    v5 = v9 - 1;
  }
  v11 = ST_STORE<SM_TRAITS>::StDmpSinglePageFindSpace(a1, v5, *a3, &v55, &v56);
  if ( v11 >= 0 )
  {
    v12 = *(_DWORD *)(a1 + 92);
    if ( (*(_BYTE *)(v12 + 3517) & 4) != 0 )
    {
      v13 = (unsigned int *)(v12 + 3520);
      __dmb(0xBu);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 - 1, v13) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock(v13);
      v15 = KeAbPostRelease((unsigned int)v13);
      v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = *(_WORD *)(v10 + 0x136) + 1;
      *(_WORD *)(v10 + 310) = v16;
      if ( !v16 && *(_DWORD *)(v10 + 100) != v10 + 100 )
        KiCheckForKernelApcDelivery(v15);
    }
    if ( (*(_DWORD *)(a1 + 72) & 0x100) != 0 )
    {
      v11 = RtlSparseBitmapCtxPrepareBits(a1 + 160, v10, a2[2] >> 4, 0);
      if ( v11 < 0 )
        goto LABEL_47;
    }
    v17 = a2[1];
    v18 = (int)v55 + *(_DWORD *)(a1 + 112);
    v19 = *(_DWORD *)(a1 + 72);
    if ( (v19 & 0x400) != 0 )
    {
      v20 = 4096;
      v52 = 4096;
    }
    else
    {
      if ( (v19 & 0x8000) != 0 )
      {
        memmove(*(_DWORD *)(a1 + 664) + 4096, a2[1], 0x1000u);
        v17 = *(_DWORD *)(a1 + 664) + 4096;
      }
      v20 = 0;
      v52 = 0;
    }
    v21 = *(_DWORD *)(a1 + 104) - (v56 & *(_DWORD *)(a1 + 96));
    v22 = *(_DWORD *)(a1 + 108);
    v57 = v21;
    if ( v21 >= v22 )
      v23 = v18;
    else
      v23 = *(_DWORD *)(a1 + 664);
    if ( !v20 )
    {
      v24 = RtlCompressBuffer(*(_WORD *)(a1 + 272), v17, 4096, v23, 4096, 4096, (int)&v52, *(_DWORD *)(a1 + 240));
      v21 = v57;
      if ( v24 >= 0 )
      {
        v20 = v52;
      }
      else
      {
        v20 = 4096;
        v52 = 4096;
      }
    }
    if ( v23 != v18 )
    {
      v25 = (*(_DWORD *)(a1 + 112) + v20 + 15) >> 4;
      *(_DWORD *)v53 = v25;
      if ( v25 > v21 )
      {
        v11 = -1073741267;
        goto LABEL_47;
      }
    }
    if ( v20 > 0xFF0 )
    {
      if ( (*(_DWORD *)(a1 + 72) & 0x200) != 0 )
      {
        v11 = -1073740762;
        goto LABEL_47;
      }
      v20 = 4096;
      v52 = 4096;
      v23 = v17;
    }
    if ( v23 != v18 )
    {
      memmove(v18, v23, v20);
      v20 = v52;
    }
    v58 = 0;
    v59 = 0;
    v60 = 0;
    v61 = 0;
    v26 = 0;
    v58 = a2[2];
    v59 = v56;
    if ( v20 < 0x1000 )
    {
      v26 = v20 & 0xFFF;
      v60 = v26;
    }
    v27 = *(_DWORD **)(a1 + 288);
    if ( v27[3] )
    {
      v28 = v27[1];
      v62[0] = v20;
      v29 = (v28 + v20 - 1) & ~(v28 - 1);
      v30 = *(_QWORD *)(a1 + 296) + 1i64;
      *(_QWORD *)(a1 + 296) = v30;
      v61 = v30;
      v60 = (v26 ^ (HIDWORD(v30) << 12)) & 0xFFF000 ^ v26;
      v62[1] = v30;
      v62[2] = (v60 >> 12) & 0xFFF;
      v27[10] = v62;
      v27[11] = 12;
      v31 = v27[4];
      v27[14] = v55;
      v27[15] = 16;
      if ( BCryptEncrypt(v31, v18, v29, (int)(v27 + 8), v50, v51, v18, v29, (int)&v53) < 0 )
      {
        v11 = -1073741174;
LABEL_47:
        v32 = *(_DWORD *)(a1 + 92);
        if ( (*(_BYTE *)(v32 + 3517) & 4) != 0 )
        {
          v33 = 20;
          v53 = -150000;
          v54 = -1;
          while ( *(_DWORD *)(v32 + 3868) && v33 && *(unsigned __int8 *)(v32 + 3518) >= 3u )
          {
            KeDelayExecutionThread(0, 0, &v53);
            --v33;
          }
          v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v34 + 310);
          v35 = (unsigned __int8 *)(v32 + 3520);
          v36 = KeAbPreAcquire(v32 + 3520, 0, 0);
          v37 = v36;
          do
            v38 = __ldrex(v35);
          while ( __strex(v38 | 1, v35) );
          __dmb(0xBu);
          if ( (v38 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v35, v36, (unsigned int)v35);
          if ( v37 )
            *(_BYTE *)(v37 + 14) |= 1u;
          v39 = *(_DWORD *)(v32 + 3528);
          *(_DWORD *)(v32 + 3524) = 1;
          *(_DWORD *)(v32 + 3528) = v39 + 1;
        }
        return v11;
      }
    }
    else if ( *(_BYTE *)(a1 + 72) )
    {
      v40 = RtlComputeCrc32(0, v18, v20);
      *v55 = v40;
    }
    v41 = *(_DWORD *)(a1 + 92);
    if ( (*(_BYTE *)(v41 + 3517) & 4) != 0 )
    {
      v42 = 20;
      v53 = -150000;
      v54 = -1;
      while ( *(_DWORD *)(v41 + 3868) && v42 && *(unsigned __int8 *)(v41 + 3518) >= 3u )
      {
        KeDelayExecutionThread(0, 0, &v53);
        --v42;
      }
      v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v43 + 310);
      v44 = (unsigned __int8 *)(v41 + 3520);
      v45 = KeAbPreAcquire(v41 + 3520, 0, 0);
      v46 = v45;
      do
        v47 = __ldrex(v44);
      while ( __strex(v47 | 1, v44) );
      __dmb(0xBu);
      if ( (v47 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)(v41 + 3520), v45, v41 + 3520);
      if ( v46 )
        *(_BYTE *)(v46 + 14) |= 1u;
      v48 = *(_DWORD *)(v41 + 3528);
      *(_DWORD *)(v41 + 3524) = 1;
      *(_DWORD *)(v41 + 3528) = v48 + 1;
    }
    v11 = ST_STORE<SM_TRAITS>::StDmpSinglePageInsert(a1, a2, &v58);
    if ( v11 >= 0 )
      v11 = 0;
  }
  return v11;
}
