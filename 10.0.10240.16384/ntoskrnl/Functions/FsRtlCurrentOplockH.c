// FsRtlCurrentOplockH 
 
int __fastcall FsRtlCurrentOplockH(int a1)
{
  int v1; // r2

  v1 = 0;
  if ( *(_DWORD *)a1 && (*(_DWORD *)(*(_DWORD *)a1 + 72) & 0x2000) != 0 )
    v1 = 1;
  return v1;
}
