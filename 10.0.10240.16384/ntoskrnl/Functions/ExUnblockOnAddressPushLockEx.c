// ExUnblockOnAddressPushLockEx 
 
unsigned int *__fastcall ExUnblockOnAddressPushLockEx(unsigned int *result, int a2)
{
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheckEx(338, a2, (int)result, 0, 0);
  __dmb(0xFu);
  if ( *result )
    result = ExpUnblockPushLock(result, 0, 0);
  return result;
}
