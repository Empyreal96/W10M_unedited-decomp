// NtSetInformationVirtualMemory 
 
int __fastcall NtSetInformationVirtualMemory(int a1, int a2, unsigned int a3, int a4, int *a5, int a6)
{
  int v9; // r5
  int v10; // r1
  unsigned int *v11; // r2
  unsigned int v13; // r0
  int v14; // r3
  unsigned int v15; // r9
  unsigned int v16; // r0
  char *v17; // r3
  char *v18; // r1
  int v19; // r3
  _DWORD *v20; // lr
  int v21; // r0
  int v22; // r3
  int v23; // r3
  _BYTE *v24; // r4
  int v25; // r10
  _DWORD *v26; // r8
  int v27; // r0
  int v28; // r6
  _DWORD *v29; // r6
  unsigned int v30; // r2
  unsigned int v31; // r2
  int v32; // r5
  int v33; // r1
  int v34; // [sp+10h] [bp-1A8h]
  _DWORD *v35; // [sp+14h] [bp-1A4h]
  int v36; // [sp+20h] [bp-198h] BYREF
  unsigned int v37; // [sp+24h] [bp-194h]
  _BYTE *v38; // [sp+28h] [bp-190h]
  int v39; // [sp+2Ch] [bp-18Ch]
  _DWORD *v40; // [sp+30h] [bp-188h]
  int v41; // [sp+34h] [bp-184h]
  unsigned int v42; // [sp+38h] [bp-180h]
  int v43; // [sp+3Ch] [bp-17Ch]
  unsigned int v44; // [sp+40h] [bp-178h]
  _DWORD *v45; // [sp+44h] [bp-174h]
  _DWORD *v46; // [sp+48h] [bp-170h]
  int v47; // [sp+4Ch] [bp-16Ch]
  int v48; // [sp+50h] [bp-168h]
  int v49; // [sp+54h] [bp-164h]
  unsigned int v50; // [sp+58h] [bp-160h]
  int v51; // [sp+5Ch] [bp-15Ch]
  unsigned int v52; // [sp+60h] [bp-158h]
  int v53; // [sp+64h] [bp-154h]
  _DWORD *v54; // [sp+68h] [bp-150h]
  unsigned int v55; // [sp+6Ch] [bp-14Ch]
  unsigned int v56; // [sp+70h] [bp-148h]
  unsigned int v57; // [sp+74h] [bp-144h]
  int v58; // [sp+78h] [bp-140h]
  int v59; // [sp+7Ch] [bp-13Ch] BYREF
  _BYTE v60[24]; // [sp+80h] [bp-138h] BYREF
  _BYTE v61[128]; // [sp+98h] [bp-120h] BYREF
  _DWORD _118[46]; // [sp+118h] [bp-A0h] BYREF

  _118[42] = a1;
  _118[45] = a4;
  v50 = a4;
  v56 = a3;
  _118[44] = a3;
  _118[43] = a2;
  v41 = a1;
  v49 = a1;
  v58 = a4;
  v43 = 0;
  v48 = 0;
  v39 = 0;
  v47 = 0;
  v35 = _118;
  v46 = _118;
  v9 = 0;
  v51 = 0;
  v37 = 0;
  v44 = 0;
  if ( a2 < 0 )
    return -1073741584;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v10 = a6;
      if ( a6 == 16 )
      {
        v11 = (unsigned int *)a5;
        goto LABEL_10;
      }
      return -1073741580;
    }
    return -1073741584;
  }
  v11 = (unsigned int *)a5;
  if ( !a5 )
    return -1073741581;
  v10 = a6;
  if ( a6 != 4 )
    return -1073741580;
LABEL_10:
  if ( a3 && a3 <= 0x1FFFFFFF )
  {
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v45 = (_DWORD *)v13;
    v57 = v13;
    v14 = *(_DWORD *)(v13 + 0x74);
    v34 = v14;
    v36 = v14;
    if ( a2 == 2 && (*(_DWORD *)(v14 + 188) & 0x400) != 0 )
    {
      v43 = 1;
      v48 = 1;
    }
    v15 = 0;
    v52 = 0;
    v40 = 0;
    v54 = 0;
    v42 = 0;
    v55 = 0;
    v16 = *(char *)(v13 + 346);
    v38 = (_BYTE *)v16;
    if ( v16 )
    {
      if ( 8 * a3 )
      {
        if ( (a4 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v16);
        v16 = 8 * a3 + a4;
        v17 = (char *)MmUserProbeAddress;
        if ( v16 > MmUserProbeAddress || v16 < v50 )
        {
          *(_BYTE *)MmUserProbeAddress = 0;
          v17 = (char *)MmUserProbeAddress;
        }
      }
      else
      {
        v17 = (char *)MmUserProbeAddress;
      }
      if ( a2 == 2 )
      {
        if ( v10 )
        {
          if ( ((unsigned __int8)v11 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v16);
          v18 = (char *)v11 + v10;
          if ( v18 > v17 || v18 < (char *)v11 )
            *v17 = 0;
        }
        v52 = *v11;
        v15 = v52;
        v19 = v11[1];
        v53 = v19;
        v20 = (_DWORD *)v11[2];
        v40 = v20;
        v54 = v20;
        v42 = v11[3];
        v55 = v42;
        if ( !v52 || v52 > 0x1FFFFFFF || v19 )
          return -1073741581;
        v21 = ProbeForWrite(v20, 4, 4);
        v22 = 8 * v52;
        if ( 8 * v52 )
        {
          if ( (v42 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v21);
          if ( v22 + v42 > MmUserProbeAddress || v22 + v42 < v42 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        if ( ((unsigned __int8)v11 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v16);
        v37 = *v11;
        v44 = v37;
      }
      v16 = (unsigned int)v38;
      goto LABEL_50;
    }
    if ( a2 != 2 )
    {
      v37 = *v11;
      v44 = v37;
      goto LABEL_50;
    }
    v52 = *v11;
    v15 = v52;
    v23 = v11[1];
    v40 = (_DWORD *)v11[2];
    v54 = v40;
    v42 = v11[3];
    if ( v52 && v52 <= 0x1FFFFFFF && !v23 )
    {
LABEL_50:
      if ( v41 == -1 )
      {
        v36 = v34;
      }
      else
      {
        v9 = ObReferenceObjectByHandleWithTag(v41, 8, PsProcessType, v16, 1716546893, &v36, 0);
        if ( v9 < 0 )
          return v9;
        v34 = v36;
      }
      v24 = v61;
      v38 = v61;
      v25 = v56;
      if ( v56 > 0x10 )
      {
        v24 = (_BYTE *)ExAllocatePoolWithTag(512, 8 * v56, 1917676877);
        v38 = v24;
        if ( !v24 )
        {
          v24 = v61;
          v9 = -1073741670;
LABEL_91:
          v26 = v35;
          goto LABEL_92;
        }
      }
      if ( a2 == 2 && v15 > 0x10 )
      {
        v35 = (_DWORD *)ExAllocatePoolWithTag(512, 8 * v15, 1917676877);
        v46 = v35;
        if ( !v35 )
        {
          v26 = _118;
          v9 = -1073741670;
          goto LABEL_92;
        }
      }
      memmove((int)v24, v50, 8 * v25);
      if ( a2 == 2 )
        memmove((int)v35, v42, 8 * v15);
      if ( !MiValidateMemoryRangeEntries(v24, v25, 0) )
      {
        v9 = -1073741582;
        goto LABEL_91;
      }
      v27 = v34;
      if ( v45[29] != v34 )
      {
        v27 = KiStackAttachProcess(v34, 0, (int)v60);
        v39 = 1;
        v47 = 1;
      }
      if ( a2 )
      {
        if ( a2 != 1 )
        {
          if ( a2 != 2 )
            goto LABEL_91;
          v26 = v35;
          if ( v25 == 1 )
          {
            v9 = MiCfgMarkValidEntries(v27, *(_DWORD *)v24, *((_DWORD *)v24 + 1), v35, v15, &v59, v43);
            v51 = v9;
            *v40 = v59;
            v28 = v34;
LABEL_93:
            if ( (v39 & 1) != 0 )
              KiUnstackDetachProcess((unsigned int)v60, 0);
            if ( v41 != -1 )
              ObfDereferenceObjectWithTag(v28);
            if ( v24 != v61 )
              ExFreePoolWithTag((unsigned int)v24);
            if ( v26 != _118 )
              ExFreePoolWithTag((unsigned int)v26);
            return v9;
          }
          v9 = -1073741582;
LABEL_92:
          v28 = v34;
          goto LABEL_93;
        }
        if ( v37 <= 5 )
        {
          MiSetPriorityVaRanges(v25, v24, v37);
          v9 = 0;
          goto LABEL_91;
        }
      }
      else if ( !v37 )
      {
        v29 = v45;
        v30 = MiGetEffectivePagePriorityThread(v45) & 7;
        if ( v30 < 5 )
          v30 |= 0x40u;
        v31 = v30 ^ ((unsigned __int8)v30 ^ (unsigned __int8)(8 * v30)) & 0x38;
        if ( (v31 & 0x38) < 0x28 )
          v31 = v31 & 0xFFFFFFC7 | 0x28;
        v32 = v31 | 0x4000;
        v33 = (v29[240] >> 9) & 7;
        if ( (*(_DWORD *)(v29[84] + 192) & 0x100000) != 0 )
          v33 = 0;
        if ( v33 < 2 && v29 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v29[250] )
          v33 = 2;
        if ( v33 <= 1 )
          v32 = v31 | 0x4400;
        v28 = v34;
        v9 = MiPrefetchVirtualMemory(v25, (int)v24, v34 + 492, v32);
        v26 = v35;
        goto LABEL_93;
      }
      v9 = -1073741581;
      goto LABEL_91;
    }
    return -1073741581;
  }
  return -1073741583;
}
