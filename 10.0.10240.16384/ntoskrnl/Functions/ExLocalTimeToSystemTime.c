// ExLocalTimeToSystemTime 
 
unsigned int __fastcall ExLocalTimeToSystemTime(__int64 *a1, _DWORD *a2)
{
  __int64 v2; // r4
  unsigned int v3; // kr00_4
  int v4; // kr04_4
  int v5; // r3
  unsigned int result; // r0

  v2 = *a1;
  v3 = *(_DWORD *)a1;
  v4 = ExpTimeZoneBias;
  v5 = MEMORY[0x61A4BC];
  *a2 = *(_DWORD *)a1 + ExpTimeZoneBias;
  result = v3 + v4;
  a2[1] = (__PAIR64__(v5, v3) + __PAIR64__(HIDWORD(v2), v4)) >> 32;
  return result;
}
