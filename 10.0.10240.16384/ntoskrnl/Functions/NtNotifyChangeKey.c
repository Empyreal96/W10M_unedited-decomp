// NtNotifyChangeKey 
 
int __fastcall NtNotifyChangeKey(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, unsigned __int8 a10)
{
  return NtNotifyChangeMultipleKeys(a1, 0, 0, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
