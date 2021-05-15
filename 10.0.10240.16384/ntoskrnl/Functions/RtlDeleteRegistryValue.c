// RtlDeleteRegistryValue 
 
int __fastcall RtlDeleteRegistryValue(int a1, int a2, unsigned __int16 *a3)
{
  int v5; // r4
  int v7; // [sp+0h] [bp-20h] BYREF
  char v8[24]; // [sp+8h] [bp-18h] BYREF

  v5 = RtlpGetRegistryHandle(a1, a2, 1, &v7);
  if ( v5 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v8, a3);
    v5 = ZwDeleteValueKey();
    if ( (a1 & 0x40000000) == 0 )
      ZwClose();
  }
  return v5;
}
