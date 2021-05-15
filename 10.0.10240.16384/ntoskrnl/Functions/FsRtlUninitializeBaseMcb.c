// FsRtlUninitializeBaseMcb 
 
int __fastcall FsRtlUninitializeBaseMcb(int a1)
{
  int result; // r0

  if ( *(_WORD *)(a1 + 8) == 1 && *(_DWORD *)a1 == 15 )
    result = ExFreeToPagedLookasideList(&FsRtlFirstMappingLookasideList, *(_DWORD *)(a1 + 12));
  else
    result = ExFreePoolWithTag(*(_DWORD *)(a1 + 12), 0);
  return result;
}
