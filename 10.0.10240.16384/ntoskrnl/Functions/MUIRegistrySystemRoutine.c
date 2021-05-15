// MUIRegistrySystemRoutine 
 
_DWORD *__fastcall MUIRegistrySystemRoutine(_DWORD *result)
{
  _DWORD *v1; // r4
  int v2; // r0
  int v3; // r2

  v1 = result;
  if ( result )
  {
    v2 = RtlpMuiRegCreateKernelRegistryInfo(
           result + 1,
           (int)(result + 2),
           result + 3,
           result[4],
           result + 5,
           result[6],
           result + 7);
    v1[8] = v2;
    if ( v2 >= 0 )
    {
      v3 = v1[1];
      if ( v3 )
        *(_DWORD *)(v3 + 12) = MEMORY[0xFFFF93A4];
    }
    result = (_DWORD *)*v1;
    if ( *v1 )
      result = (_DWORD *)KeSetEvent((int)result, 1, 0);
  }
  return result;
}
