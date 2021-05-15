// FsRtlUninitializeLargeMcb 
 
_DWORD *__fastcall FsRtlUninitializeLargeMcb(_DWORD *result)
{
  _DWORD *v1; // r4

  v1 = result;
  if ( *result )
  {
    ExFreeToNPagedLookasideList(&FsRtlFastMutexLookasideList, *result);
    *v1 = 0;
    result = (_DWORD *)FsRtlUninitializeBaseMcb(v1 + 1);
  }
  return result;
}
