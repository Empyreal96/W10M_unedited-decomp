// sub_51808C 
 
void sub_51808C()
{
  int v0; // r4
  _DWORD *v1; // r8
  unsigned int v2; // r9
  unsigned int *v3; // r5
  unsigned int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  __dmb(0xBu);
  v3 = (unsigned int *)(v0 + 12);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 + 7, v3) );
  __dmb(0xBu);
  __pld(v1);
  v5 = *v1;
  if ( (*v1 & v2) == 0 || (*v1 & v2) >= 0xFFFFFFF9 )
  {
    while ( v0 == (v5 & ~v2) )
    {
      do
        v6 = __ldrex(v1);
      while ( v6 == v5 && __strex(v5 + 7, v1) );
      __dmb(0xBu);
      if ( v6 == v5 )
        goto LABEL_13;
      v5 = v6;
      if ( (v6 & v2) != 0 && (v6 & v2) < 0xFFFFFFF9 )
        break;
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex(v3);
  while ( __strex(v7 - 7, v3) );
  __dmb(0xBu);
LABEL_13:
  JUMPOUT(0x43D4A6);
}
