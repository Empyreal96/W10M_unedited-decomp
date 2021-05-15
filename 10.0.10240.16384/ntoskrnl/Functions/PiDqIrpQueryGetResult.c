// PiDqIrpQueryGetResult 
 
int __fastcall PiDqIrpQueryGetResult(int a1, int a2)
{
  int v2; // r4
  int *v3; // r10
  _DWORD *v4; // r6
  unsigned int v5; // r2
  unsigned __int8 *v6; // r5
  int v7; // r0
  int v8; // r8
  unsigned int v9; // r2
  int v10; // r3
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r2
  unsigned __int8 *v19; // r5
  int v20; // r0
  int v21; // r8
  unsigned int v22; // r2
  int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r2
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  unsigned int v29; // r2
  int v30; // r0
  int v31; // r8
  unsigned int v32; // r2
  unsigned int *v33; // r1
  unsigned int v34; // r0
  int v35; // r1
  unsigned int v36; // r0
  unsigned int v37; // r2
  int v38; // r0
  unsigned int v39; // r1
  __int16 v40; // r3
  unsigned int v41; // r2
  unsigned __int8 *v42; // r5
  int v43; // r0
  int v44; // r8
  unsigned int v45; // r2
  unsigned int v46; // r3
  int v47; // r1
  unsigned int v48; // r0
  unsigned int v49; // r2
  int v50; // r0
  __int16 v51; // r3
  int v54; // [sp+10h] [bp-48h]
  int v55; // [sp+14h] [bp-44h] BYREF
  int v56; // [sp+18h] [bp-40h]
  int v57; // [sp+1Ch] [bp-3Ch]
  int *v58; // [sp+20h] [bp-38h]
  _DWORD *v59; // [sp+24h] [bp-34h] BYREF
  _DWORD _28[16]; // [sp+28h] [bp-30h] BYREF

  _28[15] = a2;
  _28[14] = a1;
  v2 = 0;
  v3 = *(int **)(a1 + 96);
  v58 = v3;
  v4 = *(_DWORD **)(v3[7] + 16);
  v59 = v4;
  v57 = v3[4];
  v56 = 0;
  v54 = 0;
  v55 = 0;
  if ( !v4 )
  {
    v2 = -1073741637;
    goto LABEL_88;
  }
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = (unsigned __int8 *)(v4 + 8);
  v7 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v4 + 8, v7, (unsigned int)(v4 + 8));
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = v4[29];
  if ( (v10 & 8) != 0 )
  {
    v2 = -1073741536;
    goto LABEL_18;
  }
  if ( (v10 & 4) == 0 )
    goto LABEL_13;
  if ( (v10 & 1) != 0 )
  {
    v2 = -1073741670;
  }
  else
  {
    if ( (v10 & 0x10) != 0 )
    {
LABEL_13:
      v2 = -1073741637;
      goto LABEL_18;
    }
    v4[29] = v10 | 0x10;
    v56 = 1;
  }
LABEL_18:
  __pld(v6);
  v11 = *(_DWORD *)v6;
  if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
    v12 = 0;
  else
    v12 = v11 - 16;
  if ( (v11 & 2) != 0 )
    goto LABEL_26;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)v6);
  while ( v13 == v11 && __strex(v12, (unsigned int *)v6) );
  if ( v13 != v11 )
LABEL_26:
    ExfReleasePushLock(v4 + 8, v11);
  v14 = KeAbPostRelease((unsigned int)(v4 + 8));
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  if ( v2 < 0 )
    goto LABEL_87;
  v17 = v3[2];
  if ( v17 >= 0x10 )
  {
    if ( v57 == 4653063 )
    {
      ProbeForWrite(*(_DWORD *)(a1 + 60), v17, 4);
      v2 = PiDqQuerySerializeActionQueue(v4, *(_DWORD *)(a1 + 60), v3[2], &v55, &v59);
      if ( v2 >= 0 )
      {
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v18 + 308);
        v19 = (unsigned __int8 *)(v4 + 8);
        v20 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
        v21 = v20;
        do
          v22 = __ldrex(v19);
        while ( __strex(v22 | 1, v19) );
        __dmb(0xBu);
        if ( (v22 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v4 + 8, v20, (unsigned int)(v4 + 8));
        if ( v21 )
          *(_BYTE *)(v21 + 14) |= 1u;
        PiDqQueryGetNextIoctlInfo(v4, v3[2], (unsigned int)v59, _28);
        __pld(v19);
        v23 = *(_DWORD *)v19;
        if ( (*(_DWORD *)v19 & 0xFFFFFFF0) <= 0x10 )
          v24 = 0;
        else
          v24 = v23 - 16;
        if ( (v23 & 2) != 0 )
          goto LABEL_51;
        __dmb(0xBu);
        do
          v25 = __ldrex((unsigned int *)v19);
        while ( v25 == v23 && __strex(v24, (unsigned int *)v19) );
        if ( v25 != v23 )
LABEL_51:
          ExfReleasePushLock(v4 + 8, v23);
        v26 = KeAbPostRelease((unsigned int)(v4 + 8));
        v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v28 = *(_WORD *)(v27 + 0x134) + 1;
        *(_WORD *)(v27 + 308) = v28;
        if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
          KiCheckForKernelApcDelivery(v26);
      }
      v54 = v55;
    }
    else
    {
      if ( !*(_DWORD *)(a1 + 12) )
      {
        v2 = -1073741811;
        goto LABEL_88;
      }
      v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v29 + 308);
      v30 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
      v31 = v30;
      do
        v32 = __ldrex(v6);
      while ( __strex(v32 | 1, v6) );
      __dmb(0xBu);
      if ( (v32 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v4 + 8, v30, (unsigned int)(v4 + 8));
      if ( v31 )
        *(_BYTE *)(v31 + 14) |= 1u;
      if ( !v4[24] && (_DWORD *)v4[25] == v4 + 25 && (*(_DWORD *)(v4[3] + 32) & 1) != 0 )
      {
        __dmb(0xBu);
        v33 = (unsigned int *)(a1 + 56);
        do
          v34 = __ldrex(v33);
        while ( __strex((unsigned int)PiDqIrpCancel, v33) );
        __dmb(0xBu);
        if ( *(_BYTE *)(a1 + 36) )
        {
          v2 = -1073741536;
        }
        else
        {
          v4[23] = a1;
          *(_BYTE *)(*(_DWORD *)(a1 + 96) + 3) |= 1u;
          v2 = 259;
        }
      }
      else
      {
        PiDqQueryGetNextIoctlInfo(v4, v3[2], 0, _28);
        v54 = 16;
      }
      __pld(v6);
      v35 = *(_DWORD *)v6;
      if ( (*(_DWORD *)v6 & 0xFFFFFFF0) <= 0x10 )
        v36 = 0;
      else
        v36 = v35 - 16;
      if ( (v35 & 2) != 0 )
        goto LABEL_82;
      __dmb(0xBu);
      do
        v37 = __ldrex((unsigned int *)v6);
      while ( v37 == v35 && __strex(v36, (unsigned int *)v6) );
      if ( v37 != v35 )
LABEL_82:
        ExfReleasePushLock(v4 + 8, v35);
      v38 = KeAbPostRelease((unsigned int)(v4 + 8));
      v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v40 = *(_WORD *)(v39 + 0x134) + 1;
      *(_WORD *)(v39 + 308) = v40;
      if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
        KiCheckForKernelApcDelivery(v38);
    }
LABEL_87:
    if ( v2 == 259 )
      return v2;
    goto LABEL_88;
  }
  v2 = -1073741789;
LABEL_88:
  if ( v56 )
  {
    v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v41 + 308);
    v42 = (unsigned __int8 *)(v4 + 8);
    v43 = KeAbPreAcquire((unsigned int)(v4 + 8), 0, 0);
    v44 = v43;
    do
      v45 = __ldrex(v42);
    while ( __strex(v45 | 1, v42) );
    __dmb(0xBu);
    if ( (v45 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4 + 8, v43, (unsigned int)(v4 + 8));
    if ( v44 )
      *(_BYTE *)(v44 + 14) |= 1u;
    v46 = v4[29] & 0xFFFFFFEF;
    v4[29] = v46;
    if ( v2 < 0 )
    {
      v4[29] = v46 | 1;
      PiDqQueryFreeActiveData((int)v4);
    }
    __pld(v42);
    v47 = *(_DWORD *)v42;
    if ( (*(_DWORD *)v42 & 0xFFFFFFF0) <= 0x10 )
      v48 = 0;
    else
      v48 = v47 - 16;
    if ( (v47 & 2) != 0 )
      goto LABEL_105;
    __dmb(0xBu);
    do
      v49 = __ldrex((unsigned int *)v42);
    while ( v49 == v47 && __strex(v48, (unsigned int *)v42) );
    if ( v49 != v47 )
LABEL_105:
      ExfReleasePushLock(v4 + 8, v47);
    KeAbPostRelease((unsigned int)(v4 + 8));
    v50 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v51 = *(_WORD *)(v50 + 0x134) + 1;
    *(_WORD *)(v50 + 308) = v51;
    if ( !v51 && *(_DWORD *)(v50 + 100) != v50 + 100 && !*(_WORD *)(v50 + 310) )
      KiCheckForKernelApcDelivery(v50);
  }
  PiDqIrpComplete((_DWORD *)a1, v2, v54, _28);
  return v2;
}
