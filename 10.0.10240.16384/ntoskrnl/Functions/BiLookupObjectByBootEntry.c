// BiLookupObjectByBootEntry 
 
int __fastcall BiLookupObjectByBootEntry(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *i; // r4

  for ( i = (_DWORD *)*a1; i != a1; i = (_DWORD *)*i )
  {
    if ( (i[8] & 3) != 0 && i[6] == a2 )
    {
      *a3 = i;
      return 0;
    }
  }
  return -1073741275;
}
