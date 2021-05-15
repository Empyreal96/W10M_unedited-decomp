// sub_54EF20 
 
void __fastcall sub_54EF20(int a1, unsigned __int8 *a2)
{
  int v2; // r8
  int v3; // r3
  unsigned int v4; // r2

  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v3 = *(_DWORD *)(v2 + 12);
      __dmb(0xBu);
    }
    while ( v3 < 0 );
    do
      v4 = __ldrex(a2);
    while ( __strex(v4 | 0x80, a2) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
      JUMPOUT(0x4E8E68);
  }
}
