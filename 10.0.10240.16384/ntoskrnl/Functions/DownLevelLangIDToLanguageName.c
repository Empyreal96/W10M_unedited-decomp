// DownLevelLangIDToLanguageName 
 
int __fastcall DownLevelLangIDToLanguageName(int a1, unsigned __int16 *a2, signed int a3, int a4)
{
  char v5; // r4
  int result; // r0
  const struct CultureDataType *v8; // r0
  const struct CultureDataType *v9; // r2
  unsigned __int16 *v10; // r7
  unsigned int v11; // r0
  unsigned int v12; // r4
  int varg_r0[4]; // [sp+20h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = (int)a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  v5 = a4;
  if ( a3 < 0 )
    goto LABEL_11;
  if ( !a2 )
    return sub_50EEC8();
  if ( (a4 & 0xFFFFFFFD) != 0
    || (v8 = (const struct CultureDataType *)bsearch(varg_r0, &dword_4044B0, 412, 12), (v9 = v8) == 0)
    || (v5 & 2) == 0 && IsNeutralLanguageItem(v8)
    || (v10 = (unsigned __int16 *)*((_DWORD *)v9 + 1), v11 = wcslen(v10), v12 = v11, a2)
    && StringCchCopyNW(a2, a3, v10, v11 + 1) < 0 )
  {
LABEL_11:
    result = 0;
  }
  else
  {
    result = v12 + 1;
  }
  return result;
}
