// IoSynchronousPageWriteEx 
 
int __fastcall IoSynchronousPageWriteEx(int a1, _DWORD *a2, _DWORD *a3, int a4, char a5, int a6)
{
  int v7; // r4
  unsigned int *v11; // r5
  unsigned int v12; // r6
  unsigned int *v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // r1
  int v16; // r5
  _DWORD *v17; // r0
  _DWORD *v18; // r4
  int v20; // r0
  _DWORD *v21; // r2
  int v22; // r1
  int v23; // r3
  int v24; // r2
  int v25; // r3
  int v26; // r3
  unsigned int v27; // r2
  int *v28; // r2

  v7 = *(_DWORD *)(a1 + 20);
  if ( v7 && *(_DWORD *)(v7 + 4) )
  {
    v11 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4276);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + 1, v11) );
    v13 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4280);
    v14 = (unsigned int)(a2[5] + 4095) >> 12;
    do
      v15 = __ldrex(v13);
    while ( __strex(v15 + v14, v13) );
  }
  v16 = IoGetRelatedDeviceObject(a1);
  v17 = (_DWORD *)((int (__fastcall *)(int, _DWORD, _DWORD))pIoAllocateIrp)(v16, *(char *)(v16 + 48), 0);
  v18 = v17;
  if ( !v17 )
    return sub_520AF4();
  v17[1] = a2;
  v17[2] = 67;
  v20 = v17[24];
  *((_BYTE *)v18 + 39) |= 0x20u;
  v21 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v22 = (v21[240] >> 9) & 7;
  if ( (*(_DWORD *)(v21[84] + 192) & 0x100000) != 0 )
    v22 = 0;
  if ( v22 < 2 )
  {
    if ( v21 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v21[250] )
      v22 = 2;
    if ( v22 < 2 )
    {
      v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( (*(_DWORD *)(v27 + 0x4C) & 0x400) != 0
        || *(_BYTE *)(v27 + 346) == 1
        || (*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C8) & 0x40) != 0
        || *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) == 2 )
      {
        v28 = &IoPagingWriteLowPriorityCount;
      }
      else
      {
        v28 = &IoPagingWriteLowPriorityBumpedCount;
        v22 = 2;
      }
      ++*v28;
    }
  }
  v23 = v18[2];
  v18[11] = a4;
  v18[2] = v23 & 0xFFF1FFFF | ((v22 + 1) << 17);
  *((_BYTE *)v18 + 32) = 0;
  v18[10] = a6;
  v24 = a2[6];
  v25 = a2[4];
  v18[25] = a1;
  v18[15] = v25 + v24;
  v18[20] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_BYTE *)(v20 - 40) = 4;
  LOBYTE(v24) = *(_BYTE *)(v20 - 38);
  *(_DWORD *)(v20 - 32) = a2[5];
  *(_DWORD *)(v20 - 24) = *a3;
  v26 = a3[1];
  *(_DWORD *)(v20 - 12) = a1;
  *(_DWORD *)(v20 - 20) = v26;
  *(_BYTE *)(v20 - 38) = a5 | v24;
  IopQueueThreadIrp(v18);
  return IofCallDriver(v16, v18);
}
