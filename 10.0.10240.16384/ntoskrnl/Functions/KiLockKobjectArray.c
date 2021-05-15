// KiLockKobjectArray 
 
unsigned __int8 **__fastcall KiLockKobjectArray(unsigned __int8 **result, unsigned int a2)
{
  unsigned __int8 *v2; // r5
  unsigned int v3; // r2
  unsigned __int8 **v4; // r4
  unsigned __int8 *v5; // r1
  unsigned __int8 *v6; // t1
  unsigned int v7; // r2

  v2 = *result;
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x80, v2) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)v2 & 0x80) != 0 );
    do
      v3 = __ldrex(v2);
    while ( __strex(v3 | 0x80, v2) );
  }
  if ( a2 > 1 )
  {
    v4 = result + 1;
    result = (unsigned __int8 **)(a2 - 1);
    do
    {
      v6 = *v4++;
      v5 = v6;
      if ( v6 != v2 )
      {
        v2 = v5;
        do
          v7 = __ldrex(v5);
        while ( __strex(v7 | 0x80, v5) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v7 >> 7) )
            break;
          do
          {
            __dmb(0xAu);
            __yield();
          }
          while ( (*(_DWORD *)v5 & 0x80) != 0 );
          do
            v7 = __ldrex(v5);
          while ( __strex(v7 | 0x80, v5) );
        }
      }
      result = (unsigned __int8 **)((char *)result - 1);
    }
    while ( result );
  }
  return result;
}
