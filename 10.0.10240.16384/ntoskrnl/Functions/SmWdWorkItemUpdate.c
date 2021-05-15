// SmWdWorkItemUpdate 
 
int __fastcall SmWdWorkItemUpdate(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  unsigned int *v4; // r10
  unsigned int v5; // r4
  unsigned int v8; // r4
  int result; // r0
  __int16 v10; // r2
  _DWORD *v11; // r8
  unsigned int *v12; // r5
  unsigned int v13; // r2
  int *v14; // r2
  int *v15; // r1
  int v16; // r0
  __int64 v17; // r0
  int v18; // r5
  unsigned int *v19; // r4
  unsigned int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // [sp+0h] [bp-30h]
  int v23; // [sp+0h] [bp-30h]
  unsigned int v24; // [sp+0h] [bp-30h]
  int v25; // [sp+0h] [bp-30h]
  int v28; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  v4 = a3 + 1;
  v5 = a3[1];
  __dmb(0xBu);
  v22 = v5;
  do
  {
    v8 = v22;
    __dmb(0xBu);
    v23 = (v22 ^ (((v22 >> 8) - 1) << 8)) & 0xFF00 ^ v22;
    if ( (v23 & 0xFF00) == 256 || a4 < 0 )
      v23 |= 0x40000u;
    __dmb(0xBu);
    __dmb(0xBu);
    do
      result = __ldrex(v4);
    while ( result == v8 && __strex(v23, v4) );
    __dmb(0xBu);
    v22 = result;
    __dmb(0xBu);
    __dmb(0xBu);
  }
  while ( result != v8 );
  v10 = result;
  v11 = a3;
  if ( (result & 0x40000) != 0 || a4 >= 0 && (result & 0xFF00) != 512 )
  {
    v18 = a2;
  }
  else
  {
    v12 = a1 + 22;
    v28 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)(a1 + 22));
    }
    else
    {
      do
        v13 = __ldrex(v12);
      while ( __strex(1u, v12) );
      __dmb(0xBu);
      if ( v13 )
        KxWaitForSpinLockAndAcquire(a1 + 22);
    }
    v14 = (int *)a1[21];
    if ( v14 != a1 + 20 )
    {
      v15 = a1 + 20;
      do
      {
        v16 = *v15;
        if ( (_DWORD *)(*v15 & 0xFFFFFFF8) == v11 )
          break;
        v15 = (int *)(v16 & 0xFFFFFFF8);
      }
      while ( (int *)(v16 & 0xFFFFFFF8) != v14 );
      if ( v15 != v14 )
      {
        *v15 = *v11 & 0xFFFFFFF8 | *v15 & 7;
        if ( (_DWORD *)a1[21] == v11 )
          a1[21] = v15;
        *(_DWORD *)a1[21] = *(_DWORD *)a1[21] & 7 | (8 * (*(_DWORD *)a1[21] >> 3) - 8);
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(a1 + 22, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v12 = 0;
    }
    v17 = KfLowerIrql(v28);
    v18 = a2;
    SMKM_STORE_MGR<SM_TRAITS>::SmIoCtxWorkItemComplete(v11, HIDWORD(v17), a2, a4);
    v19 = v11 + 1;
    v20 = v11[1];
    __dmb(0xBu);
    v24 = v20;
    do
    {
      v21 = v24;
      __dmb(0xBu);
      v25 = v24 ^ (v24 ^ (((v24 >> 8) - 1) << 8)) & 0xFF00;
      if ( (v25 & 0xFF00) == 256 || a4 < 0 )
        v25 |= 0x40000u;
      __dmb(0xBu);
      __dmb(0xBu);
      do
        result = __ldrex(v19);
      while ( result == v21 && __strex(v25, v19) );
      __dmb(0xBu);
      v24 = result;
      __dmb(0xBu);
      __dmb(0xBu);
    }
    while ( result != v21 );
    v10 = result;
  }
  if ( (v10 & 0xFF00) == 256 )
    result = SMKM_STORE_MGR<SM_TRAITS>::SmWorkItemFree(result, v18, v11, 0);
  return result;
}
