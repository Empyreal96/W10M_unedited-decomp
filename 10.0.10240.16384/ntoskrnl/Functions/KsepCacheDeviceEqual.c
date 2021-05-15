// KsepCacheDeviceEqual 
 
BOOL __fastcall KsepCacheDeviceEqual(int a1, int a2)
{
  return RtlCompareUnicodeString((unsigned __int16 *)(a1 + 20), (unsigned __int16 *)(a2 + 20), 1) == 0;
}
