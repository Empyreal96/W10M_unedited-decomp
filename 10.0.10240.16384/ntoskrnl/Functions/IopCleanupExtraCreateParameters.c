// IopCleanupExtraCreateParameters 
 
int __fastcall IopCleanupExtraCreateParameters(int a1)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 100);
  if ( result )
  {
    result = FsRtlpCleanupEcps();
    if ( result )
      *(_DWORD *)(a1 + 100) = 0;
  }
  return result;
}
