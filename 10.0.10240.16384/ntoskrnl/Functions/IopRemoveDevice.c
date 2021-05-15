// IopRemoveDevice 
 
int __fastcall IopRemoveDevice(_DWORD *a1, int a2, int a3)
{
  _DWORD *v5; // r5
  int v7; // r0
  int v8; // r8
  int v9; // r3
  int v10[4]; // [sp+8h] [bp-58h] BYREF
  char v11[72]; // [sp+18h] [bp-48h] BYREF

  v10[2] = 0;
  v10[3] = 0;
  if ( a1 )
    v5 = *(_DWORD **)(a1[44] + 20);
  else
    v5 = 0;
  v10[0] = 0;
  PiPnpRtlBeginOperation(v10, a2, a3, 0);
  if ( a2 == 2 )
    IopUncacheInterfaceInformation(a1, 1);
  memset(v11, 0, 40);
  v11[0] = 27;
  v11[1] = a2;
  if ( PnpFindMountableDevice(a1) )
    return sub_7E0584();
  if ( a2 == 2 || a2 == 23 )
  {
    if ( (v5[68] & 8) != 0 )
    {
      PipClearDevNodeUserFlags((int)v5, 8);
      IopDecDisableableDepends(v5);
    }
    if ( a2 == 2 )
    {
      v7 = PiSwProcessParentRemoveIrp(a1);
      PiSwStopDestroy(v7, v5[6]);
    }
  }
  v8 = IopSynchronousCall((int)a1, (int)v11, -1073741637, 0, 0);
  if ( a2 == 23 || a2 == 2 )
  {
    PoFxAbandonDevice(v5);
    v5[20] = 0;
    if ( a2 == 2 )
    {
      PipClearDevNodeFlags((int)v5, 4104);
      v9 = v5[103];
      if ( v9 )
      {
        if ( (v9 & 1) != 0 )
        {
          v5[103] = v9 & 0xFFFFFFFE;
          --*(_DWORD *)((v9 & 0xFFFFFFFE) + 416);
        }
      }
    }
  }
  if ( v10[0] )
    PiPnpRtlEndOperation(v10[0]);
  return v8;
}
