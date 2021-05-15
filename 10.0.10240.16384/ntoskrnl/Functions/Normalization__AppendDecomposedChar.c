// Normalization__AppendDecomposedChar 
 
int __fastcall Normalization__AppendDecomposedChar(_DWORD *a1, int a2, int a3)
{
  int v4; // r0
  unsigned __int16 v6; // r4
  unsigned int v7; // r3
  int v8; // r0
  int v9; // r1
  int i; // r3
  int v11; // r4
  bool v12; // zf
  int v13; // r3
  int j; // r5
  int v15; // r0
  int v16; // r1
  int v17; // r7
  int result; // r0

  v4 = a1[8];
  v6 = a2;
  if ( !v4 )
    __brkdiv0();
  v7 = *(unsigned __int16 *)(a1[9] + 2 * (a2 % v4));
  if ( (v7 & 0xE000) == 0 )
  {
    v8 = a1[10];
    v9 = (unsigned __int16)(2 * v7);
    for ( i = *(unsigned __int16 *)(v8 + 2 * v9); i && i != v6; i = *(unsigned __int16 *)(a1[10] + 2 * v9) )
      v9 = (unsigned __int16)(v9 + 2);
    v7 = *(unsigned __int16 *)(v8 + 2 * v9 + 2);
  }
  v11 = v7 >> 13;
  v12 = v7 >> 13 == 7;
  v13 = v7 & 0x1FFF;
  if ( v12 )
    v11 = 100;
  for ( j = v13; v11 > 0; j = (unsigned __int16)(j + 1) )
  {
    v15 = a1[11];
    v16 = *(unsigned __int16 *)(v15 + 2 * j);
    if ( !*(_WORD *)(v15 + 2 * j) )
      break;
    v17 = *(unsigned __int16 *)(v15 + 2 * j);
    if ( (unsigned int)(v16 - 55296) <= 0x7FF )
    {
      j = (unsigned __int16)(j + 1);
      --v11;
      v17 = *(unsigned __int16 *)(v15 + 2 * j) + ((v16 - 55287) << 10);
    }
    result = Normalization__NormalizeCharacter(a1, v17, *(unsigned __int8 *)((v17 >> 7) + a1[5]), a3);
    if ( result )
      return result;
    --v11;
  }
  return 0;
}
