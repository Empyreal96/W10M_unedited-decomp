// MiInsertNewCombineBlocks 
 
// local variable allocation has failed, the output may be wrong!
_BYTE *__fastcall MiInsertNewCombineBlocks(int a1, _BYTE *a2, int a3, int a4)
{
  unsigned int v4; // r5
  _BYTE *v5; // r4
  int v7; // r5
  int v8; // r0
  int *v9; // r2 OVERLAPPED
  int v10; // r1 OVERLAPPED
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = a2;
  v12[1] = a3;
  v12[2] = a4;
  v4 = 0;
  v5 = a2;
  do
  {
    if ( !MiLockPagedAddress(&v5[v4]) )
    {
      while ( v4 )
      {
        v4 -= 4096;
        MiUnlockPagedAddress(&v5[v4]);
      }
      return 0;
    }
    v4 += 4096;
  }
  while ( v4 < 0x3FFE8 );
  memset(v5, 0, 262120);
  v7 = 6552;
  v8 = KeAcquireInStackQueuedSpinLock((unsigned int *)(a1 + 44), (unsigned int)v12);
  v9 = (int *)(a1 + 36);
  do
  {
    v10 = *v9;
    *(_QWORD *)v5 = *(_QWORD *)(&v9 - 1);
    if ( *(int **)(v10 + 4) != v9 )
      sub_54F8B4(v8);
    *(_DWORD *)(v10 + 4) = v5;
    *v9 = (int)v5;
    v5 += 40;
    --v7;
  }
  while ( v7 );
  KeReleaseInStackQueuedSpinLock((int)v12);
  return v5;
}
