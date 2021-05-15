// MiSessionRemoveImage 
 
int __fastcall MiSessionRemoveImage(int a1, _DWORD *a2)
{
  int v2; // r6
  int v5; // r7
  int v6; // r10
  unsigned int *v7; // r5
  _DWORD *v8; // r0
  _DWORD *v9; // r4
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r1
  int v14; // r3
  _DWORD *v15; // r2
  _DWORD *v16; // r1
  _DWORD *i; // r3
  int v18; // r3
  int v19; // r3
  unsigned int v20; // r2
  _DWORD *v21; // r1
  _DWORD *j; // r3
  int v23; // r3
  unsigned int v24; // r3
  char v26[4]; // [sp+8h] [bp-68h] BYREF
  int v27; // [sp+Ch] [bp-64h]
  int v28[24]; // [sp+10h] [bp-60h] BYREF

  v2 = *(_DWORD *)(a1 + 24);
  *a2 = 0;
  v5 = 0;
  v6 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
  v7 = (unsigned int *)(v6 + 3248);
  v27 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v6 + 3248));
  }
  else
  {
    v10 = (unsigned __int8 *)(v6 + 3251);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 | 0x80, v10) );
    __dmb(0xBu);
    if ( v11 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v6 + 3248));
    while ( 1 )
    {
      v12 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v12 & 0x40000000) == 0 )
      {
        do
          v13 = __ldrex(v7);
        while ( v13 == v12 && __strex(v12 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MmLockLoadedModuleListExclusive(v26);
  v8 = MiSessionLookupImage(v2);
  v9 = v8;
  if ( !v8 )
    KeBugCheckEx(26, 8448, a1, v2, 0);
  v14 = v8[8] - 1;
  v8[8] = v14;
  if ( !v14 )
  {
    v15 = (_DWORD *)*v8;
    v16 = v8;
    if ( *v8 )
    {
      for ( i = (_DWORD *)v15[1]; i; i = (_DWORD *)i[1] )
        v15 = i;
    }
    else
    {
      v18 = v8[2];
      while ( 1 )
      {
        v15 = (_DWORD *)(v18 & 0xFFFFFFFC);
        if ( (v18 & 0xFFFFFFFC) == 0 || (_DWORD *)v15[1] == v16 )
          break;
        v18 = v15[2];
        v16 = v15;
      }
    }
    if ( v15 )
      v19 = v15[6];
    else
      v19 = 0;
    v20 = v8[1];
    *a2 = v19;
    v21 = v8;
    if ( v20 )
    {
      for ( j = *(_DWORD **)v20; j; j = (_DWORD *)*j )
        v20 = (unsigned int)j;
    }
    else
    {
      v23 = v8[2];
      while ( 1 )
      {
        v20 = v23 & 0xFFFFFFFC;
        if ( (v23 & 0xFFFFFFFC) == 0 || *(_DWORD **)v20 == v21 )
          break;
        v23 = *(_DWORD *)(v20 + 8);
        v21 = (_DWORD *)v20;
      }
    }
    if ( v20 )
      v24 = *(_DWORD *)(v20 + 20) & 0xFFFFFFFC;
    else
      v24 = 0;
    a2[1] = v24;
    RtlAvlRemoveNode(v6 + 68, (int)v8);
    v5 = 1;
  }
  MmUnlockLoadedModuleListExclusive((unsigned __int8)v26[0]);
  MiUnlockWorkingSetExclusive(v6 + 3248, v27);
  if ( !v5 )
    return 0;
  v28[0] = v9[11];
  MiManageSubsectionView(v28, (int)(v9 + 3), 4);
  a2[2] = v9[10];
  if ( *((_BYTE *)v9 + 36) == 1 )
    MiHandleDriverNonPagedSections(a1, 0, 0);
  ExFreePoolWithTag(v9);
  return 1;
}
