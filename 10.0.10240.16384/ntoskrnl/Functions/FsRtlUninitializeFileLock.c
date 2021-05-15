// FsRtlUninitializeFileLock 
 
int __fastcall FsRtlUninitializeFileLock(int result)
{
  _DWORD *v1; // r4
  int v2; // r9
  unsigned int v3; // r2
  unsigned int *v4; // r6
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r7
  int v8; // r7
  _DWORD *v9; // r1
  _DWORD *v10; // r7
  int v11; // r9
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r1
  int v15; // r7
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // [sp+8h] [bp-28h] BYREF
  int v19; // [sp+Ch] [bp-24h]

  v1 = *(_DWORD **)(result + 12);
  v2 = result;
  v19 = result;
  if ( v1 )
  {
    v18 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_5257FC();
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&FsRtlFileLockCancelCollideLock);
      while ( __strex(1u, (unsigned int *)&FsRtlFileLockCancelCollideLock) );
      __dmb(0xBu);
      if ( v3 )
        KxWaitForSpinLockAndAcquire(&FsRtlFileLockCancelCollideLock);
      v4 = v1 + 4;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(v1 + 4);
      }
      else
      {
        do
          v5 = __ldrex(v4);
        while ( __strex(1u, v4) );
        __dmb(0xBu);
        if ( v5 )
          KxWaitForSpinLockAndAcquire(v1 + 4);
      }
      while ( 1 )
      {
        v6 = v1[5];
        if ( !v6 )
          break;
        v8 = v6 - 16;
        while ( *(_DWORD *)v8 )
        {
          v9 = *(_DWORD **)v8;
          if ( *(_DWORD *)v8 )
            *(_DWORD *)v8 = *v9;
          ExFreeToNPagedLookasideList(&FsRtlSharedLockLookasideList, v9);
        }
        RtlDeleteNoSplay((_DWORD *)(v8 + 16), v1 + 5);
        ExFreeToNPagedLookasideList(&FsRtlLockTreeNodeLookasideList, v8);
      }
      while ( 1 )
      {
        v7 = v1[6];
        if ( !v7 )
          break;
        RtlDeleteNoSplay((_DWORD *)v1[6], v1 + 6);
        ExFreeToNPagedLookasideList(&FsRtlExclusiveLockLookasideList, v7);
      }
      if ( v1[7] )
      {
        do
        {
          v10 = (_DWORD *)v1[7];
          if ( v10 )
            v1[7] = *v10;
          v11 = v10[3];
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v1 + 4);
          }
          else
          {
            __dmb(0xBu);
            *v4 = 0;
          }
          *(_BYTE *)(v11 + 37) = KeAcquireQueuedSpinLock(7);
          __dmb(0xBu);
          v12 = (unsigned int *)(v11 + 56);
          do
            v13 = __ldrex(v12);
          while ( __strex(0, v12) );
          __dmb(0xBu);
          v14 = *(unsigned __int8 *)(v11 + 37);
          if ( *(_BYTE *)(v11 + 36) )
          {
            KeReleaseQueuedSpinLock(7, v14);
            *v10 = FsRtlFileLockCancelCollideList;
            FsRtlFileLockCancelCollideList = (int)v10;
          }
          else
          {
            KeReleaseQueuedSpinLock(7, v14);
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(&FsRtlFileLockCancelCollideLock);
            }
            else
            {
              __dmb(0xBu);
              FsRtlFileLockCancelCollideLock = 0;
            }
            KfLowerIrql(v18);
            *(_DWORD *)(v11 + 28) = 0;
            FsRtlCompleteLockIrpReal(v1[2], v10[2], v11, -1073741698, &v18, 0);
            ExFreeToNPagedLookasideList(&FsRtlWaitingLockLookasideList, v10);
            v15 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(&FsRtlFileLockCancelCollideLock);
            }
            else
            {
              do
                v16 = __ldrex((unsigned int *)&FsRtlFileLockCancelCollideLock);
              while ( __strex(1u, (unsigned int *)&FsRtlFileLockCancelCollideLock) );
              __dmb(0xBu);
              if ( v16 )
                KxWaitForSpinLockAndAcquire(&FsRtlFileLockCancelCollideLock);
            }
            v18 = v15;
          }
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v1 + 4);
          }
          else
          {
            do
              v17 = __ldrex(v4);
            while ( __strex(1u, v4) );
            __dmb(0xBu);
            if ( v17 )
              KxWaitForSpinLockAndAcquire(v1 + 4);
          }
        }
        while ( v1[7] );
        v2 = v19;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v1 + 4);
      }
      else
      {
        __dmb(0xBu);
        *v4 = 0;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&FsRtlFileLockCancelCollideLock);
      }
      else
      {
        __dmb(0xBu);
        FsRtlFileLockCancelCollideLock = 0;
      }
      KfLowerIrql(v18);
      result = ExFreeToNPagedLookasideList(&FsRtlLockInfoLookasideList, v1);
      *(_DWORD *)(v2 + 12) = 0;
    }
  }
  return result;
}
