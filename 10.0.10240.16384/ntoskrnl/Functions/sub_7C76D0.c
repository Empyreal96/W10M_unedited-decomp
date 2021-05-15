// sub_7C76D0 
 
// local variable allocation has failed, the output may be wrong!
int sub_7C76D0()
{
  _DWORD *v0; // r6
  int v1; // t1
  _DWORD *v2; // r5
  int v3; // r10
  int (__fastcall *v4)(_DWORD); // r1
  int (__fastcall *v5)(_DWORD); // r2
  int (__fastcall *v6)(_DWORD); // r3
  unsigned int v7; // r2
  unsigned __int8 *v8; // r4
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r2
  BOOL v12; // r5
  int v13; // r1
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  int v20; // r5
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  _DWORD *v27; // r4
  _DWORD *v28; // r5
  unsigned int *v29; // r2
  unsigned int v30; // r1
  unsigned int *v31; // r4
  unsigned int v32; // t1
  int v34; // r3
  int v35; // r5
  int v36; // r4
  unsigned int v37; // r5
  _DWORD *v38; // r6
  int v39; // r7
  unsigned int *v40; // r8
  int v41; // r9
  int v42; // r10
  _DWORD *v43; // r4
  unsigned int v44; // r2
  unsigned __int8 *v45; // r5
  int v46; // r0
  int v47; // r6
  unsigned int v48; // r2
  int v49; // r1
  int v50; // r2
  int v51; // r3
  int v52; // r1
  unsigned int v53; // r0
  unsigned int v54; // r2
  int v55; // r0
  unsigned int v56; // r1
  __int16 v57; // r3
  int v58; // r6
  unsigned int v59; // r4
  unsigned int v60; // r1
  unsigned int v61; // r7
  int v62; // r1 OVERLAPPED
  int *v63; // r9
  int v64; // r8
  unsigned int v65; // r0
  int v66; // r3
  int v67; // r2
  int v68; // r4
  int v69; // r5
  unsigned int v70; // r2
  unsigned int v71; // r4
  unsigned int v72; // r1
  int v73; // r0
  unsigned int v74; // r1
  int v75; // r3
  __int64 v76; // [sp+8h] [bp-58h] BYREF
  int v77; // [sp+10h] [bp-50h]
  int v78; // [sp+14h] [bp-4Ch]
  int v79; // [sp+18h] [bp-48h]
  int v80; // [sp+1Ch] [bp-44h]
  int v81; // [sp+20h] [bp-40h]
  int v82; // [sp+24h] [bp-3Ch]
  int (__fastcall *v83[14])(_DWORD); // [sp+28h] [bp-38h] BYREF

  ExpAcquireFastMutexContended((int)v40, v36);
  if ( v36 )
    *(_BYTE *)(v36 + 14) |= 1u;
  v40[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v40[7] = v37;
  if ( (_DWORD *)*v38 == v38 )
  {
    HIDWORD(v76) = &v76;
    LODWORD(v76) = &v76;
  }
  else
  {
    v76 = *(_QWORD *)(v41 + 112);
    *(_DWORD *)(v76 + 4) = &v76;
    *(_DWORD *)HIDWORD(v76) = &v76;
    *v38 = v38;
    v38[1] = v38;
  }
  if ( (*(_DWORD *)(v41 + 124) & 2) != 0 )
  {
    v39 = 0;
    v77 = 0;
  }
  if ( !v39 )
    goto LABEL_7;
  v58 = *(_DWORD *)(v41 + 120);
  v79 = v58;
  if ( v58 )
  {
    v42 = ExAllocatePoolWithTag(1, 4 * v58, 1483763280);
    v80 = v42;
    if ( v42 )
    {
      v27 = *(_DWORD **)(v41 + 104);
      if ( v27 != (_DWORD *)(v41 + 104) )
      {
        v28 = (_DWORD *)v42;
        do
        {
          *v28++ = v27;
          __dmb(0xBu);
          v29 = v27 + 28;
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 + 1, v29) );
          __dmb(0xBu);
          v27 = (_DWORD *)*v27;
        }
        while ( v27 != (_DWORD *)(v41 + 104) );
      }
    }
    else
    {
      v39 = 0;
      v77 = 0;
    }
  }
  if ( !v39 )
  {
LABEL_7:
    v43 = *(_DWORD **)(v41 + 104);
    if ( v43 != (_DWORD *)(v41 + 104) )
    {
      do
      {
        v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v44 + 308);
        v45 = (unsigned __int8 *)(v43 + 8);
        v46 = KeAbPreAcquire((unsigned int)(v43 + 8), 0, 0);
        v47 = v46;
        do
          v48 = __ldrex(v45);
        while ( __strex(v48 | 1, v45) );
        __dmb(0xBu);
        if ( (v48 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(v43 + 8, v46, (unsigned int)(v43 + 8));
        if ( v47 )
          *(_BYTE *)(v47 + 14) |= 1u;
        v43[29] |= 1u;
        PiDqQueryFreeActiveData((int)v43);
        PiDqQueryCompletePendedIrp(v43, v49, v50, v51);
        __pld(v45);
        v52 = *(_DWORD *)v45;
        if ( (*(_DWORD *)v45 & 0xFFFFFFF0) <= 0x10 )
          v53 = 0;
        else
          v53 = v52 - 16;
        if ( (v52 & 2) != 0 )
          goto LABEL_22;
        __dmb(0xBu);
        do
          v54 = __ldrex((unsigned int *)v45);
        while ( v54 == v52 && __strex(v53, (unsigned int *)v45) );
        if ( v54 != v52 )
LABEL_22:
          ExfReleasePushLock(v43 + 8, v52);
        v55 = KeAbPostRelease((unsigned int)(v43 + 8));
        v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v57 = *(_WORD *)(v56 + 0x134) + 1;
        *(_WORD *)(v56 + 308) = v57;
        if ( !v57 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
          KiCheckForKernelApcDelivery(v55);
        v43 = (_DWORD *)*v43;
      }
      while ( v43 != (_DWORD *)(v41 + 104) );
      v42 = v80;
      v40 = (unsigned int *)(v41 + 56);
    }
    v58 = v79;
    *(_DWORD *)(v41 + 124) &= 0xFFFFFFFD;
  }
  v59 = v40[7];
  v40[1] = 0;
  __dmb(0xBu);
  do
    v60 = __ldrex(v40);
  while ( !v60 && __strex(1u, v40) );
  if ( v60 )
    ExpReleaseFastMutexContended(v40, v60);
  KfLowerIrql((unsigned __int8)v59);
  KeAbPostRelease((unsigned int)v40);
  while ( 1 )
  {
    v61 = v76;
    if ( (__int64 *)v76 == &v76 )
      break;
    *(_QWORD *)&v62 = *(_QWORD *)v76;
    if ( *(__int64 **)(v76 + 4) != &v76 || *(_DWORD *)(v62 + 4) != (_DWORD)v76 )
      __fastfail(3u);
    LODWORD(v76) = v62;
    *(_DWORD *)(v62 + 4) = &v76;
    if ( v77 && v58 )
    {
      v63 = (int *)v42;
      v64 = v58;
      do
      {
        v1 = *v63++;
        v0 = (_DWORD *)v1;
        if ( *(_QWORD *)(v1 + 120) <= *(_QWORD *)(v61 + 16) )
        {
          v2 = (_DWORD *)v0[3];
          v3 = 0;
          if ( !PnpIsNullGuid((int)v2) )
          {
            v4 = (int (__fastcall *)(_DWORD))v2[1];
            v5 = (int (__fastcall *)(_DWORD))v2[2];
            v6 = (int (__fastcall *)(_DWORD))v2[3];
            v83[0] = *(int (__fastcall **)(_DWORD))v2;
            v83[1] = v4;
            v83[2] = v5;
            v83[3] = v6;
            v81 = IoSetActivityIdThread((int)v83);
            v3 = 1;
          }
          if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x400000) != 0 )
            Template_p(Microsoft_Windows_Kernel_PnPHandle, dword_649E54, (int)KMPnPEvt_DevQuery_ProcessingStart, v0[3]);
          v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v7 + 308);
          v8 = (unsigned __int8 *)(v0 + 8);
          v9 = KeAbPreAcquire((unsigned int)(v0 + 8), 0, 0);
          v10 = v9;
          do
            v11 = __ldrex(v8);
          while ( __strex(v11 | 1, v8) );
          __dmb(0xBu);
          if ( (v11 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v0 + 8, v9, (unsigned int)(v0 + 8));
          if ( v10 )
            *(_BYTE *)(v10 + 14) |= 1u;
          v12 = (v0[29] & 9) == 0;
          __pld(v8);
          v13 = *(_DWORD *)v8;
          if ( (*(_DWORD *)v8 & 0xFFFFFFF0) > 0x10 )
            v65 = v13 - 16;
          else
            v65 = 0;
          if ( (v13 & 2) != 0 )
            goto LABEL_43;
          __dmb(0xBu);
          do
            v14 = __ldrex((unsigned int *)v8);
          while ( v14 == v13 && __strex(v65, (unsigned int *)v8) );
          if ( v14 != v13 )
LABEL_43:
            ExfReleasePushLock(v0 + 8, v13);
          v15 = KeAbPostRelease((unsigned int)(v0 + 8));
          v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
          *(_WORD *)(v16 + 308) = v17;
          if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
            KiCheckForKernelApcDelivery(v15);
          if ( v12 )
          {
            PiDqQueryApplyObjectEvent((int)v0, *(_DWORD **)(v61 + 8));
            v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v18 + 308);
            v19 = KeAbPreAcquire((unsigned int)(v0 + 8), 0, 0);
            v20 = v19;
            do
              v67 = __ldrex(v8);
            while ( __strex(v67 | 1, v8) );
            __dmb(0xBu);
            if ( (v67 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx(v0 + 8, v19, (unsigned int)(v0 + 8));
            if ( v20 )
              *(_BYTE *)(v20 + 14) |= 1u;
            v66 = v0[29];
            if ( (v66 & 1) != 0 || (v67 = (int)(v0 + 25), v66 = v0[25], (_DWORD *)v66 != v0 + 25) )
              PiDqQueryCompletePendedIrp(v0, 1, v67, v66);
            __pld(v8);
            v21 = *(_DWORD *)v8;
            if ( (*(_DWORD *)v8 & 0xFFFFFFF0) > 0x10 )
              v22 = v21 - 16;
            else
              v22 = 0;
            if ( (v21 & 2) != 0 )
              goto LABEL_114;
            __dmb(0xBu);
            do
              v23 = __ldrex((unsigned int *)v8);
            while ( v23 == v21 && __strex(v22, (unsigned int *)v8) );
            if ( v23 != v21 )
LABEL_114:
              ExfReleasePushLock(v0 + 8, v21);
            v24 = KeAbPostRelease((unsigned int)(v0 + 8));
            v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
            *(_WORD *)(v25 + 308) = v26;
            if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
              KiCheckForKernelApcDelivery(v24);
          }
          if ( (Microsoft_Windows_Kernel_PnPEnableBits & 0x400000) != 0 )
            Template_p(Microsoft_Windows_Kernel_PnPHandle, dword_649E54, (int)KMPnPEvt_DevQuery_ProcessingStop, v0[3]);
          if ( v3 )
            IoClearActivityIdThread(v81);
        }
        --v64;
      }
      while ( v64 );
      v41 = v82;
      v40 = (unsigned int *)(v82 + 56);
    }
    PiPnpRtlObjectEventRelease(*(unsigned int **)(v61 + 8));
    ExFreePoolWithTag(v61);
    v58 = v79;
    v42 = v80;
  }
  if ( v42 )
  {
    if ( v58 )
    {
      v31 = (unsigned int *)v42;
      do
      {
        v32 = *v31++;
        PiDqQueryRelease(v32);
        --v58;
      }
      while ( v58 );
    }
    ExFreePoolWithTag(v42);
  }
  v68 = KeAbPreAcquire((unsigned int)v40, 0, 0);
  v69 = KfRaiseIrql(1);
  do
    v70 = __ldrex((unsigned __int8 *)v40);
  while ( __strex(v70 & 0xFE, (unsigned __int8 *)v40) );
  __dmb(0xBu);
  if ( (v70 & 1) == 0 )
    ExpAcquireFastMutexContended((int)v40, v68);
  if ( v68 )
    *(_BYTE *)(v68 + 14) |= 1u;
  v40[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v40[7] = v69;
  if ( *(_DWORD *)(v41 + 112) != v41 + 112 || (v34 = *(_DWORD *)(v41 + 124), (v34 & 2) != 0) )
  {
    v35 = v78;
  }
  else
  {
    v35 = 0;
    v78 = 0;
    *(_DWORD *)(v41 + 124) = v34 & 0xFFFFFFFE;
  }
  v71 = v40[7];
  v40[1] = 0;
  __dmb(0xBu);
  do
    v72 = __ldrex(v40);
  while ( !v72 && __strex(1u, v40) );
  if ( v72 )
    ExpReleaseFastMutexContended(v40, v72);
  KfLowerIrql((unsigned __int8)v71);
  KeAbPostRelease((unsigned int)v40);
  v73 = ExReleaseResourceLite(v41);
  v74 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v75 = (__int16)(*(_WORD *)(v74 + 0x134) + 1);
  *(_WORD *)(v74 + 308) = v75;
  if ( !v75 && *(_DWORD *)(v74 + 100) != v74 + 100 && !*(_WORD *)(v74 + 310) )
    v73 = KiCheckForKernelApcDelivery(v73);
  if ( v35 )
    JUMPOUT(0x6CCE36);
  return v83[13](v73);
}
