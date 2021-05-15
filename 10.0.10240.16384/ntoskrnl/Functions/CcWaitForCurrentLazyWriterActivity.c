// CcWaitForCurrentLazyWriterActivity 
 
int CcWaitForCurrentLazyWriterActivity()
{
  _DWORD *v0; // r6
  int v1; // r5
  int v2; // r4
  int v3; // r5
  __int64 v4; // kr00_8
  int v5; // r0
  int result; // r0
  int v7; // r0
  int **v8; // r2
  int v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // r2
  char v12[4]; // [sp+8h] [bp-20h] BYREF
  int v13; // [sp+Ch] [bp-1Ch]
  int v14[6]; // [sp+10h] [bp-18h] BYREF

  v0 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  v1 = v0[716];
  ++*(_DWORD *)(v1 + 12);
  v2 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v1);
  if ( !v2 )
  {
    ++*(_DWORD *)(v1 + 16);
    v3 = v0[717];
    ++*(_DWORD *)(v3 + 12);
    v2 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v3);
    if ( !v2 )
    {
      v4 = *(_QWORD *)(v3 + 32);
      v5 = *(_DWORD *)(v3 + 28);
      ++*(_DWORD *)(v3 + 16);
      v2 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v3 + 40))(v5, HIDWORD(v4), v4);
      if ( !v2 )
        return -1073741670;
    }
  }
  *(_DWORD *)v2 = v0[357];
  *(_BYTE *)(v2 + 64) = 4;
  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 4;
  v13 = 0;
  v14[1] = (int)v14;
  v14[0] = (int)v14;
  *(_DWORD *)(v2 + 8) = v12;
  if ( (dword_682610 & 0x20000) != 0 )
    CcPerfLogWorkItemEnqueue(&CcPostTickWorkQueue, v2, 0, 0);
  v7 = KeAcquireQueuedSpinLock(5);
  v8 = (int **)dword_6326AC;
  *(_DWORD *)v2 = &CcPostTickWorkQueue;
  *(_DWORD *)(v2 + 4) = v8;
  v9 = v7;
  if ( *v8 != &CcPostTickWorkQueue )
    __fastfail(3u);
  *v8 = (int *)v2;
  byte_632771 = 1;
  dword_6326AC = v2;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)&CcPostTickWorkItemCount);
  while ( __strex(v10 + 1, (unsigned int *)&CcPostTickWorkItemCount) );
  __dmb(0xBu);
  CcScheduleLazyWriteScan(1, 1);
  KeReleaseQueuedSpinLock(5, v9);
  result = KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&CcPostTickWorkItemCount);
  while ( __strex(v11 - 1, (unsigned int *)&CcPostTickWorkItemCount) );
  __dmb(0xBu);
  return result;
}
