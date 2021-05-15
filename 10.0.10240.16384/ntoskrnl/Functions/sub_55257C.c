// sub_55257C 
 
void sub_55257C()
{
  unsigned int v0; // r7
  int v1; // r8
  int v2; // r7
  unsigned __int8 *v3; // r3
  unsigned int v4; // r1
  unsigned int *v5; // r2
  unsigned int v6; // r0

  if ( MI_IS_PFN(v0) )
  {
    v2 = *(_DWORD *)v1 + 24 * v0;
    v3 = (unsigned __int8 *)(v2 + 15);
    do
      v4 = __ldrex(v3);
    while ( __strex(v4 | 0x80, v3) );
    __dmb(0xBu);
    if ( !(v4 >> 7) )
    {
      if ( (*(_WORD *)(v1 + 18) & 3) != 0 )
        MiGetPagePrivilege();
      __dmb(0xBu);
      v5 = (unsigned int *)(v2 + 12);
      do
        v6 = __ldrex(v5);
      while ( __strex(v6 & 0x7FFFFFFF, v5) );
      JUMPOUT(0x4F1BFA);
    }
  }
  JUMPOUT(0x4F1CA6);
}
