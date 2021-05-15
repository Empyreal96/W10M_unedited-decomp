// sub_813BE8 
 
void __fastcall sub_813BE8(int a1, int a2, int a3, int a4, unsigned int a5)
{
  unsigned int *v5; // r4
  int v6; // r0
  unsigned int v7; // r2
  unsigned int v8; // r1

  v6 = ZwOpenMutant();
  if ( v6 == -1073741772 )
  {
    __dmb(0xBu);
    do
      v7 = __ldrex(v5);
    while ( !v7 && __strex(0xFFFFFFFF, v5) );
    __dmb(0xBu);
  }
  else
  {
    if ( v6 < 0 )
      JUMPOUT(0x7A678E);
    __dmb(0xBu);
    do
      v8 = __ldrex(v5);
    while ( !v8 && __strex(a5, v5) );
    __dmb(0xBu);
    if ( v8 )
      ZwClose();
  }
  JUMPOUT(0x7A678A);
}
