// MiProtoFault 
 
int __fastcall MiProtoFault(int a1, _BYTE *a2, unsigned int a3, unsigned int a4, int a5, char a6, int **a7)
{
  char v10; // r4
  int v11; // r7
  int v12; // r0
  unsigned int *v14; // r4
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  int v18; // r1
  int v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r8
  int v22; // r4
  _DWORD *v23; // r0
  _DWORD *v24; // r2
  int v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  int v28; // r4
  unsigned int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // lr
  int v32; // r3
  int v33; // r4
  unsigned int v34; // r0
  unsigned int v35; // r1
  _DWORD *v36; // r3
  unsigned int v37; // r0
  unsigned int v38; // r0
  unsigned int v39; // r1
  int *v40; // [sp+8h] [bp-30h] BYREF
  int v41; // [sp+Ch] [bp-2Ch]
  unsigned int v42; // [sp+10h] [bp-28h]
  _DWORD *v43; // [sp+14h] [bp-24h]
  _DWORD *v44; // [sp+18h] [bp-20h]

  v41 = a1;
  v42 = a4;
  __mrc(15, 0, 13, 0, 3);
  v10 = *(_BYTE *)(a1 + 112);
  v11 = 0;
  *a7 = 0;
  if ( (v10 & 7) == 0 && a4 != dword_6337D8 )
  {
    v12 = a5;
    if ( !a5 )
    {
      v12 = MiLocateAddress(a3);
      if ( !v12 )
        return sub_526B40();
    }
    if ( (*(_DWORD *)(v12 + 28) & 0x8000) != 0 )
      KeBugCheckEx(26, 399684, a3);
    MiGetProtoPteAddress(v12, a3 >> 12, 0, &v40);
    v43 = (_DWORD *)*v40;
    v14 = v43 + 9;
    v44 = (_DWORD *)KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v14);
    }
    else
    {
      v15 = (unsigned __int8 *)v14 + 3;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v14);
      while ( 1 )
      {
        v17 = *v14;
        if ( (*v14 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v26 = __ldrex(v14);
          while ( v26 == v17 && __strex(v17 | 0x40000000, v14) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v18 = (int)v43;
    v19 = v43[7];
    ++v43[5];
    if ( (v19 & 0x20) == 0 && *(_DWORD *)(v18 + 32) && (v19 & 0x400) == 0 )
      ++v40[15];
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v14);
    }
    else
    {
      __dmb(0xBu);
      *v14 = 0;
    }
    KfLowerIrql(v44);
    *a7 = v40;
  }
  MiUnlockWorkingSetExclusive(v41, (unsigned __int8)*a2);
  v44 = (_DWORD *)KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v21 = 2304;
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E80);
  }
  else
  {
    do
      v20 = __ldrex((unsigned __int8 *)&dword_634E80 + 3);
    while ( __strex(v20 | 0x80, (unsigned __int8 *)&dword_634E80 + 3) );
    __dmb(0xBu);
    v21 = 0x900u;
    if ( v20 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E80);
    while ( 1 )
    {
      v22 = dword_634E80;
      if ( (dword_634E80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_634E80 & 0x40000000) == 0 )
      {
        do
          v27 = __ldrex((unsigned int *)&dword_634E80);
        while ( v27 == v22 && __strex(v22 | 0x40000000, (unsigned int *)&dword_634E80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v23 = v44;
  *a2 = (_BYTE)v44;
  if ( a6 == 1 )
  {
    v43 = (_DWORD *)((a4 >> 20) & 0xFFC);
    v44 = v43 - 267649024;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&dword_6342C0);
    }
    else
    {
      v28 = dword_6342C0 & 0x7FFFFFFF;
      v29 = (dword_6342C0 & 0x7FFFFFFF) + 1;
      do
        v30 = __ldrex((unsigned int *)&dword_6342C0);
      while ( v30 == v28 && __strex(v29, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      if ( v30 != v28 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_6342C0);
    }
    if ( (*v44 & 2) == 0
      || (*v44 & 0x400) != 0
      || (v31 = v42, v42 < dword_63389C)
      || (v32 = *((unsigned __int8 *)&MiState[2423]
                + ((int)((int)v43 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
          v32 != 6)
      && v32 != 14
      && v32 != 7 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
      }
      else
      {
        __dmb(0xBu);
        do
          v38 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v38 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
        __dmb(0xBu);
        do
          v39 = __ldrex((unsigned int *)&dword_6342C0);
        while ( __strex(v39 - 1, (unsigned int *)&dword_6342C0) );
      }
      MiUnlockWorkingSetExclusive(&MiState[v21], (unsigned __int8)*a2);
      return 0;
    }
    v44 = (_DWORD *)((v42 >> 10) & 0x3FFFFC);
    v33 = *(v44 - 0x10000000);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
      v31 = v42;
    }
    else
    {
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v34 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
      __dmb(0xBu);
      do
        v35 = __ldrex((unsigned int *)&dword_6342C0);
      while ( __strex(v35 - 1, (unsigned int *)&dword_6342C0) );
    }
    if ( (v33 & 2) != 0 )
    {
      if ( (v33 & 0x100) != 0 )
      {
        v36 = (_DWORD *)(unsigned __int8)*a2;
        v24 = v44;
        v37 = v31;
LABEL_66:
        MiCopyOnWriteEx(v37, v24 - 0x10000000, -1, v36, 0);
        goto LABEL_79;
      }
    }
    else
    {
      if ( MiFaultPteIntact(v33) )
        return -1073741802;
      v11 = -1073741819;
    }
LABEL_79:
    MiUnlockWorkingSetExclusive(&MiState[v21], (unsigned __int8)*a2);
    return v11;
  }
  v24 = (_DWORD *)((a4 >> 10) & 0x3FFFFC);
  v25 = *(v24 - 0x10000000);
  if ( (v25 & 2) != 0 )
  {
    if ( (v25 & 0x100) == 0 )
    {
      if ( (v25 & 0x10) == 0 )
        MI_WRITE_VALID_PTE_VOLATILE(v24 - 0x10000000, 1);
      goto LABEL_79;
    }
    v36 = v23;
    v37 = a4;
    goto LABEL_66;
  }
  return -1073741802;
}
