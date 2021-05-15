// RtlCheckRegistryKey 
 
int __fastcall RtlCheckRegistryKey(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v6; // [sp+0h] [bp-8h] BYREF

  v6 = a4;
  result = RtlpGetRegistryHandle(a1, a2, 0, &v6);
  if ( result >= 0 )
  {
    if ( (a1 & 0x40000000) == 0 )
      ZwClose();
    result = 0;
  }
  return result;
}
