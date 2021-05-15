// ObInsertObjectEx 
 
int __fastcall ObInsertObjectEx(int a1, char *a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r9
  int v8; // r4
  char v10; // r3
  int v11; // r1
  int v13; // r6
  _DWORD *v14; // r8
  int result; // r0
  int v16; // r0
  char v17; // r3
  int v18; // r2
  int v19; // r5
  int v20; // r0
  int v21; // r5
  _DWORD *v22; // r0
  int v23; // r5
  int v24; // r5
  int v25; // r5
  unsigned int v26; // r0
  int v27; // r0
  int v28; // r5
  bool v29; // zf
  int v30; // r6
  int v31; // r0
  int v32; // r1
  int v33; // r3
  unsigned __int8 *v34; // r6
  int v35; // r0
  int v36; // r5
  unsigned int v37; // r2
  unsigned int v38; // r2
  __int16 v39; // r3
  int v40; // r5
  int v41; // r1
  unsigned int *v42; // r0
  unsigned int v43; // r2
  unsigned int v44; // r1
  unsigned int v45; // r2
  int v46; // r0
  int v47; // r1
  int v48; // r3
  int v49; // r0
  unsigned int v50; // r2
  int v51; // r0
  unsigned int v52; // r1
  __int16 v53; // r3
  unsigned int v54; // r1
  int v55; // r4
  unsigned int v56; // r2
  unsigned int v57; // r2
  int v58; // r3
  int v59; // r0
  int v60; // r1
  unsigned int v61; // r0
  unsigned int v62; // r1
  int v63; // r6
  unsigned int v64; // r2
  unsigned int v65; // r2
  int v67; // [sp+20h] [bp-198h]
  unsigned int *v68; // [sp+20h] [bp-198h]
  bool v69; // [sp+24h] [bp-194h] BYREF
  int v70; // [sp+28h] [bp-190h]
  bool v71; // [sp+2Ch] [bp-18Ch] BYREF
  int v72; // [sp+30h] [bp-188h]
  int v73; // [sp+34h] [bp-184h]
  int v74; // [sp+38h] [bp-180h]
  int v75; // [sp+3Ch] [bp-17Ch]
  int v76; // [sp+40h] [bp-178h]
  int v77; // [sp+48h] [bp-170h] BYREF
  int v78[3]; // [sp+4Ch] [bp-16Ch] BYREF
  char v79[120]; // [sp+58h] [bp-160h] BYREF
  char v80[232]; // [sp+D0h] [bp-E8h] BYREF

  v7 = a1 - 24;
  v72 = a4;
  v8 = *(unsigned __int8 *)(a1 - 12);
  v73 = a6;
  v10 = *(_BYTE *)(a1 - 10);
  v11 = a1;
  v70 = a3;
  v13 = ObTypeIndexTable[v8 ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie];
  v14 = *(_DWORD **)(a1 - 8);
  if ( (v10 & 2) != 0 && v7 != ObpInfoMaskToOffset[v10 & 3] )
    return sub_7FA4C4();
  v16 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v17 = *(_BYTE *)(v13 + 42);
  v74 = v16;
  if ( (v17 & 8) == 0 && !v14[6] )
  {
    *(_DWORD *)(v7 + 16) = 0;
    if ( a7 )
    {
      v18 = v73;
      *a7 = 0;
      v19 = ObpCreateHandle(0, v11, a3, 0, v72 + 1, *v14, v16, 0, v18, a7);
    }
    else
    {
      v19 = 0;
    }
    v20 = v14[6];
    if ( v20 )
    {
      SeReleaseSecurityDescriptor(v20, *((char *)v14 + 8), 1);
      v14[6] = 0;
    }
    v54 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v55 = *(_DWORD *)(v54 + 2848);
    v56 = *(unsigned __int16 *)(v55 + 8);
    ++*(_DWORD *)(v55 + 20);
    if ( *(unsigned __int16 *)(v55 + 4) < v56
      || (++*(_DWORD *)(v55 + 24),
          v55 = *(_DWORD *)(v54 + 2852),
          v57 = *(unsigned __int16 *)(v55 + 8),
          ++*(_DWORD *)(v55 + 20),
          *(unsigned __int16 *)(v55 + 4) < v57) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v55, v14);
    }
    else
    {
      ++*(_DWORD *)(v55 + 24);
      (*(void (__fastcall **)(_DWORD *))(v55 + 44))(v14);
    }
LABEL_81:
    ObfDereferenceObject(a1);
    return v19;
  }
  if ( !a2 )
  {
    a2 = v79;
    v21 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v67 = v21;
    v22 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v78[2] = *(_DWORD *)(v21 + 176);
    if ( v22 )
      v77 = PsReferenceImpersonationTokenEx(v22, 0, &v69, &v71, v78, 0);
    else
      v77 = 0;
    v23 = ObFastReferenceObject((_DWORD *)(v21 + 244));
    if ( !v23 )
    {
      v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v39 = *(_WORD *)(v38 + 0x134);
      v75 = v38;
      *(_WORD *)(v38 + 308) = v39 - 1;
      v40 = v67;
      v68 = (unsigned int *)(v67 + 168);
      v41 = KeAbPreAcquire((unsigned int)v68, 0, 0);
      v76 = v41;
      v42 = (unsigned int *)(v40 + 168);
      do
        v43 = __ldrex(v42);
      while ( !v43 && __strex(0x11u, v42) );
      __dmb(0xBu);
      if ( v43 )
      {
        ExfAcquirePushLockSharedEx(v42, v41, v40 + 168);
        v41 = v76;
      }
      if ( v41 )
        *(_BYTE *)(v41 + 14) |= 1u;
      v23 = ObFastReferenceObjectLocked((_DWORD *)(v40 + 244));
      __dmb(0xBu);
      v44 = (unsigned int)v68;
      do
        v45 = __ldrex(v68);
      while ( v45 == 17 && __strex(0, v68) );
      if ( v45 != 17 )
      {
        ExfReleasePushLockShared(v68);
        v44 = (unsigned int)v68;
      }
      v46 = KeAbPostRelease(v44);
      v47 = v75;
      v48 = (__int16)(*(_WORD *)(v75 + 308) + 1);
      *(_WORD *)(v75 + 308) = v48;
      if ( !v48 && *(_DWORD *)(v47 + 100) != v47 + 100 && !*(_WORD *)(v47 + 310) )
        KiCheckForKernelApcDelivery(v46);
    }
    v78[1] = v23;
    v19 = SepCreateAccessStateFromSubjectContext(&v77, (int)v79, (int)v80, v70, (_DWORD *)(v13 + 52));
    if ( v19 < 0 )
      goto LABEL_81;
  }
  *((_DWORD *)a2 + 11) = v14[6];
  v24 = ObpAdjustAccessMask(a2, v11);
  if ( v24 < 0 )
  {
    ObfDereferenceObject(a1);
    if ( a2 == v79 )
    {
      SepDeleteAccessState((int)a2);
      SeReleaseSubjectContext((int)(a2 + 28));
    }
    result = v24;
  }
  else
  {
    if ( (*(_BYTE *)(v13 + 42) & 8) == 0 && !v14[6] )
    {
      v25 = a1;
      goto LABEL_22;
    }
    v25 = a1;
    v70 = ObpAssignSecurity(a2, 0);
    if ( v70 >= 0 )
    {
      v26 = v14[6];
      if ( (!*((_BYTE *)v14 + 8) || *((_BYTE *)v14 + 8) == 1) && v26 )
        ExFreePoolWithTag(v26);
      v14[6] = 0;
      *((_DWORD *)a2 + 11) = 0;
LABEL_22:
      *(_DWORD *)(v7 + 16) = 0;
      if ( a7 )
      {
        *a7 = 0;
        v27 = ObpCreateHandle(0, v25, 0, a2, v72 + 1, *v14, v74, 0, v73, a7);
        v28 = v27;
        if ( v27 >= 0 )
        {
          v29 = v13 == ObpSymbolicLinkObjectType;
          v30 = a1;
          if ( v29 && v27 != 0x40000000 )
            ObpCreateSymbolicLinkName(a1);
          goto LABEL_25;
        }
      }
      else if ( a2 == v79
             || ((*v14 & 0x400) != 0 ? (v32 = 1) : (v32 = v74),
                 v28 = ObpAdjustCreatorAccessState(a2, v32, v13, v25),
                 v28 >= 0) )
      {
        v33 = __mrc(15, 0, 13, 0, 3);
        --*(_WORD *)((v33 & 0xFFFFFFC0) + 0x134);
        v34 = (unsigned __int8 *)(v7 + 8);
        v35 = KeAbPreAcquire(v7 + 8, 0, 0);
        v36 = v35;
        do
          v37 = __ldrex(v34);
        while ( __strex(v37 | 1, v34) );
        __dmb(0xBu);
        if ( (v37 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(v7 + 8), v35, v7 + 8);
        if ( v36 )
          *(_BYTE *)(v36 + 14) |= 1u;
        v58 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v59 = ObpChargeQuotaForObject(v7, *(_DWORD *)(v58 + 116), 0, v58);
        __pld(v34);
        v28 = v59;
        v60 = *(_DWORD *)v34;
        if ( (*(_DWORD *)v34 & 0xFFFFFFF0) <= 0x10 )
          v61 = 0;
        else
          v61 = v60 - 16;
        if ( (v60 & 2) != 0 )
          goto LABEL_95;
        __dmb(0xBu);
        do
          v50 = __ldrex((unsigned int *)v34);
        while ( v50 == v60 && __strex(v61, (unsigned int *)v34) );
        if ( v50 != v60 )
LABEL_95:
          ExfReleasePushLock((_DWORD *)(v7 + 8), v60);
        v51 = KeAbPostRelease(v7 + 8);
        v52 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v53 = *(_WORD *)(v52 + 0x134) + 1;
        *(_WORD *)(v52 + 308) = v53;
        if ( !v53 && *(_DWORD *)(v52 + 100) != v52 + 100 && !*(_WORD *)(v52 + 310) )
          KiCheckForKernelApcDelivery(v51);
        if ( v28 >= 0 )
          goto LABEL_26;
      }
      v30 = a1;
LABEL_25:
      ObfDereferenceObject(v30);
LABEL_26:
      v31 = v14[6];
      if ( v31 )
      {
        SeReleaseSecurityDescriptor(v31, *((char *)v14 + 8), 1);
        v14[6] = 0;
      }
      v62 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v63 = *(_DWORD *)(v62 + 2848);
      v64 = *(unsigned __int16 *)(v63 + 8);
      ++*(_DWORD *)(v63 + 20);
      if ( *(unsigned __int16 *)(v63 + 4) < v64
        || (++*(_DWORD *)(v63 + 24),
            v63 = *(_DWORD *)(v62 + 2852),
            v65 = *(unsigned __int16 *)(v63 + 8),
            ++*(_DWORD *)(v63 + 20),
            *(unsigned __int16 *)(v63 + 4) < v65) )
      {
        RtlpInterlockedPushEntrySList((unsigned __int64 *)v63, v14);
      }
      else
      {
        ++*(_DWORD *)(v63 + 24);
        (*(void (__fastcall **)(_DWORD *))(v63 + 44))(v14);
      }
      if ( a2 == v79 )
      {
        SepDeleteAccessState((int)a2);
        ObFastDereferenceObject(
          (_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244),
          *((_DWORD *)a2 + 9));
        v49 = *((_DWORD *)a2 + 7);
        *((_DWORD *)a2 + 9) = 0;
        if ( v49 )
          ObfDereferenceObject(v49);
        *((_DWORD *)a2 + 7) = 0;
      }
      return v28;
    }
    ObfDereferenceObject(a1);
    if ( a2 == v79 )
    {
      SepDeleteAccessState((int)a2);
      SeReleaseSubjectContext((int)(a2 + 28));
    }
    result = v70;
  }
  return result;
}
