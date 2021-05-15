// SepAppendPrimaryGroup 
 
int __fastcall SepAppendPrimaryGroup(_DWORD *a1, int a2)
{
  int v2; // r3
  int v4; // r6
  int v5; // r4
  int result; // r0
  int v7; // r3

  v2 = a1[41];
  if ( v2 )
    v4 = *(unsigned __int16 *)(v2 + 2) + a1[40];
  else
    v4 = a1[40];
  v5 = *(unsigned __int8 *)(a2 + 1) + 2;
  result = memmove(v4, a2, 4 * v5);
  v7 = a1[35];
  a1[39] = v4;
  a1[35] = v7 - 4 * v5;
  return result;
}
