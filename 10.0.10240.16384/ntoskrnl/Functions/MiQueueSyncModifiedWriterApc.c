// MiQueueSyncModifiedWriterApc 
 
__int64 __fastcall MiQueueSyncModifiedWriterApc(int a1, int a2, int a3, int a4, unsigned int a5)
{
  __int64 v7; // [sp+0h] [bp-18h]

  KeInitializeApc(a2, *(_DWORD *)(a1 + 560), 3, (int)PopPoCoalescinCallback, 0, a3, 0, a4);
  KeInsertQueueApc(a2, 0, 0, 0);
  KeWaitForSingleObject(a5, 0, 0, 0, 0);
  return v7;
}
