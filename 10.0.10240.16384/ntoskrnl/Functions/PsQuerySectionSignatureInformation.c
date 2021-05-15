// PsQuerySectionSignatureInformation 
 
int __fastcall PsQuerySectionSignatureInformation(int a1)
{
  int v1; // r0
  int v2; // r0
  _BYTE *v3; // r1

  if ( a1 != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) )
    return -1073741637;
  v1 = *(_DWORD *)(a1 + 292);
  if ( !v1 )
    return -1073741823;
  v2 = MiSectionControlArea(v1);
  *v3 = *(_BYTE *)(*(_DWORD *)v2 + 11) >> 4;
  return 0;
}
