// PnpSetRegistryDword 
 
int __fastcall PnpSetRegistryDword(int a1, unsigned __int16 *a2)
{
  char v3[16]; // [sp+10h] [bp-10h] BYREF

  RtlInitUnicodeString((unsigned int)v3, a2);
  return ZwSetValueKey();
}
