// AslpFileGet16BitModuleName 
 
int __fastcall AslpFileGet16BitModuleName(_DWORD *a1, int a2)
{
  int v4; // r4
  char v6[272]; // [sp+8h] [bp-110h] BYREF

  if ( *(_DWORD *)(a2 + 552) == 5 )
  {
    memset(v6, 0, 256);
    v4 = AslpFileQuery16BitModuleName(v6, a2);
    if ( v4 >= 0 )
    {
      v4 = AslStringAnsiToUnicode(a1, (unsigned int)v6);
      if ( v4 < 0 )
        AslLogCallPrintf(1, (int)"AslpFileGet16BitModuleName", 3012, "AslStringAnsiToUnicode failed [%x]", v4);
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslpFileGet16BitModuleName", 3006, "AslpFileQuery16BitModuleName failed [%x]", v4);
    }
  }
  else
  {
    v4 = -1073741637;
    *a1 = 0;
  }
  return v4;
}
