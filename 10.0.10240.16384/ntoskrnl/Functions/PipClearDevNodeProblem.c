// PipClearDevNodeProblem 
 
int __fastcall PipClearDevNodeProblem(int result, int a2, int a3, int a4)
{
  int v4; // r3
  __int64 v5; // kr00_8
  int *v6; // r4
  int v7; // r1
  int v8[6]; // [sp+0h] [bp-18h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v4 = *(_DWORD *)(result + 268);
  v5 = *(_QWORD *)(result + 276);
  v6 = (int *)result;
  if ( (v4 & 0x2000) != 0 || (_DWORD)v5 )
  {
    PiPnpRtlBeginOperation(v8, a2, a3, v4);
    PipClearDevNodeFlags((int)v6, 0x2000);
    v6[69] = 0;
    v6[70] = 0;
    v7 = v6[6];
    if ( v7 )
    {
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v7, 12);
      if ( v6[70] != HIDWORD(v5) )
        PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v6[6], 13);
      PnpTraceClearDevNodeProblem(v6 + 5, v6 + 7, v5, HIDWORD(v5));
    }
    result = v8[0];
    if ( v8[0] )
      result = PiPnpRtlEndOperation(v8[0]);
  }
  return result;
}
