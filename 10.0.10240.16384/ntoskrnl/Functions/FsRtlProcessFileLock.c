// FsRtlProcessFileLock 
 
int __fastcall FsRtlProcessFileLock(int (__fastcall **a1)(int, int), int a2, int a3)
{
  int v4; // r4
  int v5; // r3
  int v8; // r4
  int v9; // r0
  int v10; // r0
  int v11; // r2
  int (__fastcall *v12)(int, int); // r0
  int v13; // r0
  int v14; // r0
  char v15; // r3
  bool v16; // r7
  bool v17; // r6
  int v18; // r0
  int v20[2]; // [sp+20h] [bp-28h] BYREF
  __int64 v21[4]; // [sp+28h] [bp-20h] BYREF

  v4 = *(_DWORD *)(a2 + 96);
  v20[1] = 0;
  v5 = *(unsigned __int8 *)(v4 + 1);
  switch ( v5 )
  {
    case 1:
      v21[0] = *(_QWORD *)(v4 + 16);
      v15 = *(_BYTE *)(v4 + 2);
      v16 = (v15 & 2) != 0;
      v17 = (v15 & 1) != 0;
      v18 = IoGetRequestorProcess(a2);
      FsRtlPrivateLock(
        (int)a1,
        *(_DWORD *)(v4 + 28),
        v21,
        *(__int64 **)(v4 + 8),
        v18,
        *(_DWORD *)(v4 + 12),
        v17,
        v16,
        v20,
        a2,
        a3);
      return v20[0];
    case 2:
      v21[0] = *(_QWORD *)(v4 + 16);
      v14 = IoGetRequestorProcess(a2);
      v10 = FsRtlFastUnlockSingle(
              (int)a1,
              *(_DWORD *)(v4 + 28),
              v21,
              *(_DWORD **)(v4 + 8),
              v14,
              *(_DWORD *)(v4 + 12),
              a3);
      goto LABEL_7;
    case 3:
      v13 = IoGetRequestorProcess(a2);
      v10 = FsRtlPrivateFastUnlockAll((int)a1, *(_DWORD *)(v4 + 28), v13, 0, 0, a3);
      goto LABEL_7;
    case 4:
      v9 = IoGetRequestorProcess(a2);
      v10 = FsRtlPrivateFastUnlockAll((int)a1, *(_DWORD *)(v4 + 28), v9, *(_DWORD *)(v4 + 12), 1, a3);
LABEL_7:
      v11 = v10;
      v12 = *a1;
      v20[0] = v11;
      FsRtlCompleteLockIrpReal(v12, a3, a2, v11, v20, 0);
      return v20[0];
  }
  v8 = -1073741808;
  *(_DWORD *)(a2 + 24) = -1073741808;
  pIofCompleteRequest(a2, 1);
  return v8;
}
