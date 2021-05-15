// sub_5264E0 
 
void sub_5264E0()
{
  int v0; // r4
  unsigned __int8 *v1; // r1
  unsigned int v2; // r2
  int v3; // r3

  KfRaiseIrql(2);
  v1 = (unsigned __int8 *)(v0 + 15);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 | 0x80, v1) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v2 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *(_DWORD *)(v0 + 12);
      __dmb(0xBu);
    }
    while ( v3 < 0 );
    do
      v2 = __ldrex(v1);
    while ( __strex(v2 | 0x80, v1) );
  }
  JUMPOUT(0x4617F6);
}
