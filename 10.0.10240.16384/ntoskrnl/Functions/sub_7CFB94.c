// sub_7CFB94 
 
int __fastcall sub_7CFB94(int a1, int a2, int a3, int a4, unsigned int a5)
{
  _DWORD *v6; // r5
  unsigned int *v7; // r6
  int v8; // r7
  int v9; // r8
  int v10; // r9
  int v11; // r10
  int v12; // r3
  unsigned int v13; // r4
  unsigned int v14; // r1
  int (__fastcall *v15)(_DWORD); // [sp-4h] [bp-4h]

  ExpAcquireFastMutexContended((int)v7, v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v7[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7[7] = a5;
  IoRemoveShareAccess(*(_DWORD *)(v9 + 28), v6 + 21);
  if ( *(_DWORD *)(v9 + 28) == v6[38] )
  {
    v12 = v6[18];
    v6[38] = 0;
    v11 = 1;
    v6[18] = v12 & 0xFFFFFFFE;
  }
  if ( *(_DWORD *)(v9 + 28) == v6[37] )
  {
    v6[37] = 0;
    RawInitiateDeleteVolume((int)v6, 1, 0);
  }
  v13 = v7[7];
  v7[1] = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex(v7);
  while ( !v14 && __strex(1u, v7) );
  if ( v14 )
    ExpReleaseFastMutexContended(v7, v14);
  KfLowerIrql((unsigned __int8)v13);
  KeAbPostRelease((unsigned int)v7);
  if ( v11 )
    FsRtlNotifyVolumeEvent(*(_DWORD *)(v9 + 28), 5);
  *(_DWORD *)(v10 + 24) = 0;
  IofCompleteRequest(v10, 1);
  return v15(0);
}
