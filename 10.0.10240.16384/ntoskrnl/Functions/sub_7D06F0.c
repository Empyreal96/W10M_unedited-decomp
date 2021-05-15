// sub_7D06F0 
 
int __fastcall sub_7D06F0(int a1)
{
  _DWORD *v1; // r4
  _DWORD *v2; // r8
  int v3; // r9
  void **v4; // r1
  int *v5; // r2
  int v6; // r3
  unsigned int v7; // r7
  int v8; // r6
  int v9; // r0
  int (__fastcall *v11)(int); // [sp-4h] [bp-4h]

  if ( (*v1 & 0x20000) != 0 )
    a1 = CmSetTraceNotifyRoutines(0, 0, 1);
  if ( (*v1 & 0x100000) != 0 )
    a1 = AlpcUnregisterLogRoutine(a1);
  v4 = &EtwpFileIoNotifyRoutines;
  if ( (*v1 & 0x2000000) != 0 )
    dword_60E6D4 = 0;
  if ( (*v1 & 0x4000000) != 0 )
    dword_60E6D0 = 0;
  if ( (*v1 & 0x200) != 0 )
    dword_60E6CC = 0;
  v5 = &EtwpDiskIoNotifyRoutines;
  if ( (*v1 & 0x100) != 0 )
  {
    EtwpDiskIoNotifyRoutines = 0;
    dword_60E6C4 = 0;
  }
  if ( (*v1 & 0x400) != 0 )
    dword_6418FC = 0;
  if ( (v1[4] & 1) != 0 )
    dword_641900 = 0;
  if ( (v1[4] & 2) != 0 )
    dword_641904 = 0;
  if ( (*v1 & 0x200000) != 0 )
  {
    v5 = 0;
    EtwpSplitIoNotifyRoutines = 0;
  }
  if ( (*v1 & 0x10000) != 0 )
    a1 = WmiSetNetworkNotify(0);
  v6 = v1[1];
  if ( (v6 & 0x10) != 0 )
    a1 = IoPerfReset(1, (int)v4, (int)v5, v6);
  if ( (v1[4] & 0x400000) != 0 )
    dword_60E6B4 = 0;
  if ( (v1[4] & 0x80000) != 0 )
    dword_60E6B8 = 0;
  if ( (v1[4] & 0x100000) != 0 )
    dword_60E6BC = 0;
  if ( (v1[4] & 0x200000) != 0 )
    dword_60E6C0 = 0;
  if ( (v1[4] & 0x1000000) != 0 )
    dword_617918 = 0;
  if ( (v1[4] & 0x2000000) != 0 )
    dword_61791C = 0;
  if ( (v1[2] & 0x8000000) != 0 )
    dword_617920 = 0;
  if ( (*v1 & 0x40000) != 0 )
    a1 = DbgSetDebugPrintCallback((int)EtwpTraceDebugPrint, 0);
  if ( (v1[1] & 2) != 0 )
    a1 = KeStopProfile((int)&EtwpProfileObject);
  if ( (v1[1] & 0x400) != 0 )
  {
    v7 = 0;
    if ( EtwpPmcProfile )
    {
      v8 = 0;
      do
      {
        a1 = KeStopProfile(v8 + dword_61AA64);
        ++v7;
        v8 += 52;
      }
      while ( v7 < EtwpPmcProfile );
    }
  }
  if ( (v1[4] & 0x80) != 0 )
    ObDisableEtwReferenceTrace(a1);
  if ( (v1[1] & 0x880000) != 0 && (!v2 || (v2[1] & 0x880000) == 0) )
    KeCancelTimer((int)&EtwpMemInfoTimer);
  v9 = EtwpUpdateFileInfoDriverState(v2, (int)v1, 0, v3);
  return v11(v9);
}
