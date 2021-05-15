// MiReleasePageFileSectionInfo 
 
_DWORD *__fastcall MiReleasePageFileSectionInfo(int a1)
{
  int v2; // r0
  _DWORD *result; // r0

  v2 = *(_DWORD *)(a1 + 4);
  if ( v2 )
    MiUnlockProtoPoolPage(v2, *(unsigned __int8 *)(a1 + 16));
  result = (_DWORD *)MiDecrementModifiedWriteCount(*(_DWORD *)a1, 0);
  if ( result )
    result = MiReleaseControlAreaWaiters(result);
  return result;
}
