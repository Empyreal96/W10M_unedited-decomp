// RtlClearBit 
 
int __fastcall RtlClearBit(int a1, unsigned int a2)
{
  int result; // r0

  result = *(_DWORD *)(a1 + 4);
  *(_BYTE *)((a2 >> 3) + result) &= ~(unsigned __int8)(1 << (a2 & 7));
  return result;
}
