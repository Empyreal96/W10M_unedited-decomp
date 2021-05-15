// KeQuerySystemTimePrecise 
 
__int64 __fastcall KeQuerySystemTimePrecise(__int64 *a1)
{
  __int64 result; // r0

  result = RtlGetSystemTimePrecise();
  *a1 = result;
  return result;
}
