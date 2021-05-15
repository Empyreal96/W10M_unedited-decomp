// MmCreateProcessAddressSpace 
 
int __fastcall MmCreateProcessAddressSpace(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25)
{
  char v27; // r9
  __int16 *v28; // r6
  int v29; // r0
  int v30; // r1
  int v31; // r2
  int v32; // r1
  int v33; // r1
  int v34; // r9
  unsigned int v35; // r0
  unsigned int v36; // r0
  __int16 v37; // r9
  int v38; // r8
  _WORD *v39; // r10
  int v40; // r7
  __int16 v41; // r3
  int v42; // r4
  int v43; // r0
  int *v44; // r4
  int *v45; // r3
  int *v46; // lr
  unsigned int v47; // r2
  unsigned int v48; // r9
  char *v49; // r1
  int v50; // r0
  unsigned int v51; // r7
  int v52; // r0
  int v53; // r10
  int v54; // r8
  unsigned int v55; // r6
  unsigned int v56; // r4
  unsigned int v57; // r1
  unsigned int v58; // r10
  int v59; // r3
  unsigned int *v60; // r2
  unsigned int *v61; // r2
  __int64 v62; // r0
  unsigned int v63; // r4
  unsigned int *v64; // r2
  unsigned int v65; // r4
  int v66; // r1
  unsigned int *v67; // r2
  unsigned int v68; // r7
  unsigned int v69; // r3
  unsigned int v71; // r0
  int v72; // r3
  int v73; // r10
  unsigned int v74; // r3
  int v75; // r4
  unsigned int v76; // r3
  int v77; // r4
  int v78; // r3
  int v79; // r6
  unsigned int v80; // r4
  int v81; // r1
  int v82; // r2
  int v83; // r3
  int v84; // [sp+4h] [bp-48h]
  int v85; // [sp+4h] [bp-48h]
  int v86; // [sp+8h] [bp-44h]
  unsigned int v87; // [sp+8h] [bp-44h]
  unsigned int v88; // [sp+Ch] [bp-40h]
  int *v89; // [sp+10h] [bp-3Ch]
  int *v90; // [sp+10h] [bp-3Ch]
  int v91; // [sp+14h] [bp-38h] BYREF
  unsigned int v92; // [sp+1Ch] [bp-30h] BYREF
  unsigned int v93; // [sp+20h] [bp-2Ch]
  char v94; // [sp+24h] [bp-28h] BYREF
  int varg_r0; // [sp+54h] [bp+8h]
  int varg_r1; // [sp+58h] [bp+Ch]
  int varg_r2; // [sp+5Ch] [bp+10h]
  int varg_r3; // [sp+60h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v27 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v28 = MiGetThreadPartition();
  if ( !MiChargeCommit((int)v28, 3u, 0) )
    return 0;
  v84 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  *(_WORD *)(a5 + 588) = RtlRandomEx(&dword_6337A0);
  *(_DWORD *)(a5 + 872) = a5 + 872;
  *(_DWORD *)(a5 + 876) = a5 + 872;
  *(_DWORD *)(a5 + 868) = 0;
  v29 = PsGetDefaultWsMaximum();
  if ( a3 != v29 )
    return sub_7BF394(
             v29,
             v30,
             v31,
             1,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a17,
             a18,
             a19,
             a20,
             a21,
             a22,
             a23,
             a24,
             a25);
  if ( !MiChargeWsles(a5 + 492, a2, 1) )
  {
LABEL_102:
    MiReturnCommit((int)v28, 3);
    if ( v28 != MiSystemPartition )
      MiDereferencePartition((int)v28, v81, v82, v83);
    return 0;
  }
  *(_DWORD *)(a5 + 540) = a2;
  *(_DWORD *)(a5 + 560) = a3;
  if ( (v27 & 1) != 0 )
    *(_BYTE *)(a5 + 604) |= 0x40u;
  if ( PsChargeProcessQuota(a5, v32, a2) < 0 )
  {
LABEL_101:
    MiChargeWsles(a5 + 492, -a2, 1);
    goto LABEL_102;
  }
  if ( !MiChargeResident(v28, a2, 0) )
  {
LABEL_100:
    PsReturnProcessQuota(a5, v33, a2);
    goto LABEL_101;
  }
  v34 = MiReservePtes(&dword_634D58, 2u);
  v86 = v34;
  if ( !v34 )
  {
LABEL_60:
    if ( v28 == MiSystemPartition )
    {
      MiReturnResidentAvailable(a2);
      do
      {
        v71 = __ldrex(&dword_634A04[5]);
        v33 = v71 + a2;
      }
      while ( __strex(v71 + a2, &dword_634A04[5]) );
    }
    else
    {
      MiReturnPartitionResidentAvailable((int)v28, a2);
    }
    goto LABEL_100;
  }
  if ( v28 == MiSystemPartition )
  {
    do
      v35 = __ldrex(&dword_634A04[4]);
    while ( __strex(v35 + a2, &dword_634A04[4]) );
  }
  if ( !MiAllocateProcessPageDirectories(a5) )
  {
LABEL_59:
    MiReleasePtes(&dword_634D58, v34, 2u);
    goto LABEL_60;
  }
  if ( !MiJoinSession(&v91) )
  {
    MiDeleteProcessPageDirectories(a5);
    goto LABEL_59;
  }
  do
    v36 = __ldrex(&dword_634DA8);
  while ( __strex(v36 + 3, &dword_634DA8) );
  v89 = 0;
  MI_INITIALIZE_COLOR_BASE(v84 + 492, 0, (int)&v92);
  v37 = v93;
  v38 = HIWORD(v93);
  v39 = (_WORD *)v92;
  v40 = 3;
  do
  {
    v41 = *v39 + 1;
    *v39 = v41;
    v42 = (unsigned __int16)(v41 & v37);
    while ( 1 )
    {
      v43 = MiGetPage((int)v28, v42 | v38, 194);
      if ( v43 != -1 )
        break;
      MiWaitForFreePage((int)v28);
    }
    --v40;
    v44 = (int *)(MmPfnDatabase + 24 * v43);
    v45 = v89;
    v46 = v44;
    v89 = v44;
    *v44 = (int)v45;
  }
  while ( v40 );
  v47 = -1070591992;
  v48 = v86;
  v49 = &v94;
  v50 = 3;
  do
  {
    *(_DWORD *)v49 = v47;
    v49 -= 4;
    v47 = ((v47 >> 10) & 0x3FFFFC) - 0x40000000;
    --v50;
  }
  while ( v50 );
  v51 = 0;
  v52 = MmPfnDatabase;
  v87 = 0;
  v53 = ((int)v44 - MmPfnDatabase) / 24;
  v54 = 0;
  while ( 1 )
  {
    v90 = (int *)*v46;
    v85 = ((int)v46 - v52) / 24;
    v88 = *(&v92 + v54);
    *v46 = 0;
    v55 = (MiDetermineUserGlobalPteMask(0) | (v85 << 12)) & 0xFFFFF9FF | dword_681128 & 0x1EC | 0x813;
    if ( !v54 )
    {
      v55 |= 1u;
      v51 = v55;
      *v46 = a5;
    }
    MiInitializePfnForOtherProcess(v85, v88, v53, 0);
    MiMarkPageActive((int)v46);
    v56 = v48;
    if ( v54 == 1 )
    {
      v58 = v55;
      v87 = v55;
    }
    else
    {
      if ( v54 )
        v56 = v48 + 4 * v54 - 4;
      v57 = (dword_681120 & 0x1ED | (v53 << 12) | MiDetermineUserGlobalPteMask(v56)) & 0xFFFFF1FF | 0x12;
      if ( v56 < 0xC0000000 || v56 > 0xC03FFFFF )
      {
        *(_DWORD *)v56 = v57;
      }
      else
      {
        v72 = *(_DWORD *)v56;
        v73 = 0;
        __dmb(0xBu);
        *(_DWORD *)v56 = v57;
        if ( (v72 & 2) == 0 )
          v73 = 1;
        if ( v56 + 1070596096 <= 0xFFF )
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v57, v56);
        if ( v73 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v58 = v87;
      if ( v54 == 2 )
        v55 |= 1u;
    }
    v59 = ((v88 >> 2) & 0x3FF) + (v56 << 8);
    v60 = (unsigned int *)(4 * v59);
    if ( (unsigned int)(4 * v59) < 0xC0000000 || (v59 = -1069547521, (unsigned int)v60 > 0xC03FFFFF) )
    {
      *v60 = v55;
    }
    else
    {
      v74 = *v60;
      v75 = 0;
      __dmb(0xBu);
      *v60 = v55;
      if ( (v74 & 2) == 0 && (v55 & 2) != 0 )
        v75 = 1;
      v59 = (int)(v60 + 267649024);
      if ( (unsigned int)(v60 + 267649024) <= 0xFFF )
        MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v55, (__int16)v60);
      if ( v75 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    v61 = (unsigned int *)v85;
    if ( (unsigned int)++v54 > 2 )
      break;
    v46 = v90;
    v52 = MmPfnDatabase;
    v53 = v85;
  }
  HIDWORD(v62) = v91;
  *(_DWORD *)(a5 + 248) = v85;
  if ( HIDWORD(v62) )
  {
    *(_DWORD *)(a5 + 324) = HIDWORD(v62);
    __dmb(0xBu);
    v61 = (unsigned int *)(a5 + 192);
    do
    {
      v63 = __ldrex(v61);
      v59 = __strex(v63 | 0x10000, v61);
    }
    while ( v59 );
    __dmb(0xBu);
  }
  LODWORD(v62) = a5;
  MiInsertNewProcess(v62, (int)v61, v59);
  MiCopyTopLevelMappings(a5, v48 << 10);
  v64 = (unsigned int *)(4 * ((v93 >> 2) & 0x3FF) + (v48 << 10));
  if ( (unsigned int)v64 < 0xC0000000 || (unsigned int)v64 > 0xC03FFFFF )
  {
    *v64 = v58;
  }
  else
  {
    v76 = *v64;
    v77 = 0;
    __dmb(0xBu);
    *v64 = v58;
    if ( (v76 & 2) == 0 && (v58 & 2) != 0 )
      v77 = 1;
    if ( (unsigned int)(v64 + 267649024) <= 0xFFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v58, (__int16)v64);
    if ( v77 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  v65 = 4 * (((v92 >> 2) & 0x3FF) + (v48 << 8));
  if ( v65 < 0xC0000000 || v65 > 0xC03FFFFF )
  {
    *(_DWORD *)v65 = v51;
  }
  else
  {
    v78 = *(_DWORD *)v65;
    v79 = 0;
    __dmb(0xBu);
    *(_DWORD *)v65 = v51;
    if ( (v78 & 2) == 0 && (v51 & 2) != 0 )
      v79 = 1;
    if ( v65 + 1070596096 <= 0xFFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v51, v65);
    if ( v79 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  MiBuildHardwarePageDirectory(v65 & 0xFFFFF000, *(_DWORD **)(a5 + 32));
  v67 = (unsigned int *)&MmPfnDatabase;
  v68 = v51 & 0xFFFFF000;
  v69 = BYTE2(MiFlags) & 3;
  if ( v69 == 3 )
  {
    v69 = MiFlags;
    if ( (MiFlags & 0x40000) != 0 )
    {
      __dmb(0xBu);
      v67 = (unsigned int *)(a5 + 188);
      do
      {
        v80 = __ldrex(v67);
        v66 = v80 | 0x400;
        v69 = __strex(v80 | 0x400, v67);
      }
      while ( v69 );
      __dmb(0xBu);
    }
  }
  *(_DWORD *)(a5 + 24) = v68;
  MiSyncSystemPdes(a5, v66, (int)v67, v69);
  MiReleasePtes(&dword_634D58, v48, 2u);
  return 1;
}
