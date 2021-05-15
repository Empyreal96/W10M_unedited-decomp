// KsepCacheHwIdHash 
 
int __fastcall KsepCacheHwIdHash(int a1, int a2, int a3, int a4)
{
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[1] = a4;
  v5[0] = 0;
  RtlHashUnicodeString(a1 + 20, 1, 0, v5);
  return v5[0];
}
