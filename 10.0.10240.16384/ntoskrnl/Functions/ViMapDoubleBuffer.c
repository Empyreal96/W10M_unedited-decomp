// ViMapDoubleBuffer 
 
int __fastcall ViMapDoubleBuffer(int a1, int a2, unsigned int a3, unsigned int a4, unsigned __int8 a5)
{
  int v5; // r5
  int v9; // r2
  int v10; // r1
  int *v11; // r4
  int v12; // r2
  int v13; // r3
  unsigned int *v14; // r9
  unsigned int v15; // r2
  __int16 v16; // r3
  int v17; // r4
  int v18; // r2
  unsigned int v19; // r4
  unsigned int v20; // r7
  int v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r8
  unsigned int v25; // r4
  bool v26; // cf
  const char *v27; // r1
  unsigned int v28; // r3
  unsigned int v30; // r2
  int v31; // [sp+0h] [bp-40h]
  int v32; // [sp+8h] [bp-38h]
  int v33; // [sp+Ch] [bp-34h]
  int v34; // [sp+10h] [bp-30h] BYREF
  int v35; // [sp+14h] [bp-2Ch]
  int v36; // [sp+18h] [bp-28h]
  int v37; // [sp+1Ch] [bp-24h]
  unsigned int v38; // [sp+20h] [bp-20h]
  int vars4; // [sp+44h] [bp+4h]

  v5 = a4;
  if ( !a4 )
  {
    ViHalPreprocessOptions(&dword_61879C, "Driver is attempting to map a 0-length transfer.", 0x21u, a1, 0, 0);
    VfReportIssueWithOptions(230, 33, a1, 0, 0, &dword_61879C);
    return 0;
  }
  if ( !*(_BYTE *)(a1 + 13) && a4 >= 4096 - (a3 & 0xFFF) )
    v5 = 4096 - (a3 & 0xFFF);
  v9 = *(_DWORD *)(a2 + 24);
  v10 = *(_DWORD *)(a2 + 16);
  if ( a3 < v10 + v9 )
  {
    v11 = &dword_618794;
    ViHalPreprocessOptions(&dword_618794, "Virtual address %p is before the first MDL %p.", 0x1000001Fu, 1, a3, a2);
    v12 = 1;
    goto LABEL_8;
  }
  if ( a3 - v10 - v9 >= *(_DWORD *)(a2 + 20) )
  {
    v11 = &dword_618798;
    ViHalPreprocessOptions(&dword_618798, "Virtual address %p is after the first MDL %p.", 0x1000001Fu, 2, a3, a2);
    v12 = 2;
LABEL_8:
    v13 = a3;
    v31 = a2;
LABEL_37:
    VfReportIssueWithOptions(230, 31, v12, v13, v31, v11);
    return 0;
  }
  v14 = (unsigned int *)(a1 + 44);
  v35 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 44);
  }
  else
  {
    do
      v15 = __ldrex(v14);
    while ( __strex(1u, v14) );
    __dmb(0xBu);
    if ( v15 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 44));
  }
  v16 = *(_WORD *)(a2 + 6);
  v36 = 1073741840;
  if ( (v16 & 5) != 0 )
    v17 = *(_DWORD *)(a2 + 12);
  else
    v17 = MmMapLockedPagesSpecifyCache(a2, 0, 1, 0, 0, 1073741840);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 44), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v14 = 0;
  }
  KfLowerIrql(v35);
  if ( !v17 )
    return 0;
  v35 = 1;
  v18 = a3 - *(_DWORD *)(a2 + 24) - *(_DWORD *)(a2 + 16);
  v19 = v17 + v18;
  v32 = v19;
  v20 = *(_DWORD *)(a2 + 20) - v18;
  v38 = v20;
  if ( !ViAllocateMapRegistersFromFile((_DWORD *)a1, v19, v5, a5, &v34) )
    return 0;
  v21 = (v19 & 0xFFF) + (v34 << 12);
  v22 = *(_DWORD *)(a1 + 36) + v21;
  v23 = *(_DWORD *)(a1 + 40);
  v34 = v22;
  if ( !v23 )
    return 0;
  v33 = v23 + v21;
  v24 = a2;
  v25 = v5;
  if ( v5 )
  {
    while ( 1 )
    {
      if ( !v24 )
        return 0;
      if ( !v35 )
        break;
      v35 = 0;
      if ( *(_DWORD *)v24 )
        goto LABEL_41;
      v26 = v25 >= v20;
      if ( v25 > v20 )
      {
        if ( (((v5 - 1) ^ (v20 - v25 + v5)) & 0xFFFFF000) != 0 )
        {
          v27 = "Extra transfer length crosses a page boundary: Mdl %p, Length %x.";
          v11 = (int *)&unk_61878C;
LABEL_36:
          ViHalPreprocessOptions(v11, v27, 0x1000001Fu, 3, a2, v5);
          v12 = 3;
          v13 = a2;
          v31 = v5;
          goto LABEL_37;
        }
LABEL_43:
        v20 = v25;
        goto LABEL_44;
      }
LABEL_42:
      if ( !v26 )
        goto LABEL_43;
LABEL_44:
      memmove(v22, v32, v20);
      v34 += v20;
      memmove(v33, v32, v20);
      v24 = *(_DWORD *)v24;
      v33 += v20;
      if ( v24 )
      {
        v37 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented((int)v14);
        }
        else
        {
          do
            v30 = __ldrex(v14);
          while ( __strex(1u, v14) );
          __dmb(0xBu);
          if ( v30 )
            KxWaitForSpinLockAndAcquire(v14);
        }
        v32 = (*(_WORD *)(v24 + 6) & 5) != 0 ? *(_DWORD *)(v24 + 12) : MmMapLockedPagesSpecifyCache(
                                                                         v24,
                                                                         0,
                                                                         1,
                                                                         0,
                                                                         0,
                                                                         v36);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v14, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v14 = 0;
        }
        KfLowerIrql(v37);
        if ( !v32 )
          return 0;
      }
      v25 -= v20;
      if ( !v25 )
        return v5;
      v20 = v38;
      v22 = v34;
    }
    if ( !*(_DWORD *)v24 )
    {
      v28 = *(_DWORD *)(v24 + 20);
      if ( v25 > v28 )
      {
        if ( (((v5 - 1) ^ (v28 - v25 + v5)) & 0xFFFFF000) != 0 )
        {
          v27 = "Extra transfer length crosses a page boundary: Mdl %p, Length %x";
          v11 = (int *)&unk_618790;
          goto LABEL_36;
        }
        goto LABEL_43;
      }
    }
    v20 = *(_DWORD *)(v24 + 20);
LABEL_41:
    v26 = v25 >= v20;
    goto LABEL_42;
  }
  return v5;
}
