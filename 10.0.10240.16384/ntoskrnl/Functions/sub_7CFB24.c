// sub_7CFB24 
 
int sub_7CFB24()
{
  int v0; // r3
  __int16 v1; // r10
  int v2; // r0
  int v4; // r2
  int v5; // r1
  _DWORD *v6; // r5
  int v7; // r6
  int v8; // r7
  unsigned int *v9; // r8
  int v10; // r9
  unsigned int v11; // r10
  int v12; // r6
  unsigned int v13; // r4
  unsigned int v14; // r1
  int v15; // [sp+0h] [bp-30h]
  int v16; // [sp+4h] [bp-2Ch]
  int v17; // [sp+8h] [bp-28h]
  int (__fastcall *v18)(int, int, int, int); // [sp+2Ch] [bp-4h]

  ExpAcquireFastMutexContended((int)v9, v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9[7] = v11;
  v4 = *(_DWORD *)(v10 + 28);
  if ( v4 && (*(_WORD *)(v4 + 48) || *(_DWORD *)(v4 + 32))
    || (v5 = *(_DWORD *)(v10 + 12), (v5 & 0xFF000000) != 0x1000000)
    || (v5 & 1) != 0 )
  {
    v12 = -1073741811;
    goto LABEL_28;
  }
  v0 = v6[18];
  if ( (v0 & 1) != 0 )
  {
    v12 = -1073741790;
    goto LABEL_28;
  }
  if ( (v0 & 2) != 0 )
  {
    v12 = -1073741202;
    goto LABEL_28;
  }
  v1 = *(_WORD *)(v10 + 18);
  v2 = *(_DWORD *)(*(_DWORD *)(v10 + 8) + 8);
  v17 = v2;
  if ( v6[19] )
  {
    v12 = IoCheckShareAccessEx(v2, v1, v4, v6 + 21, 1, 0);
    if ( v12 >= 0 )
    {
      v2 = v17;
      goto LABEL_16;
    }
LABEL_28:
    *(_DWORD *)(v8 + 28) = 0;
    goto LABEL_19;
  }
LABEL_16:
  if ( !v6[19] )
    IoSetShareAccessEx(v2, v1, *(_DWORD *)(v10 + 28), v6 + 21, 0);
  v12 = 0;
  ++v6[19];
  ++v6[20];
  *(_DWORD *)(*(_DWORD *)(v10 + 28) + 8) = v6[35];
  *(_DWORD *)(v8 + 28) = 1;
  *(_DWORD *)(*(_DWORD *)(v10 + 28) + 44) |= 8u;
  *(_DWORD *)(*(_DWORD *)(v10 + 28) + 12) = v6;
LABEL_19:
  if ( v6[19] || !RawInitiateDeleteVolume((int)v6, 0, 1) )
  {
    v9[1] = 0;
    v13 = v9[7];
    __dmb(0xBu);
    do
      v14 = __ldrex(v9);
    while ( !v14 && __strex(1u, v9) );
    if ( v14 )
      ExpReleaseFastMutexContended(v9, v14);
    KfLowerIrql((unsigned __int8)v13);
    KeAbPostRelease((unsigned int)v9);
  }
  *(_DWORD *)(v8 + 24) = v12;
  IofCompleteRequest(v8, 1);
  return v18(v12, v15, v16, v17);
}
