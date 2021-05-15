// FsRtlDeleteExtraCreateParameterLookasideList 
 
_DWORD *__fastcall FsRtlDeleteExtraCreateParameterLookasideList(unsigned __int64 *a1, char a2)
{
  _DWORD *result; // r0

  if ( (a2 & 2) != 0 )
    result = (_DWORD *)ExDeleteNPagedLookasideList(a1);
  else
    result = ExDeletePagedLookasideList((int)a1);
  return result;
}
