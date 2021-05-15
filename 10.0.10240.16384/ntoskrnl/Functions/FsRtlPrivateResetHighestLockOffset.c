// FsRtlPrivateResetHighestLockOffset 
 
int __fastcall FsRtlPrivateResetHighestLockOffset(unsigned int a1, unsigned int a2, int a3)
{
  int result; // r0

  if ( a3 >= 32 && (a3 -= 32, a1 = a2, a2 = 0, a3 >= 32) )
    result = 0;
  else
    result = (a1 >> a3) | (a2 << (32 - a3));
  return result;
}
