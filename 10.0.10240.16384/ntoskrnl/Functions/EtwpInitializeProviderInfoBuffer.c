// EtwpInitializeProviderInfoBuffer 
 
int __fastcall EtwpInitializeProviderInfoBuffer(_DWORD *a1, int a2, int a3)
{
  int v6; // r0
  int v7; // r1
  int v8; // r3
  int v9; // r4
  int v10; // r5
  int v11; // r4
  int v12; // r3
  int result; // r0
  int v14; // r1

  EtwpInitializeBufferHeader(a1, a2);
  *(_DWORD *)a2 = a3;
  v6 = EtwpResetBufferHeader(a2, 7);
  *(_DWORD *)(a2 + 44) = 3;
  *(_WORD *)(a2 + 52) = 1;
  v8 = a1[59];
  v9 = a1[60];
  v10 = a1[61];
  *(_DWORD *)(a2 + 56) = a1[58];
  *(_DWORD *)(a2 + 60) = v8;
  *(_DWORD *)(a2 + 64) = v9;
  *(_DWORD *)(a2 + 68) = v10;
  v11 = a1[31] & v7;
  v12 = *(_DWORD *)(a2 + 32);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(a2 + 32) = v12 & ~v7 | v11;
  if ( a1[31] != 1 )
    return sub_81B724(v6);
  result = *(_DWORD *)(a2 + 32) & v7;
  v14 = EtwPerfFreq;
  *(_DWORD *)(a2 + 36) = EtwPerfFreq >> 29;
  *(_DWORD *)(a2 + 32) = result | (8 * v14);
  return result;
}
