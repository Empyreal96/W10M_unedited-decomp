// AdtpEtwBuildString 
 
int __fastcall AdtpEtwBuildString(int *a1, unsigned __int16 *a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r5
  int v7; // r7
  int v9; // r5
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r2
  int result; // r0

  v4 = *a2;
  v7 = (v4 >> 1) + 1;
  if ( a2[1] <= v4 || (v9 = *((_DWORD *)a2 + 1), v10 = 2 * v7, *(_WORD *)(v9 + 2 * v7 - 2)) )
  {
    v11 = *a4;
    v12 = *a4 + v7;
    if ( v12 >= 0x400 )
      return sub_815E60();
    v9 = a3 + 2 * v11;
    *a4 = v12;
    memmove(v9, *((_DWORD *)a2 + 1), *a2);
    v10 = 2 * v7;
    *(_WORD *)(2 * v7 + v9 - 2) = 0;
  }
  a1[1] = 0;
  a1[2] = v10;
  result = 0;
  *a1 = v9;
  a1[3] = 0;
  return result;
}
