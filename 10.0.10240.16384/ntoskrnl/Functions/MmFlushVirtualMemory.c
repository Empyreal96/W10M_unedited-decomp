// MmFlushVirtualMemory 
 
int __fastcall MmFlushVirtualMemory(int a1, unsigned int *a2, unsigned int *a3, _DWORD *a4)
{
  unsigned int v4; // r10
  unsigned int v5; // r4
  int v6; // r4
  unsigned int v7; // r10
  unsigned int v8; // r9
  char v10; // r7
  unsigned int *v11; // r3
  unsigned int v12; // r1
  BOOL v14; // r0
  BOOL v15; // r4
  int v16; // r0
  _DWORD *v17; // r6
  unsigned int v18; // r2
  int v19; // r1
  int v20; // r5
  int v21; // r8
  int v22; // r3
  unsigned int v23; // r0
  int v24; // r3
  int v25; // r0
  unsigned int *v26; // r9
  unsigned int *v27; // r10
  int v28; // r0
  int v29; // r8
  unsigned int v30; // r6
  int v31; // r4
  int v32; // r8
  _DWORD *v33; // r3
  unsigned int *v34; // [sp+10h] [bp-58h] BYREF
  unsigned int v35; // [sp+14h] [bp-54h] BYREF
  unsigned int *v36; // [sp+18h] [bp-50h] BYREF
  _DWORD *v37; // [sp+1Ch] [bp-4Ch]
  unsigned int v38; // [sp+20h] [bp-48h]
  int v39; // [sp+24h] [bp-44h]
  int v40; // [sp+28h] [bp-40h]
  char v41[56]; // [sp+30h] [bp-38h] BYREF

  v4 = *a2;
  v5 = *a3;
  v36 = a3;
  v37 = a4;
  v6 = v5 + v4 - 1;
  v7 = v4 & 0xFFFFF000;
  v8 = v6 | 0xFFF;
  v10 = 0;
  *a2 = v7;
  v11 = (unsigned int *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v12 = v11[29];
  v34 = v11;
  if ( v12 != a1 )
    return sub_7E5894();
  v38 = 0;
  v15 = 1;
  if ( !*(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136) )
  {
    v14 = KeAreInterruptsEnabled();
    if ( v14 )
    {
      if ( !KeGetCurrentIrql(v14) )
        v15 = 0;
    }
  }
  v16 = MiObtainReferencedVad(v7, (int *)&v35);
  v17 = (_DWORD *)v16;
  if ( !v16 )
  {
    v31 = v35;
    if ( v35 == -1073741664 )
      v31 = -1073741799;
    goto LABEL_46;
  }
  v18 = *(_DWORD *)(v16 + 16);
  if ( !*a3 )
  {
    v8 = (v18 << 12) | 0xFFF;
    v10 = 1;
  }
  v19 = *(_DWORD *)(v16 + 28);
  if ( (v19 & 0x8000) != 0 )
    goto LABEL_44;
  v20 = v8 >> 12;
  if ( v8 >> 12 > v18 )
    goto LABEL_44;
  v21 = **(_DWORD **)(v16 + 44);
  v22 = *(_DWORD *)(v21 + 32);
  v40 = v21;
  if ( !v22 || (v19 & 7) == 2 )
  {
    v31 = -1073741688;
    goto LABEL_45;
  }
  v23 = v8 - v7 + 1;
  *v36 = v23;
  v24 = !v15
     && (*(_DWORD *)(v21 + 28) & 0x20000) != 0
     && (MEMORY[0xC0402004] < 0x1000u || v23 >= 0x100000 && MEMORY[0xC0402004] < 0x4000u);
  if ( MiFlushDirtyBitsToPfn(v7, v8, (int)v34, v24) == 1 )
    v38 = 4;
  MiGetProtoPteAddress(v17, v8 >> 12, 1, &v36);
  v25 = MiGetProtoPteAddress(v17, v7 >> 12, 1, &v34);
  v26 = v36;
  v27 = v34;
  v39 = v25;
  if ( v36 )
  {
    v35 = MiGetProtoPteAddress(v17, v20, 1, &v34);
    goto LABEL_21;
  }
  if ( !v34 || (v10 & 1) == 0 )
  {
    if ( (v10 & 1) != 0 )
    {
      v33 = v37;
      v31 = 0;
      *v37 = 0;
      v33[1] = 0;
LABEL_45:
      MiUnlockAndDereferenceVad((int)v17);
LABEL_46:
      if ( (v10 & 2) != 0 )
        KiUnstackDetachProcess((unsigned int)v41, 0);
      return v31;
    }
LABEL_44:
    v31 = -1073741799;
    goto LABEL_45;
  }
  v26 = (unsigned int *)MiFindLastSubsection(v21, 0);
  v35 = v26[1] + 4 * v26[7] - 4;
LABEL_21:
  if ( !MiFlushAcquire(v21, (int)v27, (int)v26) )
  {
    v31 = -1073741670;
    goto LABEL_45;
  }
  MiUnlockAndDereferenceVad((int)v17);
  if ( (v10 & 2) != 0 )
    KiUnstackDetachProcess((unsigned int)v41, 0);
  v28 = MI_REFERENCE_CONTROL_AREA_FILE(v21);
  v29 = v35;
  v30 = v28;
  while ( 1 )
  {
    v31 = FsRtlAcquireFileForCcFlushEx(v30);
    if ( v31 < 0 )
      break;
    v31 = MiFlushSectionInternal(v39, v29, v27, (int)v26, 0, v38, v37);
    FsRtlReleaseFileForCcFlush(v30);
    if ( v31 != -1073741740 )
      break;
    KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
  }
  v32 = v40;
  MI_DEREFERENCE_CONTROL_AREA_FILE(v40, v30);
  MiFlushRelease(v32, (int)v27, (int)v26);
  return v31;
}
