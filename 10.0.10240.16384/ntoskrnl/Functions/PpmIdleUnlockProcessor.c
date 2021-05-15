// PpmIdleUnlockProcessor 
 
int __fastcall PpmIdleUnlockProcessor(_DWORD *a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r1
  unsigned int v3; // r5
  unsigned int v5; // r2

  __pld(a1);
  v1 = *a1;
  do
  {
    v2 = v1 & 0xFF000000 | (v1 - 1) & 0xFFFFFF;
    v3 = v1;
    if ( (v2 & 0xFFFFFF) == 0 )
    {
      if ( HIBYTE(v1) != 5 )
        return sub_524CF0();
      v2 = v2 & 0xFFFFFF | 0x4000000;
    }
    __dmb(0xBu);
    do
      v5 = __ldrex(a1);
    while ( v5 == v1 && __strex(v2, a1) );
    v1 = v5;
    __dmb(0xBu);
  }
  while ( v5 != v3 );
  return HIBYTE(v2);
}
