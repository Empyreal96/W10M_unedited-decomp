// RtlWriteAcquireTickLock 
 
unsigned __int64 *__fastcall RtlWriteAcquireTickLock(unsigned __int64 *result)
{
  unsigned __int64 v1; // kr00_8
  unsigned __int64 v2; // kr08_8

  v1 = *result;
  if ( (*(_DWORD *)result & 1) != 0 )
    return (unsigned __int64 *)sub_51C02C();
  do
    v2 = __ldrexd(result);
  while ( v2 == v1 && __strexd(v1 + 1, result) );
  __dmb(0xBu);
  if ( v2 != v1 )
    JUMPOUT(0x51C030);
  return result;
}
