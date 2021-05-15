// PipSetDevNodeProblem 
 
int __fastcall PipSetDevNodeProblem(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  __int64 v5; // kr00_8
  int v10; // r1
  int v11; // [sp+0h] [bp-28h]
  int v12[8]; // [sp+8h] [bp-20h] BYREF

  v11 = a1;
  v12[1] = a4;
  v12[0] = 0;
  v4 = *(_DWORD *)(a1 + 268);
  v5 = *(_QWORD *)(a1 + 276);
  if ( (v4 & 0x2000) != 0 )
    return sub_7E0574();
  PiPnpRtlBeginOperation(v12, a2, a3, v4);
  PipSetDevNodeFlags(a1, 0x2000);
  *(_DWORD *)(a1 + 276) = a2;
  *(_DWORD *)(a1 + 280) = a3;
  v10 = *(_DWORD *)(a1 + 24);
  if ( v10 )
  {
    if ( a2 != (_DWORD)v5 )
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v10, 12);
    if ( *(_DWORD *)(a1 + 280) != HIDWORD(v5) )
      PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), 13);
    v11 = v5;
    PnpTraceSetDevNodeProblem(a1 + 20, a1 + 28, *(_DWORD *)(a1 + 276), *(_DWORD *)(a1 + 280));
  }
  if ( v12[0] )
    PiPnpRtlEndOperation(v12[0]);
  return v11;
}
