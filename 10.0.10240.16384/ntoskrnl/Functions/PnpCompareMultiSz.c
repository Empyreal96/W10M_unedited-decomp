// PnpCompareMultiSz 
 
BOOL __fastcall PnpCompareMultiSz(unsigned __int16 *a1, int a2, int a3, int a4)
{
  BOOL v6; // r4
  int v7; // r3
  unsigned int v9; // [sp+8h] [bp-18h] BYREF
  unsigned int v10[5]; // [sp+Ch] [bp-14h] BYREF

  v6 = 0;
  if ( PnpGetMultiSzLength((int)a1, 0x7FFFFFFF, &v9, a4) >= 0
    && PnpGetMultiSzLength(a2, 0x7FFFFFFF, v10, v7) >= 0
    && v9 == v10[0] )
  {
    v6 = RtlCompareUnicodeStrings(a1, v9, a2, v10[0], 1) == 0;
  }
  return v6;
}
