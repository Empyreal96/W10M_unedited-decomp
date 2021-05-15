// DownLevelGetParentLanguageName 
 
unsigned int __fastcall DownLevelGetParentLanguageName(int a1, unsigned __int16 *a2)
{
  unsigned int v3; // r0
  unsigned __int16 *v4; // r4
  unsigned int v5; // r6
  unsigned int result; // r0

  if ( a1
    && a2
    && (v3 = bsearch(a1, (unsigned int)&off_4037D0, 0x19Cu, 8, (int (*)(void))CompareLangName)) != 0
    && (v4 = (unsigned __int16 *)dword_4044B0[3 * dword_4044B0[3 * *(_DWORD *)(v3 + 4) + 2] + 1],
        v5 = wcslen(v4),
        StringCchCopyNW(a2, 0x55u, v4, v5 + 1) >= 0) )
  {
    result = v5 + 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
