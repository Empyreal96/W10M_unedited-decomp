// AslGuidToString 
 
int __fastcall AslGuidToString(_WORD *a1, int a2, int *a3)
{
  int v3; // r4

  v3 = RtlStringCchPrintfW(a1, 0x27u, (int)L"{%08lx-%04hx-%04hx-%02hx%02hx-%02hx%02hx%02hx%02hx%02hx%02hx}", *a3);
  if ( v3 >= 0 )
    return 0;
  AslLogCallPrintf(1, (int)"AslGuidToString", 320, "RtlStringCchPrintfW failed [%x]", v3);
  return v3;
}
