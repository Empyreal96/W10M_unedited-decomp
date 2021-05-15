// RtlInitUnicodeStringEx 
 
int __fastcall RtlInitUnicodeStringEx(int a1, unsigned __int16 *a2)
{
  unsigned int v3; // r0

  *(_WORD *)a1 = 0;
  *(_WORD *)(a1 + 2) = 0;
  *(_DWORD *)(a1 + 4) = a2;
  if ( !a2 )
    return 0;
  v3 = wcslen(a2);
  if ( v3 <= 0x7FFE )
  {
    *(_WORD *)a1 = 2 * v3;
    *(_WORD *)(a1 + 2) = 2 * v3 + 2;
    return 0;
  }
  return -1073741562;
}
