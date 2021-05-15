// sub_903EB0 
 
void __fastcall sub_903EB0(int a1, int a2, int a3, char a4)
{
  int v4; // r4
  int v5; // r3

  if ( (a4 & 4) == 0 || (a4 & 8) != 0 )
  {
    if ( KdpLowWriteContent(a3) )
      *(_DWORD *)(v4 + 24) = 0;
  }
  else
  {
    *(_DWORD *)(v4 + 24) = 0;
    v5 = KdpBreakpointChangeCount + 1;
    __dmb(0xBu);
    KdpBreakpointChangeCount = v5;
  }
  JUMPOUT(0x903344);
}
