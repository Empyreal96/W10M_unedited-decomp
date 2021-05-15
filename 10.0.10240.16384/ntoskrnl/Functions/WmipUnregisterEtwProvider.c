// WmipUnregisterEtwProvider 
 
_DWORD *__fastcall WmipUnregisterEtwProvider(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r3

  v1 = (_DWORD *)result[7];
  v2 = v1[27] - 1;
  v1[27] = v2;
  if ( !v2 )
  {
    v1[20] = 0;
    v1[22] = 0;
    v1[23] = 0;
    result = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1885957463);
    if ( result )
    {
      result[2] = 1;
      result = (_DWORD *)WmipQueueLegacyEtwWork(result, v1, 0);
    }
  }
  return result;
}
