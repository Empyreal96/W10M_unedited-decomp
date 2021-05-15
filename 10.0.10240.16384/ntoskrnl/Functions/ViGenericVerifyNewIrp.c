// ViGenericVerifyNewIrp 
 
int __fastcall ViGenericVerifyNewIrp(int result, int a2, int a3, int a4, int a5)
{
  int v5; // r2
  int v6; // r4
  int i; // r2

  if ( *(_DWORD *)(a2 + 40) || *(_DWORD *)(a2 + 44) )
  {
    v5 = *(_DWORD *)(a2 + 8);
    if ( (v5 & 0x402) == 0 || (v5 & 0x440) == 0 )
    {
      v6 = *(_DWORD *)(a2 + 96) - 40;
      for ( i = *(char *)(a2 + 35) - 1; i <= *(char *)(a2 + 34); ++i )
      {
        if ( *(_DWORD *)(v6 + 32) )
          return result;
        v6 += 40;
      }
      if ( *(_BYTE *)(result + 40) )
        result = VfErrorReport11(770, a5, a2);
    }
  }
  return result;
}
