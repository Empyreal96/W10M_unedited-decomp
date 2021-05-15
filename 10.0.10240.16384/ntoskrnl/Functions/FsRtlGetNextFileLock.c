// FsRtlGetNextFileLock 
 
int __fastcall FsRtlGetNextFileLock(int a1, int a2)
{
  _DWORD *v3; // r6
  int v6; // r9
  _DWORD *v7; // r5
  unsigned int *v8; // r7
  unsigned int v9; // r2
  _DWORD *v10; // r4
  _DWORD *v11; // r0
  unsigned int v12; // r7
  unsigned int v13; // r8
  __int64 v14; // r2
  int v15; // r2
  int j; // r3
  int v17; // r1
  _DWORD *v18; // r0
  _DWORD *v19; // r0
  _DWORD *v20; // r3
  int v21; // r1
  int i; // r3
  int v23; // r4
  char v24[4]; // [sp+8h] [bp-60h] BYREF
  _DWORD *v25; // [sp+Ch] [bp-5Ch] BYREF
  _DWORD *v26; // [sp+10h] [bp-58h]
  int v27; // [sp+14h] [bp-54h]
  int v28; // [sp+18h] [bp-50h]
  unsigned __int64 v29; // [sp+20h] [bp-48h] BYREF
  __int64 v30; // [sp+28h] [bp-40h]
  char v31; // [sp+30h] [bp-38h]
  int v32; // [sp+34h] [bp-34h]
  int v33; // [sp+38h] [bp-30h]
  int v34; // [sp+3Ch] [bp-2Ch]
  _DWORD var28[12]; // [sp+40h] [bp-28h] BYREF

  v3 = *(_DWORD **)(a1 + 12);
  v28 = a1;
  if ( !v3 )
    return 0;
  v6 = 0;
  memmove((int)&v29, a1 + 16, 0x28u);
  v7 = *(_DWORD **)(a1 + 56);
  v8 = v3 + 4;
  v26 = v3 + 4;
  v27 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)(v3 + 4));
  }
  else
  {
    do
      v9 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( v9 )
      KxWaitForSpinLockAndAcquire(v3 + 4);
  }
  if ( a2 )
  {
    v20 = (_DWORD *)v3[6];
    if ( v20 )
    {
      do
      {
        v7 = v20;
        v20 = (_DWORD *)v20[1];
      }
      while ( v20 );
      v21 = (int)(v7 + 4);
      goto LABEL_66;
    }
    v15 = v3[5];
    if ( !v15 )
      goto LABEL_68;
    for ( i = *(_DWORD *)(v15 + 4); i; i = *(_DWORD *)(i + 4) )
      v15 = i;
LABEL_65:
    v7 = *(_DWORD **)(v15 - 16);
    v21 = (int)(v7 + 2);
LABEL_66:
    memmove((int)&v29, v21, 0x28u);
    goto LABEL_67;
  }
  if ( v31 )
  {
    v10 = (_DWORD *)FsRtlFindFirstOverlappingExclusiveNode(v3[6], &v29, var28, &v25, v24);
    if ( v10 )
    {
      v12 = HIDWORD(v30);
      v13 = v30;
      while ( 1 )
      {
        if ( v7 == v10 && v29 == *((_QWORD *)v10 + 2) )
        {
          LODWORD(v14) = v10[7];
          HIDWORD(v14) = v10[6];
          if ( __PAIR64__(v13, v12) == v14 && v32 == v10[9] && v33 == v10[10] && v34 == v10[11] )
            break;
        }
        if ( *((_QWORD *)v10 + 3) || v13 | v12 )
          goto LABEL_28;
        v10 = RtlRealSuccessor(v10);
        if ( !v10 )
          goto LABEL_29;
      }
      v11 = v10;
    }
    else
    {
      if ( v24[0] )
      {
        v10 = v25;
LABEL_28:
        if ( !v10 )
          goto LABEL_29;
        v17 = (int)(v10 + 4);
LABEL_35:
        memmove((int)&v29, v17, 0x28u);
        v7 = v10;
LABEL_67:
        v6 = 1;
        goto LABEL_68;
      }
      v11 = v25;
      if ( !v25 )
      {
LABEL_29:
        v15 = v3[5];
        if ( !v15 )
          goto LABEL_68;
        for ( j = *(_DWORD *)(v15 + 4); j; j = *(_DWORD *)(j + 4) )
          v15 = j;
        goto LABEL_65;
      }
    }
    v10 = RtlRealSuccessor(v11);
    goto LABEL_28;
  }
  v18 = (_DWORD *)FsRtlFindFirstOverlappingSharedNode(v3[5], &v29, var28, &v25, v24);
  if ( v18 )
    goto LABEL_41;
  v18 = v25;
  if ( !v24[0] )
  {
    if ( !v25 )
      goto LABEL_68;
    v18 = RtlRealSuccessor(v25);
  }
  if ( v18 )
  {
LABEL_41:
    if ( v18 != (_DWORD *)16 )
    {
      v10 = (_DWORD *)*(v18 - 4);
      if ( v10 )
      {
        while ( v7 != v10
             || v29 != *((_QWORD *)v10 + 1)
             || v30 != *((_QWORD *)v10 + 2)
             || v32 != v10[7]
             || v33 != v10[8]
             || v34 != v10[9] )
        {
          if ( v29 < *((_QWORD *)v10 + 1) )
            goto LABEL_53;
          v10 = (_DWORD *)*v10;
          if ( !v10 )
            goto LABEL_54;
        }
        v10 = (_DWORD *)*v10;
LABEL_53:
        if ( v10 )
          goto LABEL_57;
      }
LABEL_54:
      v19 = RtlRealSuccessor(v18);
      if ( v19 )
        v10 = (_DWORD *)*(v19 - 4);
      if ( v10 )
      {
LABEL_57:
        v17 = (int)(v10 + 2);
        goto LABEL_35;
      }
    }
  }
LABEL_68:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v26, var28[11]);
  }
  else
  {
    __dmb(0xBu);
    *v26 = 0;
  }
  KfLowerIrql(v27);
  if ( !v6 )
    return 0;
  v23 = v28;
  memmove(v28 + 16, (int)&v29, 0x28u);
  *(_DWORD *)(v23 + 56) = v7;
  return v23 + 16;
}
