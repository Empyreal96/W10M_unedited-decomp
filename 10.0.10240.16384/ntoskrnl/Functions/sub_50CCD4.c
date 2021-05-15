// sub_50CCD4 
 
void sub_50CCD4()
{
  int v0; // r4
  int v1; // r8
  unsigned int *v2; // r10
  unsigned int v3; // r2

  do
  {
    if ( *(_WORD *)(v0 + 310) || v1 )
      break;
    __dmb(0xBu);
    *v2 = 0;
    KfLowerIrql(0);
    v1 = KfRaiseIrql(2);
    while ( 1 )
    {
      do
        v3 = __ldrex(v2);
      while ( __strex(1u, v2) );
      __dmb(0xBu);
      if ( !v3 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v2 );
    }
  }
  while ( *(_BYTE *)(v0 + 121) );
  JUMPOUT(0x481BDC);
}
