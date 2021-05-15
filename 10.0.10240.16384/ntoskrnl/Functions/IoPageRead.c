// IoPageRead 
 
int __fastcall IoPageRead(unsigned int a1, int a2, _DWORD *a3, int a4, int a5)
{
  _DWORD *v5; // r5
  char v7; // r10
  int v8; // r0
  int v9; // r6
  int v10; // r7
  int v11; // r4
  int v13; // lr
  _DWORD *v14; // r2
  int v15; // r1
  unsigned int v16; // r2
  int v17; // r2
  int v18; // r3
  int *v19; // r7
  int v20; // r3
  int *v21; // r5
  unsigned int *v22; // r10
  unsigned int v23; // r2
  int v24; // r2
  unsigned int v25; // r2
  int v26; // r3
  unsigned __int8 *v27; // r3
  int v28; // r2
  unsigned int v29; // r1
  int v30; // [sp+8h] [bp-28h]
  int v33; // [sp+10h] [bp-20h]

  v5 = (_DWORD *)a1;
  v30 = 0;
  v7 = 1;
  if ( (a1 & 3) != 0 )
  {
    if ( (a1 & 1) != 0 )
      v30 = 1;
    else
      v7 = 0;
    v5 = (_DWORD *)(a1 & 0xFFFFFFFC);
  }
  v8 = IoGetRelatedDeviceObject(v5);
  v9 = v8;
  if ( (a2 & 1) != 0 )
  {
    v10 = 1027;
    a2 &= 0xFFFFFFFE;
  }
  else
  {
    v10 = 67;
  }
  if ( (a2 & 2) != 0 )
  {
    v7 |= 2u;
    a2 &= 0xFFFFFFFD;
  }
  v11 = ((int (__fastcall *)(int, _DWORD, _DWORD))pIoAllocateIrp)(v8, *(char *)(v8 + 48), 0);
  if ( !v11 )
    return sub_543FE4();
  if ( MmIsFileObjectAPagingFile(v5) || (*(_WORD *)(a2 + 6) & 0x40) != 0 && (v10 & 0x40) != 0 )
    *(_BYTE *)(v11 + 39) |= 0x20u;
  v13 = *(_DWORD *)(v11 + 96);
  *(_DWORD *)(v11 + 8) = v10;
  v14 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v15 = (v14[240] >> 9) & 7;
  if ( (*(_DWORD *)(v14[84] + 192) & 0x100000) != 0 )
    v15 = 0;
  if ( v15 < 2 )
  {
    if ( v14 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v14[250] )
      v15 = 2;
    if ( v15 < 2 )
    {
      if ( (v7 & 1) == 0 || v30 == 1 || (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 0x40) != 0 )
      {
        ++IoPagingReadLowPriorityCount;
      }
      else
      {
        v15 = 2;
        ++IoPagingReadLowPriorityBumpedCount;
      }
    }
  }
  if ( (v7 & 2) != 0 && v15 == 2 )
    v15 = 3;
  v16 = *(_DWORD *)(v11 + 8) & 0xFFF1FFFF;
  *(_BYTE *)(v11 + 32) = 0;
  *(_DWORD *)(v11 + 4) = a2;
  *(_DWORD *)(v11 + 8) = v16 | ((v15 + 1) << 17);
  *(_DWORD *)(v11 + 40) = a5;
  *(_DWORD *)(v11 + 44) = a4;
  v17 = *(_DWORD *)(a2 + 24);
  v18 = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(v11 + 100) = v5;
  *(_DWORD *)(v11 + 60) = v17 + v18;
  *(_DWORD *)(v11 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_BYTE *)(v13 - 40) = 3;
  *(_DWORD *)(v13 - 12) = v5;
  v19 = (int *)(v11 + 16);
  *(_DWORD *)(v13 - 32) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(v13 - 24) = *a3;
  *(_DWORD *)(v13 - 20) = a3[1];
  *(_DWORD *)(a5 + 4) = v11;
  v20 = *(_DWORD *)(v11 + 80);
  v21 = (int *)(v20 + 908);
  v22 = (unsigned int *)(v20 + 1024);
  v33 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    JUMPOUT(0x544060);
  do
    v23 = __ldrex(v22);
  while ( __strex(1u, v22) );
  __dmb(0xBu);
  if ( v23 )
    KxWaitForSpinLockAndAcquire(v22);
  v24 = *v21;
  *v19 = *v21;
  *(_DWORD *)(v11 + 20) = v21;
  if ( *(int **)(v24 + 4) != v21 )
    JUMPOUT(0x54406A);
  *(_DWORD *)(v24 + 4) = v19;
  *v21 = (int)v19;
  if ( (dword_682604 & 0x10000) != 0 )
    JUMPOUT(0x54406E);
  __dmb(0xBu);
  *v22 = 0;
  KfLowerIrql(v33);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_BYTE *)(v25 + 0x3CD) || *(_BYTE *)(v25 + 972) == 1 )
  {
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v29 + 996) += (unsigned int)(*(_DWORD *)(a2 + 20) + 4095) >> 12;
  }
  if ( pIofCallDriver )
    JUMPOUT(0x54407C);
  v26 = (char)(*(_BYTE *)(v11 + 35) - 1);
  *(_BYTE *)(v11 + 35) = v26;
  if ( v26 <= 0 )
    JUMPOUT(0x54408A);
  v27 = (unsigned __int8 *)(*(_DWORD *)(v11 + 96) - 40);
  *(_DWORD *)(v11 + 96) = v27;
  v28 = *v27;
  *((_DWORD *)v27 + 6) = v9;
  if ( v28 == 22 )
    JUMPOUT(0x544098);
  return (*(int (__fastcall **)(int, int))(*(_DWORD *)(v9 + 8) + 4 * v28 + 56))(v9, v11);
}
