// MiPopFreeWsle 
 
unsigned int __fastcall MiPopFreeWsle(int a1)
{
  unsigned int *v1; // r2
  unsigned int result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r7
  unsigned int v5; // r6
  unsigned int v6; // r1
  unsigned int v7; // r5
  unsigned int v8; // r1
  unsigned int v9; // r3

  v1 = *(unsigned int **)(a1 + 92);
  result = *v1;
  v3 = v1[4];
  if ( *v1 > v3 )
    sub_50FA28();
  v4 = v1[9];
  v5 = v1[63];
  v6 = *(_DWORD *)(v4 * result + v5);
  if ( (v6 & 1) != 0 || (*(_DWORD *)(v4 * result + v5) & 0xFFE) != 4094 )
    KeBugCheckEx(26, 20481, v1);
  v7 = v6 >> 12;
  if ( v6 >> 12 != 0xFFFFF )
  {
    if ( v7 > v3 )
      KeBugCheckEx(26, 20482, v1);
    v8 = *(_DWORD *)(v4 * v7 + v5);
    if ( (v8 & 1) != 0 || (((unsigned __int16)result ^ (unsigned __int16)(v8 >> 1)) & 0x7FF) != 0 )
      KeBugCheckEx(26, 20483, v1);
    *(_DWORD *)(v4 * v7 + v5) = v8 | 0xFFE;
  }
  v9 = v1[2];
  *v1 = v7;
  if ( result > v9 )
    v1[2] = result;
  return result;
}
