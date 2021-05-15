// NtGetWriteWatch 
 
int __fastcall NtGetWriteWatch(int a1, int a2, unsigned int a3, unsigned int a4, _DWORD *a5, int *a6, _DWORD *a7)
{
  int v9; // r2
  int v10; // r4
  unsigned int v11; // r3
  int v12; // r9
  int v13; // r8
  int *v14; // r2
  _DWORD *v15; // r2
  unsigned int v16; // r1
  int *v17; // r3
  int v18; // r5
  int v19; // r0
  unsigned int v20; // r8
  unsigned int v21; // r4
  unsigned int v22; // r9
  _DWORD *v23; // r0
  _DWORD *v24; // r2
  unsigned int v25; // r8
  unsigned int *v26; // r6
  unsigned int v27; // r1
  unsigned __int8 *v28; // r3
  unsigned int v29; // r0
  int v30; // r0
  int v31; // r6
  int *v32; // r2
  unsigned int v33; // r0
  int v34; // r6
  int v35; // r9
  int v36; // r10
  int v37; // r2
  int v38; // r6
  unsigned int v39; // r3
  int v40; // r0
  int *v41; // r2
  int *v42; // r5
  int v43; // r6
  _DWORD *v45; // [sp+10h] [bp-528h] BYREF
  int v46; // [sp+14h] [bp-524h]
  char v47; // [sp+18h] [bp-520h]
  int v48; // [sp+1Ch] [bp-51Ch]
  int *v49; // [sp+20h] [bp-518h]
  int v50; // [sp+24h] [bp-514h] BYREF
  int *v51; // [sp+28h] [bp-510h]
  int v52; // [sp+2Ch] [bp-50Ch]
  unsigned int v53; // [sp+30h] [bp-508h]
  int v54; // [sp+34h] [bp-504h]
  int *v55; // [sp+38h] [bp-500h]
  int v56; // [sp+3Ch] [bp-4FCh]
  _DWORD *v57; // [sp+40h] [bp-4F8h]
  unsigned int v58; // [sp+44h] [bp-4F4h]
  int *v59; // [sp+48h] [bp-4F0h]
  _DWORD *v60; // [sp+4Ch] [bp-4ECh]
  _DWORD *v61; // [sp+50h] [bp-4E8h]
  int v62; // [sp+54h] [bp-4E4h] BYREF
  unsigned int *v63; // [sp+58h] [bp-4E0h]
  unsigned int v64; // [sp+5Ch] [bp-4DCh]
  unsigned int v65; // [sp+60h] [bp-4D8h]
  _BYTE v66[24]; // [sp+68h] [bp-4D0h] BYREF
  int v67; // [sp+80h] [bp-4B8h] BYREF
  char v68; // [sp+84h] [bp-4B4h]
  char v69; // [sp+85h] [bp-4B3h]
  int v70; // [sp+88h] [bp-4B0h]
  int v71; // [sp+8Ch] [bp-4ACh]
  int v72; // [sp+90h] [bp-4A8h]
  int v73; // [sp+94h] [bp-4A4h]
  _DWORD _118[270]; // [sp+118h] [bp-420h] BYREF

  _118[266] = a1;
  _118[268] = a3;
  _118[269] = a4;
  v56 = a2;
  _118[267] = a2;
  v9 = a1;
  v46 = a1;
  v54 = a1;
  v57 = (_DWORD *)a3;
  v50 = a4;
  v61 = a5;
  v51 = a5;
  v59 = a6;
  v49 = a6;
  v60 = a7;
  v48 = (int)a7;
  v71 = 0;
  v67 = 1;
  v68 = 0;
  v69 = 0;
  v72 = 0;
  v70 = 33;
  v73 = 0;
  if ( (a2 & 0xFFFFFFFE) != 0 )
    return -1073741584;
  v53 = 0;
  v58 = 0;
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_DWORD *)(v11 + 116);
  v55 = (int *)v12;
  v47 = *(_BYTE *)(v11 + 346);
  v13 = v47;
  if ( v47 )
  {
    if ( a3 > MmHighestUserAddress - 0x10000 )
    {
      v10 = -1073741583;
      v52 = -1073741583;
      return v10;
    }
    if ( MmHighestUserAddress - a3 - 0xFFFF < a4 )
    {
      v10 = -1073741582;
      v52 = -1073741582;
      return v10;
    }
    v14 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v14 = (int *)MmUserProbeAddress;
    *v14 = *v14;
    v53 = *a6;
    v58 = v53;
    if ( !v53 )
    {
      v10 = -1073741581;
      v52 = -1073741581;
      return v10;
    }
    if ( v53 > 0x3FFFFFFF )
    {
      v10 = -1073741581;
      v52 = -1073741581;
      return v10;
    }
    ProbeForWrite(a5, 4 * v53, 4);
    v15 = a7;
    if ( (unsigned int)a7 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
    v16 = v53;
    v9 = v46;
  }
  else
  {
    v53 = *a6;
    v16 = v53;
    v58 = v53;
  }
  v17 = _118;
  v49 = _118;
  v55 = _118;
  if ( v16 > 0x100 )
  {
    v17 = (int *)ExAllocatePoolWithQuotaTag(0x208u, 4 * v16, 1665625421);
    v49 = v17;
    v55 = v17;
    if ( !v17 )
      return -1073741670;
    v9 = v46;
  }
  v51 = v17;
  v57 = 0;
  v18 = 0;
  if ( v9 == -1 )
  {
    v19 = v12;
  }
  else
  {
    v10 = ObReferenceObjectByHandleWithTag(v46, 8, PsProcessType, v13, 2002218317, &v50, 0);
    v45 = (_DWORD *)v10;
    if ( v10 < 0 )
      goto LABEL_102;
    v19 = v50;
  }
  v54 = v19;
  v48 = 0;
  v20 = a4 + a3 - 1;
  if ( a3 > v20 )
  {
    v10 = -1073741582;
    goto LABEL_92;
  }
  if ( v12 != v19 )
  {
    KiStackAttachProcess(v19, 0, (int)v66);
    v18 = 1;
  }
  v21 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v22 = ((v20 >> 10) & 0x3FFFFC) - 0x40000000;
  v65 = v22;
  v23 = (_DWORD *)MiObtainReferencedVad(a3, (int *)&v45);
  if ( !v23 )
  {
    v10 = (int)v45;
    if ( v45 != (_DWORD *)-1073741664 )
      goto LABEL_92;
    goto LABEL_91;
  }
  v57 = v23;
  if ( (v23[7] & 7) != 4 || v20 > ((v23[4] << 12) | 0xFFFu) )
  {
LABEL_91:
    v10 = -1073741585;
    goto LABEL_92;
  }
  v24 = (_DWORD *)v23[9];
  v45 = v24;
  if ( v24 )
  {
    do
    {
      if ( v24[1] == 4 )
        break;
      v24 = (_DWORD *)*v24;
    }
    while ( v24 );
    v45 = v24;
  }
  v25 = (a3 >> 12) - v23[3];
  v26 = (unsigned int *)(v54 + 492);
  v63 = (unsigned int *)(v54 + 492);
  v50 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v26);
  }
  else
  {
    v28 = (unsigned __int8 *)v26 + 3;
    do
      v27 = __ldrex(v28);
    while ( __strex(v27 | 0x80, v28) );
    __dmb(0xBu);
    if ( v27 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v26);
    while ( 1 )
    {
      v29 = *v26;
      if ( (*v26 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v29 & 0x40000000) == 0 )
      {
        do
          v27 = __ldrex(v26);
        while ( v27 == v29 && __strex(v29 | 0x40000000, v26) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v21 <= v22 )
  {
    v64 = 0x3FFFFF;
    while ( 1 )
    {
      v30 = MiGetNextPageTable(v21, v22, 1, v50, 1, &v62);
      if ( !v30 )
        v30 = v22 + 4;
      v27 = (unsigned int)v45;
      if ( v21 != v30 )
        break;
LABEL_61:
      if ( v21 <= v22 )
      {
        do
        {
          v33 = *(_DWORD *)v21;
          v18 &= 0xFFFFFFF9;
          v34 = *(_DWORD *)(v27 + 12);
          if ( ((*(int *)(v34 + 4 * (v25 >> 5)) >> (v25 & 0x1F)) & 1) != 0 )
          {
            v18 |= 4u;
            if ( (v56 & 1) != 0 )
            {
              *(_BYTE *)((v25 >> 3) + v34) &= ~(1 << (v25 & 7));
              if ( (v33 & 2) != 0 && (v33 & 0x200) == 0 )
                v18 |= 2u;
              v27 = (unsigned int)v45;
            }
          }
          else if ( (v33 & 2) != 0 && (v33 & 0x200) == 0 )
          {
            v18 |= 4u;
            if ( (v56 & 1) != 0 )
              v18 |= 2u;
          }
          if ( (v18 & 2) != 0 )
          {
            v35 = 3 * (v33 >> 12);
            v36 = MmPfnDatabase;
            v37 = v33 | 0x200;
            if ( v21 + 0x40000000 > v64 )
            {
              *(_DWORD *)v21 = v37;
            }
            else
            {
              v38 = 0;
              v39 = *(_DWORD *)v21;
              __dmb(0xBu);
              *(_DWORD *)v21 = v37;
              if ( (v39 & 2) == 0 && (v33 & 2) != 0 )
                v38 = 1;
              if ( v21 >= 0xC0300000 && v21 <= 0xC0300FFF )
              {
                v40 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v40, (_DWORD *)(v40 + 4 * (v21 & 0xFFF)), v37);
              }
              if ( v38 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
            MiInsertTbFlushEntry((int)&v67, v21 << 10, 1, 0);
            MiLockPageAndSetDirty(v36 + 8 * v35, 1);
            v22 = v65;
            v27 = (unsigned int)v45;
          }
          if ( (v18 & 4) != 0 )
          {
            v41 = v51;
            *v51 = v21 << 10;
            v51 = v41 + 1;
            if ( ++v48 == v53 )
              goto LABEL_89;
          }
          ++v25;
          v21 += 4;
        }
        while ( (v21 & 0xFFF) != 0 && v21 <= v22 );
      }
      if ( v21 > v22 )
        goto LABEL_89;
    }
    while ( 1 )
    {
      v31 = *(_DWORD *)(v27 + 12);
      if ( ((*(int *)(v31 + 4 * (v25 >> 5)) >> (v25 & 0x1F)) & 1) != 0 )
      {
        if ( (v56 & 1) != 0 )
        {
          *(_BYTE *)((v25 >> 3) + v31) &= ~(1 << (v25 & 7));
          v27 = (unsigned int)v45;
        }
        v32 = v51;
        *v51 = v21 << 10;
        v51 = v32 + 1;
        if ( ++v48 == v53 )
          break;
      }
      ++v25;
      v21 += 4;
      if ( v21 == v30 )
        goto LABEL_61;
    }
LABEL_89:
    v26 = v63;
  }
  MiFlushTbList((unsigned int)&v67, v27);
  MiUnlockWorkingSetExclusive((int)v26, v50);
  v10 = 0;
LABEL_92:
  if ( v57 )
    MiUnlockAndDereferenceVad((int)v57);
  if ( (v18 & 1) != 0 )
    KiUnstackDetachProcess((unsigned int)v66, 0);
  if ( v46 != -1 )
    ObfDereferenceObjectWithTag(v54);
  if ( !v10 )
  {
    v42 = v49;
    if ( v61 )
    {
      v43 = v48;
      memmove((int)v61, (int)v49, 4 * v48);
      *v59 = v43;
    }
    *v60 = 4096;
    goto LABEL_103;
  }
LABEL_102:
  v42 = v49;
LABEL_103:
  if ( v42 != _118 )
    ExFreePoolWithTag(v42, 0);
  return v10;
}
