// KeIsWaitListEmpty 
 
BOOL __fastcall KeIsWaitListEmpty(int a1)
{
  __dmb(0xFu);
  return a1 + 8 == *(_DWORD *)(a1 + 8);
}
