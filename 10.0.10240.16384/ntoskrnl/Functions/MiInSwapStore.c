// MiInSwapStore 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiInSwapStore(int a1)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4 OVERLAPPED
  int (*v5)(); // r3
  int v6; // r0

  v2 = (_BYTE *)ExAllocatePoolWithTag(512, 40, 1934847309);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  memset(v2, 0, 40);
  KeInitializeEvent((int)(v3 + 20), 0, 0);
  v5 = MiInSwapStoreWorker;
  *((_QWORD *)v3 + 1) = *(_QWORD *)(&v3 - 1);
  *(_DWORD *)v3 = 0;
  ObfReferenceObjectWithTag(a1);
  *((_DWORD *)v3 + 9) = 2;
  *((_DWORD *)v3 + 4) = a1;
  v6 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( v6 < 15 )
    ++v6;
  ExQueueWorkItem(v3, v6 + 32);
  KeWaitForSingleObject((unsigned int)(v3 + 20), 26, 0, 0, Mi30Milliseconds);
  MiInSwapStoreContextDereference(v3);
  return 0;
}
