// FsRtlLookupReservedPerFileContext 
 
int __fastcall FsRtlLookupReservedPerFileContext(int a1)
{
  int result; // r0

  if ( *(_DWORD *)a1 )
    result = *(_DWORD *)(*(_DWORD *)a1 + 12);
  else
    result = 0;
  return result;
}
