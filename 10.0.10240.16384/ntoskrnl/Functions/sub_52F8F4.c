// sub_52F8F4 
 
void sub_52F8F4()
{
  int v0; // r7
  int v1; // r8
  unsigned int *v2; // r10
  unsigned int *v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r2

  if ( (v2[1] & ~v1) != 0 )
  {
    v3 = (unsigned int *)(v0 + 24);
    while ( 1 )
    {
      do
        v4 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( !v4 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v3 );
    }
    while ( 1 )
    {
      do
        v5 = __ldrex(v2);
      while ( __strex(1u, v2) );
      __dmb(0xBu);
      if ( !v5 )
        JUMPOUT(0x484A60);
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v2 );
    }
  }
  JUMPOUT(0x484A00);
}
