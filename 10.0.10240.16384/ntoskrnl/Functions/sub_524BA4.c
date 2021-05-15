// sub_524BA4 
 
void __fastcall sub_524BA4(int a1)
{
  unsigned __int8 *v1; // r1
  int v2; // r3
  unsigned int v3; // r2

  v1 = (unsigned __int8 *)(a1 + 15);
  while ( 1 )
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v2 = *(_DWORD *)(a1 + 12);
      __dmb(0xBu);
    }
    while ( v2 < 0 );
    do
      v3 = __ldrex(v1);
    while ( __strex(v3 | 0x80, v1) );
    __dmb(0xBu);
    if ( !(v3 >> 7) )
      JUMPOUT(0x45DC62);
  }
}
