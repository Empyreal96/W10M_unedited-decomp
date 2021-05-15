// ExUnblockPushLockEx 
 
unsigned int *__fastcall ExUnblockPushLockEx(unsigned int *result, int a2, int a3)
{
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_527198(result, a2, a3, a2 & 0xFFFFFFFC);
  __dmb(0xFu);
  if ( *result )
    result = ExpUnblockPushLock(result, 0, 0);
  return result;
}
