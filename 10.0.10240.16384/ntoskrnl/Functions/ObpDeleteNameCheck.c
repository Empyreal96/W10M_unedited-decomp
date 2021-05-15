// ObpDeleteNameCheck 
 
int __fastcall ObpDeleteNameCheck(int result)
{
  int v1; // r6
  int v2; // r3
  int *v3; // r8
  unsigned __int8 *v4; // r5
  int v5; // r3
  int v6; // r0
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r7
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1
  __int16 v15; // r3
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r3
  signed int v20; // r0
  int v21; // r1
  unsigned int v22; // r2
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r3
  int v27; // r4
  unsigned __int8 *v28; // r0
  unsigned int v29; // r2
  int v30; // r3
  int v31; // r0
  int v32; // r4
  unsigned int v33; // r2
  int v35; // r6
  int v36; // r8
  unsigned int *v37; // r4
  int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r2
  int v41; // r0
  unsigned int v42; // r4
  __int16 v43; // r2
  int v44; // r1
  unsigned int v45; // r0
  unsigned int v46; // r2
  int v47; // r0
  unsigned int v48; // r1
  __int16 v49; // r3
  unsigned int *v50; // r4
  int v51; // r1
  unsigned int v52; // r0
  unsigned int v53; // r2
  int v54; // r0
  unsigned int v55; // r1
  __int16 v56; // r3
  int v57; // r1
  unsigned int v58; // r0
  unsigned int v59; // r2
  int v60; // r0
  unsigned int v61; // r1
  __int16 v62; // r3
  int v63; // [sp+8h] [bp-38h] BYREF
  int v64; // [sp+Ch] [bp-34h]
  char v65; // [sp+1Ah] [bp-26h]
  char v66; // [sp+1Bh] [bp-25h]
  int v67; // [sp+1Ch] [bp-24h]

  v1 = result;
  if ( (*(_BYTE *)(result + 14) & 2) == 0 )
    return result;
  v2 = ObpInfoMaskToOffset[*(_BYTE *)(result + 14) & 3];
  v3 = (int *)(result - v2);
  if ( result == v2 )
    return result;
  v4 = (unsigned __int8 *)(result + 8);
  while ( 1 )
  {
    v5 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v5 & 0xFFFFFFC0) + 0x134);
    v6 = KeAbPreAcquire((unsigned int)v4, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex(v4);
    while ( __strex(v8 | 1, v4) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v6, (unsigned int)v4);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    v9 = *v3;
    if ( !*v3 )
    {
      __pld(v4);
      v16 = *(_DWORD *)v4;
      if ( (*(_DWORD *)v4 & 0xFFFFFFF0) > 0x10 )
        v17 = v16 - 16;
      else
        v17 = 0;
      if ( (v16 & 2) != 0 )
        goto LABEL_99;
      __dmb(0xBu);
      do
        v18 = __ldrex((unsigned int *)v4);
      while ( v18 == v16 && __strex(v17, (unsigned int *)v4) );
      if ( v18 != v16 )
LABEL_99:
        ExfReleasePushLock(v4, v16);
      result = KeAbPostRelease((unsigned int)v4);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
      *(_WORD *)(v14 + 308) = v19;
      if ( v19 || *(_DWORD *)(v14 + 100) == v14 + 100 )
        return result;
LABEL_34:
      if ( !*(_WORD *)(v14 + 310) )
        result = KiCheckForKernelApcDelivery(result);
      return result;
    }
    if ( (*(_BYTE *)(v1 + 15) & 0x10) != 0 || *(_DWORD *)(v1 + 4) )
    {
      __pld(v4);
      v11 = *(_DWORD *)v4;
      if ( (*(_DWORD *)v4 & 0xFFFFFFF0) > 0x10 )
        v12 = v11 - 16;
      else
        v12 = 0;
      if ( (v11 & 2) != 0 )
        goto LABEL_95;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)v4);
      while ( v13 == v11 && __strex(v12, (unsigned int *)v4) );
      if ( v13 != v11 )
LABEL_95:
        ExfReleasePushLock(v4, v11);
      result = KeAbPostRelease((unsigned int)v4);
      v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v15 = *(_WORD *)(v14 + 0x134) + 1;
      *(_WORD *)(v14 + 308) = v15;
      if ( v15 || *(_DWORD *)(v14 + 100) == v14 + 100 )
        return result;
      goto LABEL_34;
    }
    v20 = ObfReferenceObject(*v3);
    __pld(v4);
    v21 = *(_DWORD *)v4;
    if ( (*(_DWORD *)v4 & 0xFFFFFFF0) > 0x10 )
      return sub_7C4788(v20);
    if ( (v21 & 2) != 0 )
      goto LABEL_101;
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)v4);
    while ( v22 == v21 && __strex(0, (unsigned int *)v4) );
    if ( v22 != v21 )
LABEL_101:
      ExfReleasePushLock(v4, v21);
    v23 = KeAbPostRelease((unsigned int)v4);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    v64 = 0;
    v26 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v26 & 0xFFFFFFC0) + 0x134);
    v27 = KeAbPreAcquire(v9 + 148, 0, 0);
    v28 = (unsigned __int8 *)(v9 + 148);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 | 1, v28) );
    __dmb(0xBu);
    if ( (v29 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v28, v27, v9 + 148);
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    v67 = -859041228;
    ObfReferenceObject(v9);
    v65 = 1;
    v66 = 1;
    v63 = v9;
    v30 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v30 & 0xFFFFFFC0) + 0x134);
    v31 = KeAbPreAcquire((unsigned int)v4, 0, 0);
    v32 = v31;
    do
      v33 = __ldrex(v4);
    while ( __strex(v33 | 1, v4) );
    __dmb(0xBu);
    if ( (v33 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v4, v31, (unsigned int)v4);
    if ( v32 )
      *(_BYTE *)(v32 + 14) |= 1u;
    if ( *v3 == v9 && (*(_BYTE *)(v1 + 15) & 0x10) == 0 && !*(_DWORD *)(v1 + 4) )
      break;
    v50 = (unsigned int *)(v9 + 148);
    __pld((void *)(v9 + 148));
    v51 = *(_DWORD *)(v9 + 148);
    if ( (v51 & 0xFFFFFFF0) <= 0x10 )
      v52 = 0;
    else
      v52 = v51 - 16;
    if ( (v51 & 2) != 0 )
      goto LABEL_116;
    __dmb(0xBu);
    do
      v53 = __ldrex(v50);
    while ( v53 == v51 && __strex(v52, v50) );
    if ( v53 != v51 )
LABEL_116:
      ExfReleasePushLock((_DWORD *)(v9 + 148), v51);
    KeAbPostRelease(v9 + 148);
    v67 = -286387660;
    v54 = ObfDereferenceObject(v9);
    v63 = 0;
    v65 = 0;
    v66 = 0;
    v55 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v56 = *(_WORD *)(v55 + 0x134) + 1;
    *(_WORD *)(v55 + 308) = v56;
    if ( !v56 && *(_DWORD *)(v55 + 100) != v55 + 100 && !*(_WORD *)(v55 + 310) )
      KiCheckForKernelApcDelivery(v54);
    __pld(v4);
    v57 = *(_DWORD *)v4;
    if ( (*(_DWORD *)v4 & 0xFFFFFFF0) <= 0x10 )
      v58 = 0;
    else
      v58 = v57 - 16;
    if ( (v57 & 2) != 0 )
      goto LABEL_129;
    __dmb(0xBu);
    do
      v59 = __ldrex((unsigned int *)v4);
    while ( v59 == v57 && __strex(v58, (unsigned int *)v4) );
    if ( v59 != v57 )
LABEL_129:
      ExfReleasePushLock(v4, v57);
    v60 = KeAbPostRelease((unsigned int)v4);
    v61 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v62 = *(_WORD *)(v61 + 0x134) + 1;
    *(_WORD *)(v61 + 308) = v62;
    if ( !v62 && *(_DWORD *)(v61 + 100) != v61 + 100 && !*(_WORD *)(v61 + 310) )
      KiCheckForKernelApcDelivery(v60);
    PspDereferenceSiloObject(v9);
  }
  if ( v3[3] )
  {
    v35 = 0;
    v36 = v9;
LABEL_67:
    v37 = (unsigned int *)(v36 + 148);
    __pld((void *)(v36 + 148));
    v38 = *(_DWORD *)(v36 + 148);
    if ( (v38 & 0xFFFFFFF0) > 0x10 )
      v39 = v38 - 16;
    else
      v39 = 0;
    if ( (v38 & 2) != 0 )
      goto LABEL_107;
    __dmb(0xBu);
    do
      v40 = __ldrex(v37);
    while ( v40 == v38 && __strex(v39, v37) );
    if ( v40 != v38 )
LABEL_107:
      ExfReleasePushLock((_DWORD *)(v36 + 148), v38);
    KeAbPostRelease(v36 + 148);
    v41 = ObfDereferenceObject(v36);
    v42 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v43 = *(_WORD *)(v42 + 0x134);
    *(_WORD *)(v42 + 308) = v43 + 1;
    if ( v43 == -1 && *(_DWORD *)(v42 + 100) != v42 + 100 && !*(_WORD *)(v42 + 310) )
      KiCheckForKernelApcDelivery(v41);
  }
  else
  {
    if ( ObTypeIndexTable[BYTE1(v1) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v1 + 12)] == ObpSymbolicLinkObjectType )
      ObpDeleteSymbolicLinkName(v1 + 24);
    ObpLookupDirectoryEntry(*v3, v3 + 1, 0, 0, &v63);
    ObpDeleteDirectoryEntry(&v63);
    v35 = v64;
    if ( v65 )
    {
      v36 = v63;
      goto LABEL_67;
    }
  }
  if ( v35 )
    ObfDereferenceObject(v35);
  __pld(v4);
  v44 = *(_DWORD *)v4;
  if ( (*(_DWORD *)v4 & 0xFFFFFFF0) > 0x10 )
    v45 = v44 - 16;
  else
    v45 = 0;
  if ( (v44 & 2) != 0 )
    goto LABEL_97;
  __dmb(0xBu);
  do
    v46 = __ldrex((unsigned int *)v4);
  while ( v46 == v44 && __strex(v45, (unsigned int *)v4) );
  if ( v46 != v44 )
LABEL_97:
    ExfReleasePushLock(v4, v44);
  v47 = KeAbPostRelease((unsigned int)v4);
  v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v49 = *(_WORD *)(v48 + 0x134) + 1;
  *(_WORD *)(v48 + 308) = v49;
  if ( !v49 && *(_DWORD *)(v48 + 100) != v48 + 100 && !*(_WORD *)(v48 + 310) )
    KiCheckForKernelApcDelivery(v47);
  return PspDereferenceSiloObject(v9);
}
