// RtlInitUnicodeString 
 
unsigned int __fastcall RtlInitUnicodeString(unsigned int result, unsigned __int16 *a2)
{
  _WORD *v2; // r4
  __int16 v3; // r2

  v2 = (_WORD *)result;
  *(_WORD *)(result + 2) = 0;
  *(_WORD *)result = 0;
  *(_DWORD *)(result + 4) = a2;
  if ( a2 )
  {
    result = wcslen(a2);
    v3 = 2 * result;
    if ( 2 * result >= 0xFFFE )
      v3 = -4;
    v2[1] = v3 + 2;
    *v2 = v3;
  }
  return result;
}
