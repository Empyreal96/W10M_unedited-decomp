// PoIssueCoalescingNotification 
 
int __fastcall PoIssueCoalescingNotification(int a1, int a2)
{
  unsigned int v4; // r6
  int v5; // r0

  v4 = KeGetCurrentIrql();
  v5 = ExAllocatePoolWithTag(512, 28, 1883467600);
  if ( !v5 )
    return -1073741670;
  *(_DWORD *)(v5 + 20) = a2;
  *(_DWORD *)(v5 + 24) = 0;
  *(_BYTE *)(v5 + 16) = *(_BYTE *)(a1 + 16);
  if ( v4 >= 2 )
    return sub_50F694();
  PopIssueCoalescingNotification();
  return 0;
}
