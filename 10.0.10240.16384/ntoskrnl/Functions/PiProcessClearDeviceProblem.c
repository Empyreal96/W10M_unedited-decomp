// PiProcessClearDeviceProblem 
 
int __fastcall PiProcessClearDeviceProblem(int a1, int a2)
{
  int v2; // r4
  int v3; // r3
  _DWORD *v4; // r5
  int v5; // r2
  int v7; // r6
  int v8; // r7
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = 0;
  v2 = 0;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 176);
  v4 = *(_DWORD **)(v3 + 20);
  v5 = v4[43];
  if ( v5 != 769 )
  {
    v3 = 770;
    if ( v5 != 770 )
    {
      v3 = 786;
      if ( v5 != 786 )
        return sub_7E0CC0();
    }
  }
  v7 = v4[67];
  if ( (v7 & 0x6000) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 12);
    if ( v8 == 1 && PipIsProblemReadonly(v4, v4[69]) )
    {
      v2 = -1073741584;
    }
    else if ( v8 != 3 || (v7 & 0x2000) != 0 && (v3 = v4[69], v3 == 47) )
    {
      PiPnpRtlBeginOperation(v9, a2, v5, v3);
      PipClearDevNodeFlags((int)v4, 0x4000);
      PipClearDevNodeProblem(v4);
      if ( v4[43] != 769 )
        PnpRestartDeviceNode(v4);
      if ( v9[0] )
        PiPnpRtlEndOperation(v9[0]);
    }
    else
    {
      v2 = -1073741808;
    }
  }
  return v2;
}
