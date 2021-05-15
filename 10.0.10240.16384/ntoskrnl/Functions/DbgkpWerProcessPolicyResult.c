// DbgkpWerProcessPolicyResult 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall DbgkpWerProcessPolicyResult(int a1, int a2, int a3, _BYTE *a4)
{
  int result; // r0

  if ( a2 )
  {
    *a4 = 1;
    *(_QWORD *)(a1 + 72) = *(_QWORD *)&a2;
    if ( a2 == 1 )
    {
      result = DbgkpWerCaptureLiveTriageDump((_DWORD *)a1);
    }
    else if ( a2 == 2 )
    {
      result = DbgkpWerCaptureLiveFullDump((_DWORD *)a1, a4);
    }
    else
    {
      DbgPrintEx(5, 0, (int)"DBGK: DbgkpWerProcessPolicyResult: Unknown policy option %d\n\n", a2);
      result = -1073741637;
    }
  }
  else
  {
    *a4 = 1;
    result = 0;
  }
  return result;
}
