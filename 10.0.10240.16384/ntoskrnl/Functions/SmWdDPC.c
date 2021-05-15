// SmWdDPC 
 
int __fastcall SmWdDPC(int a1, int *a2)
{
  unsigned int *v3; // r5
  unsigned int v4; // r1
  unsigned int v5; // r2
  unsigned int *v6; // lr
  unsigned int *v7; // r10
  unsigned int v8; // r3
  unsigned int *v9; // r8
  unsigned int v10; // r4
  unsigned int v11; // r0
  _DWORD *v12; // r1
  int *v13; // r9
  int result; // r0
  int *v15; // r7
  bool v16; // zf
  unsigned int *v17; // r10
  int v18; // r8
  int v19; // r1
  int v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r3
  unsigned int v23; // r5
  int v24; // r4
  int v25; // t1
  unsigned int v26; // [sp+8h] [bp-40h]
  unsigned int v27; // [sp+8h] [bp-40h]
  int *v29; // [sp+18h] [bp-30h] BYREF
  int *v30; // [sp+1Ch] [bp-2Ch]
  int vars4; // [sp+4Ch] [bp+4h]

  v29 = 0;
  v30 = (int *)&v29;
  v3 = (unsigned int *)(a1 + 40);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 40);
  }
  else
  {
    v4 = 1;
    do
      v5 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v5 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 40));
  }
  v6 = (unsigned int *)(a1 + 32);
  while ( 1 )
  {
    v7 = v6;
    if ( v6 == *(unsigned int **)(a1 + 36) )
      break;
    v8 = *v6 & 0xFFFFFFF8;
    v6 = (unsigned int *)v8;
    if ( !v8 )
      break;
    v9 = (unsigned int *)(v8 + 4);
    if ( (*(_WORD *)(v8 + 6) & 1) != 0 )
    {
      v10 = *v9;
      __dmb(0xBu);
      do
      {
        if ( (v10 & 0x60000) != 0 )
          break;
        v11 = v10;
        __dmb(0xBu);
        do
          v4 = __ldrex(v9);
        while ( v4 == v10 && __strex(v10 | 0x40000, v9) );
        v10 = v4;
        __dmb(0xBu);
      }
      while ( v4 != v11 );
      __dmb(0xBu);
      if ( (v10 & 0x60000) == 0 )
      {
        v12 = (_DWORD *)(*v7 & 0xFFFFFFF8);
        *v7 = *v12 & 0xFFFFFFF8 | *v7 & 7;
        if ( *(_DWORD **)(a1 + 36) == v12 )
          *(_DWORD *)(a1 + 36) = v7;
        v6 = v7;
        **(_DWORD **)(a1 + 36) = **(_DWORD **)(a1 + 36) & 7 | (8 * (**(_DWORD **)(a1 + 36) >> 3) - 8);
        v4 = v8;
        *(_DWORD *)v8 = *(_DWORD *)v8 & 7 | (8 * (((unsigned int)*v30 >> 3) + 1));
        *v30 = *v30 & 7 | v8;
        v30 = (int *)v8;
      }
    }
    else
    {
      __dmb(0xBu);
      do
        v4 = __ldrex(v9);
      while ( __strex(v4 | 0x10000, v9) );
      __dmb(0xBu);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  v13 = a2;
  while ( 1 )
  {
    result = (int)v30;
    if ( v30 == (int *)&v29 )
      break;
    v15 = v29;
    v16 = v29 == v30;
    v29 = (int *)(*v29 & 0xFFFFFFF8);
    if ( v16 )
    {
      v29 = 0;
      v30 = (int *)&v29;
    }
    else
    {
      v4 = *v30;
      *v30 = *v30 & 7 | (8 * ((unsigned int)*v30 >> 3) - 8);
    }
    v17 = (unsigned int *)(v15 + 1);
    v18 = v13[24 * (((unsigned int)v15[1] >> 19) & 0x1F)];
    SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxWorkItemComplete(v15, v4, v18, -1073741643);
    StEtaIoTimeout(*(_DWORD *)(v18 + 1592), v19, v20, (int)dword_989680, (unsigned int)dword_989680);
    v21 = v15[1];
    __dmb(0xBu);
    v26 = v21;
    do
    {
      v22 = v26;
      __dmb(0xBu);
      v4 = v26;
      v27 = v26 & 0xFFFF00FF | (((unsigned __int8)(BYTE1(v26) - 1) | 0x400) << 8);
      __dmb(0xBu);
      __dmb(0xBu);
      do
        v23 = __ldrex(v17);
      while ( v23 == v22 && __strex(v27, v17) );
      __dmb(0xBu);
      v26 = v23;
      __dmb(0xBu);
      __dmb(0xBu);
    }
    while ( v23 != v22 );
    v13 = a2;
    if ( (v23 & 0xFF00) == 256 )
      SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFree(v23, v18, v15, 0);
  }
  v24 = 32;
  do
  {
    v25 = *v13;
    v13 += 24;
    if ( v25 )
      result = SmWdProcessStore(v13 - 24);
    --v24;
  }
  while ( v24 );
  return result;
}
