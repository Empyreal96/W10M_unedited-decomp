// MiReturnSystemVa 
 
__int16 *__fastcall MiReturnSystemVa(unsigned int a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // r4
  int v5; // lr
  __int16 *result; // r0
  unsigned int v7; // r2
  unsigned int v8; // r10
  unsigned int v9; // r7
  unsigned int v10; // r1
  unsigned int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r9
  unsigned int v14; // r3
  int v15; // r6
  int v16; // lr
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  int v19; // r2
  int v20; // r0
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // r9
  unsigned int v24; // r1
  unsigned int v25; // r6
  int v26; // lr
  unsigned int v27; // r10
  int v28; // r0
  int v29; // r1
  int v30; // r10
  char *v31; // r4
  unsigned int v32; // r2
  unsigned int v33; // r0
  int *v34; // r1
  int v35; // r6
  unsigned int v36; // r0
  int v37; // r2
  int v38; // r3
  unsigned int *v39; // r2
  unsigned int v40; // r0
  unsigned int v41; // r0
  int v42; // r0
  unsigned int v43; // r6
  unsigned int v44; // r1
  unsigned int v45; // r7
  int v46; // r0
  int v47; // r0
  unsigned int v48; // [sp+8h] [bp-70h]
  unsigned int v50; // [sp+10h] [bp-68h]
  int v51; // [sp+14h] [bp-64h]
  int v52; // [sp+18h] [bp-60h]
  unsigned int v53; // [sp+20h] [bp-58h]
  unsigned int v54; // [sp+24h] [bp-54h]
  unsigned int v56; // [sp+30h] [bp-48h]
  int v57; // [sp+34h] [bp-44h]
  unsigned int v58; // [sp+38h] [bp-40h]
  int v59; // [sp+40h] [bp-38h] BYREF
  int v60; // [sp+44h] [bp-34h]
  int v61; // [sp+48h] [bp-30h]
  int v62; // [sp+4Ch] [bp-2Ch]
  char var28[44]; // [sp+50h] [bp-28h] BYREF

  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v4 = (a1 >> 10) & 0x3FFFFC;
  v5 = a3;
  result = (__int16 *)((a2 >> 10) & 0x3FFFFC);
  v7 = ((unsigned int)result - 1073741821) & 0xFFFFF000;
  v8 = (v4 - 1073737729) & 0xFFFFF000;
  v58 = v7;
  v53 = v8;
  if ( v8 < v7 )
  {
    v52 = 0;
    v57 = 0;
    v9 = ((v8 >> 10) & 0x3FFFFC) - 0x40000000;
    v10 = (v7 << 10) - (v8 << 10);
    v11 = ((v7 >> 10) & 0x3FFFFC) - 0x40000000;
    v12 = v9;
    v48 = v11;
    v54 = v8 << 10;
    v50 = v10;
    v51 = 0;
    v13 = v9;
    v56 = v9;
    if ( v5 == 1 )
    {
      v51 = 2;
      v37 = __mrc(15, 0, 13, 0, 3);
      v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((v37 & 0xFFFFFFC0) + 0x74) + 324) + 0x2000)
          + 4 * (((v8 << 10) - dword_63389C) >> 22);
      v56 = v12;
      v57 = 1;
      KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_6342BC, (unsigned int)var28);
      v11 = v48;
      v5 = a3;
      v10 = v50;
    }
    if ( a4 )
    {
      MiInsertTbFlushEntry(a4, v9 << 10, v10 >> 22, 0);
      if ( v9 >= v48 )
        goto LABEL_19;
      while ( 1 )
      {
        v14 = *(_DWORD *)(v12 - ((v8 >> 10) & 0x3FFFFC) + 0x40000000 + v13);
        if ( (v14 & 2) != 0 && (v14 & 0x400) == 0 )
        {
          v15 = MmPfnDatabase + 24 * (v14 >> 12);
          v16 = KfRaiseIrql(2);
          v17 = (unsigned __int8 *)(v15 + 15);
          do
            v18 = __ldrex(v17);
          while ( __strex(v18 | 0x80, v17) );
          __dmb(0xBu);
          if ( v18 >> 7 )
            return (__int16 *)sub_54CBB0();
          v19 = *(_DWORD *)(v15 + 12);
          if ( (v19 & 0x3FFFFFFF) != 1 )
          {
            __dmb(0xBu);
            v39 = (unsigned int *)(v15 + 12);
            do
              v40 = __ldrex(v39);
            while ( __strex(v40 & 0x7FFFFFFF, v39) );
            KfLowerIrql(v16);
            goto LABEL_17;
          }
          *(_DWORD *)(v15 + 12) = v19 | 0x40000000;
          v20 = v52;
          v52 = v15;
          *(_BYTE *)(v15 + 18) = *(_BYTE *)(v15 + 18) & 0xF8 | 5;
          *(_DWORD *)v15 = v20;
          __dmb(0xBu);
          v21 = (unsigned int *)(v15 + 12);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 & 0x7FFFFFFF, v21) );
          KfLowerIrql(v16);
        }
        v13 += 4;
LABEL_17:
        if ( v13 >= v48 )
        {
          v12 = v56;
LABEL_19:
          v23 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            v25 = 1552;
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_6342C0);
          }
          else
          {
            do
              v24 = __ldrex((unsigned __int8 *)&dword_6342C0 + 3);
            while ( __strex(v24 | 0x80, (unsigned __int8 *)&dword_6342C0 + 3) );
            __dmb(0xBu);
            v25 = 0x610u;
            if ( v24 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_6342C0);
            while ( 1 )
            {
              v26 = dword_6342C0;
              if ( (dword_6342C0 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (dword_6342C0 & 0x40000000) == 0 )
              {
                do
                  v41 = __ldrex((unsigned int *)&dword_6342C0);
                while ( v41 == v26 && __strex(v26 | 0x40000000, (unsigned int *)&dword_6342C0) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          if ( v9 < v48 )
          {
            v27 = v9 + 1070596096;
            do
            {
              if ( v27 + 3145728 > 0x3FFFFF )
              {
                *(_DWORD *)v9 = 0;
              }
              else
              {
                __dmb(0xBu);
                *(_DWORD *)v9 = 0;
                if ( v27 <= 0xFFF )
                {
                  v28 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v28, (_DWORD *)(v28 + 4 * (v9 & 0xFFF)), 0);
                }
              }
              if ( v51 == 2 )
              {
                if ( v12 < 0xC0000000 || v12 > 0xC03FFFFF )
                {
                  *(_DWORD *)v12 = 0;
                }
                else
                {
                  __dmb(0xBu);
                  *(_DWORD *)v12 = 0;
                  if ( v12 + 1070596096 <= 0xFFF )
                  {
                    v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                    MiArmWriteConvertedHardwarePde(v42, (_DWORD *)(v42 + 4 * (v12 & 0xFFF)), 0);
                  }
                }
                v12 += 4;
              }
              v9 += 4;
              v27 += 4;
            }
            while ( v9 < v48 );
            v8 = v53;
            v25 = 0x610u;
          }
          MiReplicatePteChange(v8, v58 - 4);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&MiState[v25]);
          }
          else
          {
            __dmb(0xBu);
            MiState[v25] = 0;
          }
          KfLowerIrql(v23);
          MiFlushTbList(a4, v29);
LABEL_35:
          v5 = a3;
LABEL_36:
          if ( v5 != 16 )
            goto LABEL_37;
          v30 = 9;
          goto LABEL_38;
        }
      }
    }
    if ( v5 != 1 )
      goto LABEL_36;
    if ( v9 < v11 )
    {
      v43 = ((v8 >> 10) & 0x3FFFFC) - 3145728;
      v44 = v48;
      v45 = v9 - v12;
      do
      {
        if ( *(_DWORD *)v12 == 768 )
        {
          if ( v43 + 3145728 > 0x3FFFFF )
          {
            *(_DWORD *)(v45 + v12) = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)(v45 + v12) = 0;
            if ( v43 <= 0xFFF )
            {
              v46 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v46, (_DWORD *)(v46 + 4 * (((_WORD)v45 + (_WORD)v12) & 0xFFF)), 0);
            }
          }
          if ( v12 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v12 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v12 = 0;
            if ( v12 + 1070596096 <= 0xFFF )
            {
              v47 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v47, (_DWORD *)(v47 + 4 * (v12 & 0xFFF)), 0);
            }
          }
          v44 = v48;
        }
        v12 += 4;
        v43 += 4;
      }
      while ( v45 + v12 < v44 );
      goto LABEL_35;
    }
LABEL_37:
    v30 = a3;
LABEL_38:
    v31 = &byte_63505C[(int)(((v54 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2];
    if ( !v57 )
      KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_6342BC, (unsigned int)var28);
    v32 = v50;
    v33 = 0;
    if ( v50 )
    {
      v34 = &MiState[v31 - byte_63505C];
      do
      {
        if ( (unsigned __int8)*v31 != v30 )
          KeBugCheckEx(26, 8452, v54);
        if ( v30 != 1 || (v38 = v34[319] - 1, (v34[319] = v38) == 0) )
        {
          --MiState[(unsigned __int8)*v31 + 2408];
          dword_635310 += 0x400000;
          if ( v31 >= &byte_63505C[(int)(3072 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2] )
            dword_633890 += 0x400000;
          v32 = v50;
          *v31 = 0;
        }
        v33 += 0x400000;
        ++v31;
        ++v34;
      }
      while ( v33 < v32 );
    }
    KeReleaseInStackQueuedSpinLock((int)var28);
    result = (__int16 *)MiFreeUnmappedPageTables(v52, &v59);
    v35 = v62;
    if ( v62 )
    {
      result = MiSystemPartition;
      if ( dword_640714 )
      {
        MiReturnCommit((int)MiSystemPartition, v62 - v60);
        if ( v51 == 2 )
        {
          MiReturnSessionVaCharges(v35);
          MiReturnResidentAvailable(v35);
          do
            result = (__int16 *)__ldrex(&dword_634A2C[12]);
          while ( __strex((unsigned int)result + v35, &dword_634A2C[12]) );
        }
        else
        {
          do
            v36 = __ldrex(&dword_634D98);
          while ( __strex(v36 - v35, &dword_634D98) );
          MiReturnResidentAvailable(v35);
          do
            result = (__int16 *)__ldrex(&dword_634A2C[11]);
          while ( __strex((unsigned int)result + v35, &dword_634A2C[11]) );
        }
      }
    }
  }
  return result;
}
