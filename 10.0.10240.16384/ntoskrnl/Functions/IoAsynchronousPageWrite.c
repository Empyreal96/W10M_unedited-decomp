// IoAsynchronousPageWrite 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoAsynchronousPageWrite(_DWORD *a1, _DWORD *a2, _DWORD *a3, void (__fastcall *a4)(int, int *, _DWORD), int a5, int a6, int a7, char a8, int *a9, int *a10)
{
  int v11; // r0
  int result; // r0
  int v15; // r5
  int v16; // r4
  char v17; // r3
  int v18; // r1
  int v20; // r3
  char v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r4

  v11 = a1[5];
  if ( v11 && *(_DWORD *)(v11 + 4) )
    return sub_548F84();
  v15 = IoGetRelatedDeviceObject(a1);
  v16 = ((int (__fastcall *)(int, _DWORD, _DWORD))pIoAllocateIrp)(v15, *(char *)(v15 + 48), 0);
  if ( !v16 )
  {
    v22 = MmIsFileObjectAPagingFile((int)a1);
    __dmb(0xBu);
    if ( v22 )
    {
      do
        v23 = __ldrex(&IoAsynchronousPageWriteIrpAllocationFailure);
      while ( __strex(v23 + 1, &IoAsynchronousPageWriteIrpAllocationFailure) );
      __dmb(0xBu);
      v24 = IopAllocateReserveIrp();
    }
    else
    {
      do
        v25 = __ldrex(&IoAsynchronousPageWriteNonPagefileIrpAllocationFailure);
      while ( __strex(v25 + 1, &IoAsynchronousPageWriteNonPagefileIrpAllocationFailure) );
      __dmb(0xBu);
      v24 = IopAllocateBackpocketIrp(v15, *(char *)(v15 + 48), 0);
    }
    v16 = v24;
    if ( !v24 )
      return -1073741670;
  }
  if ( a10 )
    *a10 = v16;
  v17 = *(_BYTE *)(v16 + 39);
  v18 = *(_DWORD *)(v16 + 96);
  *(_DWORD *)(v16 + 4) = a2;
  *(_BYTE *)(v16 + 39) = v17 | 0x20;
  *(_DWORD *)(v16 + 8) = ((a6 + 1) << 17) | 3;
  *(_DWORD *)(v16 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v16 + 100) = a1;
  *(_DWORD *)(v16 + 60) = a2[4] + a2[6];
  *(_BYTE *)(v16 + 32) = 0;
  *(_DWORD *)(v16 + 40) = a9;
  *(_QWORD *)(v16 + 48) = *(_QWORD *)&a4;
  *(_BYTE *)(v18 - 40) = 4;
  *(_DWORD *)(v18 - 32) = a2[5];
  *(_DWORD *)(v18 - 24) = *a3;
  v20 = a3[1];
  v21 = *(_BYTE *)(v18 - 38);
  *(_DWORD *)(v18 - 12) = a1;
  *(_DWORD *)(v18 - 20) = v20;
  *(_BYTE *)(v18 - 38) = a8 | v21;
  IopQueueThreadIrp(v16);
  if ( a7 )
    StRtlIoStorInfoSetNvCachePriority(v16, (unsigned __int8)a7);
  result = IofCallDriver(v15, v16);
  if ( (result & 0xC0000000) == -1073741824 )
  {
    *a9 = result;
    a9[1] = 0;
    v26 = KfRaiseIrql(1);
    a4(a5, a9, 0);
    KfLowerIrql(v26);
    result = 259;
  }
  return result;
}
