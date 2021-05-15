// MmDiscardDriverSection 
 
unsigned int __fastcall MmDiscardDriverSection(unsigned int a1, int a2, unsigned int a3, unsigned int a4)
{
  int *v5; // r0
  int *v6; // r6
  unsigned int v7; // r4
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r0
  int v11; // r3
  unsigned int v13; // [sp+0h] [bp-20h]
  unsigned int v14; // [sp+8h] [bp-18h] BYREF
  unsigned int v15[5]; // [sp+Ch] [bp-14h] BYREF

  v13 = a1;
  v14 = a3;
  v15[0] = a4;
  v5 = MiLookupDataTableEntry(a1, 0);
  v6 = v5;
  v7 = v5[6];
  if ( (*(_DWORD *)(((v7 >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 || v7 == PsNtosImageBase || v7 == PsHalImageBase )
  {
    MiSnapDriverRange((int)v5, 0, 0, a1, &v14, v15);
    if ( v14 )
    {
      v8 = MiFreeInitializationCode(v6, v14 << 10, (v15[0] << 10) | 0xFFF);
      if ( v8 )
      {
        if ( v7 == PsNtosImageBase || v7 == PsHalImageBase )
        {
          v11 = dword_634D90 - v8;
          __dmb(0xBu);
          dword_634D90 = v11;
        }
        else
        {
          v9 = -v8;
          do
            v10 = __ldrex((unsigned int *)algn_634DB0);
          while ( __strex(v10 + v9, (unsigned int *)algn_634DB0) );
        }
      }
    }
  }
  return v13;
}
