// BgkNotifyDisplayOwnershipLost 
 
int __fastcall BgkNotifyDisplayOwnershipLost(int a1)
{
  int result; // r0

  if ( a1 )
    dword_64B0A8 = a1;
  result = BgkNotifyDisplayOwnershipChange(0, (int (__fastcall *)(_DWORD, _DWORD, _DWORD))BgkpResetDisplay);
  if ( dword_6416A8 != 2 )
  {
    result = MmMapIoSpace(655360, 0, 0x20000, 0);
    dword_6521E0 = result;
  }
  return result;
}
