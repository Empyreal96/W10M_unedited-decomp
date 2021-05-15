// IopReverseEnumerationOrder 
 
_DWORD **__fastcall IopReverseEnumerationOrder(_DWORD **result, _DWORD *a2)
{
  int v2; // r3

  if ( *a2 == 1 && (v2 = a2[1]) != 0 )
  {
    a2[1] = v2 - 1;
    a2[1] = **result - v2;
    *a2 = 2;
  }
  else
  {
    *a2 = 3;
    a2[1] = 0;
  }
  return result;
}
