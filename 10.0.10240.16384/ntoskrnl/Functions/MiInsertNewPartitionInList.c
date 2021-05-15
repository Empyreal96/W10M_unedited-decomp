// MiInsertNewPartitionInList 
 
void __fastcall __spoils<R2,R3,R12> MiInsertNewPartitionInList(int a1, int a2, int a3, int a4)
{
  _DWORD v4[6]; // [sp+0h] [bp-18h] BYREF

  v4[2] = a3;
  v4[3] = a4;
  KeAcquireInStackQueuedSpinLock(&dword_634318, v4);
  dword_63F710[0] = &dword_634328;
  dword_63F710[1] = dword_63432C;
  if ( *(int **)dword_63432C != &dword_634328 )
    sub_50B828();
  *(_DWORD *)dword_63432C = dword_63F710;
  dword_63432C = (int)dword_63F710;
  KeReleaseInStackQueuedSpinLock(v4);
}
