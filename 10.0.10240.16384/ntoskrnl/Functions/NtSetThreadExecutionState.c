// NtSetThreadExecutionState 
 
int __fastcall NtSetThreadExecutionState(int a1, unsigned int a2)
{
  _DWORD *v2; // r10
  int v4; // r4
  unsigned int v5; // r9
  _DWORD *v6; // r2
  BOOL v7; // r8
  _DWORD *v8; // r6
  int v9; // r3
  _DWORD *v10; // r6
  int v11; // r0
  int v12; // r3
  int v13; // r0
  int v14; // r1
  int v15; // r2
  char v17; // [sp+8h] [bp-30h]
  _DWORD *v18; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int _10[14]; // [sp+10h] [bp-28h] BYREF

  v2 = (_DWORD *)a2;
  _10[13] = a2;
  _10[12] = a1;
  _10[0] = 0;
  v17 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( !v17 )
    return -1073741637;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  _10[1] = v5;
  if ( (a1 & 0x7FFFFFBC) != 0 || (a1 & 0x40) != 0 && a1 >= 0 )
    return -1073741811;
  v6 = (_DWORD *)a2;
  if ( a2 >= MmUserProbeAddress )
    v6 = (_DWORD *)MmUserProbeAddress;
  *v6 = *v6;
  v7 = a1 >= 0;
  v8 = *(_DWORD **)(v5 + 928);
  v18 = v8;
  if ( !v8 && a1 < 0 )
  {
    v4 = PoCaptureReasonContext(0, v17, 0, 1, 0, _10);
    if ( v4 < 0 )
      return v4;
    v10 = (_DWORD *)_10[0];
    v4 = PopCreateUserPowerRequest((int *)&v18, 0, _10[0], v9);
    if ( v4 < 0 )
    {
      if ( v10 )
        PoDestroyReasonContext(v10);
      return v4;
    }
    v8 = v18;
    *(_DWORD *)(v5 + 928) = v18;
  }
  v11 = PopGetLegacyPowerRequestFlags(v8, a1, _10);
  _10[2] = v11;
  v12 = _10[0];
  *v2 = _10[0];
  if ( v7 )
  {
    PopDiagTraceSetThreadExecutionState(v5, a1);
    if ( (a1 & 1) != 0 )
    {
      PopAcquirePolicyLock();
      PopSystemRequiredSet();
      PopReleasePolicyLock();
    }
    if ( (a1 & 2) != 0 )
    {
      v13 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
      v15 = 0;
      if ( v13 != -1 && v13 || !v13 && !MEMORY[0xFFFF92D8] )
        v15 = 1;
      if ( v15 )
        PopNotifyConsoleUserPresent(1, v14, 8);
    }
  }
  else
  {
    PopApplyLegacyPowerRequestFlags((int)v8, a1, v11, v12);
  }
  return 0;
}
