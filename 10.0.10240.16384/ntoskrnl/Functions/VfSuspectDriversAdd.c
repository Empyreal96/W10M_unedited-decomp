// VfSuspectDriversAdd 
 
int __fastcall VfSuspectDriversAdd(int a1)
{
  int *v1; // r4

  v1 = (int *)VfSuspectDriversAllocateEntry((unsigned __int16 *)(a1 + 44));
  if ( !v1 )
    return 0;
  VfDriverLock();
  VfSuspectDriversInsert(v1);
  VfDriverUnlock();
  return 1;
}
