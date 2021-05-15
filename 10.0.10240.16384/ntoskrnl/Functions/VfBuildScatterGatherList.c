// VfBuildScatterGatherList 
 
// local variable allocation has failed, the output may be wrong!
int VfBuildScatterGatherList(int a1, int a2, ...)
{
  int *v2; // r7
  int v4; // r5
  int v5; // r6
  int v6; // r8
  int v7; // r7
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r1
  int v14; // r0
  int v15; // r8
  int v16; // r0
  int v17; // r10 OVERLAPPED
  int v18; // r9 OVERLAPPED
  int v19; // r0
  int v20; // r8
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  _DWORD *v25; // r4
  _DWORD *v26; // r7
  int v27; // r2
  int v28; // r3
  int v29; // r4
  int v30; // r0
  unsigned int *v31; // r4
  int v32; // r8
  unsigned int v33; // r2
  __int64 v34; // r0
  void *v35; // [sp+18h] [bp-30h]
  int v36; // [sp+1Ch] [bp-2Ch] BYREF
  int v37; // [sp+20h] [bp-28h]
  int v38; // [sp+24h] [bp-24h]
  int (__fastcall *v39)(int, int, int *, void *, int, int, int, _DWORD, int, int); // [sp+28h] [bp-20h]
  int vars4; // [sp+4Ch] [bp+4h]
  int *varg_r2; // [sp+58h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+58h] [bp+10h]
  void *varg_r3; // [sp+5Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+5Ch] [bp+14h]
  int v45; // [sp+60h] [bp+18h]
  int v46; // [sp+64h] [bp+1Ch]
  int v47; // [sp+68h] [bp+20h]
  int v48; // [sp+6Ch] [bp+24h]
  int v49; // [sp+70h] [bp+28h]
  int v50; // [sp+74h] [bp+2Ch]
  va_list va2; // [sp+78h] [bp+30h] BYREF

  va_start(va2, a2);
  va_start(varg_r3a, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3a, int *);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  v45 = va_arg(va2, _DWORD);
  v46 = va_arg(va2, _DWORD);
  v47 = va_arg(va2, _DWORD);
  v48 = va_arg(va2, _DWORD);
  v49 = va_arg(va2, _DWORD);
  v50 = va_arg(va2, _DWORD);
  v2 = varg_r2;
  v37 = a2;
  v38 = a1;
  v35 = varg_r3;
  v4 = 0;
  v39 = (int (__fastcall *)(int, int, int *, void *, int, int, int, _DWORD, int, int))ViGetRealDmaOperation(a1, 56);
  v5 = ViGetAdapterInformationInternal(a1, 1);
  v6 = v45;
  if ( !v5 )
    goto LABEL_20;
  VF_ASSERT_IRQL(2);
  if ( !varg_r2 )
    return -1073741811;
  __dmb(0xBu);
  v9 = (unsigned int *)(v5 + 92);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  v11 = (unsigned int *)(v5 + 96);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 + 1, v11) );
  __dmb(0xBu);
  VERIFY_BUFFER_LOCKED((int)varg_r2);
  if ( *(_DWORD *)(v5 + 120) == 3 )
  {
    v14 = ViCheckMdlLength(varg_r2, v13, 0, 0, v45);
    v15 = v14;
    if ( v14 )
    {
      ViHalPreprocessOptions(
        &dword_6187A4,
        "The provided MDL is not sufficient to satisfy the requested length",
        36,
        v14,
        0,
        0);
      VfReportIssueWithOptions(230, 36, v15, 0, 0, &dword_6187A4);
    }
    v6 = v45;
  }
  if ( !ViDoubleBufferDma || (v16 = ExAllocateFromNPagedLookasideList((int)&ViHalWaitBlockLookaside), (v4 = v16) == 0) )
  {
LABEL_20:
    v18 = v47;
    v17 = v46;
    goto LABEL_21;
  }
  v17 = v46;
  *(_DWORD *)(v16 + 36) = 0;
  v18 = v47;
  *(_DWORD *)(v16 + 24) = (((unsigned __int16)v35 & 0xFFFu) + v6 + 4095) >> 12;
  *(_QWORD *)v16 = *(_QWORD *)&v18;
  *(_DWORD *)(v16 + 32) = v5;
  *(_DWORD *)(v16 + 40) = v16 + 40;
  *(_DWORD *)(v16 + 44) = v16 + 40;
  v19 = ViAllocateMapRegisterFile(v5, *(_DWORD *)(v16 + 24));
  v20 = v19;
  v36 = v19;
  if ( !v19 )
  {
LABEL_16:
    ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, (_DWORD *)v4);
    v4 = 0;
LABEL_21:
    v29 = 0;
    v30 = v39(v38, v37, v2, v35, v45, v17, v18, (unsigned __int8)v48, v49, v50);
    goto LABEL_22;
  }
  *(_BYTE *)(v19 + 13) = 1;
  *(_DWORD *)(v4 + 8) = v4 + 56;
  *(_DWORD *)(v4 + 12) = v35;
  *(_DWORD *)(v4 + 16) = v45;
  *(_DWORD *)(v4 + 52) = v19;
  if ( !ViMapDoubleBuffer(v19, v2) )
  {
    ViFreeMapRegisterFile(v5);
    goto LABEL_16;
  }
  v21 = *v2;
  v22 = v2[1];
  v23 = v2[2];
  v24 = v2[3];
  v25 = *(_DWORD **)(v4 + 8);
  v26 = v2 + 4;
  *v25 = v21;
  v25[1] = v22;
  v25[2] = v23;
  v25[3] = v24;
  v25 += 4;
  v27 = v26[1];
  v28 = v26[2];
  *v25 = *v26;
  v25[1] = v27;
  v25[2] = v28;
  v29 = v20;
  ViSwap(&v36, (int **)varg_r2a, varg_r3a);
  v30 = v39(v38, v37, varg_r2, varg_r3, v45, (int)ViScatterGatherCallback, v4, (unsigned __int8)v48, v49, v50);
LABEL_22:
  v7 = v30;
  if ( v5 && v30 < 0 )
  {
    DECREMENT_SCATTER_GATHER_LISTS(v5);
    if ( v29 )
      ViFreeMapRegisterFile(v5);
    if ( v4 )
    {
      v31 = (unsigned int *)(v5 + 40);
      v32 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)v31);
      }
      else
      {
        do
          v33 = __ldrex(v31);
        while ( __strex(1u, v31) );
        __dmb(0xBu);
        if ( v33 )
          KxWaitForSpinLockAndAcquire(v31);
      }
      v34 = *(_QWORD *)(v4 + 40);
      if ( *(_DWORD *)(v34 + 4) != v4 + 40 || *(_DWORD *)HIDWORD(v34) != v4 + 40 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v34) = v34;
      *(_DWORD *)(v34 + 4) = HIDWORD(v34);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v31, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v31 = 0;
      }
      KfLowerIrql(v32);
      ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, (_DWORD *)v4);
    }
  }
  return v7;
}
