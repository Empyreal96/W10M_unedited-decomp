// MiRemovePteTracker 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiRemovePteTracker(int a1, unsigned int a2, int a3)
{
  int *v5; // r7
  int v6; // r4
  int v7; // r10
  int *v8; // r5
  int *v9; // r0
  int *v10; // r1 OVERLAPPED
  int **v11; // r2 OVERLAPPED
  int result; // r0
  char v13[40]; // [sp+10h] [bp-28h] BYREF

  v5 = 0;
  v6 = ((int)(124 * ((a2 >> 12 >> 16) ^ (4 * (unsigned __int8)(a2 >> 20)))) >> 2) & 0xF;
  v7 = a2 & 0xFFFFF000;
  KeAcquireInStackQueuedSpinLock(dword_634708, (unsigned int)v13);
  v8 = (int *)MiState[2 * v6 + 2372];
  v9 = &dword_634F90[2 * v6];
  if ( v8 == v9 )
    goto LABEL_16;
  do
  {
    if ( v7 == (v8[4] & 0xFFFFF000) )
    {
      if ( v5 )
        KeBugCheckEx(218, 1, (int)v8, a1, (int)v5);
      if ( v8[3] != a3 )
        KeBugCheckEx(218, 2, (int)v8, v8[3], a3);
      if ( a1 && (*(_WORD *)(a1 + 6) & 0x200) == 0 )
      {
        if ( v8[8] != *(_DWORD *)(a1 + 28) )
          KeBugCheckEx(218, 4, (int)v8, v8[8], *(_DWORD *)(a1 + 28));
        if ( !byte_6348E8 )
        {
          if ( v8[4] != *(_DWORD *)(a1 + 12) )
            KeBugCheckEx(218, 3, (int)v8, v8[4], *(_DWORD *)(a1 + 12));
          if ( v8[5] != *(_DWORD *)(a1 + 16) )
            KeBugCheckEx(218, 5, (int)v8, v8[5], *(_DWORD *)(a1 + 16));
        }
      }
      *(_QWORD *)&v10 = *(_QWORD *)v8;
      if ( *(int **)(*v8 + 4) != v8 || *v11 != v8 )
        __fastfail(3u);
      *v11 = v10;
      v10[1] = (int)v11;
      v5 = v8;
    }
    v8 = (int *)*v8;
  }
  while ( v8 != v9 );
  if ( !v5 )
  {
LABEL_16:
    if ( !byte_634854 )
      KeBugCheckEx(218, 6, a1, v7, a3);
  }
  dword_635010 -= a3;
  --dword_635014;
  result = KeReleaseInStackQueuedSpinLock((int)v13);
  if ( v5 )
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_634700, v5);
  return result;
}
