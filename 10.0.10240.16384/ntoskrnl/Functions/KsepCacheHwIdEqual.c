// KsepCacheHwIdEqual 
 
BOOL __fastcall KsepCacheHwIdEqual(int a1, int a2)
{
  return RtlCompareUnicodeString(a1 + 20, a2 + 20, 1) == 0;
}
