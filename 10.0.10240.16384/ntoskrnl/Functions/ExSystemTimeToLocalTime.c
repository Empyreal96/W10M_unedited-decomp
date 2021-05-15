// ExSystemTimeToLocalTime 
 
int __fastcall ExSystemTimeToLocalTime(__int64 *a1, int *a2)
{
  __int64 v2; // r4
  bool v3; // cf
  int result; // r0
  int v5; // r3

  v2 = *a1;
  v3 = *(_DWORD *)a1 >= (unsigned int)ExpTimeZoneBias;
  result = *(_DWORD *)a1 - ExpTimeZoneBias;
  v5 = dword_61A4BC;
  *a2 = result;
  a2[1] = HIDWORD(v2) - (v5 + !v3);
  return result;
}
