// FsRtlRemoveReservedPerFileContext 
 
int __fastcall FsRtlRemoveReservedPerFileContext(int *a1)
{
  int v1; // r3
  int result; // r0

  v1 = *a1;
  if ( !*a1 )
    return 0;
  result = *(_DWORD *)(v1 + 12);
  if ( result )
    *(_DWORD *)(v1 + 12) = 0;
  return result;
}
