// Normalization__GetThirdAndLastDecomposedCharPlane0 
 
int __fastcall Normalization__GetThirdAndLastDecomposedCharPlane0(_DWORD *a1, int a2)
{
  int v3; // r0
  __int16 v4; // r3
  int v5; // r0
  int v6; // r2
  int i; // r3

  v3 = a1[8];
  if ( !v3 )
    __brkdiv0();
  v4 = *(_WORD *)(a1[9] + 2 * (a2 % v3));
  if ( (v4 & 0xE000) == 0 )
  {
    v5 = a1[10];
    v6 = (unsigned __int16)(2 * v4);
    for ( i = *(unsigned __int16 *)(v5 + 2 * v6); i && i != a2; i = *(unsigned __int16 *)(a1[10] + 2 * v6) )
      v6 = (unsigned __int16)(v6 + 2);
    v4 = *(_WORD *)(v5 + 2 * v6 + 2);
  }
  return *(unsigned __int16 *)(a1[11] + 2 * ((v4 & 0x1FFF) + 2));
}
