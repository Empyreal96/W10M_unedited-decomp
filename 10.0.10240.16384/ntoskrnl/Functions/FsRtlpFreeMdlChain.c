// FsRtlpFreeMdlChain 
 
int __fastcall FsRtlpFreeMdlChain(int result)
{
  int v1; // r4
  int v2; // r5

  v1 = result;
  if ( result )
  {
    do
    {
      v2 = *(_DWORD *)v1;
      if ( (*(_WORD *)(v1 + 6) & 2) != 0 )
        MmUnlockPages(v1);
      result = IoFreeMdl(v1);
      v1 = v2;
    }
    while ( v2 );
  }
  return result;
}
