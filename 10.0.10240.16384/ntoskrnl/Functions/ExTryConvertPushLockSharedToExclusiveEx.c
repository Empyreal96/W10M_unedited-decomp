// ExTryConvertPushLockSharedToExclusiveEx 
 
BOOL __fastcall ExTryConvertPushLockSharedToExclusiveEx(unsigned int *a1, int a2, int a3)
{
  unsigned int v3; // r2

  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_527198(a1, a2, a3, a2 & 0xFFFFFFFC);
  __dmb(0xBu);
  do
    v3 = __ldrex(a1);
  while ( v3 == 17 && __strex(1u, a1) );
  __dmb(0xBu);
  return v3 == 17;
}
