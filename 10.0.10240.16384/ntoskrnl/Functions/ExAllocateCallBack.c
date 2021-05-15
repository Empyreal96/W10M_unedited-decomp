// ExAllocateCallBack 
 
_DWORD *__fastcall ExAllocateCallBack(int a1, int a2)
{
  _DWORD *result; // r0

  result = (_DWORD *)ExAllocatePoolWithTag(512, 12, 1651663427);
  if ( result )
  {
    *result = 0;
    result[1] = a1;
    result[2] = a2;
  }
  return result;
}
