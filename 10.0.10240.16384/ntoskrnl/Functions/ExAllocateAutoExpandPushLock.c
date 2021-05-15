// ExAllocateAutoExpandPushLock 
 
_DWORD *__fastcall ExAllocateAutoExpandPushLock(char a1)
{
  int v1; // r4
  int v2; // r0
  _DWORD *result; // r0

  v1 = a1 & 1;
  if ( (a1 & 1) != 0 )
    v2 = 512;
  else
    v2 = 1;
  result = (_DWORD *)ExAllocatePoolWithTag(v2, 12);
  if ( result )
  {
    *result = 0;
    result[1] = 0;
    result[2] = 0;
    if ( !v1 )
      result[1] |= 4u;
    *result = 0;
  }
  return result;
}
