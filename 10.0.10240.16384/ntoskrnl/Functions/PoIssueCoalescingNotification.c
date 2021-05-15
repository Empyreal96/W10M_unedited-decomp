// PoIssueCoalescingNotification 
 
void __fastcall PoIssueCoalescingNotification(int a1, int a2)
{
  unsigned int v4; // r6
  int v5; // r0
  int v6; // r1

  v4 = KeGetCurrentIrql(a1);
  v5 = ExAllocatePoolWithTag(512, 28, 1883467600);
  if ( v5 )
  {
    *(_DWORD *)(v5 + 20) = a2;
    *(_DWORD *)(v5 + 24) = 0;
    *(_BYTE *)(v5 + 16) = *(_BYTE *)(a1 + 16);
    if ( v4 < 2 )
      PopIssueCoalescingNotification(v5);
    else
      sub_50F694((_DWORD *)v5, v6, 0);
  }
}
