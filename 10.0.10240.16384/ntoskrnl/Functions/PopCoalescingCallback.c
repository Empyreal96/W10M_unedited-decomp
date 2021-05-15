// PopCoalescingCallback 
 
int __fastcall PopCoalescingCallback(int a1, int a2, int a3)
{
  return (*(int (__fastcall **)(_DWORD, int, _DWORD))(a1 + 12))(*(_DWORD *)(a2 + 20), a3, *(_DWORD *)(a1 + 20));
}
