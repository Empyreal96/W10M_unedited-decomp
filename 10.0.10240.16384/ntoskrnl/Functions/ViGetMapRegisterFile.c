// ViGetMapRegisterFile 
 
_DWORD *__fastcall ViGetMapRegisterFile(int a1)
{
  _DWORD *result; // r0

  result = (_DWORD *)(a1 & 0xFFFFFFFE);
  if ( !result || *result != -1393569779 )
    result = 0;
  return result;
}
