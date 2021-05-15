// DbgkpTriageDumpInitialize 
 
int __fastcall DbgkpTriageDumpInitialize(int a1, __int64 a2, int (__fastcall **a3)(int *a1, int a2, int a3, int a4, int a5, int a6))
{
  _BYTE *v5; // r0
  int result; // r0

  *(_QWORD *)a1 = a2;
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, 14284, 1297564756);
  *(_DWORD *)(a1 + 24) = v5;
  if ( v5 )
  {
    memset(v5, 0, 14284);
    *(_DWORD *)(a1 + 28) = 0;
  }
  result = 0;
  *a3 = DbgkpTriageDumpFillHeaders;
  a3[2] = (int (__fastcall *)(int *, int, int, int, int, int))DbgkpTriageDumpSnapData;
  a3[1] = (int (__fastcall *)(int *, int, int, int, int, int))DbgkpTriageDumpIsMemoryBlockPresent;
  a3[3] = (int (__fastcall *)(int *, int, int, int, int, int))DbgkpTriageDumpSaveState;
  a3[4] = (int (__fastcall *)(int *, int, int, int, int, int))DbgkpTriageDumpRestoreState;
  a3[5] = (int (__fastcall *)(int *, int, int, int, int, int))DbgkpTriageDumpWrite;
  return result;
}
