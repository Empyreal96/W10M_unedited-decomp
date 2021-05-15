// CcWriteBehind 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CcWriteBehind(int a1, int a2)
{
  int v4; // r6
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r0
  int v8; // r4 OVERLAPPED
  int result; // r0
  int v10; // r0
  int (__fastcall *v11)(_DWORD); // r3
  unsigned int v12; // r1
  int v13; // r5
  unsigned int v14; // r2
  unsigned int v15; // r2
  char v16; // [sp+8h] [bp-60h] BYREF

  v4 = 0;
  v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v6 = *(_DWORD *)(v5 + 2864);
  ++*(_DWORD *)(v6 + 12);
  v7 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v6);
  v8 = v7;
  if ( !v7 )
    return sub_521040();
  *(_DWORD *)v7 = *(_DWORD *)(v5 + 1428);
  *(_BYTE *)(v7 + 64) = 2;
  *(_DWORD *)v7 = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 8) = a1;
  *(_DWORD *)(v7 + 12) = a2;
  if ( !CcIsWriteBehindThreadpoolAtLowPriority()
    || CcLowPriWorkerThread
    || *(_DWORD *)(a1 + 364)
    || (*(_DWORD *)(a1 + 96) & 0x10000) != 0
    || (v10 = ExAllocatePoolWithTag(512, 32, 1901552451), (v4 = v10) == 0) )
  {
    *(_BYTE *)(v8 + 32) = 0;
    result = CcWriteBehindInternal(v8);
    if ( (char *)v8 == &v16 )
      v8 = 0;
  }
  else
  {
    *(_BYTE *)(v8 + 32) = 1;
    *(_BYTE *)(v8 + 18) = 4;
    *(_BYTE *)(v8 + 16) = 1;
    *(_BYTE *)(v8 + 17) = 0;
    *(_DWORD *)(v8 + 20) = 0;
    *(_DWORD *)(v8 + 24) = v8 + 24;
    *(_DWORD *)(v8 + 28) = v8 + 24;
    v11 = CcWriteBehindInternal;
    *(_QWORD *)(v10 + 8) = *(_QWORD *)(&v8 - 1);
    *(_DWORD *)v10 = 0;
    *(_DWORD *)(v10 + 16) = 1;
    *(_DWORD *)v10 = 0;
    ExQueueWorkItem(v10, 38);
    result = KeWaitForSingleObject(v8 + 16, 0, 0);
  }
  if ( v8 )
  {
    v12 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v13 = *(_DWORD *)(v12 + 2864);
    v14 = *(unsigned __int16 *)(v13 + 8);
    ++*(_DWORD *)(v13 + 20);
    if ( *(unsigned __int16 *)(v13 + 4) < v14
      || (++*(_DWORD *)(v13 + 24),
          v13 = *(_DWORD *)(v12 + 2868),
          v15 = *(unsigned __int16 *)(v13 + 8),
          ++*(_DWORD *)(v13 + 20),
          *(unsigned __int16 *)(v13 + 4) < v15) )
    {
      result = RtlpInterlockedPushEntrySList((unsigned __int64 *)v13, (_DWORD *)v8);
    }
    else
    {
      ++*(_DWORD *)(v13 + 24);
      result = (*(int (__fastcall **)(int))(v13 + 44))(v8);
    }
  }
  if ( v4 )
    result = ExFreePoolWithTag(v4, 1901552451);
  return result;
}
