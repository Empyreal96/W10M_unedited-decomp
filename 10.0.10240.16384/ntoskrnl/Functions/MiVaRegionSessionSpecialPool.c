// MiVaRegionSessionSpecialPool 
 
unsigned int __fastcall MiVaRegionSessionSpecialPool(int a1, int a2)
{
  unsigned int v2; // r4
  bool v3; // zf
  int v4; // r1
  char v5; // r3
  unsigned int result; // r0
  int v7; // r3

  v2 = (unsigned int)(a1 - dword_63389C) >> 22;
  v3 = a2 == 0;
  v4 = *(_DWORD *)(dword_63501C + 36);
  v5 = v2 & 7;
  result = (unsigned int)(a1 - dword_63389C) >> 25;
  if ( v3 )
    v7 = *(unsigned __int8 *)((v2 >> 3) + v4) & ~(1 << v5);
  else
    v7 = *(unsigned __int8 *)((v2 >> 3) + v4) | (1 << v5);
  *(_BYTE *)(result + v4) = v7;
  return result;
}
