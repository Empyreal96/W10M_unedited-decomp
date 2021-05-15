// MiInitializeLockedPagesTracking 
 
_DWORD *__fastcall MiInitializeLockedPagesTracking(int a1)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(512, 16, 2018798925);
  if ( result )
  {
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    result[3] = 1;
    result[2] = 0;
    *(_DWORD *)(a1 + 424) = result;
  }
  return result;
}
