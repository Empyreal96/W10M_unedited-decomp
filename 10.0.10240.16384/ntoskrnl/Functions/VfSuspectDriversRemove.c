// VfSuspectDriversRemove 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfSuspectDriversRemove(int a1)
{
  int v2; // r5
  _DWORD *v3; // r0
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED

  v2 = 0;
  VfDriverLock();
  v3 = (_DWORD *)ViSuspectDriversLookupEntry(a1);
  if ( v3 )
  {
    if ( v3[2] == v3[3] )
    {
      *(_QWORD *)&v5 = *(_QWORD *)v3;
      if ( *(_DWORD **)(*v3 + 4) != v3 || (_DWORD *)*v6 != v3 )
        __fastfail(3u);
      *v6 = v5;
      *(_DWORD *)(v5 + 4) = v6;
      ExFreePoolWithTag((unsigned int)v3);
    }
    else
    {
      v2 = -1073741554;
    }
  }
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return v2;
}
