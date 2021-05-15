// FsRtlCurrentOplock 
 
int __fastcall FsRtlCurrentOplock(int a1)
{
  int v1; // r1

  v1 = 0;
  if ( *(_DWORD *)a1 && (*(_DWORD *)(*(_DWORD *)a1 + 72) & 0x701E) != 0 )
    v1 = 1;
  return v1;
}
