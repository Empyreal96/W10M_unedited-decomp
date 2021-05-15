// KsepCacheDeviceHash 
 
unsigned int __fastcall KsepCacheDeviceHash(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  RtlHashUnicodeString((unsigned __int16 *)(a1 + 20), 1, 0, v5);
  return v5[0];
}
