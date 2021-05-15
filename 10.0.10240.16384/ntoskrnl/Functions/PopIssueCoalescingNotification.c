// PopIssueCoalescingNotification 
 
unsigned int __fastcall PopIssueCoalescingNotification(unsigned int a1)
{
  int v1; // r4
  unsigned __int16 i; // r8
  int v4; // r0
  unsigned int v5; // r5
  void (__fastcall *v7)(unsigned int, unsigned int, _DWORD); // r0

  v1 = 0;
  for ( i = 0; i < 8u; v1 = ++i )
  {
    v4 = ExReferenceCallBackBlock(&PopCoalescingCallbackRoutine[v1]);
    v5 = v4;
    if ( v4 )
    {
      if ( *(unsigned __int8 *)(v4 + 16) != *(unsigned __int8 *)(a1 + 16) )
      {
        v7 = (void (__fastcall *)(unsigned int, unsigned int, _DWORD))KeReadStateSemaphore(v4);
        v7(v5, a1, *(_DWORD *)(a1 + 24));
      }
      ExDereferenceCallBackBlock(&PopCoalescingCallbackRoutine[v1], v5);
    }
  }
  return ExFreePoolWithTag(a1);
}
