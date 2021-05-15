// AslpFileGetExportName 
 
int __fastcall AslpFileGetExportName(_DWORD *a1, int a2)
{
  int v4; // r0
  int v5; // r4
  char v7[272]; // [sp+8h] [bp-110h] BYREF

  memset(v7, 0, 256);
  v4 = AslpFileQueryExportName(v7, a2);
  v5 = v4;
  if ( v4 >= 0 )
  {
    v5 = AslStringAnsiToUnicode(a1, (unsigned int)v7);
    if ( v5 >= 0 )
      v5 = 0;
    else
      AslLogCallPrintf(1, (int)"AslpFileGetExportName", 2819, "AslStringAnsiToUnicode failed [%x]", v5);
  }
  else if ( v4 != -1073741275 && v4 != -1073741701 )
  {
    AslLogCallPrintf(1, (int)"AslpFileGetExportName", 2812, "AslpFileQueryExportName failed [%x]", v4);
  }
  return v5;
}
