// KiPriQueueThreadPriorityChanged 
 
int __fastcall KiPriQueueThreadPriorityChanged(int result, int a2)
{
  if ( (unsigned __int8)*(_DWORD *)(a2 + 332) != *(char *)(a2 + 347) )
    return sub_523810(result, 0);
  __dmb(0xBu);
  *(_DWORD *)(a2 + 44) = 0;
  return result;
}
