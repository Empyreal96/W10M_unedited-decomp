// KiChooseTargetProcessor 
 
int __fastcall KiChooseTargetProcessor(int a1, int a2, int *a3, _DWORD *a4)
{
  int v4; // r4
  int v5; // r9
  int v7; // r7
  int result; // r0
  int v9; // r5
  int v10; // r6
  int v11; // r4
  int v12; // r8
  int v13; // r1
  unsigned int *v14; // r1
  unsigned int v15; // r2
  int v16; // r8
  int v17; // r7
  int v18; // r8
  int v19; // r8
  int v20; // r7
  int v21; // r7
  int v22; // r3
  unsigned int v23; // r4
  unsigned int v24; // r5
  unsigned int v25; // r1
  int v26; // r2
  bool v27; // cf
  int v28; // r4
  _DWORD *v29; // r0
  unsigned int *v30; // r1
  unsigned int v31; // r2
  _DWORD *v32; // r9
  int v33; // r1
  int v34; // r3
  int v35; // r0
  int v36; // r3
  char v37; // r2
  _DWORD *v38; // r7
  int v39; // r4
  unsigned int *v40; // r5
  int v41; // r8
  int v42; // r0
  unsigned int v43; // r1
  char v44; // r2
  unsigned int *v45; // r1
  unsigned int v46; // r2
  unsigned int v47; // r1
  unsigned int v48; // r2
  int v49; // r0
  int v50; // r5
  int v52; // [sp+4h] [bp-4Ch] BYREF
  _DWORD *v53; // [sp+8h] [bp-48h]
  unsigned int v54; // [sp+Ch] [bp-44h]
  char v55[64]; // [sp+10h] [bp-40h] BYREF

  v4 = a1;
  v5 = *a3;
  v53 = a4;
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = (int)*(&KiProcessorBlock + *(_DWORD *)(a2 + 328));
      if ( (*(_WORD *)(v4 + 1756) & 1) == 0
        || *(_BYTE *)(a2 + 395) != 15 && *(_DWORD *)(a2 + 60) >= (unsigned int)KiShortExecutionCycles )
      {
        result = 0;
        goto LABEL_4;
      }
      v33 = **(_DWORD **)(v4 + 2360) & v5;
      v52 = v33;
      if ( !v33 )
        break;
      v34 = *(_DWORD *)(v4 + 3476) & v33;
      if ( v34 )
      {
        v33 &= *(_DWORD *)(v4 + 3476);
        v52 = v34;
      }
      if ( *(_DWORD *)(v4 + 1048) != *(_DWORD *)(v4 + 3468) )
        return sub_52F284();
      if ( (v33 & ~*(_DWORD *)(v4 + 3468)) != 0 )
        v33 &= ~*(_DWORD *)(v4 + 3468);
      v35 = *(_DWORD *)(v4 + 3500);
      if ( *(unsigned __int8 *)(v7 + 1052) == *(unsigned __int8 *)(v4 + 1052)
        && (*(_DWORD *)(v7 + 1048) & *(_DWORD *)(v4 + 3472)) != 0 )
      {
        LOBYTE(v35) = *(_BYTE *)(v7 + 1053);
      }
      result = (int)*(&KiProcessorBlock + (((unsigned __int8)__clz(__rbit(__ROR4__(v33, v35))) + (_BYTE)v35) & 0x1F));
LABEL_4:
      if ( !result )
        break;
LABEL_15:
      v14 = (unsigned int *)(result + 24);
      while ( 1 )
      {
        do
          v15 = __ldrex(v14);
        while ( __strex(1u, v14) );
        __dmb(0xBu);
        if ( !v15 )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( *v14 );
      }
      if ( !*(_BYTE *)(result + 19) )
      {
        *v53 = 1;
        return result;
      }
      __dmb(0xBu);
      *v14 = 0;
    }
    v9 = *(_DWORD *)(v7 + 2360);
    v10 = (int)*(&KiProcessorBlock + *(_DWORD *)(a2 + 364));
    v11 = *(_DWORD *)(v10 + 2360);
    if ( v9 == v11 )
      v12 = v7;
    else
      v12 = 0;
    result = 0;
    v13 = *(_DWORD *)v11 & v5;
    v52 = v13;
    if ( v13 )
    {
      if ( *(_DWORD *)(v10 + 1048) != *(_DWORD *)(v10 + 3468) )
      {
        if ( (*(_DWORD *)(v11 + 4) & v13) != 0 )
        {
          v13 &= *(_DWORD *)(v11 + 4);
        }
        else if ( *(_DWORD *)(a1 + 2360) == v11 )
        {
          KiReduceByEffectiveIdleSmtSet(a1, &v52);
          v13 = v52;
        }
      }
      if ( (v13 & *(_DWORD *)(v10 + 1048)) != 0 )
      {
        result = v10;
      }
      else if ( v12 && (*(_DWORD *)(v12 + 1048) & v13) != 0 )
      {
        result = v12;
      }
      else
      {
        v36 = *(_DWORD *)(v10 + 3468) & v13;
        if ( v36 || v12 && (v36 = *(_DWORD *)(v12 + 3468) & v13) != 0 )
          v13 = v36;
        v37 = *(_BYTE *)(v10 + 1053);
        v54 = __clz(__rbit(__ROR4__(v13, v37)));
        result = (int)*(&KiProcessorBlock + (((_BYTE)v54 + v37) & 0x1F));
      }
    }
    if ( result
      || (v16 = v5 & ~*(_DWORD *)(v11 + 260), v9 != v11) && v16 && (result = KiSelectIdleProcessor(v5, a1, v9, v7)) != 0
      || (v17 = *(_DWORD *)(a1 + 2360), v18 = v16 & ~*(_DWORD *)(v9 + 260), v17 != v11)
      && v17 != v9
      && v18
      && (result = KiSelectIdleProcessor(v5, a1, *(_DWORD *)(a1 + 2360), a1)) != 0 )
    {
LABEL_14:
      v4 = a1;
      goto LABEL_15;
    }
    v19 = v18 & ~*(_DWORD *)(v17 + 260);
    v20 = *(_DWORD *)(v11 + 256) & ~((1 << *(_WORD *)(v11 + 266)) | (1 << *(_WORD *)(v17 + 266)) | (1 << *(_WORD *)(v9 + 266)));
    v52 = 0;
    while ( v19 )
    {
      v49 = MmGetNextNode(*(unsigned __int16 *)(v11 + 266), &v52);
      if ( ((1 << v49) & v20) != 0 )
      {
        v50 = (int)*(&KeNodeBlock + v49);
        result = KiSelectIdleProcessor(v5, a1, v50, 0);
        if ( result )
          goto LABEL_14;
        v19 &= ~*(_DWORD *)(v50 + 260);
      }
    }
    v21 = *(_DWORD *)(v10 + 3456) & v5;
    if ( ((v21 - 1) & v21) != 0 )
    {
      v22 = *(_DWORD *)(v10 + 3460);
      v23 = *(unsigned __int8 *)(v22 + 296);
      v24 = *(unsigned __int8 *)(v22 + 297);
      memmove((int)&v55[v24], v22 + 264, v23);
      v25 = v24 + v23;
      v26 = *(char *)(a2 + 123);
      v27 = v24 >= v24 + v23;
      v28 = -1;
      if ( !v27 )
      {
        do
        {
          if ( ((1 << v24) & v21) != 0 && v55[v24] < v26 )
          {
            v26 = v55[v24];
            v28 = v24;
          }
          ++v24;
        }
        while ( v24 < v25 );
        if ( v28 >= 0 )
          v10 = (int)*(&KiProcessorBlock + v28);
      }
    }
    v29 = *(_DWORD **)(v10 + 2360);
    v30 = (unsigned int *)(v10 + 24);
    while ( 1 )
    {
      do
        v31 = __ldrex(v30);
      while ( __strex(1u, v30) );
      __dmb(0xBu);
      if ( !v31 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v30 );
    }
    if ( (*v29 & v5) == 0 )
      break;
    __dmb(0xBu);
    v4 = a1;
    *v30 = 0;
  }
  v32 = v53;
  *v53 = 0;
  if ( (*(_BYTE *)(v10 + 19) & 2) != 0 )
  {
    __dmb(0xBu);
    *(_DWORD *)(v10 + 24) = 0;
    v38 = *(_DWORD **)(v10 + 2360);
    v39 = v10;
    v40 = v38 + 35;
    v41 = v38[65] & *(_DWORD *)(a2 + 356);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v38 + 35);
    }
    else
    {
      v42 = *v40 & 0x7FFFFFFF;
      do
        v43 = __ldrex(v40);
      while ( v43 == v42 && __strex(v42 + 1, v40) );
      __dmb(0xBu);
      if ( v43 != v42 )
        ExpWaitForSpinLockSharedAndAcquire(v38 + 35);
    }
    if ( (v38[34] & v41) != 0 )
    {
      v44 = *(_BYTE *)(v10 + 1053);
      v54 = __clz(__rbit(__ROR4__(v38[34] & v41, v44)));
      v39 = (int)*(&KiProcessorBlock + (((_BYTE)v54 + v44) & 0x1F));
    }
    v45 = (unsigned int *)(v39 + 24);
    while ( 1 )
    {
      do
        v46 = __ldrex(v45);
      while ( __strex(1u, v45) );
      __dmb(0xBu);
      if ( !v46 )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
      }
      while ( *v45 );
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v38 + 35);
    }
    else
    {
      __dmb(0xBu);
      do
        v47 = __ldrex(v40);
      while ( __strex(v47 & 0xBFFFFFFF, v40) );
      __dmb(0xBu);
      do
        v48 = __ldrex(v40);
      while ( __strex(v48 - 1, v40) );
    }
    v10 = v39;
    if ( (*(_BYTE *)(v39 + 19) & 1) == 0 )
      *v32 = 1;
  }
  return v10;
}
