// AdtpBuildMacStrings 
 
int __fastcall AdtpBuildMacStrings(int a1, int a2, _BYTE *a3)
{
  int v6; // r4
  int v7; // r0

  if ( *(_WORD *)a1 == 33 )
  {
    if ( a2 && a3 )
    {
      *(_WORD *)(a2 + 2) = 36;
      v7 = ExAllocatePoolWithTag(1, 36, 1799447891);
      *(_DWORD *)(a2 + 4) = v7;
      if ( !v7 )
      {
        v6 = -1073741801;
        goto LABEL_7;
      }
      *a3 = 1;
      *(_WORD *)a2 = 2
                   * ((RtlEthernetAddressToStringW((unsigned __int8 *)(a1 + 2), *(_DWORD *)(a2 + 4))
                     - *(_DWORD *)(a2 + 4)) >> 1);
    }
    return 0;
  }
  v6 = -1073741503;
LABEL_7:
  if ( a3 && *a3 )
  {
    *a3 = 0;
    ExFreePoolWithTag(*(_DWORD *)(a2 + 4));
  }
  return v6;
}
