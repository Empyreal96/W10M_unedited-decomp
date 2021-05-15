// ExIsResourceAcquiredSharedLite 
 
int __fastcall ExIsResourceAcquiredSharedLite(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r6
  unsigned int v6; // r5
  unsigned int v8; // r7
  unsigned int *v9; // r8
  unsigned int v10; // r1
  int v11; // r2
  unsigned int v12; // r0
  unsigned int v13; // r3
  int v14; // r0
  unsigned int *v15; // r1
  int *v16; // r0
  int v17; // r1
  int v18; // t1
  unsigned int *v19; // r2
  unsigned int v20; // r4
  int v21; // [sp+0h] [bp-28h] BYREF
  unsigned int *v22; // [sp+4h] [bp-24h]
  int v23; // [sp+8h] [bp-20h]
  int v24; // [sp+Ch] [bp-1Ch]
  int vars4; // [sp+2Ch] [bp+4h]

  v21 = a1;
  v22 = (unsigned int *)a2;
  v23 = a3;
  v24 = a4;
  if ( !*(_DWORD *)(a1 + 32) )
    return 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(a1 + 24) == v5 )
    return *(_DWORD *)(a1 + 28) >> 2;
  if ( (*(_WORD *)(a1 + 14) & 0x80) != 0 )
    return 0;
  v8 = *(unsigned __int8 *)(v5 + 401);
  v9 = (unsigned int *)(a1 + 52);
  v21 = 0;
  v22 = (unsigned int *)(a1 + 52);
  v6 = 0;
  __dmb(0xBu);
  LOBYTE(v23) = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) == 0 )
  {
    do
      v10 = __ldrex(v9);
    while ( __strex((unsigned int)&v21, v9) );
    __dmb(0xBu);
    if ( v10 )
      KxWaitForLockOwnerShip(&v21);
    v11 = *(_DWORD *)(a1 + 8);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 4);
      if ( v8 < v12 && *(_DWORD *)(v11 + 8 * v8) == v5 )
      {
        v13 = *(_DWORD *)(v11 + 8 * v8 + 4);
LABEL_16:
        v6 = v13 >> 2;
        goto LABEL_17;
      }
      v17 = 1;
      if ( v12 > 1 )
      {
        while ( 1 )
        {
          v18 = *(_DWORD *)(v11 + 8);
          v11 += 8;
          if ( v18 == v5 )
            break;
          if ( ++v17 >= v12 )
            goto LABEL_17;
        }
        v13 = *(_DWORD *)(v11 + 4);
        goto LABEL_16;
      }
    }
LABEL_17:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v21, vars4);
    }
    else
    {
      v14 = v21;
      if ( !v21 )
      {
        v15 = v22;
        __dmb(0xBu);
        do
          v16 = (int *)__ldrex(v15);
        while ( v16 == &v21 && __strex(0, v15) );
        if ( v16 == &v21 )
          goto LABEL_23;
        v14 = KxWaitForLockChainValid(&v21);
      }
      v21 = 0;
      __dmb(0xBu);
      v19 = (unsigned int *)(v14 + 4);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 ^ 1, v19) );
    }
LABEL_23:
    KfLowerIrql((unsigned __int8)v23);
    return v6;
  }
  return sub_51C974();
}
