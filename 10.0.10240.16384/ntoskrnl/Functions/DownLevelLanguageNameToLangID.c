// DownLevelLanguageNameToLangID 
 
int __fastcall DownLevelLanguageNameToLangID(int a1, int a2)
{
  char v2; // r4
  int v3; // r0
  int v4; // r3
  int *v5; // r1
  int v6; // r2
  int result; // r0

  v2 = a2;
  if ( a1
    && (a2 & 0xFFFFFFFD) == 0
    && (v3 = bsearch(a1, &off_4037D0, 412, 8)) != 0
    && ((v4 = *(_DWORD *)(v3 + 4), v5 = dword_4044B0, v6 = 3 * v4, (v2 & 2) != 0)
     || !IsNeutralLanguageItem((const struct CultureDataType *)&dword_4044B0[3 * v4])) )
  {
    result = LOWORD(v5[v6]);
  }
  else
  {
    result = 0;
  }
  return result;
}
