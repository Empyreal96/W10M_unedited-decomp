// FsRtlCheckLockForReadAccess 
 
int __fastcall FsRtlCheckLockForReadAccess(int a1, int a2)
{
  int v3; // r4
  int v5; // r7
  int v6; // r3
  int v7; // r0
  int v8[2]; // [sp+8h] [bp-20h] BYREF
  __int64 v9[3]; // [sp+10h] [bp-18h] BYREF

  v3 = *(_DWORD *)(a1 + 12);
  if ( !v3 )
    return 1;
  if ( !*(_DWORD *)(v3 + 24) )
    return 1;
  v5 = *(_DWORD *)(a2 + 96);
  v8[1] = 0;
  v6 = *(_DWORD *)(v5 + 8);
  v9[0] = *(_QWORD *)(v5 + 16);
  v8[0] = v6;
  if ( v9[0] + (unsigned __int64)(unsigned int)v6 <= *(_QWORD *)v3 )
    return 1;
  v7 = IoGetRequestorProcess(a2);
  return ((int (__fastcall *)(int, __int64 *, int *, _DWORD, _DWORD, int))FsRtlFastCheckLockForRead)(
           a1,
           v9,
           v8,
           *(_DWORD *)(v5 + 12),
           *(_DWORD *)(v5 + 28),
           v7);
}
