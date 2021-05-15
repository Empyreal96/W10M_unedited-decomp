// MiComputeCommitChargeForZeroPteRange 
 
int __fastcall MiComputeCommitChargeForZeroPteRange(int a1, unsigned int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v8; // r7
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v5 = a3;
  v6 = 0;
  if ( (*(_DWORD *)(a1 + 28) & 0x8000) != 0 )
  {
    if ( *(int *)(a1 + 32) < 0 )
      v6 = a3;
    return v6;
  }
  if ( (*(_DWORD *)(a1 + 28) & 7) == 2 )
  {
    v8 = (a2 >> 2) & 0xFFFFF;
    if ( a3 )
    {
      do
      {
        v6 += MiComputeImageVadCommitCharge(a1, v8, v5, v9);
        v8 += v9[0];
        v5 -= v9[0];
      }
      while ( v5 );
    }
    return v6;
  }
  return sub_52269C();
}
