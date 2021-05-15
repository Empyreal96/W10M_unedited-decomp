// CmpLockNameHashEntryExclusive 
 
int __fastcall CmpLockNameHashEntryExclusive(unsigned int a1)
{
  unsigned __int8 *v1; // r5
  int result; // r0
  int v3; // r4
  unsigned int v4; // r2

  v1 = (unsigned __int8 *)(CmpNameCacheTable
                         + 8
                         * (((unsigned __int16)(-30045 * (a1 ^ (a1 >> 9))) ^ (unsigned __int16)((101027
                                                                                               * (a1 ^ (a1 >> 9))) >> 9)) & 0x7FF));
  result = KeAbPreAcquire((unsigned int)v1, 0, 0);
  v3 = result;
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 | 1, v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    result = ExfAcquirePushLockExclusiveEx(v1, result, (unsigned int)v1);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  return result;
}
