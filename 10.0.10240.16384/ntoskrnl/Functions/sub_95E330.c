// sub_95E330 
 
int __fastcall sub_95E330(int a1)
{
  int v2; // r4
  unsigned int v3; // r5
  int result; // r0

  v2 = MxMemoryLicense();
  dword_633810 = v2;
  v3 = ((MiLargestSystemVa() - 1) << 22) / 0x18u - 1;
  if ( v3 > 0xFFFFF )
    v3 = 0xFFFFF;
  if ( v3 > 0xFFFFC )
    v3 = 1048572;
  MiLimitLoaderBlockHighMemory(a1, v3);
  result = MiLimitLoaderBlockTotalMemory(a1, v2);
  dword_634690 = -1;
  if ( !MmDynamicPfn )
    return sub_96D63C(result);
  if ( v3 > 0xFF7FC )
  {
    v3 = 1046524;
    result = MiLimitLoaderBlockHighMemory(a1, 1046524);
  }
  dword_633850 = v3;
  return result;
}
