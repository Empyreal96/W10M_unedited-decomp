// IoEnumerateRegisteredFiltersList 
 
int __fastcall IoEnumerateRegisteredFiltersList(_DWORD *a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r7
  int v4; // r8
  unsigned int v8; // r4
  int v9; // r3
  unsigned int v11; // r6
  int *v12; // r3
  int *i; // r4
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r3

  v3 = 0;
  v4 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(__int16 *)(v8 + 0x134) - 1;
  *(_WORD *)(v8 + 308) = v9;
  if ( !ExAcquireResourceExclusiveLite((int)&IopDatabaseResource, 0, (int)a3, v9) )
    return sub_81BBBC();
  v11 = a2 >> 2;
  v12 = (int *)IopFsNotifyChangeQueueHead;
  while ( v12 != &IopFsNotifyChangeQueueHead )
  {
    v12 = (int *)*v12;
    ++v3;
  }
  *a3 = v3;
  if ( v3 > v11 )
    v4 = -1073741789;
  for ( i = (int *)IopFsNotifyChangeQueueHead; v11; i = (int *)*i )
  {
    if ( i == &IopFsNotifyChangeQueueHead )
      break;
    ObfReferenceObject(i[2]);
    --v11;
    *a1++ = i[2];
  }
  v14 = ExReleaseResourceLite((int)&IopDatabaseResource);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v4;
}
