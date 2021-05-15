// ExDestroyHandle 
 
int __fastcall ExDestroyHandle(int a1, int a2, _DWORD *a3)
{
  unsigned int v7; // r6

  if ( *(_DWORD *)(a1 + 60) )
    return sub_7F7170();
  v7 = a3[1];
  *a3 = 0;
  __dmb(0xFu);
  if ( *(_DWORD *)(a1 + 32) )
    ExfUnblockPushLock(a1 + 32, 0);
  ExpFreeHandleTableEntry(a1, a2, a3);
  return v7 >> 27;
}
