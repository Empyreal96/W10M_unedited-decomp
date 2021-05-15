// sub_7D03F0 
 
int __fastcall sub_7D03F0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12)
{
  int v13; // r4
  char *v14; // r5
  int v15; // r8
  char *v16; // r9
  int v17; // r10
  int v18; // r1
  int v19; // r7
  int v20; // r4
  int v21; // r0
  unsigned int v22; // r1
  int v23; // r4
  void **v24; // r1
  int v25; // r6
  int v26; // r0
  void *v27; // r2
  int v28; // r3
  unsigned int v29; // r1
  bool v30; // nf
  char *v31; // r4
  int v32; // r0
  int v33; // r1
  int v34; // [sp+10h] [bp-70h]
  int v35; // [sp+18h] [bp-68h] BYREF
  int v36; // [sp+1Ch] [bp-64h]
  int v37; // [sp+20h] [bp-60h]
  int v38; // [sp+28h] [bp-58h]
  char v39[68]; // [sp+38h] [bp-48h] BYREF
  int (__fastcall *v40)(int); // [sp+7Ch] [bp-4h]

  v18 = *((_DWORD *)v14 + 1);
  if ( (v18 & v17) != 0 )
    v19 = a12 | v17;
  else
    v19 = a12;
  if ( (v18 & 0x800000) != 0 )
    v19 |= 0x800000u;
  if ( v16 && (*((_DWORD *)v16 + 1) & 0x880000) != 0 )
  {
    v20 = -10000 * EtwpMemInfoInterval;
    v21 = _rt_sdiv64(-10000i64, -10000 * EtwpMemInfoInterval);
    KiSetTimerEx((int)&EtwpMemInfoTimer, v22, v20, v21, 0, (int)&EtwpMemInfoDpc);
    v13 = v34;
  }
  if ( EtwpFileSystemReady )
  {
    v15 = EtwpUpdateFileInfoDriverState(v16, (int)v14, 1, v13);
    v30 = v15 < 0;
    if ( v15 )
    {
LABEL_70:
      if ( !v30 )
        return v40(v15);
      goto LABEL_65;
    }
  }
  if ( !v14 )
  {
LABEL_64:
    v30 = v15 < 0;
    goto LABEL_70;
  }
  if ( (*(_DWORD *)v14 & 0x2000000) != 0 )
  {
    dword_60E6D4 = (int)EtwpTraceFileIo;
    v23 = v35 | 0x2000000;
    v35 |= 0x2000000u;
  }
  else
  {
    v23 = v35;
  }
  if ( (*(_DWORD *)v14 & 0x4000000) != 0 )
  {
    v23 |= 0x4000000u;
    v35 = v23;
    dword_60E6D0 = (int)EtwpTraceFileIo;
  }
  if ( (*(_DWORD *)v14 & 0x200) != 0 )
  {
    v23 |= 0x200u;
    v35 = v23;
    dword_60E6CC = (int)EtwpTraceFileName;
  }
  v24 = &EtwpFltIoNotifyRoutines;
  if ( (*(_DWORD *)v14 & 0x100) != 0 )
  {
    v23 |= 0x100u;
    v35 = v23;
    EtwpDiskIoNotifyRoutines = (int)EtwpTraceIo;
    dword_60E6C4 = (int)EtwpTraceRedirectedIo;
  }
  if ( (*(_DWORD *)v14 & 0x400) != 0 )
  {
    v23 |= 0x400u;
    v35 = v23;
    dword_6418FC = (int)EtwpTraceIoInit;
  }
  if ( (*((_DWORD *)v14 + 4) & 1) != 0 )
  {
    dword_641900 = (int)EtwpTraceOpticalIo;
    v25 = v38 | 1;
    v38 |= 1u;
  }
  else
  {
    v25 = v38;
  }
  if ( (*((_DWORD *)v14 + 4) & 2) != 0 )
  {
    v25 |= 2u;
    v38 = v25;
    dword_641904 = (int)EtwpTraceOpticalIoInit;
  }
  v26 = 0x200000;
  if ( (*(_DWORD *)v14 & 0x200000) != 0 )
  {
    v23 |= 0x200000u;
    v35 = v23;
    EtwpSplitIoNotifyRoutines = (int)EtwpTraceSplitIo;
  }
  if ( (*((_DWORD *)v14 + 4) & 0x400000) != 0 )
  {
    v25 |= 0x400000u;
    v38 = v25;
    dword_60E6B4 = (int)EtwpTraceFltIo;
  }
  if ( (*((_DWORD *)v14 + 4) & v17) != 0 )
  {
    v25 |= v17;
    v38 = v25;
    dword_60E6B8 = (int)EtwpTraceFltIo;
  }
  if ( (*((_DWORD *)v14 + 4) & 0x100000) != 0 )
  {
    v25 |= 0x100000u;
    v38 = v25;
    dword_60E6BC = (int)EtwpTraceFltTimedIo;
  }
  if ( (*((_DWORD *)v14 + 4) & 0x200000) != 0 )
  {
    v25 |= 0x200000u;
    v38 = v25;
    dword_60E6C0 = (int)EtwpTraceFltTimedIo;
  }
  v27 = &EtwpWdfNotifyRoutines;
  if ( (*((_DWORD *)v14 + 4) & 0x1000000) != 0 )
  {
    v25 |= 0x1000000u;
    v38 = v25;
    dword_617918 = (int)EtwpTraceWdf;
  }
  if ( (*((_DWORD *)v14 + 4) & 0x2000000) != 0 )
  {
    v25 |= 0x2000000u;
    v38 = v25;
    dword_61791C = (int)EtwpTraceWdf;
  }
  if ( (*((_DWORD *)v14 + 2) & 0x8000000) != 0 )
  {
    dword_617920 = (int)EtwpSystemTraceWdf;
    v37 |= 0x8000000u;
  }
  if ( (*(_DWORD *)v14 & 0x20000) != 0 )
  {
    v26 = CmSetTraceNotifyRoutines(EtwpTraceRegistry, EtwpTraceRegistryTransaction, 0);
    v15 = v26;
    if ( v26 < 0 )
      goto LABEL_65;
    v23 |= 0x20000u;
    v35 = v23;
  }
  if ( (*(_DWORD *)v14 & 0x100000) != 0 )
  {
    v26 = AlpcRegisterLogRoutine();
    v15 = v26;
    if ( v26 < 0 )
      goto LABEL_65;
    v23 |= 0x100000u;
    v35 = v23;
  }
  if ( (*(_DWORD *)v14 & 0x10000) != 0 )
  {
    EtwpTdiIoNotify = (int)EtwpTraceNetwork;
    v26 = WmiSetNetworkNotify(EtwpTraceNetwork);
    v23 |= 0x10000u;
    v35 = v23;
  }
  v28 = *((_DWORD *)v14 + 1);
  if ( (v28 & 0x10) != 0 )
  {
    v26 = IoPerfInit(1, (int)v24, (int)v27, v28);
    v15 = v26;
    if ( v26 < 0 )
      goto LABEL_65;
    v19 |= 0x10u;
    v36 = v19;
  }
  if ( (*(_DWORD *)v14 & 0x40000) == 0 )
  {
LABEL_54:
    if ( (*((_DWORD *)v14 + 1) & 2) != 0 )
    {
      v26 = EtwpTimeProfileInit();
      v19 |= 2u;
      v36 = v19;
    }
    if ( (*((_DWORD *)v14 + 1) & 0x400) != 0 )
    {
      v26 = EtwpPmcProfileInit(v26);
      v36 = v19 | 0x400;
    }
    if ( (*((_DWORD *)v14 + 4) & 0x80) != 0 )
    {
      ObEnableEtwReferenceTrace(v26);
      v38 = v25 | 0x80;
    }
    if ( (*((_DWORD *)v14 + 1) & 0x20000) != 0 )
    {
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)&EtwpEthreadSyncTrackingSequence);
      while ( __strex(v29 + 1, (unsigned int *)&EtwpEthreadSyncTrackingSequence) );
      __dmb(0xBu);
    }
    goto LABEL_64;
  }
  v26 = DbgSetDebugPrintCallback((int)EtwpTraceDebugPrint, 1);
  v15 = v26;
  if ( v26 >= 0 )
  {
    v35 = v23 | 0x40000;
    goto LABEL_54;
  }
LABEL_65:
  v31 = (char *)(v39 - v16);
  v32 = v14 - v16;
  v33 = 8;
  do
  {
    *(_DWORD *)&v16[(_DWORD)v31] = *(_DWORD *)v16 & ~*(_DWORD *)&v16[v32];
    v16 += 4;
    --v33;
  }
  while ( v33 );
  EtwpDisableKernelTrace((int)v39, (int)&v35);
  return v40(v15);
}
