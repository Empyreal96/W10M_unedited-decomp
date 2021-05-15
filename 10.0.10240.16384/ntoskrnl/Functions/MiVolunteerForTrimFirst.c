// MiVolunteerForTrimFirst 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiVolunteerForTrimFirst(int result, int a2, int a3, int a4)
{
  int v4; // r4
  unsigned int v5; // r2
  int v6; // r7
  int *v7; // r5
  int v8; // r8
  int *v9; // r1 OVERLAPPED
  int **v10; // r2 OVERLAPPED
  int v11; // r1
  int v12; // r0
  unsigned int *v13; // r1
  unsigned int *v14; // r2
  int **v15; // r1
  int v16; // [sp+0h] [bp-20h] BYREF
  unsigned int *v17; // [sp+4h] [bp-1Ch]
  int v18; // [sp+8h] [bp-18h]

  v16 = a2;
  v17 = (unsigned int *)a3;
  v18 = a4;
  v4 = result;
  v5 = *(_DWORD *)(result + 44);
  v6 = dword_6404B8;
  if ( v5 < *(_DWORD *)(dword_6404B8 + 52) )
  {
    if ( a2 > 0 )
      return result;
    if ( !*(_DWORD *)(result + 12) )
      return result;
    v7 = (int *)(result + 12);
    if ( dword_6404C0 == result + 12 )
      return result;
    v8 = 2;
  }
  else
  {
    if ( a2 < 0 )
      return result;
    if ( !*(_DWORD *)(result + 12) )
      return result;
    v7 = (int *)(result + 12);
    if ( dword_6404BC == result + 12 )
      return result;
    v8 = 1;
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_634980, &v16, v5, MiState);
  if ( *(_BYTE *)(v6 + 45) || !*(_DWORD *)(v4 + 12) )
  {
    *(_BYTE *)(v6 + 46) = 1;
  }
  else
  {
    *(_QWORD *)&v9 = *(_QWORD *)v7;
    if ( *(int **)(*v7 + 4) != v7 || *v10 != v7 )
      __fastfail(3u);
    *v10 = v9;
    v9[1] = (int)v10;
    if ( v8 == 1 )
    {
      v11 = dword_6404BC;
      *v7 = dword_6404BC;
      v7[1] = (int)&dword_6404BC;
      if ( *(int **)(v11 + 4) != &dword_6404BC )
        sub_5379B0(3516);
      *(_DWORD *)(v11 + 4) = v7;
      dword_6404BC = (int)v7;
    }
    else
    {
      v15 = (int **)dword_6404C0;
      *v7 = (int)&dword_6404BC;
      v7[1] = (int)v15;
      if ( *v15 != &dword_6404BC )
        __fastfail(3u);
      *v15 = v7;
      dword_6404C0 = (int)v7;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(&v16);
  v12 = v16;
  if ( v16 )
    goto LABEL_22;
  v13 = v17;
  __dmb(0xBu);
  do
    result = __ldrex(v13);
  while ( (int *)result == &v16 && __strex(0, v13) );
  if ( (int *)result != &v16 )
  {
    v12 = KxWaitForLockChainValid(&v16);
LABEL_22:
    v16 = 0;
    __dmb(0xBu);
    v14 = (unsigned int *)(v12 + 4);
    do
      result = __ldrex(v14);
    while ( __strex(result ^ 1, v14) );
  }
  return result;
}
