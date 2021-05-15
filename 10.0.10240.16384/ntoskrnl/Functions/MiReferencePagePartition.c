// MiReferencePagePartition 
 
__int16 *__fastcall MiReferencePagePartition(int a1, int a2, int a3, int a4)
{
  __int16 *v4; // r4
  _DWORD v6[4]; // [sp+0h] [bp-10h] BYREF

  v6[1] = a3;
  v6[2] = a4;
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634318, (unsigned int)v6);
  v4 = MiSystemPartition;
  if ( dword_63F708 )
    ++dword_63F708;
  else
    v4 = 0;
  KeReleaseInStackQueuedSpinLock((int)v6);
  return v4;
}
