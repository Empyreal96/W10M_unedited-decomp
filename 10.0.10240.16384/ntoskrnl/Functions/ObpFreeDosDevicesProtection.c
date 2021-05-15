// ObpFreeDosDevicesProtection 
 
unsigned int __fastcall ObpFreeDosDevicesProtection(int a1, int a2, int a3)
{
  int v4; // [sp+0h] [bp-8h] BYREF
  unsigned int v5; // [sp+4h] [bp-4h] BYREF

  v4 = a3;
  v5 = 0;
  RtlGetDaclSecurityDescriptor(a1, (_BYTE *)&v4 + 1, &v5, (bool *)&v4);
  return ExFreePoolWithTag(v5);
}
