// AuthzBasepAllocateSecurityAttribute 
 
_BYTE *__fastcall AuthzBasepAllocateSecurityAttribute(_WORD *a1)
{
  int v2; // r6
  int v3; // r4
  _BYTE *result; // r0
  _BYTE *v5; // r4

  v2 = (unsigned __int16)*a1;
  v3 = 1;
  if ( (unsigned int)KeGetCurrentIrql() >= 2 )
    v3 = 512;
  result = (_BYTE *)ExAllocatePoolWithTag(v3, v2 + 64, 1950442835);
  v5 = result;
  if ( result )
  {
    memset(result, 0, 64);
    *((_WORD *)v5 + 8) = 0;
    *((_WORD *)v5 + 9) = *a1;
    *((_DWORD *)v5 + 5) = v5 + 64;
    RtlCopyUnicodeString(v5 + 16, a1);
    *((_DWORD *)v5 + 11) = v5 + 44;
    *((_DWORD *)v5 + 12) = v5 + 44;
    *((_DWORD *)v5 + 14) = v5 + 56;
    *((_DWORD *)v5 + 15) = v5 + 56;
    result = v5;
  }
  return result;
}
