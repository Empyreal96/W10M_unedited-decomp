// AslRegistryBuildUserPath 
 
int __fastcall AslRegistryBuildUserPath(int a1, unsigned __int16 *a2)
{
  int v4; // r4
  int v5; // r0
  unsigned __int16 v6; // r3
  _BYTE *v7; // r0
  int v8; // r2
  int v9; // r3
  _DWORD v11[6]; // [sp+8h] [bp-18h] BYREF

  v11[0] = 0;
  v11[1] = 0;
  v4 = RtlFormatCurrentUserKeyPath((unsigned __int16 *)v11);
  if ( v4 >= 0 )
  {
    *(_WORD *)a1 = 0;
    v5 = wcslen(a2);
    v6 = LOWORD(v11[0]) + 2 * (v5 + 1);
    *(_WORD *)(a1 + 2) = v6;
    v7 = AslAlloc(v5, v6);
    *(_DWORD *)(a1 + 4) = v7;
    if ( v7 )
    {
      RtlAppendUnicodeStringToString((unsigned __int16 *)a1, (unsigned __int16 *)v11);
      RtlAppendUnicodeToString((unsigned __int16 *)a1, (int)a2, v8, v9);
      v4 = 0;
    }
    else
    {
      v4 = -1073741801;
      AslLogCallPrintf(1, (int)"AslRegistryBuildUserPath", 1257, "Out of memory");
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslRegistryBuildUserPath", 1245, "RtlFormatCurrentUserKeyPath failed [%x]", v4);
  }
  RtlFreeAnsiString(v11);
  return v4;
}
