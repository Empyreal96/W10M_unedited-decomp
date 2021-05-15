// sub_50F694 
 
void __fastcall sub_50F694(_DWORD *a1, int a2, int a3)
{
  a1[2] = PopIssueCoalescingNotification;
  a1[3] = a1;
  *a1 = a3;
  ExQueueWorkItem(a1, 1);
  JUMPOUT(0x4253D2);
}
