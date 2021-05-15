// SeAuditingHardLinkEvents 
 
BOOL __fastcall SeAuditingHardLinkEvents(int a1, int a2)
{
  int v2; // r3
  int v3; // r3

  if ( (*(_WORD *)(a2 + 2) & 0x10) == 0 )
    return 0;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v2 = *(_DWORD *)(a2 + 12);
    if ( !v2 )
      return 0;
    v3 = v2 + a2;
  }
  else
  {
    v3 = *(_DWORD *)(a2 + 12);
  }
  return v3 && *(_WORD *)(v3 + 4) && (byte_61D3E4 && a1 || byte_61D3E5 && !a1);
}
