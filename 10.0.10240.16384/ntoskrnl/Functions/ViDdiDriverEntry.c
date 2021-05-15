// ViDdiDriverEntry 
 
int __fastcall ViDdiDriverEntry(int a1)
{
  int v2; // r5
  int v3; // r4
  int v4; // r2
  int v5; // r3
  _DWORD *v6; // r7
  int v7; // r0
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  *(_DWORD *)(a1 + 148) = ViDdiDispatchWmi;
  ViDdiDeviceObjectArray = ExAllocatePoolWithTag(512, 4, 1631872598);
  if ( !ViDdiDeviceObjectArray )
    return -1073741670;
  v3 = 0;
  while ( 1 )
  {
    v2 = IoCreateDevice(a1, 4, 0, 0x22u, 384, 0, v9);
    if ( v2 < 0 )
      break;
    v4 = ViDdiDeviceObjectArray;
    v5 = v9[0];
    *(_DWORD *)(ViDdiDeviceObjectArray + 4 * v3) = v9[0];
    **(_DWORD **)(v5 + 40) = v3++;
    if ( v3 )
    {
      v6 = *(_DWORD **)v4;
      v7 = *(_DWORD *)v4;
      *(_DWORD *)(*(_DWORD *)v4 + 28) &= 0xFFFFFF7F;
      v2 = IoWMIRegistrationControl(v7, 1);
      if ( v2 >= 0 )
        return 0;
      IoDeleteDevice(v6);
      return v2;
    }
  }
  return v2;
}
