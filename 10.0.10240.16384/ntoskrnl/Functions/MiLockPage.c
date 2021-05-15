// MiLockPage 
 
int __fastcall MiLockPage(int a1)
{
  int result; // r0
  unsigned __int8 *v3; // r1
  unsigned int v4; // r2
  int v5; // r3

  result = KfRaiseIrql(2);
  v3 = (unsigned __int8 *)(a1 + 15);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 0x80, v3) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v5 = *(_DWORD *)(a1 + 12);
      __dmb(0xBu);
    }
    while ( v5 < 0 );
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x80, v3) );
  }
  return result;
}
