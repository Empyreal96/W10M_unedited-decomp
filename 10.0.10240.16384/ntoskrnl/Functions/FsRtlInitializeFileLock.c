// FsRtlInitializeFileLock 
 
int __fastcall FsRtlInitializeFileLock(int result, __int64 a2)
{
  *(_DWORD *)(result + 12) = 0;
  *(_BYTE *)(result + 8) = 0;
  *(_QWORD *)result = a2;
  __dmb(0xBu);
  *(_DWORD *)(result + 60) = 0;
  return result;
}
