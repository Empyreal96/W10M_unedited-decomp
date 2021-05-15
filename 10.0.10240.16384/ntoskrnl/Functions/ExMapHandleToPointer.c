// ExMapHandleToPointer 
 
_DWORD *__fastcall ExMapHandleToPointer(int a1, __int16 a2)
{
  _DWORD *v3; // r4
  int v4; // r5
  unsigned int v5; // r1

  if ( (a2 & 0x7FC) == 0 )
    return 0;
  v3 = (_DWORD *)ExpLookupHandleTableEntry(a1, a2);
  if ( !v3 )
    return 0;
  do
  {
    while ( 1 )
    {
      __pld(v3);
      v4 = *v3;
      if ( (*v3 & 1) != 0 )
        break;
      if ( !v4 )
        return 0;
      ExpBlockOnLockedHandleEntry(a1, (unsigned __int64 *)v3, *v3);
    }
    do
      v5 = __ldrex(v3);
    while ( v5 == v4 && __strex(v4 - 1, v3) );
    __dmb(0xBu);
  }
  while ( v5 != v4 );
  return v3;
}
