// AslGuidToString_UStr 
 
int __fastcall AslGuidToString_UStr(int a1, int *a2)
{
  _WORD *v4; // r0
  unsigned int v5; // r4
  int v6; // r5

  *(_WORD *)a1 = 76;
  *(_WORD *)(a1 + 2) = 78;
  v4 = AslAlloc(a1, 78);
  v5 = (unsigned int)v4;
  if ( v4 )
  {
    v6 = RtlStringCchPrintfW(
           v4,
           *(unsigned __int16 *)(a1 + 2) >> 1,
           (int)L"{%08lx-%04hx-%04hx-%02hx%02hx-%02hx%02hx%02hx%02hx%02hx%02hx}",
           *a2);
    if ( v6 >= 0 )
    {
      *(_DWORD *)(a1 + 4) = v5;
      v5 = 0;
      v6 = 0;
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslGuidToString_UStr", 252, "RtlStringCchPrintfW failed [%x]", v6);
    }
    if ( v5 )
      ExFreePoolWithTag(v5);
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslGuidToString_UStr", 232, "Out of memory");
    v6 = -1073741801;
  }
  return v6;
}
