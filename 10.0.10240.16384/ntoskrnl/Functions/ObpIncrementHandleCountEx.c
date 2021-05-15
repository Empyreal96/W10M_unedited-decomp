// ObpIncrementHandleCountEx 
 
int __fastcall ObpIncrementHandleCountEx(int a1, int a2, int a3, int a4, char a5, __int16 a6, int a7)
{
  int v7; // r6
  char v8; // r10
  int v9; // r7
  unsigned int v10; // r1
  unsigned __int8 *v11; // r9
  int v12; // r0
  unsigned int v13; // r2
  int result; // r0
  char v15; // r2
  char v16; // r3
  int v17; // r0
  unsigned int *v18; // r5
  unsigned int v19; // r10
  int v20; // r8
  int *v21; // r0
  int v22; // r4
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // r8
  char v26; // r3
  unsigned int v27; // r4
  unsigned int *v28; // r5
  unsigned int v29; // r2
  int v30; // r1
  int v31; // r0
  int v32; // r2
  unsigned int v33; // r2
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int *v37; // r2
  unsigned int v38; // r1
  unsigned int v39; // r1
  unsigned int v40; // r2
  int v41; // r0
  unsigned int v42; // r1
  __int16 v43; // r3
  int v44; // r10
  int v45; // r3
  int v46; // r0
  int v47; // r8
  int v48; // r3
  int v49; // r0
  int v50; // r4
  unsigned int v51; // r2
  unsigned int v52; // r2
  int v53; // r0
  unsigned int v54; // r1
  __int16 v55; // r3
  int v56; // r0
  int v57; // r1
  unsigned int v58; // r0
  char v59; // r2
  _DWORD *v60; // r3
  _DWORD *v61; // r3
  int **v62; // r3
  _DWORD *v63; // r3
  int v64; // r1
  unsigned int v65; // r0
  unsigned int v66; // r2
  int v67; // r1
  unsigned int v68; // r0
  int v69; // r1
  unsigned int v70; // r0
  _DWORD *v71; // r6
  unsigned int v72; // r2
  unsigned __int8 *v73; // r4
  int v74; // r0
  int v75; // r5
  unsigned int v76; // r2
  _DWORD *v77; // r2
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r2
  int v81; // r0
  unsigned int v82; // r1
  int v83; // r3
  unsigned int v84; // r2
  int v85; // r0
  unsigned int v86; // r1
  int v87; // r3
  BOOL v89; // [sp+Ch] [bp-5Ch] BYREF
  int v90; // [sp+10h] [bp-58h]
  int v91; // [sp+14h] [bp-54h]
  int v92; // [sp+18h] [bp-50h]
  int v93; // [sp+1Ch] [bp-4Ch] BYREF
  int v94; // [sp+20h] [bp-48h]
  int v95; // [sp+24h] [bp-44h]
  int v96; // [sp+28h] [bp-40h]
  char v97[56]; // [sp+30h] [bp-38h] BYREF

  v7 = a4 - 24;
  v95 = a2;
  v96 = a4;
  v8 = a6;
  v9 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(a4 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(a4 - 12)];
  v92 = a1;
  if ( (a6 & 0x400) != 0 )
    v94 = 1;
  else
    v94 = a5;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 308);
  v11 = (unsigned __int8 *)(a4 - 16);
  v12 = KeAbPreAcquire(a4 - 16, 0, 0);
  do
    v13 = __ldrex(v11);
  while ( __strex(v13 | 1, v11) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    return sub_8003C0(v12);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v15 = *(_BYTE *)(v7 + 15);
  v89 = (v15 & 1) != 0;
  v16 = *(_BYTE *)(v7 + 14);
  v17 = a7;
  v90 = 0;
  v93 = 0;
  if ( (v16 & 8) != 0 )
    v18 = (unsigned int *)(v7 - ObpInfoMaskToOffset[v16 & 0xF]);
  else
    v18 = 0;
  if ( (v15 & 1) == 0 )
    goto LABEL_25;
  *(_BYTE *)(v7 + 15) = v15 & 0xFE;
  if ( !v18 )
  {
    v32 = *(unsigned __int8 *)(v7 + 12);
    v90 = 0;
    v20 = *(_DWORD *)(ObTypeIndexTable[BYTE1(v7) ^ (unsigned __int8)ObHeaderCookie ^ v32] + 84);
    v19 = *(_DWORD *)(ObTypeIndexTable[BYTE1(v7) ^ (unsigned __int8)ObHeaderCookie ^ v32] + 80);
    goto LABEL_16;
  }
  v19 = *v18;
  v91 = v18[1];
  if ( !a7 && (!*(_DWORD *)(v7 + 20) || (v17 = *(_DWORD *)(v7 + 20) & 0xFFFFFFF8) == 0) )
  {
LABEL_15:
    v20 = v91;
LABEL_16:
    v21 = (int *)a3;
    if ( a3 == PsInitialSystemProcess )
    {
      v8 = a6;
      *(_DWORD *)(v7 + 16) = 1;
      goto LABEL_26;
    }
    v22 = *(_DWORD *)(a3 + 332);
    if ( v19 && PspChargeQuota(*(_DWORD *)(a3 + 332), 0, 1, v19) < 0 )
    {
      *(_DWORD *)(v7 + 16) = 0;
    }
    else if ( v20 && PspChargeQuota(v22, 0, 0, v20) < 0 )
    {
      if ( v19 )
        PspReturnQuota(v22, 0, 1, v19);
      *(_DWORD *)(v7 + 16) = 0;
    }
    else
    {
      __dmb(0xBu);
      v23 = (unsigned int *)(v22 + 1024);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 + 1, v23) );
      __dmb(0xBu);
      *(_DWORD *)(v7 + 16) = v22;
      if ( v22 )
      {
        v8 = a6;
LABEL_25:
        v21 = (int *)a3;
LABEL_26:
        v25 = 0;
        goto LABEL_27;
      }
    }
    if ( v18 )
    {
      v56 = v18[3];
      if ( v56 )
        PsReturnSharedPoolQuota(v56, v90, 0);
    }
LABEL_113:
    v25 = -1073741756;
    goto LABEL_114;
  }
  v25 = SeComputeQuotaInformationSize(v17, (unsigned int *)&v93);
  if ( v25 >= 0 )
  {
    v30 = v93;
    v90 = v93;
    if ( v93 )
    {
      v31 = PsChargeSharedPoolQuota(a3, v93, 0);
      v18[3] = v31;
      if ( !v31 )
        goto LABEL_113;
      v30 = v90;
    }
    v18[2] = v30;
    goto LABEL_15;
  }
  v8 = a6;
  v21 = (int *)a3;
LABEL_27:
  if ( v25 < 0 )
    goto LABEL_114;
  if ( (v8 & 0x20) != 0 )
  {
    if ( (v8 & 2) != 0 || (*(_BYTE *)(v7 + 15) & 8) == 0 )
    {
      v25 = -1073741811;
      goto LABEL_114;
    }
    v59 = *(_BYTE *)(v7 + 14);
    if ( (v59 & 0x10) != 0 )
      v60 = (_DWORD *)(v7 - ObpInfoMaskToOffset[v59 & 0x1F]);
    else
      v60 = 0;
    if ( !*v60 && *(_DWORD *)(v7 + 4)
      || ((*(_BYTE *)(v7 + 14) & 0x10) == 0 ? (v61 = 0) : (v61 = (_DWORD *)(v7 - ObpInfoMaskToOffset[v59 & 0x1F])),
          *v61
       && ((*(_BYTE *)(v7 + 14) & 0x10) == 0 ? (v62 = 0) : (v62 = (int **)(v7 - ObpInfoMaskToOffset[v59 & 0x1F])),
           *v62 != v21)) )
    {
      v25 = -1073741790;
      goto LABEL_114;
    }
    *(_DWORD *)(v7 - ObpInfoMaskToOffset[v59 & 0x1F]) = v21;
  }
  else if ( (*(_BYTE *)(v7 + 15) & 8) != 0 )
  {
    v63 = (_DWORD *)((*(_BYTE *)(v7 + 14) & 0x10) != 0 ? v7 - ObpInfoMaskToOffset[*(_BYTE *)(v7 + 14) & 0x1F] : 0);
    if ( *v63 )
    {
      v25 = -1073741790;
      goto LABEL_114;
    }
  }
  if ( v94 && (*(_BYTE *)(v7 + 15) & 4) != 0 )
  {
    v25 = -1073741790;
    goto LABEL_114;
  }
  if ( !*(_DWORD *)(v7 + 4)
    && !v89
    && (*(_BYTE *)(v9 + 42) & 0x10) != 0
    && !*(_DWORD *)(v9 + 92)
    && *(_DWORD *)(v9 + 96) )
  {
    v25 = -1073741823;
    goto LABEL_114;
  }
  v26 = *(_BYTE *)(v9 + 42);
  v27 = 0;
  v89 = 0;
  if ( (v26 & 0x10) != 0 )
  {
    v25 = ObpLockHandleDataBaseEntry(v7, v21, (unsigned int *)&v89);
    if ( v25 >= 0 )
    {
      v27 = v89;
      goto LABEL_35;
    }
LABEL_114:
    __pld(v11);
    v57 = *(_DWORD *)v11;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
      v58 = 0;
    else
      v58 = v57 - 16;
    if ( (v57 & 2) != 0 )
      goto LABEL_183;
    __dmb(0xBu);
    do
      v84 = __ldrex((unsigned int *)v11);
    while ( v84 == v57 && __strex(v58, (unsigned int *)v11) );
    if ( v84 != v57 )
LABEL_183:
      ExfReleasePushLock((_DWORD *)(v7 + 8), v57);
    v85 = KeAbPostRelease(v7 + 8);
    v86 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v87 = (__int16)(*(_WORD *)(v86 + 0x134) + 1);
    *(_WORD *)(v86 + 308) = v87;
    if ( !v87 && *(_DWORD *)(v86 + 100) != v86 + 100 && !*(_WORD *)(v86 + 310) )
      KiCheckForKernelApcDelivery(v85);
    return v25;
  }
LABEL_35:
  __dmb(0xBu);
  v28 = (unsigned int *)(v7 + 4);
  do
    v29 = __ldrex(v28);
  while ( __strex(v29 + 1, v28) );
  __dmb(0xBu);
  if ( !*(_DWORD *)(v9 + 92) )
    goto LABEL_38;
  __pld(v11);
  v64 = *(_DWORD *)v11;
  if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
    v65 = 0;
  else
    v65 = v64 - 16;
  if ( (v64 & 2) != 0 )
    goto LABEL_142;
  __dmb(0xBu);
  do
    v40 = __ldrex((unsigned int *)v11);
  while ( v40 == v64 && __strex(v65, (unsigned int *)v11) );
  if ( v40 != v64 )
LABEL_142:
    ExfReleasePushLock((_DWORD *)(v7 + 8), v64);
  v41 = KeAbPostRelease(v7 + 8);
  v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v43 = *(_WORD *)(v42 + 0x134) + 1;
  *(_WORD *)(v42 + 308) = v43;
  if ( !v43 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
    KiCheckForKernelApcDelivery(v41);
  v44 = 0;
  v45 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v46 = a3;
  v47 = v92;
  if ( a3 != v45 && v92 != 3 )
  {
    v44 = 1;
    KiStackAttachProcess(a3, 0, (int)v97);
    v46 = a3;
  }
  v25 = (*(int (__fastcall **)(int, _DWORD, int, int, int, unsigned int))(v9 + 92))(v47, a5, v46, v96, v95, v27);
  if ( v44 )
    KiUnstackDetachProcess((unsigned int)v97, 0);
  v48 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v48 & 0xFFFFFFC0) + 0x134);
  v49 = KeAbPreAcquire(v7 + 8, 0, 0);
  v50 = v49;
  do
    v51 = __ldrex(v11);
  while ( __strex(v51 | 1, v11) );
  __dmb(0xBu);
  if ( (v51 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v7 + 8), v49, v7 + 8);
  if ( v50 )
    *(_BYTE *)(v50 + 14) |= 1u;
  if ( v25 < 0 )
  {
    if ( (*(_BYTE *)(v9 + 42) & 0x10) != 0 )
      ObpUnlockHandleDatabaseEntry(v7, a3);
    __dmb(0xBu);
    do
      v66 = __ldrex(v28);
    while ( __strex(v66 - 1, v28) );
    __dmb(0xBu);
    __pld(v11);
    v67 = *(_DWORD *)v11;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
      v68 = 0;
    else
      v68 = v67 - 16;
    if ( (v67 & 2) != 0 )
      goto LABEL_149;
    __dmb(0xBu);
    do
      v52 = __ldrex((unsigned int *)v11);
    while ( v52 == v67 && __strex(v68, (unsigned int *)v11) );
    if ( v52 != v67 )
LABEL_149:
      ExfReleasePushLock((_DWORD *)(v7 + 8), v67);
    v53 = KeAbPostRelease(v7 + 8);
    v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v55 = *(_WORD *)(v54 + 0x134) + 1;
    *(_WORD *)(v54 + 308) = v55;
    if ( !v55 && *(_DWORD *)(v54 + 100) != v54 + 100 && !*(_WORD *)(v54 + 310) )
      KiCheckForKernelApcDelivery(v53);
    ObpDeleteNameCheck(v7);
    result = v25;
  }
  else
  {
LABEL_38:
    if ( (*(_BYTE *)(v9 + 42) & 0x10) != 0 )
      ObpIncrementHandleDataBase((int *)v7, a3);
    __pld(v11);
    v69 = *(_DWORD *)v11;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
      v70 = 0;
    else
      v70 = v69 - 16;
    if ( (v69 & 2) != 0 )
      goto LABEL_154;
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)v11);
    while ( v33 == v69 && __strex(v70, (unsigned int *)v11) );
    if ( v33 != v69 )
LABEL_154:
      ExfReleasePushLock((_DWORD *)(v7 + 8), v69);
    v34 = KeAbPostRelease(v7 + 8);
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v36 = *(_WORD *)(v35 + 0x134) + 1;
    *(_WORD *)(v35 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
      KiCheckForKernelApcDelivery(v34);
    if ( !v92 && (*(_BYTE *)(v7 + 14) & 1) != 0 )
    {
      v71 = (_DWORD *)(v7 - 16);
      if ( v71 )
      {
        v72 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v72 + 310);
        v73 = (unsigned __int8 *)(v9 + 128);
        v74 = KeAbPreAcquire(v9 + 128, 0, 0);
        v75 = v74;
        do
          v76 = __ldrex(v73);
        while ( __strex(v76 | 1, v73) );
        __dmb(0xBu);
        if ( (v76 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v9 + 128), v74, v9 + 128);
        if ( v75 )
          *(_BYTE *)(v75 + 14) |= 1u;
        v77 = *(_DWORD **)(v9 + 4);
        *v71 = v9;
        v71[1] = v77;
        if ( *v77 != v9 )
          __fastfail(3u);
        __pld(v73);
        *v77 = v71;
        *(_DWORD *)(v9 + 4) = v71;
        v78 = *(_DWORD *)v73;
        if ( (*(_DWORD *)v73 & 0xFFFFFFF0) <= 0x10 )
          v79 = 0;
        else
          v79 = v78 - 16;
        if ( (v78 & 2) != 0 )
          goto LABEL_173;
        __dmb(0xBu);
        do
          v80 = __ldrex((unsigned int *)v73);
        while ( v80 == v78 && __strex(v79, (unsigned int *)v73) );
        if ( v80 != v78 )
LABEL_173:
          ExfReleasePushLock((_DWORD *)(v9 + 128), v78);
        v81 = KeAbPostRelease(v9 + 128);
        v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v83 = (__int16)(*(_WORD *)(v82 + 0x136) + 1);
        *(_WORD *)(v82 + 310) = v83;
        if ( !v83 && *(_DWORD *)(v82 + 100) != v82 + 100 )
          KiCheckForKernelApcDelivery(v81);
      }
    }
    __dmb(0xBu);
    v37 = (unsigned int *)(v9 + 28);
    do
    {
      v38 = __ldrex(v37);
      v39 = v38 + 1;
    }
    while ( __strex(v39, v37) );
    __dmb(0xBu);
    if ( v39 <= *(_DWORD *)(v9 + 36) )
      return v25;
    *(_DWORD *)(v9 + 36) = v39;
    result = v25;
  }
  return result;
}
