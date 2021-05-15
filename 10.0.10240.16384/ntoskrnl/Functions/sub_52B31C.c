// sub_52B31C 
 
void __fastcall sub_52B31C(int a1, unsigned int *a2)
{
  unsigned int v2; // r2

  while ( 1 )
  {
    do
      v2 = __ldrex(a2);
    while ( __strex(1u, a2) );
    __dmb(0xBu);
    if ( !v2 )
    {
      __dmb(0xBu);
      *a2 = 0;
      JUMPOUT(0x46CA26);
    }
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *a2 );
  }
}
