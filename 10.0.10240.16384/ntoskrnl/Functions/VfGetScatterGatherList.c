// VfGetScatterGatherList 
 
int VfGetScatterGatherList(int a1, int a2, ...)
{
  void *v2; // r4
  _DWORD *v4; // r8
  int v5; // r5
  int v6; // r6
  int v7; // r7
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r1
  int v13; // r1
  int v14; // r0
  int v15; // r7
  _DWORD *v16; // r0
  _DWORD *v17; // r1
  int v18; // lr
  int v19; // r2
  int v20; // r4
  unsigned int v21; // r0
  unsigned int i; // r7
  unsigned int v23; // r3
  int v24; // r1
  int v25; // r0
  int v26; // r7
  int v27; // r0
  int v28; // r1
  int v29; // r2
  int v30; // r3
  _DWORD *v31; // r4
  _DWORD *v32; // r8
  int v33; // r2
  int v34; // r3
  int v35; // r4
  int v36; // r0
  unsigned int *v37; // r4
  int v38; // r8
  unsigned int v39; // r2
  __int64 v40; // r0
  void *v41; // [sp+10h] [bp-38h]
  int v42[2]; // [sp+14h] [bp-34h] BYREF
  int v43; // [sp+1Ch] [bp-2Ch]
  int v44; // [sp+20h] [bp-28h]
  int (__fastcall *v45)(int, int, _DWORD *, void *, unsigned int, int, int, _DWORD); // [sp+24h] [bp-24h]
  int vars4; // [sp+4Ch] [bp+4h]
  _DWORD *varg_r2; // [sp+58h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+58h] [bp+10h]
  void *varg_r3; // [sp+5Ch] [bp+14h] BYREF
  va_list varg_r3a; // [sp+5Ch] [bp+14h]
  unsigned int v51; // [sp+60h] [bp+18h]
  int v52; // [sp+64h] [bp+1Ch]
  int v53; // [sp+68h] [bp+20h]
  int v54; // [sp+6Ch] [bp+24h]
  va_list va2; // [sp+70h] [bp+28h] BYREF

  va_start(va2, a2);
  va_start(varg_r3a, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3a, _DWORD *);
  va_copy(va2, varg_r3a);
  varg_r3 = va_arg(va2, void *);
  v51 = va_arg(va2, _DWORD);
  v52 = va_arg(va2, _DWORD);
  v53 = va_arg(va2, _DWORD);
  v54 = va_arg(va2, _DWORD);
  v2 = varg_r3;
  v43 = a2;
  v41 = varg_r3;
  v44 = a1;
  v4 = varg_r2;
  v5 = 0;
  v45 = (int (__fastcall *)(int, int, _DWORD *, void *, unsigned int, int, int, _DWORD))ViGetRealDmaOperation(a1, 44);
  v6 = ViGetAdapterInformationInternal(a1, 1);
  if ( !v6 )
    goto LABEL_25;
  VF_ASSERT_IRQL(2);
  if ( !varg_r2 )
    return -1073741811;
  __dmb(0xBu);
  v9 = (unsigned int *)(v6 + 92);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  v11 = (unsigned int *)(v6 + 96);
  do
    v12 = __ldrex(v11);
  while ( __strex(v12 + 1, v11) );
  __dmb(0xBu);
  VERIFY_BUFFER_LOCKED((int)varg_r2);
  if ( *(_DWORD *)(v6 + 120) == 3 )
  {
    v14 = ViCheckMdlLength(varg_r2, v13, 0, 0, v51);
    v15 = v14;
    if ( v14 )
    {
      ViHalPreprocessOptions(
        &dword_6187A0,
        "The provided MDL is not sufficient to satisfy the requested length",
        36,
        v14,
        0,
        0);
      VfReportIssueWithOptions(230, 36, v15, 0, 0, &dword_6187A0);
      v2 = varg_r3;
    }
  }
  if ( !ViDoubleBufferDma )
    goto LABEL_25;
  v16 = (_DWORD *)ExAllocateFromNPagedLookasideList((int)&ViHalWaitBlockLookaside);
  v5 = (int)v16;
  if ( !v16 )
    goto LABEL_25;
  v16[9] = 0;
  v17 = v4;
  *v16 = v53;
  v18 = 0;
  v16[1] = v52;
  v16[10] = v16 + 10;
  v16[11] = v16 + 10;
  v19 = v4[6] - (_DWORD)v2;
  v20 = (unsigned __int16)v2 & 0xFFF;
  v21 = v19 + v4[5] + v4[4];
  for ( i = v21; v21 < v51; v21 += i )
  {
    v17 = (_DWORD *)*v17;
    if ( !v17 )
      break;
    v23 = v20 + i;
    v20 = v17[6];
    i = v17[5];
    v18 += (v23 + 4095) >> 12;
  }
  if ( v21 + 4096 < v20 + v51 )
  {
    DECREMENT_SCATTER_GATHER_LISTS(v6);
    ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, (_DWORD *)v5);
    return -1073741789;
  }
  v24 = v18 + ((v20 - v21 + i + v51 + 4095) >> 12);
  *(_DWORD *)(v5 + 24) = v24;
  *(_DWORD *)(v5 + 32) = v6;
  v25 = ViAllocateMapRegisterFile(v6, v24);
  v26 = v25;
  v42[0] = v25;
  if ( !v25 )
  {
LABEL_24:
    ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, (_DWORD *)v5);
    v5 = 0;
LABEL_25:
    v35 = 0;
    v36 = v45(v44, v43, v4, v41, v51, v52, v53, (unsigned __int8)v54);
    goto LABEL_26;
  }
  *(_BYTE *)(v25 + 13) = 1;
  *(_DWORD *)(v5 + 8) = v5 + 56;
  *(_DWORD *)(v5 + 52) = v25;
  *(_DWORD *)(v5 + 12) = v41;
  *(_DWORD *)(v5 + 16) = v51;
  if ( !ViMapDoubleBuffer(v25, v4) )
  {
    ViFreeMapRegisterFile(v6);
    goto LABEL_24;
  }
  v27 = *v4;
  v28 = v4[1];
  v29 = v4[2];
  v30 = v4[3];
  v31 = *(_DWORD **)(v5 + 8);
  v32 = v4 + 4;
  v42[1] = v5;
  *v31 = v27;
  v31[1] = v28;
  v31[2] = v29;
  v31[3] = v30;
  v31 += 4;
  v33 = v32[1];
  v34 = v32[2];
  *v31 = *v32;
  v31[1] = v33;
  v31[2] = v34;
  v35 = v26;
  ViSwap(v42, (_DWORD **)varg_r2a, varg_r3a);
  v36 = v45(v44, v43, varg_r2, varg_r3, v51, (int)ViScatterGatherCallback, v5, (unsigned __int8)v54);
LABEL_26:
  v7 = v36;
  if ( v6 && v36 < 0 )
  {
    DECREMENT_SCATTER_GATHER_LISTS(v6);
    if ( v35 )
      ViFreeMapRegisterFile(v6);
    if ( v5 )
    {
      v37 = (unsigned int *)(v6 + 40);
      v38 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)v37);
      }
      else
      {
        do
          v39 = __ldrex(v37);
        while ( __strex(1u, v37) );
        __dmb(0xBu);
        if ( v39 )
          KxWaitForSpinLockAndAcquire(v37);
      }
      v40 = *(_QWORD *)(v5 + 40);
      if ( *(_DWORD *)(v40 + 4) != v5 + 40 || *(_DWORD *)HIDWORD(v40) != v5 + 40 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v40) = v40;
      *(_DWORD *)(v40 + 4) = HIDWORD(v40);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v37, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v37 = 0;
      }
      KfLowerIrql(v38);
      ExFreeToNPagedLookasideList((int)&ViHalWaitBlockLookaside, (_DWORD *)v5);
    }
  }
  return v7;
}
