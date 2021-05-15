// MiFormFullImageName 
 
int __fastcall MiFormFullImageName(unsigned __int16 *a1, _WORD *a2, unsigned __int16 *a3)
{
  unsigned __int16 v6; // r3
  int v7; // r0
  int result; // r0

  v6 = *a2 + *a1 + 2;
  a3[1] = v6;
  v7 = ExAllocatePoolWithTag(1, v6, 1413770573);
  *((_DWORD *)a3 + 1) = v7;
  if ( !v7 )
    JUMPOUT(0x80B274);
  *a3 = *a1;
  memmove(v7, *((_DWORD *)a1 + 1), *a1);
  if ( RtlAppendStringToString(a3, a2) < 0 )
    return sub_80B26C();
  result = 1;
  *(_WORD *)(*((_DWORD *)a3 + 1) + 2 * (*a3 >> 1)) = 0;
  return result;
}
