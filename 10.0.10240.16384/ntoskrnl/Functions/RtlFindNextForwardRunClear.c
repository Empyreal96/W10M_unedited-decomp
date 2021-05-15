// RtlFindNextForwardRunClear 
 
int __fastcall RtlFindNextForwardRunClear(int a1, int a2, int a3)
{
  return RtlFindNextForwardRunClearCapped(a1, a2, -1, a3);
}
