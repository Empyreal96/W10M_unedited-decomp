// AslpFileGetImageNtHeader 
 
int __fastcall AslpFileGetImageNtHeader(_DWORD *a1, int a2)
{
  int v2; // r4
  int v3; // r3
  int v4; // r2

  if ( *(_DWORD *)(a2 + 552) == 6 )
  {
    v3 = *(_DWORD *)(a2 + 536);
    v4 = *(_DWORD *)(v3 + 60);
    if ( *(_QWORD *)(a2 + 528) >= (unsigned __int64)(unsigned int)(v4 + 248) )
    {
      *a1 = v4 + v3;
      v2 = 0;
    }
    else
    {
      v2 = -1073741701;
      AslLogCallPrintf(1, (int)"AslpFileGetImageNtHeader", 2402, "File mapping invalid [%x]", -1073741701);
    }
  }
  else
  {
    v2 = -1073741637;
    AslLogCallPrintf(1, (int)"AslpFileGetImageNtHeader", 2391, "File mapping not a PE [%x]", -1073741637);
  }
  return v2;
}
