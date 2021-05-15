// ExpWnfComposeValueName 
 
int __fastcall ExpWnfComposeValueName(int a1, int a2, unsigned __int16 *a3, int a4)
{
  int result; // r0
  int v6; // r1
  int v7; // r4
  unsigned __int16 *varg_r2; // [sp+18h] [bp+10h]

  varg_r2 = a3;
  RtlInt64ToUnicodeString(a1 ^ 0xA3BC0074, a2 ^ 0x41C64E6D, 16, a3);
  result = *a3 >> 1;
  *a3 = 32;
  v6 = 16 - result;
  if ( result )
  {
    v7 = 32;
    do
    {
      --result;
      v7 -= 2;
      *(_WORD *)(v7 + *((_DWORD *)a3 + 1)) = *(_WORD *)(*((_DWORD *)a3 + 1) + 2 * result);
    }
    while ( result );
  }
  for ( ; v6; *(_WORD *)(*((_DWORD *)a3 + 1) + 2 * v6) = 48 )
    --v6;
  return result;
}
