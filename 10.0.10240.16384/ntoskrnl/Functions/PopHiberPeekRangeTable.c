// PopHiberPeekRangeTable 
 
int __fastcall PopHiberPeekRangeTable(int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r1
  _DWORD v6[2]; // [sp+8h] [bp-8h] BYREF

  v6[0] = a3;
  v6[1] = a4;
  v4 = *(_DWORD *)PopReadProducerConsumerBuffer(a1, a2, v6, dword_61EF00, a3, 0);
  return ((v4 >> 8) & 0x3FFFFF) + 4 * ((unsigned __int8)v4 + 1);
}
