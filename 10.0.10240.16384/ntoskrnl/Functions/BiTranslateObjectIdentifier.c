// BiTranslateObjectIdentifier 
 
int __fastcall BiTranslateObjectIdentifier(_DWORD *a1, unsigned int a2, _DWORD *a3)
{
  _DWORD *i; // r4
  int result; // r0

  for ( i = (_DWORD *)*a1; i != a1; i = (_DWORD *)*i )
  {
    if ( (i[8] & 4) != 0 && !memcmp(a2, (unsigned int)(i + 2), 16) )
    {
      result = 0;
      if ( (i[8] & 3) != 0 )
      {
        *a3 = i[6];
        return result;
      }
      return -1073741275;
    }
  }
  return -1073741275;
}
