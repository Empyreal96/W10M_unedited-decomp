// FsRtlAcquireToCreateMappedSection 
 
int __fastcall FsRtlAcquireToCreateMappedSection(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  char v6; // r4
  int v8; // r7
  unsigned int v9; // r2
  int v11; // r5
  unsigned int v12; // r6
  int v13; // r4
  int v14; // r0
  unsigned int v15; // r2
  unsigned int *v16; // r4
  unsigned int v17; // r5
  unsigned int v18; // r1
  int v19; // [sp+0h] [bp-30h] BYREF
  unsigned int v20; // [sp+4h] [bp-2Ch]
  int v21; // [sp+8h] [bp-28h]
  int v22; // [sp+Ch] [bp-24h]

  v20 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 16;
  *a3 = 0;
  *a4 = 0;
  v6 = a2;
  v8 = ((int (__fastcall *)(int, int, int, int *))FsRtlAcquireFileExclusiveCommon)(a1, 1, a2, &v19);
  if ( v8 < 0 )
    return v8;
  if ( (v6 & 0x44) == 0 || (v11 = *(_DWORD *)(a1 + 12)) == 0 )
  {
LABEL_3:
    v9 = v20;
    if ( v20 >= 0xC )
      *a3 = v21;
    if ( v9 >= 0x10 )
      *a4 = v22;
    return v8;
  }
  v12 = *(_DWORD *)(v11 + 40);
  v13 = KeAbPreAcquire(v12, 0, 0);
  v14 = KfRaiseIrql(1);
  do
    v15 = __ldrex((unsigned __int8 *)v12);
  while ( __strex(v15 & 0xFE, (unsigned __int8 *)v12) );
  __dmb(0xBu);
  if ( (v15 & 1) != 0 )
  {
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    *(_DWORD *)(v12 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v12 + 28) = v14;
    v16 = *(unsigned int **)(v11 + 40);
    *(_BYTE *)(v11 + 6) |= 0x10u;
    v17 = v16[7];
    v16[1] = 0;
    __dmb(0xBu);
    do
      v18 = __ldrex(v16);
    while ( !v18 && __strex(1u, v16) );
    if ( v18 )
      ExpReleaseFastMutexContended(v16, v18);
    KfLowerIrql((unsigned __int8)v17);
    KeAbPostRelease((unsigned int)v16);
    goto LABEL_3;
  }
  return sub_802A4C(v14);
}
