// SeGetTokenControlInformation 
 
int __fastcall SeGetTokenControlInformation(_DWORD *a1, _DWORD *a2)
{
  int v4; // r3
  int v5; // r4
  int v6; // r5
  unsigned int v7; // r2
  int result; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  a2[2] = a1[6];
  a2[3] = a1[7];
  *a2 = a1[4];
  a2[1] = a1[5];
  v4 = a1[1];
  v5 = a1[2];
  v6 = a1[3];
  a2[6] = *a1;
  a2[7] = v4;
  a2[8] = v5;
  a2[9] = v6;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  ExAcquireResourceSharedLite(a1[12], 1);
  a2[4] = a1[13];
  a2[5] = a1[14];
  result = ExReleaseResourceLite(a1[12]);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
