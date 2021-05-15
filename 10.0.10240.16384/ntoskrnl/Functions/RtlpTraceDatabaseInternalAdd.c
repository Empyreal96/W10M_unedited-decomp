// RtlpTraceDatabaseInternalAdd 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpTraceDatabaseInternalAdd(int a1, unsigned int a2, int a3, int *a4)
{
  int v9; // r2
  _DWORD *v10; // r0
  unsigned int v11; // r9
  unsigned int v12; // r2
  int v13; // r3
  __int64 v14; // kr00_8
  int v15; // r3
  unsigned int v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  int *v19; // [sp+0h] [bp-20h] BYREF

  v19 = a4;
  if ( a2 > 0x100 )
    return 0;
  if ( !RtlpTraceDatabaseInternalFind(a1, a2, a3, &v19) )
  {
    v10 = *(_DWORD **)(a1 + 12);
    v11 = 4 * (a2 + 8);
    if ( v11 > v10[5] - v10[6] )
    {
      v12 = *(_DWORD *)(a1 + 16);
      if ( v12 && *(_DWORD *)(a1 + 20) > v12 )
        goto LABEL_10;
      v10 = (_DWORD *)RtlpTraceDatabaseAllocate(4096, *(_QWORD *)(a1 + 4));
      if ( !v10 )
        goto LABEL_10;
      *v10 = -1412580421;
      v10[1] = a1;
      v10[4] = v10;
      v10[5] = v10 + 1024;
      v10[6] = v10 + 7;
      v10[3] = 4096;
      v10[2] = *(_DWORD *)(a1 + 12);
      v13 = *(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 12) = v10;
      *(_DWORD *)(a1 + 20) = v13 + 4096;
    }
    v14 = *(_QWORD *)(v10 + 5);
    if ( v11 <= (int)v14 - HIDWORD(v14) )
    {
      v10[6] = HIDWORD(v14) + v11;
      *(_DWORD *)HIDWORD(v14) = -1412584790;
      v15 = 1;
      *(_QWORD *)(HIDWORD(v14) + 4) = *(_QWORD *)(&a2 - 1);
      *(_DWORD *)(HIDWORD(v14) + 28) = HIDWORD(v14) + 32;
      *(_QWORD *)(HIDWORD(v14) + 12) = 0i64;
      memmove(*(_DWORD *)(HIDWORD(v14) + 28), a3, 4 * a2);
      v16 = (*(int (__fastcall **)(unsigned int, int))(a1 + 72))(a2, a3);
      v17 = *(_DWORD *)(a1 + 64);
      if ( !v17 )
        __brkdiv0();
      v18 = v16 % v17;
      if ( !(v17 >> 4) )
        __brkdiv0();
      ++*(_DWORD *)(a1 + 4 * (v18 / (v17 >> 4)) + 84);
      *(_DWORD *)(HIDWORD(v14) + 24) = *(_DWORD *)(*(_DWORD *)(a1 + 68) + 4 * v18);
      *(_DWORD *)(*(_DWORD *)(a1 + 68) + 4 * v18) = HIDWORD(v14);
      if ( a4 )
        *a4 = HIDWORD(v14);
      ++*(_DWORD *)(a1 + 76);
      return 1;
    }
    DbgPrint("Trace database: failing attempt to save biiiiig trace (size %u) \n", a2);
LABEL_10:
    if ( a4 )
      *a4 = 0;
    return 0;
  }
  v9 = (int)v19;
  ++v19[1];
  if ( a4 )
    *a4 = v9;
  ++*(_DWORD *)(a1 + 80);
  return 1;
}
