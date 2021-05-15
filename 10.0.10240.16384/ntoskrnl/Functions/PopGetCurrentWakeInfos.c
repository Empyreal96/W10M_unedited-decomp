// PopGetCurrentWakeInfos 
 
unsigned int __fastcall PopGetCurrentWakeInfos(int *a1, int a2, int a3, int a4)
{
  int v5; // r5
  unsigned int v6; // r4
  unsigned int v7; // r7
  int *v8; // r6
  int **v9; // lr
  unsigned int *v10; // r2
  unsigned int v11; // r1
  _DWORD v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[1] = a3;
  v13[2] = a4;
  v5 = 0;
  PopAcquireWakeSourceSpinLock((unsigned int)v13);
  v6 = PopWakeInfoCount;
  if ( PopWakeInfoCount )
  {
    v5 = ExAllocatePoolWithTag(512, 4 * PopWakeInfoCount);
    if ( v5 )
    {
      v7 = 0;
      v8 = (int *)PopWakeInfoList;
      if ( (int *)PopWakeInfoList != &PopWakeInfoList )
      {
        v9 = (int **)v5;
        do
        {
          if ( v7 >= v6 )
            break;
          *v9++ = v8;
          __dmb(0xBu);
          v10 = (unsigned int *)(v8 + 2);
          do
            v11 = __ldrex(v10);
          while ( __strex(v11 + 1, v10) );
          __dmb(0xBu);
          v8 = (int *)*v8;
          ++v7;
        }
        while ( v8 != &PopWakeInfoList );
      }
    }
    else
    {
      v6 = 0;
    }
  }
  PopWakeSourceLockOwner = 0;
  KeReleaseInStackQueuedSpinLock((int)v13);
  *a1 = v5;
  return v6;
}
