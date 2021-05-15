// PspEmptyPropertySet 
 
_DWORD *__fastcall PspEmptyPropertySet(_DWORD *result)
{
  if ( (_DWORD *)*result != result )
    result = (_DWORD *)sub_7C0BDC();
  return result;
}
