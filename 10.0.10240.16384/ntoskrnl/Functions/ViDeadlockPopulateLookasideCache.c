// ViDeadlockPopulateLookasideCache 
 
_DWORD *__fastcall ViDeadlockPopulateLookasideCache(int a1, __int16 a2)
{
  int v2; // r4
  _DWORD *v4; // r5
  _DWORD *result; // r0
  _DWORD *v6; // r4

  LOWORD(v2) = a2;
  v4 = 0;
  do
  {
    result = (_DWORD *)ExAllocateFromNPagedLookasideList(a1);
    if ( !result )
      break;
    v2 = (unsigned __int16)(v2 - 1);
    *result = v4;
    v4 = result;
  }
  while ( v2 );
  if ( v4 )
  {
    do
    {
      v6 = (_DWORD *)*v4;
      result = (_DWORD *)ExFreeToNPagedLookasideList(a1, v4);
      v4 = v6;
    }
    while ( v6 );
  }
  return result;
}
