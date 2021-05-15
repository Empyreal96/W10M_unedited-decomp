// KiAddProcessorToGroupDatabase 
 
int __fastcall KiAddProcessorToGroupDatabase(int result, int a2)
{
  int v2; // r6
  int v4; // r4
  int v5; // r5
  unsigned int v6; // r8
  unsigned int v7; // r7
  __int16 v8; // r3
  int v9; // r2
  unsigned int v10; // r1
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r1

  v2 = *(_DWORD *)(result + 2360);
  v4 = *(unsigned __int16 *)(v2 + 264);
  v5 = result;
  v6 = KiGroupBlock[2 * v4] + 1;
  v7 = 31 - __clz(v6);
  *(_DWORD *)(result + 1048) = v6;
  v8 = *(_WORD *)(v2 + 264);
  *(_BYTE *)(result + 1053) = v7;
  *(_BYTE *)(result + 1052) = v8;
  KiGroupBlock[2 * v4] |= v6;
  if ( KeForceGroupAwareness )
    return sub_519D4C();
  if ( *(_BYTE *)(result + 1052) )
  {
    if ( KiActiveGroups )
      v12 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~dword_681D78[0] >> 16))
                            + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~dword_681D78[0] >> 24))
                            + *((_BYTE *)RtlpBitsClearTotal
                              + (unsigned __int8)((unsigned __int16)~LOWORD(dword_681D78[0]) >> 8))
                            + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~LOBYTE(dword_681D78[0])));
    else
      v12 = 0;
    if ( !v12 )
      __brkdiv0();
    v13 = v7 % v12;
    result = v7 / v12;
    *(_BYTE *)v5 = v13;
  }
  else
  {
    *(_BYTE *)result = v7;
  }
  v9 = *(_DWORD *)(v5 + 20);
  v10 = v7 + (*(unsigned __int8 *)(v5 + 1052) << 6);
  KiProcessorIndexToNumberMappingTable[v9] = v10;
  KiProcessorNumberToIndexMappingTable[v10] = v9;
  v11 = 5;
  do
  {
    if ( !a2 )
      *(_DWORD *)(v2 + 292) |= v6;
    *(_DWORD *)(v2 + 296) |= v6;
    v2 += 8;
    --v11;
  }
  while ( v11 );
  return result;
}
