// sub_50AFCC 
 
void sub_50AFCC()
{
  int v0; // r7
  unsigned int *v1; // r8
  unsigned int v2; // r2

  KfRaiseIrql(2);
  v1 = (unsigned int *)(v0 + 44);
  while ( 1 )
  {
    do
      v2 = __ldrex(v1);
    while ( __strex(1u, v1) );
    __dmb(0xBu);
    if ( !v2 )
      JUMPOUT(0x45D2AC);
    do
    {
      __dmb(0xAu);
      __yield();
    }
    while ( *v1 );
  }
}
