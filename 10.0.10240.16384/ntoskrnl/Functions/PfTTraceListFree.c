// PfTTraceListFree 
 
int __fastcall PfTTraceListFree(int *a1)
{
  int result; // r0
  __int64 v3; // r2

  while ( 1 )
  {
    result = *a1;
    if ( (int *)*a1 == a1 )
      break;
    v3 = *(_QWORD *)result;
    if ( *(int **)(result + 4) != a1 || *(_DWORD *)(v3 + 4) != result )
      __fastfail(3u);
    *a1 = v3;
    *(_DWORD *)(v3 + 4) = a1;
    PfTFreeTraceDump(result);
  }
  return result;
}
