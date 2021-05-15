// ExfAcquireCacheAwarePushLockExclusiveEx 
 
unsigned __int8 **__fastcall ExfAcquireCacheAwarePushLockExclusiveEx(unsigned __int8 **result, int a2, unsigned int a3)
{
  unsigned __int8 *v3; // r3
  unsigned __int8 **v6; // r6
  unsigned __int8 **v7; // r7
  unsigned int v8; // r5
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned __int8 *v13; // r0

  v3 = *result;
  v6 = result + 1;
  v7 = result + 32;
  do
    v8 = __ldrex(v3);
  while ( __strex(v8 | 1, v3) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
  {
    v13 = *result;
    goto LABEL_14;
  }
  while ( v6 < v7 )
  {
    v9 = *v6;
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 1, v9) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
    {
      v11 = *--v7;
      do
        v12 = __ldrex(v11);
      while ( __strex(v12 | 1, v11) );
      __dmb(0xBu);
      if ( (v12 & 1) != 0 )
      {
        v13 = *v7;
LABEL_14:
        result = (unsigned __int8 **)ExfAcquirePushLockExclusiveEx(v13, a2, a3);
      }
    }
    else
    {
      ++v6;
    }
  }
  return result;
}
