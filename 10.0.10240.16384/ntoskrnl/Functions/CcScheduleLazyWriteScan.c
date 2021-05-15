// CcScheduleLazyWriteScan 
 
int __fastcall CcScheduleLazyWriteScan(int a1, int a2)
{
  int v3; // r2
  int v4; // r0
  int v6; // [sp+0h] [bp-18h]

  v6 = a1;
  v3 = (unsigned __int8)CcCoalescingState;
  if ( CcCoalescingState && !a1 )
    return v6;
  if ( a2 )
  {
    v4 = 8;
  }
  else if ( CcCoalescingState )
  {
    v4 = 16;
  }
  else
  {
    v4 = 4;
  }
  if ( a1 )
  {
    CcNotifyWriteBehind(v4);
  }
  else
  {
    if ( byte_632770 )
      goto LABEL_7;
    KiSetTimerEx((int)&unk_632740, 0, *(__int64 *)CcFirstDelay, 0, 0, (int)&LazyWriter);
  }
  v3 = (unsigned __int8)CcCoalescingState;
LABEL_7:
  if ( !v3 )
    byte_632770 = 1;
  return v6;
}
