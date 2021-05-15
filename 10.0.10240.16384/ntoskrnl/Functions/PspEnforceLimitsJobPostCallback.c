// PspEnforceLimitsJobPostCallback 
 
int __fastcall PspEnforceLimitsJobPostCallback(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char a17)
{
  int v19; // r3
  unsigned int v20; // r7
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  unsigned int v25; // r10
  __int64 v26; // kr08_8
  int v27; // r0
  __int16 v28; // r3
  int v29; // r4
  __int64 v30; // r2
  int v31; // r2
  unsigned int v32; // r10
  int v33; // r6
  char *v34; // r9
  int v35; // r1
  unsigned int v36; // r3
  unsigned int v37; // r0
  int v38; // r9
  int v39; // r3
  __int64 v40; // kr10_8
  int v41; // r2
  bool v42; // cf
  int v43; // r3
  int v44; // r2
  unsigned int v45; // r1
  int v46; // r2
  int v47; // r2
  int v48; // r3
  _QWORD *v49; // r5
  int v50; // r0
  int v51; // r3
  int v52; // r0
  int v53; // r0
  __int16 v54; // r3
  unsigned __int64 v56; // r2
  unsigned int *v57; // r6
  int v58; // r0
  int v59; // r9
  unsigned int v60; // r2
  int v61; // r0
  unsigned int v62; // r1
  unsigned int v63; // r2
  unsigned int v64; // r2
  int v65; // r0
  int v66; // r3
  int v67; // r2
  int v68; // r1
  int v69; // r6
  char *v70; // r9
  int v71; // r1
  int v72; // r0
  int v73; // r3
  unsigned int *v74; // r2
  unsigned int v75; // r0
  __int64 v76; // kr70_8
  int v77; // r0
  __int16 v78; // r3
  int v79; // r2
  int v80; // r3
  int v81; // r0
  int v82; // r3
  int v83; // [sp+0h] [bp-F0h]
  __int64 v84; // [sp+4h] [bp-ECh]
  unsigned int v85; // [sp+Ch] [bp-E4h]
  unsigned int v86; // [sp+10h] [bp-E0h]
  unsigned int v87; // [sp+14h] [bp-DCh]
  unsigned int v88; // [sp+18h] [bp-D8h]
  int v89; // [sp+1Ch] [bp-D4h]
  _DWORD v90[2]; // [sp+20h] [bp-D0h] BYREF
  unsigned __int64 v91; // [sp+28h] [bp-C8h] BYREF
  int v92[4]; // [sp+30h] [bp-C0h] BYREF
  __int64 v93[8]; // [sp+40h] [bp-B0h] BYREF
  char v94[8]; // [sp+80h] [bp-70h] BYREF
  __int64 v95; // [sp+88h] [bp-68h]
  __int64 v96; // [sp+B8h] [bp-38h]
  __int64 v97; // [sp+C0h] [bp-30h]

  v19 = __mrc(15, 0, 13, 0, 3);
  v20 = v19 & 0xFFFFFFC0;
  if ( (v19 & 0xFFFFFFC0) != 0 )
    --*(_WORD *)((v19 & 0xFFFFFFC0) + 0x136);
  v21 = ExAcquireResourceSharedLite(a1 + 32, 1);
  v24 = *(_DWORD *)(a1 + 520);
  if ( v24 )
    return sub_7C2890(v21, v22, v23, v24, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17);
  memset(v93, 0, sizeof(v93));
  memmove((int)v94, a1 + 600, 0x50u);
  v25 = *(_DWORD *)(a1 + 272);
  v26 = *(_QWORD *)(a1 + 264);
  v88 = *(_DWORD *)(a1 + 276);
  v87 = *(_DWORD *)(a1 + 88);
  v83 = *(_DWORD *)(a1 + 92);
  v86 = *(_DWORD *)(a1 + 112);
  v85 = *(_DWORD *)(a1 + 116);
  v89 = *(_DWORD *)(a1 + 208);
  if ( (*(_DWORD *)(a1 + 176) & 4) != 0 )
  {
    HIDWORD(v84) = *(_DWORD *)(a1 + 160);
    LODWORD(v84) = *(_DWORD *)(a1 + 164);
  }
  else
  {
    v84 = 0i64;
  }
  PspGetEffectiveNoWakeCharge(a1, &v91, v90);
  v27 = ExReleaseResourceLite(a1 + 32);
  if ( v20 )
  {
    v28 = *(_WORD *)(v20 + 310) + 1;
    *(_WORD *)(v20 + 310) = v28;
    if ( !v28 && *(_DWORD *)(v20 + 100) != v20 + 100 )
      KiCheckForKernelApcDelivery(v27);
  }
  v29 = 0;
  if ( v93[0] && (unsigned __int64)(v96 + v26) > v93[0] )
    v29 = 0x10000;
  if ( v93[1] && v97 + __PAIR64__(v88, v25) > v93[1] )
    v29 |= 0x20000u;
  LODWORD(v30) = v95;
  if ( v93[2] )
  {
    HIDWORD(v30) = v83;
    v56 = v30 + __PAIR64__(HIDWORD(v95), v87);
    if ( v56 > v93[2] )
      v29 |= 4u;
  }
  v31 = HIDWORD(v93[4]);
  v32 = v93[3];
  if ( v93[4] || v93[3] )
  {
    if ( v20 )
      --*(_WORD *)(v20 + 310);
    v57 = (unsigned int *)(a1 + 552);
    v58 = KeAbPreAcquire(a1 + 552, 0, 0);
    v59 = v58;
    do
      v60 = __ldrex(v57);
    while ( !v60 && __strex(0x11u, v57) );
    __dmb(0xBu);
    if ( v60 )
      ExfAcquirePushLockSharedEx((_DWORD *)(a1 + 552), v58, a1 + 552);
    if ( v59 )
      *(_BYTE *)(v59 + 14) |= 1u;
    if ( (*(_DWORD *)(a1 + 176) & 0x200000) != 0 )
    {
      v61 = 1;
      v63 = (*(_QWORD *)(a1 + 512) + (unsigned __int64)*(unsigned int *)(a1 + 756)) >> 32;
      v62 = *(_DWORD *)(a1 + 512) + *(_DWORD *)(a1 + 756);
    }
    else
    {
      v61 = 0;
      v62 = 0;
      v63 = 0;
    }
    if ( v93[4] )
    {
      if ( v61 )
      {
LABEL_76:
        if ( __PAIR64__(v63, v62) > v93[4] )
          goto LABEL_77;
LABEL_78:
        if ( v32 | HIDWORD(v93[3]) )
        {
          if ( v61 )
            goto LABEL_82;
          if ( *(_QWORD *)(a1 + 512) <= __PAIR64__(HIDWORD(v93[3]), v32) )
            goto LABEL_85;
        }
        if ( !v61 )
          goto LABEL_86;
LABEL_82:
        if ( v63 > HIDWORD(v93[3]) || v63 >= HIDWORD(v93[3]) && v62 > v32 )
        {
LABEL_86:
          __dmb(0xBu);
          do
            v64 = __ldrex(v57);
          while ( v64 == 17 && __strex(0, v57) );
          if ( v64 != 17 )
            ExfReleasePushLockShared((_DWORD *)(a1 + 552));
          v65 = KeAbPostRelease(a1 + 552);
          if ( v20 )
          {
            v66 = (__int16)(*(_WORD *)(v20 + 310) + 1);
            *(_WORD *)(v20 + 310) = v66;
            if ( !v66 )
            {
              v31 = v20 + 100;
              if ( *(_DWORD *)(v20 + 100) != v20 + 100 )
                KiCheckForKernelApcDelivery(v65);
            }
          }
          goto LABEL_15;
        }
LABEL_85:
        v29 |= 0x8000u;
        goto LABEL_86;
      }
      if ( *(_QWORD *)(a1 + 512) > v93[4] )
      {
LABEL_77:
        v29 |= 0x200u;
        goto LABEL_86;
      }
    }
    if ( !v61 )
      goto LABEL_78;
    goto LABEL_76;
  }
LABEL_15:
  v33 = 0;
  v34 = (char *)v93 - a2;
  v35 = a2;
  do
  {
    v36 = (unsigned int)&v34[v35];
    v37 = *(_DWORD *)&v34[v35 + 40];
    if ( v37 )
    {
      v31 = *(_DWORD *)(v35 + 24);
      v36 = *(_DWORD *)(v36 + 52);
      if ( v31 == v36 )
      {
        v36 = *(_DWORD *)(v35 + 36);
        if ( v36 >= v37 )
          v29 |= PspRateControlLimitFlag(v33);
      }
    }
    ++v33;
    v35 += 4;
  }
  while ( v33 < 3 );
  v38 = HIDWORD(v93[3]);
  if ( v29 )
  {
    if ( v20 )
    {
      v36 = *(__int16 *)(v20 + 310) - 1;
      *(_WORD *)(v20 + 310) = v36;
    }
    ExAcquireResourceExclusiveLite(a1 + 32, 1, v31, v36);
    v67 = *(_DWORD *)(a1 + 520);
    if ( v67 )
    {
      *(_DWORD *)(v67 + 4) |= v29;
      v68 = *(_DWORD *)(a1 + 520) + 72;
      if ( (v29 & 0x10000) != 0 )
        *(_QWORD *)v68 = v93[0];
      if ( (v29 & 0x20000) != 0 )
        *(_QWORD *)(v68 + 8) = v93[1];
      if ( (v29 & 4) != 0 )
        *(_QWORD *)(v68 + 16) = v93[2];
      if ( (v29 & 0x200) != 0 )
        *(_QWORD *)(v68 + 32) = v93[4];
      if ( (v29 & 0x8000) != 0 )
      {
        *(_DWORD *)(v68 + 24) = v32;
        *(_DWORD *)(v68 + 28) = v38;
      }
      v69 = 0;
      v70 = (char *)v93 - v68;
      do
      {
        if ( (PspRateControlLimitFlag(v69) & v29) != 0 )
        {
          *(_DWORD *)(v71 + 40) = *(_DWORD *)&v70[v71 + 40];
          *(_DWORD *)(v71 + 52) = *(_DWORD *)&v70[v71 + 52];
        }
        ++v69;
      }
      while ( v69 < 3 );
    }
    if ( *(_DWORD *)(a1 + 212) && (*(_DWORD *)(a1 + 428) & 0x800) != 0 && (*(_DWORD *)(a1 + 744) & 4) == 0 )
      PspSendReliableJobNotification((int *)a1, 11);
    v72 = ExReleaseResourceLite(a1 + 32);
    if ( v20 )
    {
      v73 = (__int16)(*(_WORD *)(v20 + 310) + 1);
      *(_WORD *)(v20 + 310) = v73;
      if ( !v73 && *(_DWORD *)(v20 + 100) != v20 + 100 )
        KiCheckForKernelApcDelivery(v72);
    }
  }
  v39 = *(_DWORD *)(a2 + 12);
  if ( v39 )
  {
    if ( (*(_DWORD *)(v39 + 188) & 1) == 0 )
    {
      __dmb(0xBu);
      v74 = (unsigned int *)(*(_DWORD *)(a2 + 12) + 188);
      do
        v75 = __ldrex(v74);
      while ( __strex(v75 & 0xFFFFFFDF, v74) );
      __dmb(0xBu);
      v76 = *(_QWORD *)(a2 + 8);
      v92[0] = *(_DWORD *)(a2 + 8);
      v92[1] = 2;
      v92[2] = *(_DWORD *)(HIDWORD(v76) + 176);
      PspRemoveProcessFromJobChain((_DWORD *)HIDWORD(v76), v92, 14, 1816);
    }
    ObfDereferenceObject(*(_DWORD *)(a2 + 12));
  }
  if ( !v84 || __PAIR64__(v85, v86) + v95 <= __PAIR64__(v84, HIDWORD(v84)) )
    goto LABEL_21;
  if ( v89 )
  {
    if ( v89 == 1 )
    {
      if ( v20 )
        --*(_WORD *)(v20 + 310);
      ExAcquireResourceSharedLite(a1 + 32, 1);
      if ( !*(_DWORD *)(a1 + 212) || (*(_DWORD *)(a1 + 428) & 2) == 0 )
      {
        v77 = ExReleaseResourceLite(a1 + 32);
        if ( v20 )
        {
          v78 = *(_WORD *)(v20 + 310) + 1;
          *(_WORD *)(v20 + 310) = v78;
          if ( !v78 && *(_DWORD *)(v20 + 100) != v20 + 100 )
            KiCheckForKernelApcDelivery(v77);
        }
        PspTerminateAllProcessesInJobHierarchy(a1, 1816, 1);
        goto LABEL_21;
      }
      if ( PspSendJobNotification(a1) >= 0 )
      {
        *(_DWORD *)(a1 + 176) &= 0xFFFFFFFB;
        *(_DWORD *)(a1 + 160) = 0;
        *(_DWORD *)(a1 + 164) = 0;
      }
      goto LABEL_149;
    }
  }
  else if ( PspTerminateAllProcessesInJobHierarchy(a1, 1816, 1) )
  {
    if ( v20 )
    {
      v80 = *(__int16 *)(v20 + 310) - 1;
      *(_WORD *)(v20 + 310) = v80;
    }
    ExAcquireResourceExclusiveLite(a1 + 32, 1, v79, v80);
    if ( !*(_DWORD *)(a1 + 144) && *(_DWORD *)(a1 + 212) && (*(_DWORD *)(a1 + 428) & 2) != 0 )
      PspSendJobNotification(a1);
LABEL_149:
    v81 = ExReleaseResourceLite(a1 + 32);
    if ( v20 )
    {
      v82 = (__int16)(*(_WORD *)(v20 + 310) + 1);
      *(_WORD *)(v20 + 310) = v82;
      if ( !v82 && *(_DWORD *)(v20 + 100) != v20 + 100 )
        KiCheckForKernelApcDelivery(v81);
    }
    goto LABEL_21;
  }
LABEL_21:
  v40 = *(_QWORD *)(a2 + 16);
  v41 = v90[1];
  v42 = __CFADD__(v90[0], (_DWORD)v40);
  *(_DWORD *)(a2 + 16) = v90[0] + v40;
  v43 = *(unsigned __int8 *)(a2 + 48);
  v44 = HIDWORD(v40) + v42 + v41;
  *(_DWORD *)(a2 + 20) = v44;
  if ( !v43 )
  {
    v45 = *(_DWORD *)(a2 + 16);
    if ( v44 || v45 >= PspSystemNoWakeChargeLimit )
    {
      PspSendNoWakeChargeLimitNotification(0, v45);
      *(_BYTE *)(a2 + 48) = 1;
    }
    else
    {
      v43 = HIDWORD(v91);
      if ( v91 >= (unsigned int)PspJobNoWakeChargeLimit )
        PspSendNoWakeChargeLimitNotification(a1, v91);
    }
  }
  v46 = *(_DWORD *)(a1 + 572);
  if ( v46 )
  {
    if ( v20 )
    {
      v43 = *(__int16 *)(v20 + 310) - 1;
      *(_WORD *)(v20 + 310) = v43;
    }
    ExAcquireResourceExclusiveLite(v46 + 32, 1, v46, v43);
    if ( v20 )
    {
      v48 = *(__int16 *)(v20 + 310) - 1;
      *(_WORD *)(v20 + 310) = v48;
    }
    ExAcquireResourceExclusiveLite(a1 + 32, 1, v47, v48);
    v49 = (_QWORD *)(*(_DWORD *)(a1 + 572) + 600);
    *v49 += *(_QWORD *)(a1 + 600);
    v49[1] += *(_QWORD *)(a1 + 608);
    v49[2] += *(_QWORD *)(a1 + 616);
    v49[3] += *(_QWORD *)(a1 + 624);
    v49[4] += *(_QWORD *)(a1 + 632);
    v49[5] += *(_QWORD *)(a1 + 640);
    v49[6] += *(_QWORD *)(a1 + 648);
    v49[7] += *(_QWORD *)(a1 + 656);
    v49[8] += *(_QWORD *)(a1 + 664);
    v49[9] += *(_QWORD *)(a1 + 672);
    memset((_BYTE *)(a1 + 600), 0, 80);
    v50 = ExReleaseResourceLite(a1 + 32);
    if ( v20 )
    {
      v51 = (__int16)(*(_WORD *)(v20 + 310) + 1);
      *(_WORD *)(v20 + 310) = v51;
      if ( !v51 && *(_DWORD *)(v20 + 100) != v20 + 100 )
        KiCheckForKernelApcDelivery(v50);
    }
    v52 = *(_DWORD *)(a1 + 572) + 32;
  }
  else
  {
    if ( v20 )
    {
      v43 = *(__int16 *)(v20 + 310) - 1;
      *(_WORD *)(v20 + 310) = v43;
    }
    ExAcquireResourceExclusiveLite(a1 + 32, 1, 0, v43);
    memset((_BYTE *)(a1 + 600), 0, 80);
    v52 = a1 + 32;
  }
  v53 = ExReleaseResourceLite(v52);
  if ( v20 )
  {
    v54 = *(_WORD *)(v20 + 310) + 1;
    *(_WORD *)(v20 + 310) = v54;
    if ( !v54 && *(_DWORD *)(v20 + 100) != v20 + 100 )
      KiCheckForKernelApcDelivery(v53);
  }
  return 0;
}
