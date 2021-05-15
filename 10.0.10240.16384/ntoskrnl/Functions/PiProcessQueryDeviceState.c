// PiProcessQueryDeviceState 
 
int __fastcall PiProcessQueryDeviceState(int *a1, int a2, int a3, int a4)
{
  int v4; // r3
  int *v6; // r4
  int v7; // r6
  char v8; // r5
  int v10; // r3
  int v11; // r0
  int v12; // r2
  int v13; // [sp+8h] [bp-20h] BYREF
  int v14[7]; // [sp+Ch] [bp-1Ch] BYREF

  v14[0] = a4;
  v13 = 0;
  v4 = a1[44];
  v6 = *(int **)(v4 + 20);
  PiPnpRtlBeginOperation(&v13, a2, a3, v4);
  PoFxActivateDevice(v6[4]);
  v6[114] |= 0x100u;
  v7 = IopQueryDeviceState(a1, v14);
  if ( v7 < 0 )
  {
    v7 = 0;
  }
  else
  {
    v8 = v14[0];
    if ( (v14[0] & 2) != 0 )
      PipSetDevNodeUserFlags(v6, 2);
    else
      PipClearDevNodeUserFlags(v6, 2);
    if ( (v8 & 0x40) != 0 )
      return sub_7CB890(v6);
    PipClearDevNodeUserFlags(v6, 64);
    v10 = v6[68];
    if ( (v8 & 0x20) != 0 )
    {
      if ( (v10 & 8) == 0 )
      {
        PipSetDevNodeUserFlags(v6, 8);
        IopIncDisableableDepends(v6);
      }
    }
    else if ( (v10 & 8) != 0 )
    {
      IopDecDisableableDepends(v6);
      PipClearDevNodeUserFlags(v6, 8);
    }
    if ( ((v8 & 9) != 0 || (v8 & 4) != 0 && (v8 & 0x10) == 0) && PnpCheckForActiveDependencies((int)v6, 3) )
    {
      v12 = 51;
LABEL_26:
      PnpRequestDeviceRemoval(v6, 0, v12);
      v7 = -1073741823;
      goto LABEL_14;
    }
    if ( (v8 & 9) != 0 )
    {
      if ( (v8 & 1) != 0 )
        v12 = 29;
      else
        v12 = 24;
      goto LABEL_26;
    }
    if ( (v8 & 0x10) != 0 )
    {
      if ( (v8 & 4) != 0 )
        PnpRequestDeviceAction(a1, 13, 0, 1, 0, 0);
      else
        PnpRequestDeviceAction(a1, 13, 0, 0, 0, 0);
    }
    else if ( (v8 & 4) != 0 )
    {
      v12 = 43;
      goto LABEL_26;
    }
  }
LABEL_14:
  PoFxIdleDevice(v6[4]);
  v11 = v13;
  v6[114] &= 0xFFFFFEFF;
  if ( v11 )
    PiPnpRtlEndOperation(v11);
  return v7;
}
