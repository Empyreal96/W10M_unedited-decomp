// IopNotifyAlreadyRegisteredFileSystems 
 
_DWORD *__fastcall IopNotifyAlreadyRegisteredFileSystems(_DWORD *result, int a2, int a3)
{
  if ( (_DWORD *)*result != result && (*(_DWORD **)*result != result || !a3) )
    result = (_DWORD *)sub_80C328();
  return result;
}
