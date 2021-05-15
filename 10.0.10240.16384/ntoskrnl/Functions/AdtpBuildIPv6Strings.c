// AdtpBuildIPv6Strings 
 
int __fastcall AdtpBuildIPv6Strings(_WORD *a1, int a2, _BYTE *a3, int a4, _BYTE *a5)
{
  int v9; // r4
  int v10; // r0
  int v11; // r0

  if ( *a1 != 23 )
  {
    v9 = -1073741503;
    goto LABEL_13;
  }
  if ( a2 && a3 )
  {
    *(_WORD *)(a2 + 2) = 110;
    v10 = ExAllocatePoolWithTag(1, 110, 1799447891);
    *(_DWORD *)(a2 + 4) = v10;
    if ( !v10 )
    {
LABEL_6:
      v9 = -1073741801;
      goto LABEL_13;
    }
    *a3 = 1;
    *(_WORD *)a2 = 2 * ((RtlIpv6AddressToStringW(a1 + 4, *(_DWORD *)(a2 + 4)) - *(_DWORD *)(a2 + 4)) >> 1);
  }
  if ( !a4 || !a5 )
    return 0;
  *(_WORD *)(a4 + 2) = 16;
  v11 = ExAllocatePoolWithTag(1, 16, 1799447891);
  *(_DWORD *)(a4 + 4) = v11;
  if ( !v11 )
    goto LABEL_6;
  *a5 = 1;
  if ( StringCchPrintfW(*(_WORD **)(a4 + 4), 8u, (int)L"%d", (unsigned __int16)(a1[1] << 8) | HIBYTE(a1[1])) >= 0 )
  {
    *(_WORD *)a4 = 2 * wcslen(*(unsigned __int16 **)(a4 + 4));
    return 0;
  }
  v9 = -1073741811;
LABEL_13:
  if ( a3 && *a3 )
  {
    *a3 = 0;
    ExFreePoolWithTag(*(_DWORD *)(a2 + 4));
  }
  if ( a5 && *a5 )
  {
    *a5 = 0;
    ExFreePoolWithTag(*(_DWORD *)(a4 + 4));
  }
  return v9;
}
