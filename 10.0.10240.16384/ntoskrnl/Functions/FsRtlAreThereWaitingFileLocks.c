// FsRtlAreThereWaitingFileLocks 
 
BOOL __fastcall FsRtlAreThereWaitingFileLocks(int a1)
{
  BOOL v1; // r3
  int v2; // r2

  v1 = 0;
  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 12);
    if ( v2 )
      v1 = *(_DWORD *)(v2 + 28) != 0;
  }
  return v1;
}
