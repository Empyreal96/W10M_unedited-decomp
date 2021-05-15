// BiLookupObjectByIdentifierAndBootEntry 
 
int __fastcall BiLookupObjectByIdentifierAndBootEntry(_DWORD *a1, unsigned int a2, int a3, _DWORD *a4)
{
  _DWORD *i; // r4
  int v9; // r5

  for ( i = (_DWORD *)*a1; i != a1; i = (_DWORD *)*i )
  {
    v9 = i[8];
    if ( (v9 & 4) != 0 && !memcmp(a2, (unsigned int)(i + 2), 16) && (v9 & 3) != 0 && i[6] == a3 )
    {
      *a4 = i;
      return 0;
    }
  }
  return -1073741275;
}
