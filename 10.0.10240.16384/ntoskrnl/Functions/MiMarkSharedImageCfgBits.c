// MiMarkSharedImageCfgBits 
 
int __fastcall MiMarkSharedImageCfgBits(int *a1, int a2)
{
  int v3; // r5
  int v4; // r1
  unsigned int v5; // r6
  int v6; // r3
  _DWORD *v7; // r4
  unsigned int v8; // r10
  int v9; // r4
  unsigned int *v10; // r5
  int v11; // r7
  int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r8
  unsigned int *v15; // r3
  unsigned int v16; // r6
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r4
  unsigned int v20; // r8
  unsigned int v21; // r10
  unsigned int v22; // r1
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  unsigned int v26; // r1
  unsigned int v27; // r2
  int v28; // r7
  int v29; // r4
  unsigned int v30; // r1
  unsigned int v31; // r1
  unsigned int v32; // r2
  _DWORD *v34; // [sp+10h] [bp-50h]
  unsigned int v35; // [sp+14h] [bp-4Ch]
  int v36; // [sp+18h] [bp-48h]
  int v37; // [sp+1Ch] [bp-44h]
  unsigned int v38; // [sp+20h] [bp-40h]
  int v39; // [sp+28h] [bp-38h] BYREF
  int v40; // [sp+2Ch] [bp-34h] BYREF
  _DWORD var30[13]; // [sp+30h] [bp-30h] BYREF

  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v36 = v3;
  v37 = MiGetControlAreaCfg(**(_DWORD **)(a2 + 44));
  v5 = 2 * ((unsigned int)(((*(_DWORD *)(v4 + 16) + 1) << 12) - (*(_DWORD *)(v4 + 12) << 12)) >> 4);
  v6 = *a1;
  v7 = (_DWORD *)a1[2];
  v8 = v6 + ((2 * ((*(_DWORD *)(v4 + 12) << 8) & 0xFFFFFFFu)) >> 3);
  v34 = v7;
  v35 = v8;
  MiLockNestedVad(v7);
  if ( MiVadDeleted((int)v7) )
  {
    v9 = -1073741558;
  }
  else
  {
    v10 = (unsigned int *)(v3 + 492);
    v11 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v10);
    }
    else
    {
      v12 = *v10 & 0x7FFFFFFF;
      do
        v13 = __ldrex(v10);
      while ( v13 == v12 && __strex(v12 + 1, v10) );
      __dmb(0xBu);
      if ( v13 != v12 )
        ExpWaitForSpinLockSharedAndAcquire(v10);
    }
    v38 = v8 + (v5 >> 3);
    v14 = v38 | 0xFFF;
    v15 = 0;
    v16 = v8 & 0xFFFFF000;
    var30[0] = 0;
    var30[1] = 0;
    var30[2] = 0;
    if ( (v8 & 0xFFFFF000) <= (v38 | 0xFFF) )
    {
      while ( 1 )
      {
        v17 = MiIsCfgBitMapPageShared(v16, v7, v11, v15);
        v18 = v17;
        if ( v17 != 1 )
        {
          if ( v17 == 3 || v17 == 2 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v10);
            }
            else
            {
              __dmb(0xBu);
              do
                v26 = __ldrex(v10);
              while ( __strex(v26 & 0xBFFFFFFF, v10) );
              __dmb(0xBu);
              do
                v27 = __ldrex(v10);
              while ( __strex(v27 - 1, v10) );
            }
            KfLowerIrql(v11);
            if ( v18 == 3 )
            {
              v28 = v16 | 0x3FFFFF;
              if ( (v16 | 0x3FFFFF) > v14 )
                v28 = v14;
            }
            else
            {
              v28 = v16 | 0xFFF;
            }
            v9 = MiSetProtectionOnSection(v36, v34, v16, v28, 2u, 0, &v40, &v39);
            if ( v9 < 0 )
              goto LABEL_63;
            v16 = v28 - 4095;
            v11 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v10);
            }
            else
            {
              v15 = (unsigned int *)*v10;
              v29 = *v10 & 0x7FFFFFFF;
              do
              {
                v30 = __ldrex(v10);
                if ( v30 != v29 )
                  break;
                v15 = (unsigned int *)__strex(v29 + 1, v10);
              }
              while ( v15 );
              __dmb(0xBu);
              if ( v30 != v29 )
                ExpWaitForSpinLockSharedAndAcquire(v10);
            }
          }
          else
          {
            v19 = v8 - v16;
            if ( v16 >= v8 )
              v19 = 0;
            if ( v16 + 4096 <= v38 )
            {
              v20 = 4096 - v19;
            }
            else
            {
              v20 = v38 - v19 - v16;
              if ( v38 - v19 == v16 )
                break;
            }
            v21 = (v19 - v8 + v16) >> 1;
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v10);
            }
            else
            {
              __dmb(0xBu);
              do
                v22 = __ldrex(v10);
              while ( __strex(v22 & 0xBFFFFFFF, v10) );
              __dmb(0xBu);
              do
                v23 = __ldrex(v10);
              while ( __strex(v23 - 1, v10) );
            }
            KfLowerIrql(v11);
            v9 = MiCopyToCfgBitMap(v19 + v16, v34, v37, v21 << 7, var30, v20, 0);
            if ( v9 < 0 )
              goto LABEL_63;
            v11 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v10);
            }
            else
            {
              v15 = (unsigned int *)*v10;
              v24 = *v10 & 0x7FFFFFFF;
              do
              {
                v25 = __ldrex(v10);
                if ( v25 != v24 )
                  break;
                v15 = (unsigned int *)__strex(v24 + 1, v10);
              }
              while ( v15 );
              __dmb(0xBu);
              if ( v25 != v24 )
                ExpWaitForSpinLockSharedAndAcquire(v10);
            }
            v14 = v38 | 0xFFF;
            v8 = v35;
          }
        }
        v16 += 4096;
        if ( v16 > v14 )
          break;
        v7 = v34;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v10);
    }
    else
    {
      __dmb(0xBu);
      do
        v31 = __ldrex(v10);
      while ( __strex(v31 & 0xBFFFFFFF, v10) );
      __dmb(0xBu);
      do
        v32 = __ldrex(v10);
      while ( __strex(v32 - 1, v10) );
    }
    KfLowerIrql(v11);
    v9 = 0;
  }
LABEL_63:
  MiUnlockNestedVad(v34);
  return v9;
}
