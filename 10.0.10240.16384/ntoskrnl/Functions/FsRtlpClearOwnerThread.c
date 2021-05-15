// FsRtlpClearOwnerThread 
 
int __fastcall FsRtlpClearOwnerThread(int a1, int a2)
{
  int result; // r0

  if ( a2 )
  {
    result = *(_DWORD *)(a2 + 20);
    *(_DWORD *)(a2 + 20) = 0;
  }
  else
  {
    result = *(_DWORD *)(a1 + 12);
    *(_DWORD *)(a1 + 12) = 0;
  }
  if ( result )
    result = ObDereferenceObjectDeferDeleteWithTag(result, 1953261124);
  return result;
}
