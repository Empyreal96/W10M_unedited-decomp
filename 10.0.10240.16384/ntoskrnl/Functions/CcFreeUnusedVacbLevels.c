// CcFreeUnusedVacbLevels 
 
_DWORD *__fastcall CcFreeUnusedVacbLevels(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r1

  v1 = result;
  if ( (_DWORD *)*result != result )
    return (_DWORD *)sub_5269B4();
  v2 = result[2];
  if ( v2 )
  {
    result = (_DWORD *)ExFreeToNPagedLookasideList(&CcVacbLevelLookasideList, v2);
    v1[2] = 0;
  }
  return result;
}
