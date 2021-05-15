// ViCiPreprocessOptions 
 
_DWORD *ViCiPreprocessOptions(_DWORD *result, const char *a2, char a3, int a4, ...)
{
  if ( *result == -1 )
  {
    if ( (a3 & 0xFu) >= 5 )
      *result = 4;
    else
      *result = ViCiDefaultActions[a3 & 0xF];
  }
  if ( *result )
  {
    if ( (*result & 0x10) != 0 )
      *result = 0;
    VfUtilDbgPrint((int)"*********** Verifier Detected a Code Integrity Issue ************\n");
    VfUtilDbgPrint((int)"**\n");
    VfUtilDbgPrint((int)"** ");
    if ( a2 )
      DbgPrintEx(101, 0, (int)a2, a4);
    VfUtilDbgPrint((int)"\n");
    VfUtilDbgPrint((int)"**\n");
    result = (_DWORD *)VfUtilDbgPrint((int)"*****************************************************************\n");
  }
  return result;
}
