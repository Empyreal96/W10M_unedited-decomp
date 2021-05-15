// RtlWriteReleaseTickLock 
 
__int64 *__fastcall RtlWriteReleaseTickLock(__int64 *result)
{
  __int64 v1; // kr00_8

  v1 = *result;
  __dmb(0xBu);
  *result = v1 + 1;
  return result;
}
