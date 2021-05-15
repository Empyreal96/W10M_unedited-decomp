// ViDeadlockPreprocessOptions 
 
_DWORD *ViDeadlockPreprocessOptions(_DWORD *result, const char *a2, int a3, int a4, __int64 a5, ...)
{
  unsigned int v7; // r5

  if ( *result == -1 )
  {
    v7 = a3 & 0xFFF;
    if ( v7 >= 0xC )
      *result = 4;
    else
      *result = *(_DWORD *)&ViDeadlockDefaultActions[2 * v7];
  }
  if ( *result )
  {
    if ( (*result & 0x10) != 0 )
      *result = 0;
    ViDeadlockIssue = a3;
    unk_61CC84 = a4;
    unk_61CC88 = a5;
    VfUtilDbgPrint((int)"************ Verifier Detected a Potential Deadlock *************\n");
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
