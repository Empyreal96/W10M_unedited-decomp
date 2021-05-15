// PiProcessResourceRequirementsChanged 
 
int __fastcall PiProcessResourceRequirementsChanged(int *a1)
{
  int v2; // r0
  int *v3; // r5
  int v4; // r2
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r7
  int v9; // r4
  int v11; // [sp+10h] [bp-20h] BYREF
  char v12; // [sp+14h] [bp-1Ch]

  v2 = a1[2];
  if ( v2 )
    v3 = *(int **)(*(_DWORD *)(v2 + 176) + 20);
  else
    v3 = 0;
  ObfReferenceObject(v2);
  v4 = v3[43];
  if ( v4 == 787 || v4 == 788 )
  {
    v9 = -1073741738;
  }
  else
  {
    PoFxActivateDevice(a1[2]);
    v3[114] |= 0x40u;
    PipClearDevNodeFlags((int)v3, 256);
    PipSetDevNodeFlags((int)v3, 1024);
    PipClearDevNodeProblem((int)v3, v5, v6, v7);
    if ( v3[43] == 776 )
    {
      if ( a1[5] )
        PipClearDevNodeFlags((int)v3, 2048);
      else
        PipSetDevNodeFlags((int)v3, 2048);
      PnpReallocateResources(v3);
      v11 = 3;
      v12 = PnPBootDriversInitialized;
      v8 = a1[6] != 0;
      ObfReferenceObject(*(_DWORD *)(IopRootDeviceNode + 16));
      v9 = PipProcessDevNodeTree(IopRootDeviceNode, (int)a1, (int)&v11, 0, 0, v8, 0);
      if ( v9 < 0 )
        v9 = 0;
    }
    else
    {
      v9 = -1073741823;
    }
  }
  if ( (v3[114] & 0x40) != 0 )
  {
    PoFxIdleDevice(v3[4]);
    v3[114] &= 0xFFFFFFBF;
  }
  ObfDereferenceObject(a1[2]);
  return v9;
}
