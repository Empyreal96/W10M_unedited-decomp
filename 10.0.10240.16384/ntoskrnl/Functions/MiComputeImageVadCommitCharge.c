// MiComputeImageVadCommitCharge 
 
int __fastcall MiComputeImageVadCommitCharge(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  int v6; // r0
  unsigned int v7; // r1
  int result; // r0
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = (int)a4;
  v6 = MiGetProtoPteAddress(a1, a2, 13, v9);
  v7 = *(_DWORD *)(v9[0] + 28) - ((v6 - *(_DWORD *)(v9[0] + 4)) >> 2);
  if ( v7 > a3 )
    v7 = a3;
  result = 0;
  if ( (*(_WORD *)(v9[0] + 16) & 0xA) == 10 )
    return sub_5226AC(0);
  *a4 = v7;
  return result;
}
