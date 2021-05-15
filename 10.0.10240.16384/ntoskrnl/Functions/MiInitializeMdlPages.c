// MiInitializeMdlPages 
 
int __fastcall MiInitializeMdlPages(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r5
  int v8; // r6
  int v9; // r4
  int v10; // r7
  _DWORD *v11; // r0
  _DWORD *v13; // r4
  _DWORD *v14; // r9
  int v15; // lr
  _DWORD *v16; // r5
  _DWORD *v17; // r4
  BOOL v18; // r1
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r0
  _DWORD *v23; // r0
  bool v24; // zf
  _DWORD *v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r0
  int v29; // r2
  int v30; // r1
  _DWORD *v31; // r3
  unsigned __int8 *v32; // r1
  int v33; // r3
  unsigned int v34; // r2
  int v35; // r0
  int v36; // r4
  _DWORD *v37; // [sp+0h] [bp-50h]
  _DWORD *v38; // [sp+4h] [bp-4Ch]
  int v39; // [sp+4h] [bp-4Ch]
  _DWORD *v40; // [sp+8h] [bp-48h]
  int v41; // [sp+Ch] [bp-44h]
  _DWORD *v42; // [sp+10h] [bp-40h]
  BOOL v44; // [sp+18h] [bp-38h]
  int v45; // [sp+1Ch] [bp-34h]
  int v46; // [sp+20h] [bp-30h]
  int v48; // [sp+28h] [bp-28h]
  int v50; // [sp+30h] [bp-20h]

  v6 = a2;
  v8 = *(_DWORD *)(a2 + 20) >> 12;
  v9 = dword_633818;
  v10 = 0;
  v50 = dword_633818;
  if ( a6 == 1 )
  {
    v28 = ExAllocatePoolWithTag(512, 16 * dword_633818, 1818520909);
    v10 = v28;
    if ( v28 )
    {
      if ( v9 )
      {
        v29 = v28;
        v30 = v9;
        do
        {
          *(_DWORD *)(v29 + 8) = 0;
          *(_DWORD *)(v29 + 12) = 0xFFFFF;
          v29 += 16;
          --v30;
        }
        while ( v30 );
      }
    }
  }
  v41 = 0;
  v11 = (_DWORD *)(v6 + 28);
  v37 = (_DWORD *)(v6 + 28);
  if ( (a4 & 0x80000200) != 0 )
    return sub_513650();
  v13 = 0;
  v38 = 0;
  v40 = 0;
  v42 = 0;
  v14 = 0;
  v15 = a5;
  v46 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  if ( v8 )
  {
    v45 = v8;
    v16 = 0;
    while ( 1 )
    {
      v17 = (_DWORD *)(MmPfnDatabase + 24 * *v11);
      v18 = v17[2] == 0;
      v44 = v18;
      v17[5] = v17[5] & 0xF7FFFFFD | 0xFFFFD;
      *v17 = v46;
      v39 = 0;
      if ( v8 != a3 && (a4 & 4) != 0 )
        goto LABEL_9;
      if ( v15 != 3 || v18 || (a4 & 1) != 0 )
        break;
      v39 = 1;
      if ( MiPageAttributeBatchChangeNeeded(v17, 1) != 1 )
      {
        v25 = v42;
        v42 = v17;
LABEL_34:
        v17[2] = v25;
        goto LABEL_9;
      }
      v17[2] = v16;
      v16 = v17;
LABEL_9:
      v48 = KfRaiseIrql(2);
      v19 = (unsigned __int8 *)v17 + 15;
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x80, v19) );
      __dmb(0xBu);
      if ( v20 >> 7 )
      {
        v32 = (unsigned __int8 *)v17 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v33 = v17[3];
            __dmb(0xBu);
          }
          while ( (v33 & 0x80000000) != 0 );
          do
            v34 = __ldrex(v32);
          while ( __strex(v34 | 0x80, v32) );
          __dmb(0xBu);
        }
        while ( v34 >> 7 );
      }
      MiInitializeMdlPfn(v17, a4);
      __dmb(0xBu);
      v21 = v17 + 3;
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 & 0x7FFFFFFF, v21) );
      KfLowerIrql(v48);
      if ( v44 || (a4 & 1) != 0 )
      {
        v23 = v37;
      }
      else
      {
        v23 = v37;
        ++v41;
        if ( v10 )
        {
          v26 = v10 + 16 * (dword_633814 & *v37 | (v17[5] >> 28 << byte_6337F5));
          *v17 = *(_DWORD *)(v26 + 12);
          v27 = *(_DWORD *)(v26 + 8);
          *(_DWORD *)(v26 + 12) = v17;
          *(_DWORD *)(v26 + 8) = v27 + 1;
        }
        else
        {
          *v17 = v14;
          v14 = v17;
        }
      }
      if ( !v39 )
        v17[2] = 128;
      v11 = v23 + 1;
      v37 = v11;
      v24 = v45 == 1;
      v15 = a5;
      --v45;
      if ( v24 )
      {
        v38 = v16;
        v6 = a2;
        v13 = v38;
        goto LABEL_22;
      }
    }
    if ( MiPageAttributeBatchChangeNeeded(v17, v15) != 1 )
      goto LABEL_9;
    v39 = 1;
    v25 = v40;
    v40 = v17;
    goto LABEL_34;
  }
LABEL_22:
  if ( v8 != a3 && (a4 & 4) != 0 )
  {
    if ( !v8 )
      goto LABEL_58;
    MiFreePagesFromMdl(a1, v6, a4 < 0, 0x80000000);
    v8 = 0;
  }
  if ( v8 )
  {
    if ( v40 )
      MiChangePageAttributeBatch(v40, a5, 128);
    if ( v13 )
      MiChangePageAttributeBatch(v13, 1, -1);
    if ( v41 )
    {
      if ( v10 )
      {
        MiZeroInParallel(v10, v50, a4);
        ExFreePoolWithTag(v10, 0);
      }
      else if ( v14 )
      {
        do
        {
          MiZeroPhysicalPage(((int)v14 - MmPfnDatabase) / 24, 3, *((unsigned __int8 *)v14 + 18) >> 6);
          v31 = (_DWORD *)*v14;
          *v14 = v46;
          v14 = v31;
        }
        while ( v31 );
        v6 = a2;
        v13 = v38;
      }
      if ( v13 )
        MiChangePageAttributeBatch(v13, 3, 128);
      if ( v42 )
        MiChangePageAttributeBatch(v42, 3, 128);
    }
    if ( (unsigned int)(a3 - v8) > 0x1000 )
    {
      v35 = ExAllocatePoolWithTag(512, 4 * (v8 + 7), 1768189261);
      v36 = v35;
      if ( v35 )
      {
        *(_DWORD *)v35 = 0;
        *(_WORD *)(v35 + 6) = 0;
        *(_DWORD *)(v35 + 16) = 0;
        *(_DWORD *)(v35 + 20) = v8 << 12;
        *(_DWORD *)(v35 + 24) = 0;
        *(_WORD *)(v35 + 4) = 4 * (((unsigned int)((v8 << 12) + 4095) >> 12) + 7);
        memmove(v35 + 28, v6 + 28, 4 * v8);
        ExFreePoolWithTag(v6, 0);
        v6 = v36;
      }
    }
    *(_DWORD *)(v6 + 8) = 0;
    *(_WORD *)(v6 + 6) |= 2u;
    if ( (dword_682604 & 1) != 0 )
      MiLogMdlRangeEvent(v6 + 28, 632, v8);
    return v6;
  }
LABEL_58:
  if ( v10 )
    ExFreePoolWithTag(v10, 0);
  ExFreePoolWithTag(v6, 0);
  return 0;
}
