// FsRtlOplockBreakH 
 
int __fastcall FsRtlOplockBreakH(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r6
  _DWORD *v8; // r8
  int v9; // r5
  int v10; // r4
  int result; // r0
  unsigned int v12; // r8
  unsigned int v13; // r10
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int *v17; // r4
  unsigned int v18; // r1
  unsigned __int8 v19; // [sp+18h] [bp-30h] BYREF
  char v20[3]; // [sp+19h] [bp-2Fh] BYREF
  int v21; // [sp+1Ch] [bp-2Ch]
  _DWORD *v22; // [sp+20h] [bp-28h]
  _DWORD *v23; // [sp+24h] [bp-24h]
  int v24; // [sp+28h] [bp-20h]
  int *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v24 = a4;
  v6 = a3;
  v23 = (_DWORD *)*a1;
  v8 = v23;
  v22 = v23;
  v9 = *(_DWORD *)(a2 + 96);
  v10 = 0;
  v19 = 0;
  result = 0;
  v21 = 0;
  if ( !v23 )
    return result;
  v21 = FsRtlpAttachOplockKey(a2);
  if ( !v21 )
  {
    if ( !*(_BYTE *)v9 )
    {
      if ( (*(_DWORD *)(*(_DWORD *)(v9 + 8) + 8) & 0xFFEFFE7F) == 0 )
      {
        v21 = 0;
        goto LABEL_18;
      }
      if ( (*(_DWORD *)(v9 + 12) & 0x10000) != 0 )
        v6 |= 0x10000000u;
    }
    while ( 1 )
    {
      v20[0] = 0;
      if ( !v10 )
      {
        v12 = v8[19];
        v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v14 = KeAbPreAcquire(v12, 0, 0);
        v15 = v14;
        do
          v16 = __ldrex((unsigned __int8 *)v12);
        while ( __strex(v16 & 0xFE, (unsigned __int8 *)v12) );
        __dmb(0xBu);
        if ( (v16 & 1) == 0 )
          ExpAcquireFastMutexContended(v12, v14);
        if ( v15 )
          *(_BYTE *)(v15 + 14) |= 1u;
        *(_DWORD *)(v12 + 4) = v13;
        v19 = 1;
        v8 = v23;
      }
      v21 = FsRtlpOplockBreakByCacheFlags(v8, v9, a2, v6, 0x2000, v24, a5, a6, &v19, (int)v20);
      if ( !v20[0] )
        break;
      v10 = v19;
    }
  }
LABEL_18:
  if ( v19 )
  {
    v17 = (unsigned int *)v22[19];
    v17[1] = 0;
    __dmb(0xBu);
    do
      v18 = __ldrex(v17);
    while ( !v18 && __strex(1u, v17) );
    if ( v18 )
      ExpReleaseFastMutexContended(v17, v18);
    KeAbPostRelease((unsigned int)v17);
  }
  return v21;
}
