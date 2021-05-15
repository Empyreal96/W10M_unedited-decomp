// SdbpFindMatchingName 
 
int __fastcall SdbpFindMatchingName(int a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r0

  while ( a2 )
  {
    v6 = SdbFindFirstTag(a1, a2, *(unsigned __int16 *)(a3 + 12));
    if ( !v6 )
      JUMPOUT(0x8179AE);
    v7 = SdbGetStringTagPtr(a1, v6);
    if ( !v7 )
      JUMPOUT(0x81799C);
    if ( (*(_DWORD *)(a3 + 20) & 1) != 0 )
      return sub_81798C();
    if ( !wcsicmp(v7, *(unsigned __int16 **)(a3 + 32)) )
      break;
    a2 = SdbpGetNextIndexedRecord(a1, *(_DWORD *)a3, a3);
  }
  return a2;
}
