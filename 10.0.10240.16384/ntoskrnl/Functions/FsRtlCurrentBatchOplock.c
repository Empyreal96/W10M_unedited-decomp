// FsRtlCurrentBatchOplock 
 
int __fastcall FsRtlCurrentBatchOplock(int a1)
{
  int v1; // r2

  v1 = 0;
  if ( *(_DWORD *)a1 && (*(_DWORD *)(*(_DWORD *)a1 + 72) & 0xC) != 0 )
    v1 = 1;
  return v1;
}
