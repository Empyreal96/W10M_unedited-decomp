// FsRtlPrivateCancelFileLockIrp 
 
int __fastcall FsRtlPrivateCancelFileLockIrp(int a1, int a2)
{
  int v2; // r3
  int v3; // r7
  unsigned int *v4; // r4
  int v5; // r10
  unsigned int v6; // r2
  int *v7; // r2
  int i; // r5
  unsigned int v9; // r2
  int *v10; // r0
  int v12; // [sp+8h] [bp-28h]
  int v13[9]; // [sp+Ch] [bp-24h] BYREF
  int vars4; // [sp+34h] [bp+4h]

  v2 = *(_DWORD *)(a2 + 28);
  v3 = 0;
  v4 = (unsigned int *)(v2 + 16);
  v12 = a2;
  if ( a1 )
  {
    KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&FsRtlFileLockCancelCollideLock);
    }
    else
    {
      do
        v6 = __ldrex((unsigned int *)&FsRtlFileLockCancelCollideLock);
      while ( __strex(1u, (unsigned int *)&FsRtlFileLockCancelCollideLock) );
      __dmb(0xBu);
      if ( v6 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&FsRtlFileLockCancelCollideLock);
    }
    v7 = &FsRtlFileLockCancelCollideList;
    a2 = v12;
    v3 = 1;
  }
  else
  {
    v5 = *(unsigned __int8 *)(a2 + 37);
    v7 = (int *)(v2 + 28);
  }
  while ( 1 )
  {
    for ( i = *v7; i; i = *(_DWORD *)i )
    {
      if ( *(_DWORD *)(i + 12) == a2 )
      {
        *v7 = *(_DWORD *)i;
        if ( !v3 && i == v4[4] )
          v4[4] = (unsigned int)v7;
        *(_DWORD *)(a2 + 28) = 0;
        if ( v3 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            v10 = &FsRtlFileLockCancelCollideLock;
            goto LABEL_32;
          }
          __dmb(0xBu);
          FsRtlFileLockCancelCollideLock = 0;
        }
        else if ( (dword_682604 & 0x10000) != 0 )
        {
          v10 = (int *)v4;
LABEL_32:
          KiReleaseSpinLockInstrumented(v10, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v4 = 0;
        }
        KfLowerIrql(v5);
        FsRtlCompleteLockIrpReal(*(int (__fastcall **)(int, int))(i + 4), *(_DWORD *)(i + 8), v12, -1073741536, v13, 0);
        return ExFreeToNPagedLookasideList((int)&FsRtlWaitingLockLookasideList, (_DWORD *)i);
      }
      v7 = (int *)i;
    }
    if ( !v3 )
      break;
    v3 = 0;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v4);
    }
    else
    {
      do
        v9 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      if ( v9 )
        KxWaitForSpinLockAndAcquire(v4);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&FsRtlFileLockCancelCollideLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      FsRtlFileLockCancelCollideLock = 0;
    }
    a2 = v12;
    v7 = (int *)(v4 + 3);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  return KfLowerIrql(v5);
}
