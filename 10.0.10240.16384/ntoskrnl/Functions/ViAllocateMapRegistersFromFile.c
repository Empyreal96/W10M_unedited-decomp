// ViAllocateMapRegistersFromFile 
 
int __fastcall ViAllocateMapRegistersFromFile(_DWORD *a1, unsigned int a2, int a3, int a4, _DWORD *a5)
{
  unsigned int v5; // r5
  int *v7; // r9
  unsigned int *v8; // r6
  unsigned int v9; // r8
  unsigned int v10; // r7
  unsigned int v11; // r2
  unsigned int v12; // lr
  int *v13; // r4
  int *v14; // r6
  unsigned int v15; // r3
  int v16; // r1
  int v17; // t1
  int v18; // r4
  unsigned int *v19; // r4
  unsigned int *v20; // r9
  int v21; // r0
  unsigned int v22; // r3
  int v23; // r3
  unsigned int v24; // r2
  unsigned int v25; // r3
  unsigned int v27; // [sp+8h] [bp-38h]
  const void *v28; // [sp+10h] [bp-30h]
  int v30; // [sp+1Ch] [bp-24h]
  int vars4; // [sp+44h] [bp+4h]

  v5 = ((a2 & 0xFFF) + a3 + 4095) >> 12;
  v7 = a1 + 12;
  v8 = a1 + 11;
  v27 = a3;
  v9 = a2;
  v10 = 0;
  v30 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v8);
  }
  else
  {
    do
      v11 = __ldrex(v8);
    while ( __strex(1u, v8) );
    __dmb(0xBu);
    if ( v11 )
      KxWaitForSpinLockAndAcquire(v8);
  }
  v12 = v27;
  if ( a1[5] )
  {
    v28 = (const void *)(v9 + v27);
    v13 = v7;
    if ( v7 < &v7[5 * a1[4]] )
    {
      v14 = &v7[5 * a1[4]];
      do
      {
        v15 = *v13;
        if ( *v13 && v15 >= v9 && v15 < (unsigned int)v28 )
        {
          ViHalPreprocessOptions(
            &dword_61877C,
            "Driver is trying to map an address range(%p-%p) that is already mapped    at %p",
            (const void *)0x1D,
            (const void *)v9,
            v28);
          VfReportIssueWithOptions(230, 29, v9, (int)v28, *v13, &dword_61877C);
        }
        v13 += 5;
      }
      while ( v13 < v14 );
      v12 = v27;
      v8 = a1 + 11;
      v10 = 0;
    }
  }
  if ( v5 )
  {
    v16 = 0;
    while ( v16 != a1[4] )
    {
      v17 = *v7;
      v7 += 5;
      if ( v17 )
        v10 = 0;
      else
        ++v10;
      ++v16;
      if ( v10 >= v5 )
        goto LABEL_27;
    }
    ViHalPreprocessOptions(&dword_618780, "Map registers needed: %x available: %x", 0x10000000, 2);
    VfReportIssueWithOptions(230, 0, 2, v5, v10, &dword_618780);
    v18 = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v8, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
  }
  else
  {
    v16 = 0;
LABEL_27:
    v19 = (unsigned int *)&v7[-5 * v5];
    *a5 = v16 - v5;
    if ( v5 )
    {
      v20 = a1 + 5;
      do
      {
        v21 = v9 & 0xFFF;
        v22 = 4096 - v21;
        --v5;
        if ( 4096 - v21 >= v12 )
          v22 = v12;
        *v19 = v9;
        v19[1] = v22;
        if ( a4 )
          v23 = 1;
        else
          v23 = 2;
        v19[2] = v23;
        v19[4] = v9;
        __dmb(0xBu);
        do
          v24 = __ldrex(v20);
        while ( __strex(v24 + 1, v20) );
        __dmb(0xBu);
        ViTagBuffer(v19[3] + v21 + 4096, v19[1], 3);
        v25 = v19[1];
        v19 += 5;
        v12 = v27 - v25;
        v27 -= v25;
        v9 = (v9 + 4096) & 0xFFFFF000;
      }
      while ( v5 );
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v8, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    v18 = 1;
  }
  KfLowerIrql(v30);
  return v18;
}
