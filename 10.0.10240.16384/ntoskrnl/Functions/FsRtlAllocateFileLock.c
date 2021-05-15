// FsRtlAllocateFileLock 
 
int __fastcall FsRtlAllocateFileLock(int a1, int a2)
{
  int result; // r0

  result = ExAllocateFromPagedLookasideList((int)&FsRtlFileLockLookasideList);
  if ( result )
  {
    *(_DWORD *)(result + 12) = 0;
    *(_BYTE *)(result + 8) = 0;
    *(_DWORD *)result = a1;
    *(_DWORD *)(result + 4) = a2;
    __dmb(0xBu);
    *(_DWORD *)(result + 60) = 0;
  }
  return result;
}
