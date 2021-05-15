// ObCreateObjectTypeEx 
 
int __fastcall ObCreateObjectTypeEx(unsigned __int16 *a1, int a2, int a3, int a4, int *a5)
{
  unsigned int v7; // r1
  unsigned __int16 *v8; // r0
  unsigned int v9; // r2
  int v10; // t1
  int v11; // r8
  int v12; // r9
  int v13; // r10
  int v14; // r10
  unsigned int v15; // r4
  int *v16; // r5
  int v17; // r5
  _DWORD *v18; // r3
  int v19; // r4
  int v20; // r5
  unsigned int v21; // r0
  _BYTE *v22; // r0
  unsigned int v23; // r2
  char v24; // r1
  int v25; // r3
  int v26; // r2
  char *v27; // r3
  unsigned int v28; // r2
  unsigned __int8 *v29; // r6
  int v30; // r0
  int v31; // r5
  unsigned int v32; // r2
  _DWORD *v33; // r2
  int v34; // r3
  unsigned int v36; // r3
  int v37; // r1
  unsigned int v38; // r2
  unsigned int v39; // r2
  int v40; // r0
  unsigned int v41; // r1
  int v42; // r3
  int v43; // r5
  unsigned int v44; // r2
  unsigned __int8 *v45; // r5
  int v46; // r0
  int v47; // r4
  unsigned int v48; // r2
  int v49; // r5
  unsigned int *v50; // r4
  int v51; // r1
  unsigned int v52; // r0
  unsigned int v53; // r2
  int v54; // r0
  unsigned int v55; // r1
  __int16 v56; // r3
  unsigned int *v57; // r4
  int v58; // r1
  unsigned int v59; // r0
  unsigned int v60; // r2
  int v61; // r0
  unsigned int v62; // r1
  __int16 v63; // r3
  unsigned int *v64; // r4
  int v65; // r1
  unsigned int v66; // r0
  unsigned int v67; // r2
  int v68; // r0
  unsigned int v69; // r1
  __int16 v70; // r3
  int v71; // r3
  int v72; // r1
  _DWORD *v73; // r0
  unsigned int *v74; // r5
  int v75; // r1
  unsigned int v76; // r0
  unsigned int *v77; // r6
  int v78; // r1
  unsigned int v79; // r0
  unsigned int v80; // r2
  int v81; // r0
  unsigned int v82; // r1
  __int16 v83; // r3
  int v84; // r6
  unsigned int *v85; // r5
  int v86; // r1
  unsigned int v87; // r0
  unsigned int v88; // r2
  int v89; // r0
  unsigned int v90; // r1
  __int16 v91; // r3
  unsigned int *v92; // r5
  int v93; // r1
  unsigned int v94; // r0
  unsigned int v95; // r2
  int v96; // r0
  unsigned int v97; // r1
  int v98; // r3
  char v99[8]; // [sp+10h] [bp-128h] BYREF
  _DWORD *v100; // [sp+18h] [bp-120h] BYREF
  int v101; // [sp+1Ch] [bp-11Ch]
  unsigned __int16 v102; // [sp+20h] [bp-118h] BYREF
  unsigned __int16 v103; // [sp+22h] [bp-116h]
  _DWORD *v104; // [sp+24h] [bp-114h]
  int v105; // [sp+28h] [bp-110h] BYREF
  int v106; // [sp+2Ch] [bp-10Ch]
  unsigned __int8 v107; // [sp+3Ah] [bp-FEh]
  char v108; // [sp+3Bh] [bp-FDh]
  int v109; // [sp+3Ch] [bp-FCh]
  int v110; // [sp+40h] [bp-F8h] BYREF
  int v111; // [sp+44h] [bp-F4h]
  char *v112; // [sp+48h] [bp-F0h]
  int *v113; // [sp+4Ch] [bp-ECh]
  int v114; // [sp+50h] [bp-E8h]
  int v115[12]; // [sp+58h] [bp-E0h] BYREF
  int v116[44]; // [sp+88h] [bp-B0h] BYREF

  v112 = (char *)a4;
  v113 = a5;
  if ( !a1
    || (v7 = *a1) == 0
    || (v7 & 1) != 0
    || !a2
    || (*(_DWORD *)(a2 + 8) & 0xFFFEF00D) != 0
    || *(_WORD *)a2 != 88
    || (*(_BYTE *)(a2 + 2) & 0x10) != 0 && !*(_DWORD *)(a2 + 52) && !*(_DWORD *)(a2 + 56) )
  {
    JUMPOUT(0x7CF412);
  }
  if ( (*(_BYTE *)(a2 + 2) & 4) == 0 )
  {
    v34 = *(_DWORD *)(a2 + 36);
    if ( v34 != 512 )
    {
      if ( v34 )
        return sub_7CF40C();
    }
  }
  v8 = (unsigned __int16 *)*((_DWORD *)a1 + 1);
  v9 = v7 >> 1;
  v114 = *(_DWORD *)(a2 + 36);
  while ( v9 )
  {
    v10 = *v8++;
    --v9;
    if ( v10 == 92 )
      return -1073741773;
  }
  v107 = 0;
  v108 = 0;
  v11 = 0;
  v105 = 0;
  v106 = 0;
  v12 = 0;
  v109 = -60876;
  v13 = ObpTypeDirectoryObject;
  if ( ObpTypeDirectoryObject )
  {
    v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v44 + 308);
    v45 = (unsigned __int8 *)(v13 + 148);
    v46 = KeAbPreAcquire(v13 + 148, 0, 0);
    v47 = v46;
    do
      v48 = __ldrex(v45);
    while ( __strex(v48 | 1, v45) );
    __dmb(0xBu);
    if ( (v48 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 148), v46, v13 + 148);
    if ( v47 )
      *(_BYTE *)(v47 + 14) |= 1u;
    v109 = -859041228;
    ObfReferenceObject(v13);
    v107 = 1;
    v108 = 1;
    v105 = v13;
    if ( ObpLookupDirectoryEntry(ObpTypeDirectoryObject, a1, 64, 0, (int)&v105) )
    {
      if ( v107 )
      {
        v49 = v105;
        v50 = (unsigned int *)(v105 + 148);
        __pld((void *)(v105 + 148));
        v51 = *v50;
        if ( (*v50 & 0xFFFFFFF0) <= 0x10 )
          v52 = 0;
        else
          v52 = v51 - 16;
        if ( (v51 & 2) != 0 )
          goto LABEL_94;
        __dmb(0xBu);
        do
          v53 = __ldrex(v50);
        while ( v53 == v51 && __strex(v52, v50) );
        if ( v53 != v51 )
LABEL_94:
          ExfReleasePushLock(v50, v51);
        KeAbPostRelease((unsigned int)v50);
        v54 = ObfDereferenceObject(v49);
        v55 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v56 = *(_WORD *)(v55 + 0x134) + 1;
        *(_WORD *)(v55 + 308) = v56;
        if ( !v56 && *(_DWORD *)(v55 + 100) != v55 + 100 && !*(_WORD *)(v55 + 310) )
          KiCheckForKernelApcDelivery(v54);
      }
      if ( v106 )
        ObfDereferenceObject(v106);
      return -1073741771;
    }
    v14 = v107;
    v12 = v105;
    v11 = v106;
  }
  else
  {
    v14 = 0;
  }
  v101 = ExAllocatePoolWithTag(1, a1[1], 1833853519);
  if ( !v101 )
  {
    if ( v14 )
    {
      v57 = (unsigned int *)(v12 + 148);
      __pld((void *)(v12 + 148));
      v58 = *(_DWORD *)(v12 + 148);
      if ( (v58 & 0xFFFFFFF0) <= 0x10 )
        v59 = 0;
      else
        v59 = v58 - 16;
      if ( (v58 & 2) != 0 )
        goto LABEL_112;
      __dmb(0xBu);
      do
        v60 = __ldrex(v57);
      while ( v60 == v58 && __strex(v59, v57) );
      if ( v60 != v58 )
LABEL_112:
        ExfReleasePushLock((_DWORD *)(v12 + 148), v58);
      KeAbPostRelease(v12 + 148);
      v61 = ObfDereferenceObject(v12);
      v62 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v63 = *(_WORD *)(v62 + 0x134) + 1;
      *(_WORD *)(v62 + 308) = v63;
      if ( !v63 && *(_DWORD *)(v62 + 100) != v62 + 100 && !*(_WORD *)(v62 + 310) )
        KiCheckForKernelApcDelivery(v61);
    }
    if ( v11 )
      ObfDereferenceObject(v11);
    return -1073741670;
  }
  HIWORD(v100) = a1[1];
  RtlCopyUnicodeString((unsigned __int16 *)&v100, a1);
  v15 = v101;
  v16 = (int *)ObpTypeObjectType;
  if ( !ObpTypeObjectType )
  {
    memset(v116, 0, 144);
    memmove((int)&v116[10], a2, 0x58u);
    LOBYTE(v116[5]) = 2;
    v116[3] = v15;
    v16 = v116;
    v116[33] = 1416258127;
    v116[2] = (int)v100;
  }
  memset(v115, 0, 44);
  v115[0] = 16;
  v115[3] = v16[20];
  v115[4] = v16[21];
  v115[5] = 2048;
  v17 = ObpAllocateObject(v115, 0, (int)v16, &v100, 144, &v110, 0);
  if ( v17 < 0 )
  {
    if ( v14 )
    {
      v64 = (unsigned int *)(v12 + 148);
      __pld((void *)(v12 + 148));
      v65 = *(_DWORD *)(v12 + 148);
      if ( (v65 & 0xFFFFFFF0) <= 0x10 )
        v66 = 0;
      else
        v66 = v65 - 16;
      if ( (v65 & 2) != 0 )
        goto LABEL_129;
      __dmb(0xBu);
      do
        v67 = __ldrex(v64);
      while ( v67 == v65 && __strex(v66, v64) );
      if ( v67 != v65 )
LABEL_129:
        ExfReleasePushLock((_DWORD *)(v12 + 148), v65);
      KeAbPostRelease(v12 + 148);
      v68 = ObfDereferenceObject(v12);
      v69 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v70 = *(_WORD *)(v69 + 0x134) + 1;
      *(_WORD *)(v69 + 308) = v70;
      if ( !v70 && *(_DWORD *)(v69 + 100) != v69 + 100 && !*(_WORD *)(v69 + 310) )
        KiCheckForKernelApcDelivery(v68);
      v15 = v101;
    }
    if ( v11 )
      ObfDereferenceObject(v11);
    ExFreePoolWithTag(v15);
    return v17;
  }
  v18 = (_DWORD *)v110;
  *(_DWORD *)(v110 + 16) = 0;
  v19 = (int)(v18 + 6);
  v18[8] = v100;
  v18[9] = v101;
  v18[12] = 0;
  v18[13] = 0;
  v18[14] = 0;
  v18[15] = 0;
  if ( ObpTypeObjectType )
  {
    v20 = 1;
    if ( NlsMbCodePageTag )
      LOWORD(v21) = RtlxUnicodeStringToOemSize(a1);
    else
      v21 = ((unsigned int)*a1 + 2) >> 1;
    v111 = (unsigned __int16)(((v21 + 2) & 0xFFFC) + 1);
    v22 = (_BYTE *)ExAllocatePoolWithTag(1, v111, 1851023951);
    v100 = v22;
    if ( !v22 )
      goto LABEL_139;
    memset(v22, 0, v111);
    v103 = v111;
    v104 = v100;
    if ( RtlUnicodeStringToAnsiString(&v102, a1, 0, (int)v100) >= 0 )
    {
      v23 = *a1 >> 1;
      if ( v23 < 4 )
      {
        v36 = v103;
        do
        {
          if ( v23 < v36 )
          {
            *((_BYTE *)v104 + v23) = 32;
            ++v102;
            v36 = v103;
          }
          ++v23;
        }
        while ( v23 < 4 );
      }
      v20 = 0;
      *(_DWORD *)(v19 + 132) = *v104;
    }
    ExFreePoolWithTag((unsigned int)v100);
    if ( v20 )
    {
LABEL_139:
      if ( *a1 < 4u )
        v71 = 1063936591;
      else
        v71 = **((_DWORD **)a1 + 1);
      *(_DWORD *)(v19 + 132) = v71;
    }
  }
  else
  {
    ObpTypeObjectType = (int)(v18 + 6);
    v18[12] = 1;
    v18[39] = 1416258127;
  }
  memmove(v19 + 40, a2, 0x58u);
  v24 = v114;
  *(_DWORD *)(v19 + 76) = v114;
  if ( (NtGlobalFlag & 0x4000) != 0 )
    *(_BYTE *)(v19 + 42) |= 0x20u;
  if ( (*(_BYTE *)(a2 + 2) & 0x10) != 0 )
    v25 = 8;
  else
    v25 = 0;
  v26 = v25 + 48;
  if ( (v24 & 1) != 0 )
    *(_DWORD *)(v19 + 80) += v26;
  else
    *(_DWORD *)(v19 + 84) += v26;
  if ( !*(_DWORD *)(a2 + 68) )
    *(_DWORD *)(v19 + 108) = SeDefaultObjectMethod;
  *(_DWORD *)(v19 + 128) = 0;
  *(_DWORD *)v19 = v19;
  *(_DWORD *)(v19 + 4) = v19;
  *(_DWORD *)(v19 + 136) = v19 + 136;
  *(_DWORD *)(v19 + 140) = v19 + 136;
  if ( (*(_BYTE *)(v19 + 42) & 4) != 0 )
  {
    *(_DWORD *)(v19 + 68) |= 0x100000u;
    v27 = &ObpDefaultObject;
  }
  else
  {
    v27 = v112;
  }
  *(_DWORD *)(v19 + 16) = v27;
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v28 + 310);
  v29 = (unsigned __int8 *)(ObpTypeObjectType + 128);
  v30 = KeAbPreAcquire(ObpTypeObjectType + 128, 0, 0);
  v31 = v30;
  do
    v32 = __ldrex(v29);
  while ( __strex(v32 | 1, v29) );
  __dmb(0xBu);
  if ( (v32 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v29, v30, (unsigned int)v29);
  if ( v31 )
    *(_BYTE *)(v31 + 14) |= 1u;
  if ( (*(_BYTE *)(v110 + 14) & 1) != 0 )
    v33 = (_DWORD *)(v110 - 16);
  else
    v33 = 0;
  v72 = ObpTypeObjectType;
  v73 = *(_DWORD **)(ObpTypeObjectType + 4);
  *v33 = ObpTypeObjectType;
  v33[1] = v73;
  if ( *v73 != v72 )
    __fastfail(3u);
  *v73 = v33;
  *(_DWORD *)(v72 + 4) = v33;
  v37 = ObpTypeObjectType;
  v38 = *(_DWORD *)(ObpTypeObjectType + 24);
  if ( v38 < 0x30 )
    ObpObjectTypes[v38 - 1] = v19;
  v74 = (unsigned int *)(v37 + 128);
  __pld((void *)(v37 + 128));
  v75 = *(_DWORD *)(v37 + 128);
  if ( (v75 & 0xFFFFFFF0) <= 0x10 )
    v76 = 0;
  else
    v76 = v75 - 16;
  if ( (v75 & 2) != 0 )
    goto LABEL_151;
  __dmb(0xBu);
  do
    v39 = __ldrex(v74);
  while ( v39 == v75 && __strex(v76, v74) );
  if ( v39 != v75 )
LABEL_151:
    ExfReleasePushLock(v74, v75);
  v40 = KeAbPostRelease((unsigned int)v74);
  v41 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v42 = (__int16)(*(_WORD *)(v41 + 0x136) + 1);
  *(_WORD *)(v41 + 310) = v42;
  if ( !v42 && *(_DWORD *)(v41 + 100) != v41 + 100 )
    KiCheckForKernelApcDelivery(v40);
  if ( v19 == ObpTypeObjectType )
  {
    v43 = 2;
  }
  else
  {
    v17 = ObpAllocateTypeIndex(v99);
    if ( v17 < 0 )
    {
      if ( v14 )
      {
        v77 = (unsigned int *)(v12 + 148);
        __pld((void *)(v12 + 148));
        v78 = *(_DWORD *)(v12 + 148);
        if ( (v78 & 0xFFFFFFF0) <= 0x10 )
          v79 = 0;
        else
          v79 = v78 - 16;
        if ( (v78 & 2) != 0 )
          goto LABEL_163;
        __dmb(0xBu);
        do
          v80 = __ldrex(v77);
        while ( v80 == v78 && __strex(v79, v77) );
        if ( v80 != v78 )
LABEL_163:
          ExfReleasePushLock((_DWORD *)(v12 + 148), v78);
        KeAbPostRelease(v12 + 148);
        v81 = ObfDereferenceObject(v12);
        v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v83 = *(_WORD *)(v82 + 0x134) + 1;
        *(_WORD *)(v82 + 308) = v83;
        if ( !v83 && *(_DWORD *)(v82 + 100) != v82 + 100 && !*(_WORD *)(v82 + 310) )
          KiCheckForKernelApcDelivery(v81);
      }
      if ( v11 )
        ObfDereferenceObject(v11);
      goto LABEL_187;
    }
    v43 = (unsigned __int8)v99[0];
  }
  ObTypeIndexTable[v43] = v19;
  *(_BYTE *)(v19 + 20) = v43;
  if ( !ObpTypeDirectoryObject )
  {
LABEL_71:
    if ( v14 )
    {
      v92 = (unsigned int *)(v12 + 148);
      __pld((void *)(v12 + 148));
      v93 = *(_DWORD *)(v12 + 148);
      if ( (v93 & 0xFFFFFFF0) <= 0x10 )
        v94 = 0;
      else
        v94 = v93 - 16;
      if ( (v93 & 2) != 0 )
        goto LABEL_196;
      __dmb(0xBu);
      do
        v95 = __ldrex(v92);
      while ( v95 == v93 && __strex(v94, v92) );
      if ( v95 != v93 )
LABEL_196:
        ExfReleasePushLock((_DWORD *)(v12 + 148), v93);
      KeAbPostRelease(v12 + 148);
      v96 = ObfDereferenceObject(v12);
      v97 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v98 = (__int16)(*(_WORD *)(v97 + 0x134) + 1);
      *(_WORD *)(v97 + 308) = v98;
      if ( !v98 && *(_DWORD *)(v97 + 100) != v97 + 100 && !*(_WORD *)(v97 + 310) )
        KiCheckForKernelApcDelivery(v96);
    }
    if ( v11 )
      ObfDereferenceObject(v11);
    v17 = 0;
    *v113 = v19;
    return v17;
  }
  if ( ObpInsertDirectoryEntry(ObpTypeDirectoryObject, v19, (int)&v105) )
  {
    v14 = v107;
    v12 = v105;
    v11 = v106;
    goto LABEL_71;
  }
  ObTypeIndexTable[v43] = 0;
  if ( v107 )
  {
    v84 = v105;
    v85 = (unsigned int *)(v105 + 148);
    __pld((void *)(v105 + 148));
    v86 = *v85;
    if ( (*v85 & 0xFFFFFFF0) <= 0x10 )
      v87 = 0;
    else
      v87 = v86 - 16;
    if ( (v86 & 2) != 0 )
      goto LABEL_179;
    __dmb(0xBu);
    do
      v88 = __ldrex(v85);
    while ( v88 == v86 && __strex(v87, v85) );
    if ( v88 != v86 )
LABEL_179:
      ExfReleasePushLock(v85, v86);
    KeAbPostRelease((unsigned int)v85);
    v89 = ObfDereferenceObject(v84);
    v90 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v91 = *(_WORD *)(v90 + 0x134) + 1;
    *(_WORD *)(v90 + 308) = v91;
    if ( !v91 && *(_DWORD *)(v90 + 100) != v90 + 100 && !*(_WORD *)(v90 + 310) )
      KiCheckForKernelApcDelivery(v89);
  }
  if ( v106 )
    ObfDereferenceObject(v106);
  v17 = -1073741670;
LABEL_187:
  ObfDereferenceObject(v19);
  return v17;
}
