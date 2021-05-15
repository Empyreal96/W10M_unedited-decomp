// SepAppendDefaultDacl 
 
int __fastcall SepAppendDefaultDacl(_DWORD *a1, int a2)
{
  unsigned int v2; // r5
  int v4; // r4
  int result; // r0
  int v6; // r3

  v2 = *(unsigned __int16 *)(a2 + 2);
  v4 = a1[40] + 4 * (*(unsigned __int8 *)(a1[39] + 1) + 2);
  result = memmove(v4, a2, v2);
  v6 = a1[35];
  a1[41] = v4;
  a1[35] = v6 - v2;
  return result;
}
