// MiFreeDriverInitialization 
 
int __fastcall MiFreeDriverInitialization(int a1)
{
  unsigned int v1; // r4
  int result; // r0
  int v4; // r5
  int v5; // r7
  int v6; // r3
  int v7; // [sp+8h] [bp-28h] BYREF
  int v8[9]; // [sp+Ch] [bp-24h] BYREF

  v1 = *(_DWORD *)(a1 + 24);
  if ( (*(_DWORD *)(((v1 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
    return sub_7CDEB0();
  v4 = 0;
  v5 = 0;
  do
  {
    result = MiSnapDriverRange(a1, v5, 2, 0, &v7, v8);
    v5 = result;
    if ( v7 )
    {
      result = MiFreeInitializationCode(a1, v7 << 10, (v8[0] << 10) | 0xFFF);
      v4 += result;
    }
  }
  while ( v5 );
  if ( v4 )
  {
    if ( v1 == PsNtosImageBase || v1 == PsHalImageBase )
    {
      v6 = dword_634D90 - v4;
      __dmb(0xBu);
      dword_634D90 = v6;
    }
    else
    {
      do
        result = __ldrex((unsigned int *)algn_634DB0);
      while ( __strex(result - v4, (unsigned int *)algn_634DB0) );
    }
  }
  return result;
}
