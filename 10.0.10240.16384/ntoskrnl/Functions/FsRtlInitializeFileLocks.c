// FsRtlInitializeFileLocks 
 
__int64 FsRtlInitializeFileLocks()
{
  __int64 v1; // [sp+0h] [bp-18h]

  ExInitializeNPagedLookasideList((int)&FsRtlSharedLockLookasideList, 0, 0, 512);
  ExInitializeNPagedLookasideList((int)&FsRtlExclusiveLockLookasideList, 0, 0, 512);
  ExInitializeNPagedLookasideList((int)&FsRtlWaitingLockLookasideList, 0, 0, 512);
  ExInitializeNPagedLookasideList((int)&FsRtlLockTreeNodeLookasideList, 0, 0, 512);
  ExInitializeNPagedLookasideList((int)&FsRtlLockInfoLookasideList, 0, 0, 512);
  ExInitializePagedLookasideList((int)&FsRtlFileLockLookasideList, 0, 0, 0, 64, 1818643526, 8);
  FsRtlCreateLockInfo = 1;
  dword_631EA4 = 0;
  unk_631EA8 = 0;
  byte_631EAC = 1;
  byte_631EAD = 0;
  byte_631EAE = 4;
  dword_631EB0 = 0;
  dword_631EB8 = (int)&dword_631EB4;
  dword_631EB4 = (int)&dword_631EB4;
  FsRtlFileLockCancelCollideLock = 0;
  FsRtlFileLockCancelCollideList = 0;
  return v1;
}
