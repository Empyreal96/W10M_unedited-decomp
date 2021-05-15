// IoUnregisterFsRegistrationChange 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoUnregisterFsRegistrationChange(int a1, int a2)
{
  int v4; // r2
  int v5; // r3
  int *i; // r0
  int v7; // r0
  unsigned int v8; // r1
  __int16 v9; // r3
  int *v11; // r1 OVERLAPPED
  int **v12; // r2 OVERLAPPED

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = *(__int16 *)(v4 + 0x134) - 1;
  *(_WORD *)(v4 + 308) = v5;
  ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 1, v4, v5);
  for ( i = (int *)IopFsNotifyChangeQueueHead; i != &IopFsNotifyChangeQueueHead; i = (int *)*i )
  {
    if ( i[2] == a1 && i[3] == a2 )
    {
      *(_QWORD *)&v11 = *(_QWORD *)i;
      if ( *(int **)(*i + 4) != i || *v12 != i )
        __fastfail(3u);
      *v12 = v11;
      v11[1] = (int)v12;
      ExFreePoolWithTag((unsigned int)i);
      break;
    }
  }
  v7 = ExReleaseResourceLite((int)&IopDatabaseResource);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_WORD *)(v8 + 0x134) + 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
    KiCheckForKernelApcDelivery(v7);
  return ObfDereferenceObject(a1);
}
