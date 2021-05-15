// FsRtlCompleteLockIrpReal 
 
int __fastcall FsRtlCompleteLockIrpReal(int (__fastcall *a1)(int, int), int a2, int a3, int a4, int *a5, int a6)
{
  int result; // r0

  if ( a1 )
  {
    if ( a6 )
      *(_DWORD *)(a6 + 72) = 0;
    *(_DWORD *)(a3 + 24) = a4;
    result = a1(a2, a3);
    *a5 = result;
  }
  else
  {
    *(_DWORD *)(a3 + 24) = a4;
    result = pIofCompleteRequest(a3, 1);
    *a5 = a4;
  }
  return result;
}
