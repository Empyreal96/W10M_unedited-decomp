// ViPacketNotificationCallback 
 
_DWORD *__fastcall ViPacketNotificationCallback(_DWORD *a1, int a2, int a3)
{
  if ( a3 == 1 )
  {
    if ( a2 )
      *(_DWORD *)(a2 + 8) &= 0x3FFFFFFFu;
  }
  else if ( a3 == 2 )
  {
    a1 = (_DWORD *)ViPacketFree(a1);
  }
  return a1;
}
