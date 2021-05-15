// KiActivateWaiterPriQueue 
 
int __fastcall KiActivateWaiterPriQueue(int result, int a2, int a3, int a4)
{
  unsigned int *v4; // r4
  unsigned int v5; // r1
  int v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[0] = a4;
  v4 = (unsigned int *)result;
  if ( *(_DWORD *)(result + 8) != result + 8 )
  {
    if ( *(_DWORD *)(result + 4) )
    {
      result = KiAttemptFastRemovePriQueue(result, v6, -1);
      if ( result )
      {
        result = KiWakePriQueueWaiter(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, v4, result, v6[0]);
        if ( !result )
          return sub_515664();
      }
    }
  }
  __dmb(0xBu);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 & 0xFFFFFF7F, v4) );
  return result;
}
