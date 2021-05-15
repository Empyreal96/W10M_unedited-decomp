// LdrpGetParentLangId 
 
int __fastcall LdrpGetParentLangId(int a1, _WORD *a2)
{
  unsigned __int16 v4[88]; // [sp-4h] [bp-168h] BYREF
  char v5[184]; // [sp+ACh] [bp-B8h] BYREF

  if ( !a2 || !DownLevelLangIDToLanguageName(a1, v4, 85, 2) )
    return -1073741811;
  if ( DownLevelGetParentLanguageName(v4, v5) >= 2 )
    *a2 = DownLevelLanguageNameToLangID((int)v5, 2);
  else
    *a2 = 0;
  return 0;
}
