// SepStopReferencingLogonSession 
 
int __fastcall SepStopReferencingLogonSession(int a1)
{
  int v2; // r4
  _DWORD *v3; // r1
  unsigned int i; // r6
  unsigned int v6; // r7

  v2 = SepConvertToOwnTokenClaims(a1);
  if ( v2 >= 0 )
  {
    v3 = (_DWORD *)(*(_DWORD *)(a1 + 192) + 20);
    __pld(v3);
    for ( i = *v3; ; i = v6 )
    {
      if ( (int)(i - 1) <= 0 )
        return sub_7DBAC4();
      __dmb(0xBu);
      do
        v6 = __ldrex(v3);
      while ( v6 == i && __strex(i - 1, v3) );
      if ( v6 == i )
        break;
    }
    *(_DWORD *)(a1 + 176) |= 0x20u;
  }
  return v2;
}
