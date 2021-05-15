// PpmInfoAdjustSetting 
 
int __fastcall PpmInfoAdjustSetting(int a1, int a2, unsigned int a3, unsigned int a4, int a5, unsigned int a6)
{
  unsigned int v8; // r5
  int v10; // r4
  int v11; // r9

  v8 = a3;
  if ( a6 < *(_DWORD *)(a1 + 20) && (*(_BYTE *)(a1 + 25) & 8) == 0 )
    return 0;
  v10 = 0;
  v11 = 1 << *(_BYTE *)(a1 + 24);
  if ( a3 <= a4 )
  {
    do
    {
      if ( PpmInfoWriteData(a5, a6, v8, a1, a2) )
        v10 = 1;
      ++v8;
    }
    while ( v8 <= a4 );
    if ( v10 && (v11 & 0x200) != 0 )
      *(_DWORD *)(a2 + 52) = PpmPerfComputePerfReductionTolerance(*(_DWORD *)(a2 + 44));
  }
  return v10;
}
