// VfIsPCIBus 
 
int __fastcall VfIsPCIBus(int a1)
{
  int v1; // r4
  unsigned int v3; // [sp+8h] [bp-60h] BYREF
  int v4[22]; // [sp+10h] [bp-58h] BYREF

  v1 = 0;
  v3 = 0;
  if ( a1 && !IoGetDeviceProperty(a1, 0, 0x50u, v4, &v3) && !wcsicmp((int)v4, L"PCI bus") )
    v1 = 1;
  return v1;
}
