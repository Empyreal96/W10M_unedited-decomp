// AslpFileGetClrVersionAttribute 
 
int __fastcall AslpFileGetClrVersionAttribute(int a1, int a2)
{
  int v4; // r2
  int v5; // r4
  int v6; // r3
  int v7; // r3
  unsigned __int16 *v8; // r6
  unsigned int v9; // r0
  int v10; // r3
  unsigned __int16 *v12; // [sp+8h] [bp-118h] BYREF
  char v13[272]; // [sp+10h] [bp-110h] BYREF

  memset(v13, 0, 256);
  v12 = 0;
  v5 = AslFileMappingEnsure(a2);
  if ( v5 >= 0 )
  {
    if ( *(_DWORD *)(a2 + 552) != 6 )
      goto LABEL_4;
    if ( (*(_DWORD *)(a1 + 688) & 1) == 0 )
    {
      v5 = AslpFileGetFileKindDetailAttribute(a1, a2);
      if ( v5 < 0 )
      {
        AslLogCallPrintf(
          1,
          (int)"AslpFileGetClrVersionAttribute",
          3670,
          "AslpFileGetFileKindDetailAttribute failed [%x]",
          v5);
        return v5;
      }
    }
    v7 = *(_DWORD *)(a1 + 680);
    if ( v7 == 12 || v7 == 13 || v7 == 14 || v7 == 15 )
    {
      v5 = AslpFileGetClrVersion(v13, a2, v4, v7);
      if ( v5 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileGetClrVersionAttribute", 3689, "AslpFileGetClrVersion failed [%x]", v5);
        return v5;
      }
      v5 = AslStringAnsiToUnicode(&v12, (unsigned int)v13);
      if ( v5 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileGetClrVersionAttribute", 3695, "AslStringAnsiToUnicode failed [%x]", v5);
        return v5;
      }
      v8 = v12;
      v5 = AslStringXmlSanitize(v12);
      if ( v5 < 0 )
      {
        AslLogCallPrintf(1, (int)"AslpFileGetClrVersionAttribute", 3701, "AslStringXmlSanitize failed [%x]", v5);
        return v5;
      }
      *(_DWORD *)(a1 + 648) = 4;
      v9 = wcslen(v8);
      *(_QWORD *)(a1 + 656) = (int)v8;
      v10 = *(_DWORD *)(a1 + 664);
      *(_DWORD *)(a1 + 652) = v9;
      v6 = v10 | 5;
    }
    else
    {
LABEL_4:
      v6 = *(_DWORD *)(a1 + 664) | 2;
    }
    *(_DWORD *)(a1 + 664) = v6;
    return 0;
  }
  AslLogCallPrintf(1, (int)"AslpFileGetClrVersionAttribute", 3653, "AslFileMappingEnsure failed [%x]", v5);
  return v5;
}
