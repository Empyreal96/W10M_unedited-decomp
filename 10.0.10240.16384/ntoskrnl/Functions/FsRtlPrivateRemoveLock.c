// FsRtlPrivateRemoveLock 
 
int __fastcall FsRtlPrivateRemoveLock(int a1, int a2, char a3)
{
  int v5; // r3
  int v6; // r1
  int result; // r0

  v5 = *(unsigned __int8 *)(a2 + 16);
  v6 = *(_DWORD *)(a2 + 24);
  if ( v5 )
    result = FsRtlFastUnlockSingleExclusive(
               a1,
               v6,
               (unsigned int *)a2,
               (_QWORD *)(a2 + 8),
               *(_DWORD *)(a2 + 28),
               *(_DWORD *)(a2 + 20),
               0,
               1,
               a3);
  else
    result = FsRtlFastUnlockSingleShared(
               a1,
               v6,
               (int *)a2,
               (_QWORD *)(a2 + 8),
               *(_DWORD *)(a2 + 28),
               *(_DWORD *)(a2 + 20),
               0,
               1,
               a3);
  return result;
}
