// PiSwPdoDriverEntry 
 
int __fastcall PiSwPdoDriverEntry(_DWORD *a1)
{
  int v1; // r2

  v1 = a1[6];
  PiSwDeviceDriverObject = (int)a1;
  *(_DWORD *)(v1 + 4) = HvlRegisterWheaErrorNotification;
  a1[41] = PiSwPdoPnPDispatch;
  a1[36] = IopPowerDispatch;
  a1[37] = IopSystemControlDispatch;
  return 0;
}
