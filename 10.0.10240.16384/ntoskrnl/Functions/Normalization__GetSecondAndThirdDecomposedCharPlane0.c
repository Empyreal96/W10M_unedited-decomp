// Normalization__GetSecondAndThirdDecomposedCharPlane0 
 
int __fastcall Normalization__GetSecondAndThirdDecomposedCharPlane0(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r0
  int result; // r0
  int v8; // r1
  int v9; // t0
  unsigned int v10; // r4
  int v11; // r6
  int v12; // r4
  int i; // r5

  v5 = a1[8];
  *a4 = 0;
  *a3 = 0;
  if ( !v5 )
    __brkdiv0();
  v9 = a2 / v5;
  v8 = a2 % v5;
  result = v9;
  v10 = *(unsigned __int16 *)(a1[9] + 2 * v8);
  if ( (v10 & 0xE000) == 0 )
  {
    v11 = a1[10];
    v12 = (unsigned __int16)(2 * v10);
    for ( i = *(unsigned __int16 *)(v11 + 2 * (unsigned __int16)v12);
          i && i != a2;
          i = *(unsigned __int16 *)(a1[10] + 2 * v12) )
    {
      v12 = (unsigned __int16)(v12 + 2);
    }
    v10 = *(unsigned __int16 *)(v11 + 2 * v12 + 2);
  }
  if ( v10 >> 13 > 1 )
  {
    result = a1[11];
    *a3 = *(unsigned __int16 *)(result + 2 * ((v10 & 0x1FFF) + 1));
    if ( v10 >> 13 != 2 )
      *a4 = *(unsigned __int16 *)(result + 2 * ((v10 & 0x1FFF) + 2));
  }
  return result;
}
