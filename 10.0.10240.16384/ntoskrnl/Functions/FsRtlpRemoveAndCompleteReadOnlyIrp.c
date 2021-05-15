// FsRtlpRemoveAndCompleteReadOnlyIrp 
 
int __fastcall FsRtlpRemoveAndCompleteReadOnlyIrp(_DWORD *a1, int a2, __int16 a3)
{
  _DWORD *v3; // r6
  int v4; // r10
  unsigned int *v8; // r4
  unsigned int v9; // r5
  __int64 v10; // kr00_8
  int v11; // r4
  int v12; // r2
  int v13; // r3

  v3 = a1 - 22;
  v4 = a1[2];
  ObfDereferenceObjectWithTag(*(_DWORD *)(v4 + 28));
  *((_BYTE *)v3 + 37) = KeAcquireQueuedSpinLock(7);
  __dmb(0xBu);
  v8 = v3 + 14;
  do
    v9 = __ldrex(v8);
  while ( __strex(0, v8) );
  __dmb(0xBu);
  KeReleaseQueuedSpinLock(7, *((unsigned __int8 *)v3 + 37));
  v10 = *(_QWORD *)a1;
  if ( *(_DWORD **)(*a1 + 4) != a1 || *(_DWORD **)HIDWORD(v10) != a1 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v10) = v10;
  *(_DWORD *)(v10 + 4) = HIDWORD(v10);
  if ( *(_DWORD *)(v4 + 16) == 590400 )
  {
    if ( !*((_BYTE *)v3 + 36) )
    {
      v11 = v3[3];
      memset((_BYTE *)v11, 0, 24);
      if ( (a3 & 0x4000) != 0 )
        v12 = 4;
      else
        v12 = 0;
      *(_WORD *)v11 = 1;
      *(_DWORD *)(v11 + 4) = 1;
      if ( (a3 & 0x2000) != 0 )
        v13 = 2;
      else
        v13 = 0;
      *(_DWORD *)(v11 + 8) = v13 | v12 | ((a3 & 0x1000) != 0);
      *(_WORD *)(v11 + 2) = 24;
      v3[7] = 24;
    }
  }
  else
  {
    v3[7] = 8;
  }
  if ( *((_BYTE *)v3 + 36) )
    a2 = -1073741536;
  v3[6] = a2;
  return pIofCompleteRequest(v3, 1);
}
