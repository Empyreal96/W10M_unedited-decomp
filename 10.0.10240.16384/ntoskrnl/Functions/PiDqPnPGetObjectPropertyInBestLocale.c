// PiDqPnPGetObjectPropertyInBestLocale 
 
int __fastcall PiDqPnPGetObjectPropertyInBestLocale(int a1, int a2, int a3, _DWORD *a4, int a5, unsigned __int16 *a6, int a7)
{
  unsigned __int16 *v11; // r6
  bool i; // zf
  int result; // r0

  memset((_BYTE *)a7, 0, 40);
  v11 = a6;
  for ( i = *a6 == 0; !i; i = *v11 == 0 )
  {
    result = PiDqPnPGetObjectProperty(a1, a2, a3, a4, a5, (int)v11, (_DWORD *)a7);
    if ( result < 0 || *(_DWORD *)(a7 + 28) )
      return result;
    PnpFreeDevProperty(a7, 1483763280);
    v11 += wcslen(v11) + 1;
  }
  return PiDqPnPGetObjectProperty(a1, a2, a3, a4, a5, 0, (_DWORD *)a7);
}
