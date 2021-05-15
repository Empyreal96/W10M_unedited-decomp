// MiInsertPageInFreeOrZeroedList 
 
int __fastcall MiInsertPageInFreeOrZeroedList(int a1, char a2)
{
  int v2; // r7
  int v3; // r5
  int v5; // r3
  int v6; // r1
  int v7; // r2
  int v8; // r3
  char v9; // r0
  int v10; // r1
  unsigned int v11; // lr
  unsigned int v12; // r2
  int v13; // r4
  int v14; // r9
  int v15; // r1
  unsigned int v16; // r8
  unsigned int v17; // r8
  unsigned int v18; // r8
  unsigned int *v19; // r1
  unsigned int v20; // r0
  _DWORD *v21; // r8
  unsigned int *v22; // r4
  unsigned int v23; // r1
  _DWORD *v24; // r4
  int v25; // r3
  unsigned int v26; // r4
  unsigned int v27; // r4
  int v28; // r0
  unsigned int *v29; // r1
  unsigned int *v30; // r2
  int result; // r0
  unsigned int v32; // r1
  int v33; // r3
  __int16 j; // lr
  _DWORD *v35; // r0
  char v36; // r2
  __int16 v37; // r9
  unsigned int v38; // r1
  int i; // r3
  _DWORD *v40; // r8
  int v41; // r0
  unsigned int *v42; // r1
  unsigned int *v43; // r2
  int v44; // r3
  char *v45; // r4
  int v46; // r0
  unsigned int *v47; // r1
  int *v48; // r0
  unsigned int *v49; // r2
  unsigned int v50; // r0
  int v51; // [sp+Ch] [bp-5Ch]
  int v52; // [sp+10h] [bp-58h]
  int v53; // [sp+14h] [bp-54h]
  unsigned int v54; // [sp+18h] [bp-50h]
  unsigned int v55; // [sp+18h] [bp-50h]
  int *v56; // [sp+1Ch] [bp-4Ch]
  char v58[8]; // [sp+28h] [bp-40h] BYREF
  int v59; // [sp+30h] [bp-38h] BYREF
  unsigned int *v60; // [sp+34h] [bp-34h]
  int var28[11]; // [sp+40h] [bp-28h] BYREF

  v2 = a1;
  v3 = MmPfnDatabase + 24 * a1;
  *(_DWORD *)(v3 + 12) &= 0xBFFFFFFF;
  if ( (a2 & 1) != 0 )
  {
    v56 = &dword_63FB80;
    if ( (MiFlags & 0x80) != 0 )
      return sub_5338D4();
    v5 = 0;
  }
  else
  {
    v56 = &dword_63FC00;
    v5 = 1;
  }
  v52 = v5;
  if ( (*(_BYTE *)(v3 + 23) & 7) == 3 )
  {
    if ( MiGetPagePrivilege(v3, 1, v58) )
    {
      v55 = (int)((unsigned __int64)(715827883i64 * (v3 - MmPfnDatabase)) >> 32) >> 2;
      if ( KeSetPagePrivilege() < 0 )
        KeBugCheckEx(26, 333067, v55 + (v55 >> 31));
    }
    *(_DWORD *)(v3 + 20) &= 0xF8FFFFFF;
  }
  __dmb(0xFu);
  v6 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v7 = (*(_DWORD *)(v3 + 12) ^ (v6 << 20)) & 0xF00000;
  v8 = *(_DWORD *)(v3 + 4);
  v9 = *(_BYTE *)(v3 + 19) & 0xF8;
  v10 = *(_DWORD *)(v3 + 20);
  *(_DWORD *)(v3 + 12) ^= v7;
  v11 = v10 & 0xF8FFFFFF;
  *(_DWORD *)(v3 + 20) = v10 & 0xF8FFFFFF;
  *(_BYTE *)(v3 + 19) = v9;
  *(_DWORD *)(v3 + 4) = v8 | 0x80000000;
  if ( (v9 & 0x40) != 0 )
    return MiInsertPageInList(v3, 32, v8 | 0x80000000);
  v12 = (v11 >> 28 << byte_6337F5) | dword_633814 & v2;
  v54 = v12;
  v13 = 0;
  v53 = dword_63F718 + 104 * (v12 >> byte_6337F5);
  v14 = v52;
  v51 = dword_63FB0C;
  if ( (a2 & 0x40) == 0 )
  {
    if ( v52 == 1 )
    {
      if ( *(unsigned __int16 *)(dword_63FB0C + 8 * v12 + 4) < dword_6403B4 )
      {
        v37 = 1024;
        v38 = 0;
        for ( i = 0; ; i = 1 )
        {
          v40 = (_DWORD *)(v53 + 4 * i);
          v38 += v40[14];
          if ( (v37 & 0x400) != 0 )
            v38 += (v40[10] + v40[12]) << 10;
          if ( (v37 & 2) != 0 )
            break;
          v37 |= 2u;
        }
        v2 = a1;
        v14 = 1;
        if ( v38 > 0x40 )
          v13 = 1;
      }
      *(_DWORD *)(v3 + 20) = v11 & 0xF7FFFFFF;
      *(_BYTE *)(v3 + 18) &= 0xC7u;
      *(_BYTE *)(v3 + 19) = v9 & 0xDF;
    }
    else
    {
      v15 = dword_63FB08;
      v51 = dword_63FB08;
      if ( *(unsigned __int16 *)(dword_63FB08 + 8 * v12 + 4) >= dword_6403B4 )
        goto LABEL_10;
      v32 = 0;
      v33 = 0;
      for ( j = 1026; ; j |= 2u )
      {
        v35 = (_DWORD *)(v53 + 4 * v33);
        v32 += v35[14];
        if ( (j & 0x400) != 0 )
          v32 += (v35[10] + v35[12]) << 10;
        if ( (j & 2) != 0 )
          break;
        v33 = 1;
      }
      if ( v32 > 0x40 )
        v13 = 1;
    }
  }
  v15 = v51;
LABEL_10:
  if ( v13 != 1 || (unsigned int)dword_640580 < 0x100 )
  {
    do
    {
      v16 = __ldrex((unsigned int *)&dword_640580);
      v17 = v16 + 1;
    }
    while ( __strex(v17, (unsigned int *)&dword_640580) );
    if ( v17 > 0x80 )
    {
LABEL_13:
      v18 = v17 - 1;
      if ( v18 == dword_6402AC || v18 == dword_6402B0 )
        MiUpdateAvailableEvents(MiSystemPartition);
      v19 = (unsigned int *)(v53 + 4 * (v14 + 14));
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
      v21 = (_DWORD *)(*(_DWORD *)&MiSystemPartition[2 * v14 + 512] + 20 * v54);
      v22 = v21 + 4;
      v59 = 0;
      v60 = v21 + 4;
      __dmb(0xBu);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireQueuedSpinLockInstrumented(&v59, v21 + 4);
      }
      else
      {
        do
          v23 = __ldrex(v22);
        while ( __strex((unsigned int)&v59, v22) );
        __dmb(0xBu);
        if ( v23 )
          KxWaitForLockOwnerShip(&v59);
      }
      *(_BYTE *)(v3 + 18) ^= (*(_BYTE *)(v3 + 18) ^ v14) & 7;
      if ( v21[2] == 0xFFFFF )
      {
        *(_DWORD *)(v3 + 12) |= 0xFFFFFu;
        v21[2] = v2;
      }
      else
      {
        v24 = (_DWORD *)(MmPfnDatabase + 24 * v21[3]);
        *(_DWORD *)(v3 + 12) = *(_DWORD *)(v3 + 12) & 0xFFF00000 | (24 * v21[3] / 24) & 0xFFFFF;
        *v24 = v2;
      }
      v25 = *v21;
      v21[3] = v2;
      *v21 = v25 + 1;
      *(_DWORD *)v3 = 0xFFFFF;
      do
      {
        v26 = __ldrex((unsigned int *)v56);
        v27 = v26 + 1;
      }
      while ( __strex(v27, (unsigned int *)v56) );
      if ( (dword_682604 & 0x10000) != 0 )
      {
        result = KiReleaseQueuedSpinLockInstrumented(&v59);
        goto LABEL_31;
      }
      v28 = v59;
      if ( !v59 )
      {
        v29 = v60;
        __dmb(0xBu);
        v30 = (unsigned int *)&v59;
        do
          result = __ldrex(v29);
        while ( (int *)result == &v59 && __strex(0, v29) );
        if ( (int *)result == &v59 )
        {
LABEL_31:
          if ( byte_6403B0 || v27 < 8 || v14 != 1 )
            return result;
          KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640280, &v59, v30, (unsigned __int8)byte_6403B0);
          if ( !byte_6403B0 )
          {
            byte_6403B0 = 1;
            KeSetEvent((int)&unk_6403A0, 0, 0);
          }
          if ( (dword_682604 & 0x10000) != 0 )
            return KiReleaseQueuedSpinLockInstrumented(&v59);
          v41 = v59;
          if ( !v59 )
          {
            v42 = v60;
            __dmb(0xBu);
            do
              result = __ldrex(v42);
            while ( (int *)result == &v59 && __strex(0, v42) );
            if ( (int *)result == &v59 )
              return result;
            v41 = KxWaitForLockChainValid(&v59);
          }
          v59 = 0;
          __dmb(0xBu);
          v43 = (unsigned int *)(v41 + 4);
          do
            result = __ldrex(v43);
          while ( __strex(result ^ 1, v43) );
          return result;
        }
        v28 = KxWaitForLockChainValid(&v59);
      }
      v59 = 0;
      __dmb(0xBu);
      v30 = (unsigned int *)(v28 + 4);
      do
        result = __ldrex(v30);
      while ( __strex(result ^ 1, v30) );
      goto LABEL_31;
    }
    if ( v17 == 128 )
    {
      v44 = 1;
    }
    else
    {
      if ( v17 != 2 )
        goto LABEL_13;
      v44 = 0;
    }
    v45 = (char *)&unk_640284 + 20 * v44;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640280, var28, 5 * v44, &unk_640284);
    KeSetEvent((int)v45, 0, 0);
    ++*((_DWORD *)v45 + 4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(var28);
      goto LABEL_13;
    }
    v46 = var28[0];
    if ( !var28[0] )
    {
      v47 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v48 = (int *)__ldrex(v47);
      while ( v48 == var28 && __strex(0, v47) );
      if ( v48 == var28 )
        goto LABEL_13;
      v46 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v49 = (unsigned int *)(v46 + 4);
    do
      v50 = __ldrex(v49);
    while ( __strex(v50 ^ 1, v49) );
    goto LABEL_13;
  }
  v36 = *(_BYTE *)(v3 + 18);
  if ( (v36 & 7) != 5 )
    *(_BYTE *)(v3 + 18) = v36 & 0xF8 | 5;
  return RtlpInterlockedPushEntrySList((unsigned __int64 *)(v15 + 8 * v54), (_DWORD *)v3);
}
