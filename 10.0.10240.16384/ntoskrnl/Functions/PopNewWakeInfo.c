// PopNewWakeInfo 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall __spoils<R2,R3,R12> PopNewWakeInfo(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r0
  _DWORD *v5; // r4
  int *v6; // r2 OVERLAPPED
  int v7; // r1 OVERLAPPED
  int v8; // r0
  int v9; // r0
  int v10; // r5
  _DWORD *v11; // r0
  __int64 v12; // kr00_8
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[2] = a3;
  v13[3] = a4;
  v4 = (_BYTE *)ExAllocatePoolWithTag(512, 104, 544040269);
  v5 = v4;
  if ( v4 )
  {
    memset(v4, 0, 104);
    v5[1] = v5;
    v5[2] = 1;
    *v5 = v5;
    v5[3] = v5 + 3;
    v5[4] = v5 + 3;
  }
  PopAcquireWakeSourceSpinLock((unsigned int)v13);
  v6 = &PopWakeInfoList;
  v7 = PopPendingWakeInfo;
  if ( PopPendingWakeInfo )
  {
    v8 = PopWakeInfoList;
    *(_DWORD *)PopPendingWakeInfo = PopWakeInfoList;
    *(_DWORD *)(v7 + 4) = &PopWakeInfoList;
    if ( *(int **)(v8 + 4) != &PopWakeInfoList )
      __fastfail(3u);
    *(_DWORD *)(v8 + 4) = v7;
    PopWakeInfoList = v7;
    v9 = ++PopWakeInfoCount;
    PopPendingWakeInfo = 0;
  }
  else
  {
    v7 = PopWakeInfoList;
    v9 = PopWakeInfoCount;
  }
  v10 = PopCurrentWakeInfo;
  if ( PopCurrentWakeInfo )
  {
    *(_QWORD *)PopCurrentWakeInfo = *(_QWORD *)&v7;
    if ( *(int **)(v7 + 4) != &PopWakeInfoList )
      __fastfail(3u);
    ++v9;
    *(_DWORD *)(v7 + 4) = v10;
    PopWakeInfoCount = v9;
    PopWakeInfoList = v10;
    PopCurrentWakeInfo = 0;
  }
  if ( v5 )
  {
    PopCurrentWakeInfo = (int)v5;
    if ( v9 == 1 )
    {
      v11 = (_DWORD *)dword_61F2CC;
      v12 = *(_QWORD *)dword_61F2CC;
      if ( *(int **)dword_61F2CC != &PopWakeInfoList || *(_DWORD *)HIDWORD(v12) != dword_61F2CC )
        __fastfail(3u);
      dword_61F2CC = *(_DWORD *)(dword_61F2CC + 4);
      *(_DWORD *)HIDWORD(v12) = &PopWakeInfoList;
      *v11 = v11;
      v11[1] = v11;
      PopWakeInfoDereference(v11);
      --PopWakeInfoCount;
    }
  }
  PopReleaseWakeSourceSpinLock((int)v13);
  KeResetEvent((int)&PopWakeSourceAvailable);
  PopFixedWakeSourceMask = 0;
}
