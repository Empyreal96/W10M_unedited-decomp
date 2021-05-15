// sub_7FF478 
 
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_7FF478(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, unsigned int *a16)
{
  __int64 v16; // kr00_8
  int v17; // r0
  int v18; // r0
  int v19; // r1
  _DWORD *v20; // r10
  _DWORD *v21; // r7
  unsigned int v22; // r8
  unsigned int v23; // r4
  int v24; // r3
  int v25; // r4
  int *v26; // r4
  int v27; // r0
  _DWORD *v28; // r8
  unsigned int v29; // r7
  int v30; // r3
  unsigned int v31; // r0
  int v32; // r0
  unsigned int v33; // r0
  _DWORD *v34; // r0
  unsigned int v35; // r3
  int v36; // r4
  unsigned int v37; // r2
  int v38; // r3
  __int16 v39; // r2
  int v40; // r4
  unsigned int *v41; // r0
  unsigned int v42; // r2
  unsigned int v43; // r2
  int v44; // r0
  unsigned int v45; // r1
  int v46; // r3
  unsigned int v47; // r2
  unsigned int v48; // r2
  __int16 v49; // r3
  unsigned int *v50; // r8
  int v51; // r0
  int v52; // r4
  unsigned int v53; // r2
  unsigned int v54; // r2
  int v55; // r0
  unsigned int v56; // r1
  int v57; // r3
  _DWORD *v58; // r6
  int v59; // r7
  int v60; // r9
  int v61; // r10
  unsigned int v62; // r3
  unsigned int v63; // r8
  int v64; // r4
  int v65; // r5
  int v66; // r4
  unsigned int v67; // r3
  int v68; // r6
  unsigned int v69; // r2
  unsigned int v70; // r2
  int v71; // r4
  int v72; // r8
  int v73; // r3
  unsigned int *v74; // r2
  unsigned int v75; // r1
  int *v76; // r7
  int v77; // r1
  unsigned int v78; // r0
  unsigned int v79; // r2
  int v80; // r0
  int v81; // r0
  unsigned int v82; // r1
  int v83; // r3
  _DWORD *v84; // r0
  unsigned int v85; // r3
  int v86; // r4
  unsigned int v87; // r2
  unsigned int v88; // r2
  int v89; // r3
  unsigned int *v90; // r2
  unsigned int v91; // r1
  unsigned int v92; // r1
  unsigned int v93; // r3
  int v94; // r4
  unsigned int v95; // r2
  unsigned int v96; // r2
  int v97; // [sp-44h] [bp-44h]
  int v98; // [sp-40h] [bp-40h]
  unsigned int *v99; // [sp-40h] [bp-40h]
  int v100; // [sp-3Ch] [bp-3Ch]
  unsigned int v101; // [sp-38h] [bp-38h] BYREF
  int v102; // [sp-34h] [bp-34h] BYREF
  _DWORD *v103; // [sp-30h] [bp-30h]
  _DWORD v104[11]; // [sp-2Ch] [bp-2Ch] BYREF

  if ( !v61 )
    JUMPOUT(0x73739A);
  v62 = (unsigned int)KeGetPcr();
  v63 = (v62 & 0xFFFFF000) + 1408;
  v64 = *(_DWORD *)((v62 & 0xFFFFF000) + 0xB40);
  ++*(_DWORD *)(v64 + 12);
  v65 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v64);
  if ( !v65 )
  {
    ++*(_DWORD *)(v64 + 16);
    v66 = *(_DWORD *)(v63 + 1476);
    ++*(_DWORD *)(v66 + 12);
    v65 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v66);
    if ( !v65 )
    {
      v16 = *(_QWORD *)(v66 + 32);
      v17 = *(_DWORD *)(v66 + 28);
      ++*(_DWORD *)(v66 + 16);
      v18 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v66 + 40))(v17, HIDWORD(v16), v16);
      v65 = v18;
      if ( !v18 )
LABEL_44:
        __asm { POP.W           {R4-R11,PC} }
    }
  }
  *(_DWORD *)v65 = *(_DWORD *)(v63 + 20);
  if ( ObpCaptureObjectCreateInformation(v60, v60, v59, &v102, v65 + 116, 1) < 0 )
  {
    v67 = (unsigned int)KeGetPcr();
    v68 = *(_DWORD *)((v67 & 0xFFFFF000) + 0xB40);
    v69 = *(unsigned __int16 *)(v68 + 8);
    ++*(_DWORD *)(v68 + 20);
    if ( *(unsigned __int16 *)(v68 + 4) < v69
      || (++*(_DWORD *)(v68 + 24),
          v68 = *(_DWORD *)((v67 & 0xFFFFF000) + 0xB44),
          v70 = *(unsigned __int16 *)(v68 + 8),
          ++*(_DWORD *)(v68 + 20),
          *(unsigned __int16 *)(v68 + 4) < v70) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v68, (_DWORD *)v65);
    }
    else
    {
      ++*(_DWORD *)(v68 + 24);
      (*(void (__fastcall **)(int))(v68 + 44))(v65);
    }
    goto LABEL_44;
  }
  if ( !v58 )
  {
    v20 = (_DWORD *)(v61 + 52);
    v21 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v104[3] = v21[44];
    if ( v22 )
    {
      if ( (*(_DWORD *)(v22 + 960) & 8) != 0 )
      {
        v38 = __mrc(15, 0, 13, 0, 3);
        v39 = *(_WORD *)((v38 & 0xFFFFFFC0) + 0x134);
        v101 = v38 & 0xFFFFFFC0;
        *(_WORD *)((v38 & 0xFFFFFFC0) + 0x134) = v39 - 1;
        v99 = (unsigned int *)(v22 + 944);
        v40 = KeAbPreAcquire(v22 + 944, 0, 0);
        v41 = (unsigned int *)(v22 + 944);
        do
          v42 = __ldrex(v41);
        while ( !v42 && __strex(0x11u, v41) );
        __dmb(0xBu);
        if ( v42 )
          ExfAcquirePushLockSharedEx(v41, v40, v22 + 944);
        if ( v40 )
          *(_BYTE *)(v40 + 14) |= 1u;
        if ( (*(_DWORD *)(v22 + 960) & 8) != 0 )
        {
          v71 = *(_DWORD *)(v22 + 904) & 0xFFFFFFF8;
          ObfReferenceObject(v71);
          v104[1] = *(_DWORD *)(v22 + 904) & 3;
        }
        else
        {
          v71 = 0;
        }
        __dmb(0xBu);
        do
          v43 = __ldrex(v99);
        while ( v43 == 17 && __strex(0, v99) );
        if ( v43 != 17 )
          ExfReleasePushLockShared(v99);
        v44 = KeAbPostRelease((unsigned int)v99);
        v45 = v101;
        v46 = (__int16)(*(_WORD *)(v101 + 308) + 1);
        *(_WORD *)(v101 + 308) = v46;
        if ( !v46 && *(_DWORD *)(v45 + 100) != v45 + 100 && !*(_WORD *)(v45 + 310) )
          KiCheckForKernelApcDelivery(v44);
      }
      else
      {
        v71 = 0;
      }
      v104[0] = v71;
    }
    else
    {
      v104[0] = 0;
    }
    v23 = ObFastReferenceObject(v21 + 61);
    if ( !v23 )
    {
      v48 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v49 = *(_WORD *)(v48 + 0x134);
      v101 = v48;
      *(_WORD *)(v48 + 308) = v49 - 1;
      v50 = v21 + 42;
      v51 = KeAbPreAcquire((unsigned int)(v21 + 42), 0, 0);
      v52 = v51;
      do
        v53 = __ldrex(v50);
      while ( !v53 && __strex(0x11u, v50) );
      __dmb(0xBu);
      if ( v53 )
        ExfAcquirePushLockSharedEx(v21 + 42, v51, (unsigned int)(v21 + 42));
      if ( v52 )
        *(_BYTE *)(v52 + 14) |= 1u;
      v23 = ObFastReferenceObjectLocked(v21 + 61);
      __dmb(0xBu);
      do
        v54 = __ldrex(v50);
      while ( v54 == 17 && __strex(0, v50) );
      if ( v54 != 17 )
        ExfReleasePushLockShared(v21 + 42);
      v55 = KeAbPostRelease((unsigned int)(v21 + 42));
      v56 = v101;
      v57 = (__int16)(*(_WORD *)(v101 + 308) + 1);
      *(_WORD *)(v101 + 308) = v57;
      if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
        KiCheckForKernelApcDelivery(v55);
    }
    v104[2] = v23;
    if ( SepCreateAccessStateFromSubjectContext(v104, v65, v65 + 160, a14, v20) < 0 )
      goto LABEL_71;
    v61 = v97;
    v58 = (_DWORD *)v65;
  }
  v24 = *(_DWORD *)(v65 + 140);
  if ( v24 )
    v58[11] = v24;
  v25 = v58[11];
  if ( v25 )
  {
    if ( !RtlValidSecurityDescriptor(v58[11], v19) )
    {
LABEL_71:
      if ( v58 == (_DWORD *)v65 )
      {
        SepDeleteAccessState((int)v58);
        ObFastDereferenceObject((_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 244), v58[9]);
        v32 = v58[7];
        v58[9] = 0;
        if ( v32 )
          ObfDereferenceObject(v32);
        v58[7] = 0;
      }
      v33 = *(_DWORD *)(v65 + 140);
      if ( v33 )
      {
        SeReleaseSecurityDescriptor(v33, *(_BYTE *)(v65 + 124), 1);
        *(_DWORD *)(v65 + 140) = 0;
      }
      v34 = v103;
      if ( v103 )
      {
        if ( HIWORD(v102) == 248 )
        {
          v35 = (unsigned int)KeGetPcr();
          v36 = *(_DWORD *)((v35 & 0xFFFFF000) + 0xB28);
          v37 = *(unsigned __int16 *)(v36 + 8);
          ++*(_DWORD *)(v36 + 20);
          if ( *(unsigned __int16 *)(v36 + 4) < v37
            || (++*(_DWORD *)(v36 + 24),
                v36 = *(_DWORD *)((v35 & 0xFFFFF000) + 0xB2C),
                v47 = *(unsigned __int16 *)(v36 + 8),
                ++*(_DWORD *)(v36 + 20),
                *(unsigned __int16 *)(v36 + 4) < v47) )
          {
            v34 = (_DWORD *)RtlpInterlockedPushEntrySList((unsigned __int64 *)v36, v34);
          }
          else
          {
            ++*(_DWORD *)(v36 + 24);
            v34 = (_DWORD *)(*(int (**)(void))(v36 + 44))();
          }
        }
        else
        {
          v34 = (_DWORD *)ExFreePoolWithTag((unsigned int)v103);
        }
      }
      SeClearLearningModeObjectInformation((int)v34);
      v93 = (unsigned int)KeGetPcr();
      v94 = *(_DWORD *)((v93 & 0xFFFFF000) + 0xB40);
      v95 = *(unsigned __int16 *)(v94 + 8);
      ++*(_DWORD *)(v94 + 20);
      if ( *(unsigned __int16 *)(v94 + 4) < v95
        || (++*(_DWORD *)(v94 + 24),
            v94 = *(_DWORD *)((v93 & 0xFFFFF000) + 0xB44),
            v96 = *(unsigned __int16 *)(v94 + 8),
            ++*(_DWORD *)(v94 + 20),
            *(unsigned __int16 *)(v94 + 4) < v96) )
      {
        RtlpInterlockedPushEntrySList((unsigned __int64 *)v94, (_DWORD *)v65);
      }
      else
      {
        ++*(_DWORD *)(v94 + 24);
        (*(void (__fastcall **)(int))(v94 + 44))(v65);
      }
      goto LABEL_44;
    }
    if ( (*(_WORD *)(v25 + 2) & 0x10) != 0 && (v58[5] & 0x1000000) == 0 )
      v58[4] |= SeObjectCreateSaclAccessBits(v25);
  }
  v26 = (int *)(v65 + 356);
  if ( ObpLookupObjectName(
         *(_DWORD *)(v65 + 120),
         (int)&v102,
         *(_DWORD *)(v65 + 116),
         v61,
         v60,
         a15,
         *(_DWORD *)(v65 + 144),
         0,
         (int)v58,
         v65 + 356,
         &v101) >= 0 )
  {
    if ( *(_BYTE *)(v65 + 374) )
    {
      v72 = *(_DWORD *)(v65 + 360) - 24;
      v100 = v72;
      ObfReferenceObject(*(_DWORD *)(v65 + 360));
      v73 = v72 - ObpInfoMaskToOffset[*(_BYTE *)(v72 + 14) & 3];
      __dmb(0xBu);
      v74 = (unsigned int *)(v73 + 12);
      do
        v75 = __ldrex(v74);
      while ( __strex(v75 + 1, v74) );
      __dmb(0xBu);
    }
    if ( *(_BYTE *)(v65 + 374) )
    {
      v76 = (int *)(*v26 + 148);
      __pld(v76);
      v77 = *v76;
      if ( (*v76 & 0xFFFFFFF0) <= 0x10 )
        v78 = 0;
      else
        v78 = v77 - 16;
      if ( (v77 & 2) != 0 )
        goto LABEL_22;
      __dmb(0xBu);
      do
        v79 = __ldrex((unsigned int *)v76);
      while ( v79 == v77 && __strex(v78, (unsigned int *)v76) );
      if ( v79 != v77 )
LABEL_22:
        ExfReleasePushLock(v76, v77);
      KeAbPostRelease((unsigned int)v76);
      v80 = *v26;
      *(_DWORD *)(v65 + 376) = -286387660;
      v81 = ObfDereferenceObject(v80);
      *v26 = 0;
      *(_BYTE *)(v65 + 374) = 0;
      *(_BYTE *)(v65 + 375) = 0;
      v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v83 = (__int16)(*(_WORD *)(v82 + 0x134) + 1);
      *(_WORD *)(v82 + 308) = v83;
      if ( !v83 && *(_DWORD *)(v82 + 100) != v82 + 100 && !*(_WORD *)(v82 + 310) )
        KiCheckForKernelApcDelivery(v81);
    }
    v27 = *(_DWORD *)(v65 + 360);
    if ( v27 )
    {
      ObfDereferenceObject(v27);
      *(_DWORD *)(v65 + 360) = 0;
    }
    v28 = (_DWORD *)v101;
    v29 = v101 - 24;
    if ( (*(_BYTE *)(v101 - 9) & 1) != 0 )
    {
      v30 = *(_DWORD *)(v101 - 8);
      v98 = 0;
      if ( v30 )
      {
        v31 = *(_DWORD *)(v30 + 24);
        if ( v31 )
        {
          SeReleaseSecurityDescriptor(v31, *(_BYTE *)(v30 + 8), 1);
          *(_DWORD *)(*(_DWORD *)(v29 + 16) + 24) = 0;
        }
        v84 = *(_DWORD **)(v29 + 16);
        v85 = (unsigned int)KeGetPcr();
        v86 = *(_DWORD *)((v85 & 0xFFFFF000) + 0xB20);
        v87 = *(unsigned __int16 *)(v86 + 8);
        ++*(_DWORD *)(v86 + 20);
        if ( *(unsigned __int16 *)(v86 + 4) < v87
          || (++*(_DWORD *)(v86 + 24),
              v86 = *(_DWORD *)((v85 & 0xFFFFF000) + 0xB24),
              v88 = *(unsigned __int16 *)(v86 + 8),
              ++*(_DWORD *)(v86 + 20),
              *(unsigned __int16 *)(v86 + 4) < v88) )
        {
          RtlpInterlockedPushEntrySList((unsigned __int64 *)v86, v84);
        }
        else
        {
          ++*(_DWORD *)(v86 + 24);
          (*(void (__fastcall **)(_DWORD *))(v86 + 44))(v84);
        }
        *(_DWORD *)(v29 + 16) = 0;
      }
    }
    else
    {
      v98 = 1;
    }
    if ( (*(_DWORD *)(v65 + 116) & *(_DWORD *)(ObTypeIndexTable[BYTE1(v29) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v29 + 12)]
                                             + 48)) != 0
      || (v104[7] = &v102,
          v104[6] = v97 + 8,
          v104[8] = *(_DWORD *)(v65 + 120),
          SeSetLearningModeObjectInformation(),
          ObpCreateHandle(v98, v28, 0, v58, 0, *(_DWORD *)(v65 + 116), v60, 0, 0, &v101) < 0) )
    {
      PspDereferenceSiloObject((int)v28);
    }
    else
    {
      *a16 = v101;
    }
    if ( v100 )
    {
      v89 = v100 - ObpInfoMaskToOffset[*(_BYTE *)(v100 + 14) & 3];
      __dmb(0xBu);
      v90 = (unsigned int *)(v89 + 12);
      do
      {
        v91 = __ldrex(v90);
        v92 = v91 - 1;
      }
      while ( __strex(v92, v90) );
      __dmb(0xBu);
      if ( !v92 )
        ObpDeleteNameCheck(v100);
      ObfDereferenceObject(v100 + 24);
    }
  }
  goto LABEL_71;
}
