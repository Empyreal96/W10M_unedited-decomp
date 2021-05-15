// ExMapHandleToPointerEx 
 
_DWORD *__fastcall ExMapHandleToPointerEx(int a1, __int16 a2)
{
  _DWORD *result; // r0

  result = ExMapHandleToPointer(a1, a2);
  if ( !result )
    result = (_DWORD *)sub_7F77FC();
  return result;
}
