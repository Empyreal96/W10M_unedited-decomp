// MiDbgCopyMemory 
 
int __fastcall MiDbgCopyMemory(unsigned int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r6
  unsigned int v7; // r10
  int v8; // r8
  int v9; // r4
  int v10; // r3
  int *v11; // r2
  int v12; // r8
  __int64 v13; // r0
  unsigned int v14; // r0
  int v15; // r0
  int *v16; // r0
  int *v17; // r8
  unsigned int v18; // r1
  int v19; // lr
  unsigned int v20; // r0
  __int64 v21; // r0
  int v22; // r2
  __int64 v23; // r0
  int v24; // r0
  unsigned __int8 v26[4]; // [sp+0h] [bp-68h] BYREF
  int v27; // [sp+4h] [bp-64h]
  int *v28; // [sp+8h] [bp-60h]
  int v29; // [sp+Ch] [bp-5Ch]
  int v30; // [sp+10h] [bp-58h]
  int v31; // [sp+14h] [bp-54h]
  int v32; // [sp+18h] [bp-50h]
  int v33; // [sp+1Ch] [bp-4Ch]
  int v34; // [sp+20h] [bp-48h] BYREF
  int v35; // [sp+28h] [bp-40h] BYREF
  int v36; // [sp+2Ch] [bp-3Ch]
  _DWORD _30[20]; // [sp+30h] [bp-38h] BYREF

  _30[17] = a2;
  v6 = a4;
  v34 = a4;
  _30[19] = a4;
  v27 = a3;
  _30[18] = a3;
  v31 = a2;
  v7 = a1;
  _30[16] = a1;
  if ( !a4 )
    return -1073741583;
  v9 = a6;
  v35 = a6 & 0x40;
  if ( (a6 & 0x40) != 0 )
  {
    if ( (a6 & 2) != 0 )
      return -1073741582;
    if ( (a6 & 1) == 0 )
      return -1073741582;
    v10 = 4;
    if ( (a6 & 4) == 0 )
      return -1073741582;
  }
  else
  {
    v10 = 4;
  }
  v28 = 0;
  v32 = 0;
  v29 = 17;
  v26[0] = 17;
  v11 = 0;
  v30 = 0;
  v33 = 0;
  v12 = 1;
  if ( (a6 & 2) != 0 )
  {
    if ( (a6 & 4) != 0 || (unsigned int)KeGetCurrentIrql(a1) <= 1 )
    {
      v13 = MiDbgTranslatePhysicalAddress(v7, v31, a6, _30);
      v36 = HIDWORD(v13);
      v7 = v13;
      if ( !(_DWORD)v13 )
        return -1073741823;
LABEL_57:
      if ( (v9 & 1) != 0 )
      {
        v7 = MiDbgWriteCheck(v7, &v35, v12);
        if ( !v7 )
        {
          v8 = -1073741585;
          goto LABEL_66;
        }
        v30 = 1;
LABEL_61:
        v15 = v27;
LABEL_62:
        v24 = MiCopyToUntrustedMemory(v7, v15, v6, a5);
LABEL_65:
        v8 = v24;
        goto LABEL_66;
      }
LABEL_63:
      v15 = v27;
      goto LABEL_64;
    }
    return -1073741582;
  }
  if ( (a6 & 4) == 0 )
  {
    v14 = KeGetCurrentIrql(a1);
    if ( v14 > 1 )
      return -1073741582;
    v31 = 0;
    if ( v7 < dword_63389C )
    {
      if ( (a6 & 1) != 0 )
      {
        ProbeForWrite(v7, v6, v6);
      }
      else
      {
        if ( ((v6 - 1) & v7) != 0 )
          ExRaiseDatatypeMisalignment(v14);
        if ( v7 + v6 > MmUserProbeAddress || v7 + v6 < v7 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      v15 = v27;
      if ( (a6 & 1) != 0 )
        goto LABEL_62;
LABEL_64:
      v24 = MiCopyFromUntrustedMemory(v15, v7, v6, a5);
      goto LABEL_65;
    }
    v16 = (int *)MiAcquireProperVm(v7, v26);
    v17 = v16;
    v28 = v16;
    if ( !v16 || v16 == (int *)1 )
    {
      v17 = &dword_634F00;
      v28 = &dword_634F00;
      v29 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634F00);
      }
      else
      {
        do
        {
          v18 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
          v11 = (int *)__strex(v18 | 0x80, (unsigned __int8 *)&dword_634F00 + 3);
        }
        while ( v11 );
        __dmb(0xBu);
        if ( v18 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634F00);
        while ( 1 )
        {
          v19 = dword_634F00;
          if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_634F00 & 0x40000000) == 0 )
          {
            v11 = &dword_634F00;
            do
              v20 = __ldrex((unsigned int *)&dword_634F00);
            while ( v20 == v19 && __strex(v19 | 0x40000000, (unsigned int *)&dword_634F00) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        v9 = a6;
        v6 = v34;
        v17 = v28;
      }
    }
    else
    {
      v29 = v26[0];
    }
    v10 = (int)&dword_634F00;
    if ( v17 == &dword_634F00 )
    {
      if ( MiGetPhysicalAddress(v7, &v35, &v34, (int)&dword_634F00) )
      {
        v21 = MiDbgTranslatePhysicalAddress(v35, v36, v9, _30);
        v36 = HIDWORD(v21);
        v7 = v21;
        if ( (_DWORD)v21 )
        {
          v9 |= 2u;
          if ( (v9 & 1) != 0 )
          {
            if ( !v34 )
            {
              v8 = -1073741819;
LABEL_66:
              if ( (v30 & 1) != 0 )
                MiDbgReleaseAddress(v7, &v35, v9);
              if ( (v9 & 2) != 0 )
                MiDbgUnTranslatePhysicalAddress(_30);
              goto LABEL_70;
            }
            goto LABEL_61;
          }
          goto LABEL_63;
        }
        v8 = -1073741823;
      }
      else
      {
        v8 = -1073741819;
      }
      goto LABEL_70;
    }
    v12 = v31;
  }
  if ( MiIsAddressValid(v7, 0, (int)v11, v10) )
  {
    if ( !v35 )
      goto LABEL_57;
    MmGetPhysicalAddress((int)&v35, v7, v22, v35);
    v23 = MiDbgTranslatePhysicalAddress(v35, v36, v9, _30);
    v36 = HIDWORD(v23);
    v7 = v23;
    if ( (_DWORD)v23 )
    {
      v9 |= 2u;
      goto LABEL_57;
    }
    v8 = -1073741823;
  }
  else
  {
    v8 = -1073741585;
  }
LABEL_70:
  if ( v28 )
    MiUnlockWorkingSetExclusive((int)v28, v29);
  return v8;
}
