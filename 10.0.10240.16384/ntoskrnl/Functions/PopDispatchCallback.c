// PopDispatchCallback 
 
int __fastcall PopDispatchCallback(int a1)
{
  int result; // r0

  result = ExNotifyCallback(ExCbPowerState, a1, 0);
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134) )
    sub_81B670(result);
  return result;
}
