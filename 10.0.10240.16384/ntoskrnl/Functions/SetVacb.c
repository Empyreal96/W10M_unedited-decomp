// SetVacb 
 
int __fastcall SetVacb(int a1, int a2, unsigned int a3, int a4, unsigned int a5)
{
  __int64 v6; // kr00_8
  int result; // r0
  int varg_r0; // [sp+18h] [bp+8h]

  varg_r0 = a1;
  v6 = *(_QWORD *)(a1 + 24);
  result = 1;
  if ( v6 > 0x2000000 )
    return sub_53B488(1);
  if ( a5 < 0xFFFFFFFE )
    *(_DWORD *)(*(_DWORD *)(a1 + 64) + 4 * (a3 >> 18)) = a5;
  return result;
}
