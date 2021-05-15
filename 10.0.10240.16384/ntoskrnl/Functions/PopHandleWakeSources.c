// PopHandleWakeSources 
 
int PopHandleWakeSources()
{
  int v0; // r4
  int v1; // r6
  int *v2; // r5
  int result; // r0
  unsigned int *v4; // r7
  int v5; // r0
  int *v6; // r4
  int v7; // r3
  int **v8; // r1
  int **v9; // r1
  unsigned int v10; // r1
  char v11[8]; // [sp+10h] [bp-30h] BYREF
  char v12[40]; // [sp+18h] [bp-28h] BYREF

  v0 = 0;
  v1 = 0;
  v11[0] = 0;
  if ( (PopFixedWakeSourceMask & 1) != 0 || (PopSimulate & 0x200000) != 0 )
  {
    v1 = 1;
  }
  else if ( (PopFixedWakeSourceMask & 2) != 0 || (PopSimulate & 0x400000) != 0 )
  {
    v1 = 2;
  }
  else
  {
    if ( PopValidateRTCWake(v11) && (PopSimulate & 0x100000) == 0 )
      v1 = 4;
    v0 = (unsigned __int8)v11[0];
  }
  PopAcquireWakeSourceSpinLock((unsigned int)v12);
  v2 = (int *)PopCurrentWakeInfo;
  if ( PopCurrentWakeInfo && !v1 )
    PopWakeInfoReference(PopCurrentWakeInfo);
  PopReleaseWakeSourceSpinLock((int)v12);
  if ( !v2 )
    return KeSetEvent((int)&PopWakeSourceAvailable, 0, 0);
  if ( v1 )
  {
    if ( (unsigned int)dword_61ECB0 >= 3 )
      v4 = 0;
    else
      v4 = *(unsigned int **)&PopAction[24 * dword_61ECB0 + 104];
    if ( v1 != 4 || v4 == (unsigned int *)-1 )
    {
      v5 = 1;
    }
    else if ( v0 )
    {
      v5 = 3;
    }
    else
    {
      v5 = 2;
    }
    v6 = (int *)PopNewWakeSource(v5);
    PopAcquireWakeSourceSpinLock((unsigned int)v12);
    PopCurrentWakeInfo = 0;
    PopReleaseWakeSourceSpinLock((int)v12);
    PopUnlinkWakeSources(v2);
    if ( v6 )
    {
      v7 = v6[2];
      if ( v7 == 2 || v7 == 3 )
        ExCopyWakeTimerInfo(v4, v6 + 3);
      else
        v6[3] = v1;
      v8 = (int **)v2[4];
      *v6 = (int)(v2 + 3);
      v6[1] = (int)v8;
      if ( *v8 != v2 + 3 )
        __fastfail(3u);
      *v8 = v6;
      v2[4] = (int)v6;
      v2[5] = 1;
    }
    PopAcquireWakeSourceSpinLock((unsigned int)v12);
    v9 = (int **)dword_61F2CC;
    *v2 = (int)&PopWakeInfoList;
    v2[1] = (int)v9;
    if ( *v9 != &PopWakeInfoList )
      __fastfail(3u);
    *v9 = v2;
    dword_61F2CC = (int)v2;
    ++PopWakeInfoCount;
    PopReleaseWakeSourceSpinLock((int)v12);
    result = PopFinalizeWakeInfo(v2);
  }
  else
  {
    KeInitializeDpc((int)(v2 + 6), (int)PopWakeSourceTimeoutDpc, 0);
    KeInitializeTimerEx(v2 + 14, 0);
    result = KiSetTimerEx((int)(v2 + 14), v10, -20000000i64, 0, 0, (int)(v2 + 6));
  }
  return result;
}
