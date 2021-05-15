// KiAcquireTimer2LockUnlessDisabled 
 
int __fastcall KiAcquireTimer2LockUnlessDisabled(unsigned __int8 *a1)
{
  unsigned int v1; // r2
  int result; // r0

  do
    v1 = __ldrex(a1);
  while ( __strex(v1 | 0x80, a1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v1 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( (*(_DWORD *)a1 & 0x80) != 0 );
    do
      v1 = __ldrex(a1);
    while ( __strex(v1 | 0x80, a1) );
  }
  if ( (a1[1] & 0x20) != 0 )
    result = sub_52C554();
  else
    result = (a1[1] & 0x20) != 0;
  return result;
}
