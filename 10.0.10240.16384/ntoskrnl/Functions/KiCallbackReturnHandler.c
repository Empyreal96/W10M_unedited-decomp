// KiCallbackReturnHandler 
 
int __fastcall KiCallbackReturnHandler(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = *(_DWORD *)(a1 + 4);
  if ( (v3 & 0x66) != 0 )
  {
    if ( (v3 & 0x20) == 0 )
      KeBugCheck(30);
  }
  else if ( &loc_420692 == *(_UNKNOWN **)(a1 + 12) && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    RtlUnwindEx(a2, (int)&loc_420698 + 1, a1, *(_DWORD *)a1, a3, 0);
  }
  return 1;
}
