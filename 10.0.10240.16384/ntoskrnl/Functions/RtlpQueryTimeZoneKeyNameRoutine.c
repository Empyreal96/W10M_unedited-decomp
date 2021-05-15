// RtlpQueryTimeZoneKeyNameRoutine 
 
int __fastcall RtlpQueryTimeZoneKeyNameRoutine(int a1, int a2, unsigned __int16 *a3, unsigned int a4, int a5, int a6)
{
  unsigned int v7; // r0
  unsigned int v8; // r1
  int v9; // r4
  int result; // r0

  v7 = wcsnlen(a3, a4 >> 1);
  v8 = *(unsigned __int16 *)(a6 + 2);
  if ( 2 * (v7 + 1) > v8 )
    v7 = (v8 >> 1) - 1;
  v9 = 2 * v7;
  memmove(*(_DWORD *)(a6 + 4), (int)a3, 2 * v7);
  result = 0;
  *(_WORD *)(v9 + *(_DWORD *)(a6 + 4)) = 0;
  *(_WORD *)a6 = v9;
  return result;
}
