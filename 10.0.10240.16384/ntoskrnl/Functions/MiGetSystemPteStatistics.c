// MiGetSystemPteStatistics 
 
int __fastcall MiGetSystemPteStatistics(_DWORD *a1, _DWORD *a2, unsigned int *a3, int a4)
{
  int v5; // r3
  int v6; // r6
  unsigned int v9; // r2
  unsigned int v10; // r3
  unsigned int v11; // r4
  int result; // r0
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v5 = a1[3];
  v6 = 1;
  if ( (v5 & 4) != 0 )
    v6 = 16;
  v9 = RtlFindLongestRunClear(a1, v13, (int)a3, v5) * v6;
  v10 = dword_635310;
  *a3 = v9;
  v11 = (v10 >> 12) - 0x20000;
  if ( v10 >> 12 <= 0x20000 )
    v11 = 0;
  if ( v11 > v9 )
    *a3 = v11;
  result = MiGetNumberOfCachedPtes((int)a1);
  *a2 = v11 + (a1[12] + result) * v6;
  return result;
}
