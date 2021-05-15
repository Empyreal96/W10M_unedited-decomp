// HvpViewMapLogPinChange 
 
unsigned int __fastcall HvpViewMapLogPinChange(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // r2
  unsigned int result; // r0
  unsigned int v9; // r3

  v7 = a1 + 48 * *(_DWORD *)(a1 + 24);
  *(_BYTE *)(v7 + 36) = 0;
  *(_DWORD *)(v7 + 32) = a2;
  *(_DWORD *)(v7 + 40) = a5;
  *(_DWORD *)(v7 + 44) = a6;
  *(_DWORD *)(v7 + 48) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  result = RtlWalkFrameChain(v7 + 52, 6, 0);
  *(_DWORD *)(a1 + 24) = ((unsigned __int8)*(_DWORD *)(a1 + 24) + 1) & 0xF;
  v9 = *(_DWORD *)(a1 + 28) + 1;
  if ( v9 >= 0x10 )
    v9 = 16;
  *(_DWORD *)(a1 + 28) = v9;
  return result;
}
