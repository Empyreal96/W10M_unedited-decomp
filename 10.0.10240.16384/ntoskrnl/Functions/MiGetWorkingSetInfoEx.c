// MiGetWorkingSetInfoEx 
 
int __fastcall MiGetWorkingSetInfoEx(int a1, unsigned int *a2, unsigned int a3, int a4)
{
  unsigned int *v4; // r5
  int v5; // r6
  _DWORD *v8; // r10
  unsigned int *v9; // r8
  int v10; // r4
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r2
  _DWORD *v16; // r4
  int *v17; // r6
  unsigned int v18; // r2
  unsigned int v19; // r1
  int *v20; // r0
  unsigned int v21; // r1
  int v22; // r2
  int v23; // r2
  unsigned int v24; // r2
  unsigned int v25; // r3
  int v28; // [sp+4h] [bp-4Ch]
  unsigned int *v29; // [sp+8h] [bp-48h]
  int v30; // [sp+Ch] [bp-44h]
  char v32[56]; // [sp+18h] [bp-38h] BYREF

  v4 = (unsigned int *)a1;
  v5 = 0;
  v28 = 0;
  if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
  {
    v5 = a1 - 492;
    if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 - 492 )
    {
      KiStackAttachProcess(a1 - 492, 0, (int)v32);
      v28 = 1;
    }
  }
  v8 = (_DWORD *)v4[23];
  v9 = (unsigned int *)v8[63];
  v30 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v11 = (unsigned __int8 *)v4 + 3;
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v13 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v14 = __ldrex(v4);
        while ( v14 == v13 && __strex(v13 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v5 && (*(_DWORD *)(v5 + 192) & 0x20) != 0 )
  {
    v10 = -1073741558;
    goto LABEL_40;
  }
  v15 = v4[13];
  if ( a4 )
  {
    v16 = a2 + 1;
    v17 = 0;
    *a2 = v15;
    if ( 4 * (v15 + 1) > a3 )
    {
LABEL_21:
      v10 = -1073741820;
      goto LABEL_40;
    }
LABEL_24:
    v29 = (unsigned int *)((char *)v9 + v8[9] * v8[2]);
    do
    {
      v19 = *v9;
      if ( (*v9 & 1) != 0 && (v19 < 0xC0000000 || v19 > 0xC03FFFFF) )
      {
        v20 = (int *)(MmPfnDatabase + 24 * (*(_DWORD *)(((v19 >> 10) & 0x3FFFFC) - 0x40000000) >> 12));
        if ( a4 )
        {
          v21 = v19 & 0xFFFFF000 | *v16 & 0xFFF;
          *v16 = v21;
          v22 = ((unsigned __int16)v21 ^ ((unsigned int)v20[5] >> 28 << 9)) & 0xE00 ^ v21;
          *v16 = v22;
          v23 = v22 ^ ((unsigned __int16)v22 ^ (((v20[5] & 0x8000000) != 0) << 8)) & 0x100;
          *v16 = v23;
          if ( (v20[5] & 0x8000000) != 0 )
          {
            v25 = v20[3] & 0x3FFFFFFF;
            if ( v25 >= 7 )
              LOBYTE(v25) = 7;
            *v16 = ((unsigned __int8)v23 ^ (unsigned __int8)(32 * v25)) & 0xE0 ^ v23;
            *v16 = *v16 & 0xFFFFFFE0 | MiGetPfnProtection((int)v20, v9) & 0x1F;
          }
          else
          {
            v24 = v23 & 0xFFFFFF1F;
            *v16 = v24;
            *v16 = v24 & 0xFFFFFFE0 | ((unsigned int)v20[2] >> 5) & 0x1F;
          }
          ++v16;
        }
        else if ( (v20[5] & 0x8000000) != 0 )
        {
          MiIdentifyPfnWrapper(v20, v17);
          v17[4] = *v9 & 0xFFFFF000;
          v17 += 6;
        }
      }
      v9 = (unsigned int *)((char *)v9 + v8[9]);
    }
    while ( v9 <= v29 );
    v4 = (unsigned int *)a1;
    goto LABEL_39;
  }
  v16 = 0;
  v17 = (int *)(a2 + 2);
  v18 = v15 - v4[14];
  a2[1] = v18;
  if ( 24 * v18 + 8 > a3 )
    goto LABEL_21;
  if ( v18 )
    goto LABEL_24;
LABEL_39:
  v10 = 0;
LABEL_40:
  MiUnlockWorkingSetExclusive((int)v4, v30);
  if ( v28 == 1 )
    KiUnstackDetachProcess((unsigned int)v32, 0);
  return v10;
}
