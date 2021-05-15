// MiInsertPteTracker 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiInsertPteTracker(_DWORD *a1, int a2, char a3, char a4)
{
  _DWORD *v8; // r5
  _DWORD **v9; // r0
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  int result; // r0
  unsigned int v13; // r4
  int v14; // r3
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r3
  int *v20; // r2 OVERLAPPED
  int v21; // r1 OVERLAPPED
  unsigned int v22; // r2
  int v23; // [sp+0h] [bp-30h] BYREF
  char v24[40]; // [sp+8h] [bp-28h] BYREF

  if ( (unsigned __int16)word_634704 < 0xAu )
  {
    v8 = (_DWORD *)RtlpInterlockedPopEntrySList((unsigned __int64 *)&unk_634700);
    goto LABEL_6;
  }
  v9 = (_DWORD **)RtlpInterlockedFlushSList((unsigned __int64 *)&unk_634700);
  v8 = v9;
  if ( v9 )
  {
    v10 = *v9;
    if ( *v8 )
    {
      do
      {
        v11 = (_DWORD *)*v10;
        ExFreePoolWithTag(v10);
        v10 = v11;
      }
      while ( v11 );
    }
LABEL_6:
    if ( v8 )
      goto LABEL_9;
  }
  result = ExAllocatePoolWithTag(512, 68);
  v8 = (_DWORD *)result;
  if ( !result )
  {
    byte_634854 = 1;
    return result;
  }
LABEL_9:
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v14 = a1[5];
      v15 = ((unsigned __int16)a1[6] + (unsigned __int16)a1[4]) & 0xFFF;
      v8[2] = 1;
      v13 = (unsigned int)(v14 + v15 + 4095) >> 12;
    }
    else
    {
      v13 = a1[5] >> 12;
      v8[2] = 0;
    }
  }
  else
  {
    v16 = a1[5];
    v17 = ((unsigned __int16)a1[6] + (unsigned __int16)a1[4]) & 0xFFF;
    v8[2] = a1;
    v13 = (unsigned int)(v16 + v17 + 4095) >> 12;
    v8[5] = a1[4];
    v8[6] = a1[6];
    v8[7] = a1[5];
  }
  if ( (a3 & 2) != 0 )
    ++v13;
  v8[3] = v13;
  RtlCaptureStackBackTrace(1u, 7u, (int)(v8 + 10), (int)&v23);
  v8[4] = a1[3];
  v8[8] = a1[7];
  v18 = v8[9] ^ ((unsigned __int8)v8[9] ^ (unsigned __int8)(4 * a4)) & 0xC;
  v8[9] = v18;
  v19 = v18 & 0xFFFFFFFE | ((a3 & 1) != 0);
  v8[9] = v19;
  v8[9] = v19 & 0xFFFFFFED | (16 * ((a3 & 2) != 0));
  v23 = v8[4] >> 12;
  KeAcquireInStackQueuedSpinLock(dword_634708, (unsigned int)v24);
  v20 = &dword_634F90[2 * (((31 * (HIBYTE(v23) ^ (4 * (BYTE2(v23) ^ (4 * BYTE1(v23)))))) >> 2) & 0xF)];
  v21 = *v20;
  *(_QWORD *)v8 = *(_QWORD *)&v21;
  if ( *(int **)(v21 + 4) != v20 )
    __fastfail(3u);
  *(_DWORD *)(v21 + 4) = v8;
  *v20 = (int)v8;
  dword_635010 += v13;
  v22 = dword_635014 + 1;
  dword_635014 = v22;
  if ( v22 > dword_635018 )
    dword_635018 = v22;
  return KeReleaseInStackQueuedSpinLock((int)v24);
}
