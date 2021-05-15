// PnpIrpDeviceEnumerated 
 
int __fastcall PnpIrpDeviceEnumerated(int a1)
{
  char v3[48]; // [sp+8h] [bp-30h] BYREF

  memset(v3, 0, 40);
  v3[0] = 27;
  v3[1] = 25;
  return IopSynchronousCall(a1, v3, -1073741637, 0, 0);
}
