// FsRtlCheckUpperOplock 
 
int __fastcall FsRtlCheckUpperOplock(int *a1, char a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  int v7; // r2
  int v8; // r3
  int v9; // r10
  _DWORD *v10; // r5
  int v11; // r8
  int v12; // r6
  int v13; // r4
  unsigned __int8 *v14; // r0
  unsigned int v15; // r2
  int v16; // r4
  int v17; // r3
  _DWORD *i; // r4
  int v19; // r4
  int v20; // r0
  int v21; // r6
  unsigned int *v22; // r4
  unsigned int v23; // r1
  char v25[4]; // [sp+18h] [bp-70h] BYREF
  int v26; // [sp+1Ch] [bp-6Ch]
  int v27; // [sp+20h] [bp-68h]
  int v28; // [sp+24h] [bp-64h]
  int v29; // [sp+28h] [bp-60h]
  unsigned __int8 *v30; // [sp+2Ch] [bp-5Ch]
  int v31; // [sp+30h] [bp-58h]
  int v32; // [sp+34h] [bp-54h]
  unsigned int v33; // [sp+38h] [bp-50h]
  _BYTE v34[72]; // [sp+40h] [bp-48h] BYREF

  v28 = a4;
  v29 = a3;
  if ( (a2 & 1) != 0 )
    v6 = 4096;
  else
    v6 = 0;
  if ( (a2 & 4) != 0 )
    v7 = 0x4000;
  else
    v7 = 0;
  if ( (a2 & 2) != 0 )
    v8 = 0x2000;
  else
    v8 = 0;
  v9 = v8 | v7 | v6;
  v32 = *a1;
  v10 = (_DWORD *)v32;
  v25[0] = 0;
  v27 = 0;
  v11 = 0;
  v31 = 0;
  v12 = 0;
  v26 = 0;
  if ( !v32 )
    return v12;
  v30 = *(unsigned __int8 **)(v32 + 76);
  v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = KeAbPreAcquire((unsigned int)v30, 0, 0);
  v14 = v30;
  do
    v15 = __ldrex(v30);
  while ( __strex(v15 & 0xFE, v30) );
  __dmb(0xBu);
  if ( (v15 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)v30, v13);
    v14 = v30;
  }
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  *((_DWORD *)v14 + 1) = v33;
  v25[0] = 1;
  v16 = v10[18];
  if ( v16 != 1 )
  {
    if ( (a6 & 0x20000) != 0 )
    {
      if ( v16 == 4096 || v16 == 4112 )
      {
        for ( i = (_DWORD *)v10[5]; i != v10 + 5; i = (_DWORD *)*i )
        {
          if ( *(_DWORD *)(i[2] + 16) == 590400 )
          {
            i = (_DWORD *)i[1];
            FsRtlpRemoveAndCompleteReadOnlyIrp((_DWORD *)*i, 0, 4096);
          }
        }
        FsRtlpComputeShareableOplockState(v10);
        goto LABEL_55;
      }
      v17 = -1073739511;
      goto LABEL_34;
    }
    if ( !FsRtlpOplockUpperLowerCompatible(v10[18], v9) )
    {
      switch ( v9 )
      {
        case 0:
          v19 = 1;
          v11 = 28672;
          goto LABEL_46;
        case 4096:
          v27 = 1;
          if ( (v16 & 0x5000) != 20480 )
          {
            if ( (v16 & 0x5000) != 0 )
              v11 = v16 & 0x5000;
            goto LABEL_45;
          }
          v31 = 1;
          break;
        case 12288:
          v27 = 1;
          break;
        case 20480:
          if ( (v16 & 4) != 0 )
            v27 = 1;
          v11 = 0x2000;
          goto LABEL_45;
        default:
          v17 = -1073741597;
LABEL_34:
          v26 = v17;
          goto LABEL_55;
      }
      v11 = 0x4000;
LABEL_45:
      v19 = 0;
LABEL_46:
      memset(v34, 0, 40);
      v34[0] = 3;
      if ( v27 )
      {
        v20 = FsRtlpOplockBreakToII(v10, (int)v34, 0, a6, v29, v28, a5, v25, 0);
      }
      else
      {
        if ( !v19 )
          goto LABEL_51;
        v20 = FsRtlpOplockBreakToNone(v10, (int)v34, 0, a6, v29, v28, a5, v25, 0);
      }
      v12 = v20;
      v26 = v20;
LABEL_51:
      if ( !v12 && (v11 & v10[18]) != 0 )
      {
        v21 = v31;
        v26 = FsRtlpOplockBreakByCacheFlags(v10, (int)v34, 0, (v31 != 0) | a6, v11, v29, v28, a5, v25, 0);
        if ( v21 )
          v26 = FsRtlpOplockBreakByCacheFlags(v10, (int)v34, 0, a6, 0x2000, v29, v28, a5, v25, 0);
      }
      goto LABEL_55;
    }
  }
LABEL_55:
  if ( v25[0] )
  {
    v22 = *(unsigned int **)(v32 + 76);
    v22[1] = 0;
    __dmb(0xBu);
    do
      v23 = __ldrex(v22);
    while ( !v23 && __strex(1u, v22) );
    if ( v23 )
      ExpReleaseFastMutexContended(v22, v23);
    KeAbPostRelease((unsigned int)v22);
  }
  return v26;
}
