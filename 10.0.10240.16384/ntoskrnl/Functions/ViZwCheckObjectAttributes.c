// ViZwCheckObjectAttributes 
 
_DWORD *__fastcall ViZwCheckObjectAttributes(_DWORD *result)
{
  _DWORD *v1; // r4

  v1 = result;
  if ( result )
  {
    ViZwCheckVirtualAddress(result);
    ViZwCheckUnicodeString(v1[2]);
    ViZwCheckVirtualAddress(v1[4]);
    result = (_DWORD *)ViZwCheckVirtualAddress(v1[5]);
  }
  return result;
}
