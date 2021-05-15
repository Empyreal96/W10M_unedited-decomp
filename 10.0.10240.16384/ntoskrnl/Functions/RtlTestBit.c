// RtlTestBit 
 
int __fastcall RtlTestBit(int a1, unsigned int a2)
{
  return (*(char *)((a2 >> 3) + *(_DWORD *)(a1 + 4)) >> (a2 & 7)) & 1;
}
