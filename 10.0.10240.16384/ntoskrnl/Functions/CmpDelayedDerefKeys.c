// CmpDelayedDerefKeys 
 
_DWORD *__fastcall CmpDelayedDerefKeys(_DWORD *result)
{
  if ( (_DWORD *)*result != result )
    result = (_DWORD *)sub_804D0C();
  return result;
}
