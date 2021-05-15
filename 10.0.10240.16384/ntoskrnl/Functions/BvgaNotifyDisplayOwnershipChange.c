// BvgaNotifyDisplayOwnershipChange 
 
int __fastcall BvgaNotifyDisplayOwnershipChange(int a1, int (__fastcall *a2)(_DWORD, _DWORD, _DWORD), int a3)
{
  if ( a1 )
  {
    if ( BvgaDisplayState )
      BvgaAcquireDisplayOwnership();
  }
  else if ( BvgaDisplayState != 2 )
  {
    BvgaNotifyDisplayOwnershipLost(0, a2, a3, BvgaDisplayState);
  }
  BgkNotifyDisplayOwnershipChange(a1, a2);
  return 0;
}
