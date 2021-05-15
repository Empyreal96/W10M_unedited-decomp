// MiDeprioritizeVARange 
 
int __fastcall MiDeprioritizeVARange(unsigned int a1, unsigned int a2, unsigned int *a3, int a4)
{
  int v5; // r1
  int v6; // r2
  unsigned int v7; // r4
  unsigned int v8; // r9
  unsigned int v9; // r7
  int v10; // r8
  int result; // r0
  int v12; // r2
  char v13; // r1
  unsigned int v14; // r8
  int v15; // r0
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r1
  unsigned int v20; // r3
  int v21; // r5
  int v22; // r3
  char v23; // r3
  bool v24; // zf
  int v25; // r3
  unsigned __int8 *v26; // r3
  unsigned int v27; // r1
  unsigned __int8 *v28; // r1
  int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // r0
  unsigned int v32; // r0
  int v33; // [sp+0h] [bp-C0h]
  int v34; // [sp+4h] [bp-BCh]
  int v35; // [sp+8h] [bp-B8h]
  unsigned int v36; // [sp+Ch] [bp-B4h]
  int v37; // [sp+10h] [bp-B0h]
  unsigned int varA8[47]; // [sp+18h] [bp-A8h] BYREF
  int varg_r3; // [sp+D4h] [bp+14h]

  varA8[44] = a1;
  varA8[45] = a2;
  varA8[46] = (unsigned int)a3;
  varg_r3 = a4;
  v37 = a4 & 7;
  v5 = (a1 >> 10) & 0x3FFFFC;
  v34 = dword_634484;
  v6 = a3[23];
  v7 = v5 - 0x40000000;
  v8 = v5 - 1073740800;
  v9 = 0;
  v35 = v6;
  v36 = v5 - 1073740800;
  varg_r3 = a4;
  varA8[0] = 0;
  if ( (a4 & 0x10) != 0 )
  {
    v10 = 17;
    v33 = 17;
  }
  else
  {
    v10 = KfRaiseIrql(2);
    v33 = v10;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a3);
    }
    else
    {
      v16 = (unsigned __int8 *)a3 + 3;
      do
      {
        v17 = __ldrex(v16);
        v6 = __strex(v17 | 0x80, v16);
      }
      while ( v6 );
      __dmb(0xBu);
      if ( v17 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(a3);
      while ( 1 )
      {
        v18 = *a3;
        a4 = *a3 & 0xBFFFFFFF;
        if ( a4 == 0x80000000 )
          break;
        if ( (v18 & 0x40000000) == 0 )
        {
          v6 = v18 | 0x40000000;
          do
            v19 = __ldrex(a3);
          while ( v19 == v18 && __strex(v6, a3) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
  result = MiIsAddressValid(v7, 0, v6, a4);
  if ( !result )
    v7 = (v7 & 0xFFFFF000) + 4096;
  if ( v7 < v8 )
  {
    v13 = varg_r3;
    v14 = 0;
    do
    {
      if ( (v7 & 0xFFF) != 0 || (v15 = MiIsAddressValid(v7, 1, v12, v7 & 0xFFF), v13 = varg_r3, v15) )
      {
        v20 = *(_DWORD *)v7;
        if ( (*(_DWORD *)v7 & 2) != 0 )
        {
          v12 = 3 * (v20 >> 12);
          v21 = MmPfnDatabase + 24 * (v20 >> 12);
          if ( *(_DWORD *)v21 )
          {
            if ( (*(_BYTE *)(v21 + 19) & 8) == 0 )
            {
              v22 = *(_DWORD *)(v21 + 4);
              if ( (v22 & 0x80000000) == 0 )
              {
                MiDemoteCombinedPte(v7, v22 | 0x80000000);
                v13 = varg_r3;
              }
              v23 = *(_BYTE *)(v21 + 19);
              v24 = (v23 & 8) == 0;
              v25 = v23 & 7;
              if ( !v24 )
                v25 = 5;
              if ( (v13 & 8) == 0 && v37 != v25 )
              {
                v26 = (unsigned __int8 *)(v21 + 15);
                do
                  v27 = __ldrex(v26);
                while ( __strex(v27 | 0x80, v26) );
                __dmb(0xBu);
                if ( v27 >> 7 )
                {
                  v28 = (unsigned __int8 *)(v21 + 15);
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v29 = *(_DWORD *)(v21 + 12);
                      __dmb(0xBu);
                    }
                    while ( (v29 & 0x80000000) != 0 );
                    do
                      v30 = __ldrex(v28);
                    while ( __strex(v30 | 0x80, v28) );
                    __dmb(0xBu);
                  }
                  while ( v30 >> 7 );
                }
                MiUpdatePfnPriority(v21, v37, 1);
                __dmb(0xBu);
                v12 = v21 + 12;
                do
                  v31 = __ldrex((unsigned int *)v12);
                while ( __strex(v31 & 0x7FFFFFFF, (unsigned int *)v12) );
                v13 = varg_r3;
              }
              if ( (v13 & 0x20) != 0 && v14 >= *(_DWORD *)(a3[23] + 4) )
              {
                v32 = MiLocateWsle(v7 << 10, (int)a3, *(_DWORD *)v21);
                v14 = v32;
                if ( v34 )
                {
                  if ( (*(_DWORD *)v7 & 0x10) != 0 )
                  {
                    v12 = *(_DWORD *)(v35 + 36) * v32;
                    if ( (*(_DWORD *)(v12 + *(_DWORD *)(v35 + 252)) & 0xE00) != 3584 )
                      MiLogPageAccess(a3, v7);
                  }
                }
                varA8[v9 + 1] = v14;
                v9 = varA8[0] + 1;
                varA8[0] = v9;
                if ( v9 == 32 )
                {
                  MiFreeWsleList((int)a3, varA8, 0);
                  v9 = 0;
                  varA8[0] = 0;
                }
                v13 = varg_r3;
              }
            }
          }
        }
      }
      else
      {
        v7 += 4092;
      }
      v7 += 4;
      result = 8;
    }
    while ( v7 < v36 );
    v10 = v33;
    if ( v9 )
      result = MiFreeWsleList((int)a3, varA8, 0);
  }
  if ( v10 != 17 )
    result = MiUnlockWorkingSetExclusive((int)a3, v10);
  return result;
}
