// FsRtlAreThereCurrentOrInProgressFileLocks 
 
BOOL __fastcall FsRtlAreThereCurrentOrInProgressFileLocks(int a1)
{
  int v1; // r2
  int v2; // r3
  int v3; // r3
  BOOL result; // r0

  v1 = *(_DWORD *)(a1 + 12);
  result = 1;
  if ( !v1 || (*(_DWORD *)(v1 + 20) || *(_DWORD *)(v1 + 24) ? (v2 = 1) : (v2 = 0), !v2) )
  {
    v3 = *(_DWORD *)(a1 + 60);
    __dmb(0xBu);
    if ( !v3 )
      result = 0;
  }
  return result;
}
