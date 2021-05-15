// MiTranslatePageForCopy 
 
int __fastcall MiTranslatePageForCopy(unsigned int a1, unsigned int **a2, int *a3, int *a4, _BYTE *a5, _DWORD *a6)
{
  unsigned int v6; // lr
  int v7; // r5
  int *v8; // r1
  unsigned int v9; // r3
  int v10; // r0
  int v11; // r2
  unsigned int *v12; // r7
  int v13; // r6
  int v14; // r4
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  unsigned int v19; // r8
  unsigned int *v20; // r4
  unsigned int v21; // r3
  int v22; // r9
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r1
  int v27; // r0
  int v28; // r4
  unsigned int v29; // r1
  unsigned int v30; // r0
  int v31; // r1
  unsigned int v32; // r8
  unsigned int v33; // r0
  unsigned int v34; // r1
  unsigned int v35; // r3
  int v36; // r9
  int v37; // r9
  unsigned int v38; // r1
  unsigned int v39; // r4
  unsigned int v40; // r1
  unsigned int v41; // r0
  int v42; // r3
  int v43; // r0
  unsigned int *v44; // r9
  int v45; // r4
  int v46; // r0
  unsigned int v47; // r3
  int v48; // r8
  int v49; // r0
  int v50; // r1
  char v51; // r3
  int v52; // r1
  unsigned __int8 *v53; // r0
  unsigned int v54; // r2
  int v55; // r3
  unsigned __int8 v57[4]; // [sp+10h] [bp-48h] BYREF
  unsigned int v58; // [sp+14h] [bp-44h]
  unsigned int v59; // [sp+18h] [bp-40h] BYREF
  int v60; // [sp+1Ch] [bp-3Ch] BYREF
  int *v61; // [sp+20h] [bp-38h]
  unsigned int *v62; // [sp+24h] [bp-34h] BYREF
  unsigned int **v63; // [sp+28h] [bp-30h]
  int *v64; // [sp+2Ch] [bp-2Ch]
  int v65[10]; // [sp+30h] [bp-28h] BYREF

  v58 = a1;
  v63 = a2;
  v64 = a3;
  *a6 = 0;
  *a2 = 0;
  v6 = a1;
  *a4 = 0;
  v61 = a4;
  *a5 = 17;
  *a3 = -1;
  if ( a1 + 0x40000000 <= 0x3FFFFF )
    return -1073741585;
  v8 = v65;
  v9 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v10 = 2;
  do
  {
    *v8++ = v9;
    v9 = ((v9 >> 10) & 0x3FFFFC) - 0x40000000;
    --v10;
  }
  while ( v10 );
  v59 = -1;
  v7 = 0;
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v6 < 0xC0400000 || v6 > dword_633894 )
  {
    v13 = 17;
    v57[0] = 17;
    v19 = 0;
    v20 = (unsigned int *)&dword_634E00;
    while ( 1 )
    {
      v21 = v20[23];
      v12 = v20;
      if ( v6 >= v21 && v6 < ((*(_DWORD *)(v21 + 56) + 4095) & 0xFFFFF000) )
        break;
      ++v19;
      v20 += 32;
      if ( v19 >= 3 )
        goto LABEL_39;
    }
    v22 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v20);
    }
    else
    {
      v23 = (unsigned __int8 *)v20 + 3;
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 | 0x80, v23) );
      __dmb(0xBu);
      if ( v24 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v20);
      while ( 1 )
      {
        v25 = *v20;
        if ( (*v20 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v25 & 0x40000000) == 0 )
        {
          do
            v26 = __ldrex(v20);
          while ( v26 == v25 && __strex(v25 | 0x40000000, v20) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v6 = v58;
    v13 = v22;
    v57[0] = v22;
LABEL_39:
    if ( v19 == 3 )
    {
      v27 = MiAcquireProperVm(v6, v57);
      v13 = v57[0];
      v12 = (unsigned int *)v27;
    }
    if ( !v12 )
      return -1073741664;
  }
  else
  {
    v12 = (unsigned int *)(v11 + 492);
    v13 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v12);
    }
    else
    {
      v15 = (unsigned __int8 *)v12 + 3;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v12);
      while ( 1 )
      {
        v17 = *v12;
        if ( (*v12 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v12);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v12) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  v14 = KfRaiseIrql(2);
  v60 = v14;
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
    v14 = v60;
  }
  v31 = 2;
  while ( 1 )
  {
    v32 = *(_DWORD *)v65[--v31];
    v62 = (unsigned int *)v65[v31];
    if ( (v32 & 2) == 0 )
      break;
    if ( v31 == 1 )
    {
      if ( (v32 & 0x400) != 0 )
      {
        v59 = ((unsigned int)v65[0] >> 2) & 0x3FF;
        v31 = 0;
        goto LABEL_54;
      }
    }
    else
    {
LABEL_54:
      if ( !v31 )
        goto LABEL_58;
    }
  }
  if ( v31 )
    v7 = -1073741819;
LABEL_58:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_6342C0);
  }
  else
  {
    __dmb(0xBu);
    do
      v33 = __ldrex((unsigned int *)&dword_6342C0);
    while ( __strex(v33 & 0xBFFFFFFF, (unsigned int *)&dword_6342C0) );
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&dword_6342C0);
    while ( __strex(v34 - 1, (unsigned int *)&dword_6342C0) );
  }
  KfLowerIrql(v14);
  v35 = v59;
  v36 = -1;
  if ( v59 != -1 )
  {
    if ( v12 == (unsigned int *)1 )
    {
      v12 = dword_634F00;
      v37 = KfRaiseIrql(2);
      v60 = v37;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(dword_634F00);
      }
      else
      {
        do
          v38 = __ldrex((unsigned __int8 *)dword_634F00 + 3);
        while ( __strex(v38 | 0x80, (unsigned __int8 *)dword_634F00 + 3) );
        __dmb(0xBu);
        if ( v38 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(dword_634F00);
        while ( 1 )
        {
          v39 = dword_634F00[0];
          if ( (dword_634F00[0] & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_634F00[0] & 0x40000000) == 0 )
          {
            v40 = dword_634F00[0] | 0x40000000;
            do
              v41 = __ldrex(dword_634F00);
            while ( v41 == v39 && __strex(v40, dword_634F00) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        v37 = v60;
      }
      v35 = v59;
      v13 = v37;
      v36 = -1;
    }
    else
    {
      v7 = -1073741819;
    }
LABEL_83:
    if ( v7 < 0 )
    {
      MiUnlockWorkingSetExclusive((int)v12, v13);
      return v7;
    }
    v7 = 0;
    v57[0] = 17;
    if ( (v32 & 2) != 0 )
    {
      v36 = v35 + (v32 >> 12);
      if ( !MI_IS_PFN(v36) )
      {
        v7 = -1073741503;
        goto LABEL_129;
      }
      v52 = MmPfnDatabase + 24 * v36;
      v53 = (unsigned __int8 *)(v52 + 15);
      do
        v54 = __ldrex(v53);
      while ( __strex(v54 | 0x80, v53) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v54 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v55 = *(_DWORD *)(v52 + 12);
          __dmb(0xBu);
        }
        while ( (v55 & 0x80000000) != 0 );
        do
          v54 = __ldrex(v53);
        while ( __strex(v54 | 0x80, v53) );
      }
LABEL_130:
      *v63 = v12;
      *a5 = v13;
      *v64 = v36;
      return v7;
    }
    while ( ((v32 >> 10) & 1) == 0 )
    {
      v42 = (v32 >> 5) & 0x1F;
      if ( v42 == 24 || !v42 )
      {
        v7 = -1073741819;
        goto LABEL_129;
      }
      if ( (v32 & 0x800) == 0 )
      {
        if ( (v32 & 0x10) == 0 )
        {
          MiUnlockWorkingSetExclusive((int)v12, v13);
          goto LABEL_119;
        }
LABEL_95:
        v7 = -1073741608;
        goto LABEL_129;
      }
      v43 = MiLockTransitionLeafPage(v62, (unsigned int)v57);
      if ( v43 )
      {
        if ( (*(_BYTE *)(v43 + 18) & 0x20) == 0 )
        {
          v36 = (v43 - MmPfnDatabase) / 24;
          goto LABEL_130;
        }
        if ( (*(_BYTE *)(v43 + 18) & 8) == 0 )
        {
          v59 = 1;
          MiWaitForCollidedFaultComplete(v43, 0, v58, v12, v13, v57[0], &v59);
        }
        goto LABEL_95;
      }
    }
    v44 = (unsigned int *)((v32 & 0x1FC | (v32 >> 2) & 0x3FFFFE00) - 0x40000000);
    if ( (v32 & 0xFFFFE000) == -8192 )
    {
      v44 = (unsigned int *)MiCheckVirtualAddress(v58, &v60, (int *)&v62);
      if ( !v44 )
      {
LABEL_101:
        v7 = -1073741819;
        goto LABEL_102;
      }
    }
    v45 = MiLockProtoPoolPage((unsigned int)v44, v57);
    if ( !v45 )
    {
LABEL_104:
      v7 = -1073741608;
LABEL_102:
      v36 = -1;
LABEL_129:
      MiUnlockWorkingSetExclusive((int)v12, v13);
      LOBYTE(v13) = 17;
      goto LABEL_130;
    }
    v46 = MiLockLeafPage(v44, 0);
    v47 = *v44;
    v48 = v46;
    if ( (*v44 & 2) != 0 )
    {
LABEL_106:
      v36 = (v46 - MmPfnDatabase) / 24;
      *v61 = v45;
      goto LABEL_130;
    }
    if ( !v47 )
    {
      MiUnlockProtoPoolPage(v45, v57[0]);
      goto LABEL_101;
    }
    if ( (v47 & 0x400) != 0 )
    {
      v49 = v45;
      goto LABEL_111;
    }
    if ( (v47 & 0x800) != 0 )
    {
      v51 = *(_BYTE *)(v46 + 18);
      if ( (v51 & 0x20) == 0 )
        goto LABEL_106;
      v49 = v45;
      if ( (v51 & 8) == 0 )
      {
        MiObtainProtoReference(v45, 1);
        v59 = 1;
        MiWaitForCollidedFaultComplete(v48, v45, v58, v12, v13, v57[0], &v59);
        goto LABEL_104;
      }
LABEL_111:
      v50 = v57[0];
    }
    else
    {
      v50 = v57[0];
      v49 = v45;
      if ( (v47 & 0x10) == 0 )
      {
        MiUnlockProtoPoolPage(v45, v57[0]);
        MiUnlockWorkingSetExclusive((int)v12, v13);
        v36 = -1;
LABEL_119:
        LOBYTE(v13) = 17;
        v12 = 0;
        v7 = 273;
        goto LABEL_130;
      }
    }
    MiUnlockProtoPoolPage(v49, v50);
    goto LABEL_104;
  }
  if ( v12 != (unsigned int *)1 )
  {
    v35 = 0;
    goto LABEL_83;
  }
  return -1073741664;
}
