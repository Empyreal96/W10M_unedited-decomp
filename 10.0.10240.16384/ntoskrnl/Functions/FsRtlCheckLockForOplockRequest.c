// FsRtlCheckLockForOplockRequest 
 
int __fastcall FsRtlCheckLockForOplockRequest(int a1)
{
  int v1; // r5
  int result; // r0

  v1 = *(_DWORD *)(a1 + 12);
  if ( v1 && (*(_DWORD *)(v1 + 20) || *(_DWORD *)(v1 + 24)) )
    result = sub_526A80();
  else
    result = 1;
  return result;
}
