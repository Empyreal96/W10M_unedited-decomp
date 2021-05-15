// MmQueryVirtualMemory 
 
int __fastcall MmQueryVirtualMemory(int a1, unsigned int a2, int a3, unsigned int *a4, unsigned int a5, _DWORD *a6, int a7)
{
  int v10; // r8
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r0
  _DWORD *v14; // r2
  int v15; // r5
  unsigned int v16; // lr
  int v17; // r4
  int v18; // r0
  int v19; // r8
  unsigned int v20; // r4
  int v21; // r9
  int v22; // r4
  unsigned int v23; // r5
  unsigned int v24; // r2
  unsigned int v25; // r1
  int v26; // r4
  unsigned int v27; // r3
  unsigned int i; // r2
  _DWORD *v29; // r3
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int v32; // r2
  unsigned int v33; // r9
  int v34; // r1
  int v35; // r10
  int v36; // r5
  int v37; // r0
  int v38; // r3
  int v39; // r8
  unsigned int v40; // r6
  unsigned int *v41; // r4
  int v42; // r2
  int v43; // r5
  int v44; // r2
  unsigned __int64 *v45; // r3
  unsigned __int64 v46; // kr00_8
  unsigned int *v47; // r4
  int v48; // r2
  int v49; // r3
  int v50; // r0
  unsigned int *v51; // lr
  int v52; // r1
  int v53; // r2
  int v54; // r3
  int v55; // r2
  int v56; // r3
  int v57; // r5
  int v59; // [sp+10h] [bp-C0h]
  _DWORD *v60; // [sp+18h] [bp-B8h]
  unsigned int v61; // [sp+1Ch] [bp-B4h]
  unsigned int v62; // [sp+1Ch] [bp-B4h]
  char v63; // [sp+24h] [bp-ACh]
  int v64; // [sp+28h] [bp-A8h]
  _DWORD *v65; // [sp+34h] [bp-9Ch] BYREF
  unsigned int *v66; // [sp+38h] [bp-98h]
  int v67; // [sp+3Ch] [bp-94h]
  unsigned int v68; // [sp+40h] [bp-90h]
  int v69; // [sp+44h] [bp-8Ch] BYREF
  int v70; // [sp+48h] [bp-88h]
  int v71; // [sp+4Ch] [bp-84h]
  int v72; // [sp+50h] [bp-80h]
  unsigned int v73; // [sp+58h] [bp-78h]
  int v74; // [sp+5Ch] [bp-74h]
  int v75; // [sp+60h] [bp-70h]
  _DWORD v76[4]; // [sp+68h] [bp-68h] BYREF
  unsigned int v77; // [sp+78h] [bp-58h] BYREF
  int v78; // [sp+7Ch] [bp-54h]
  int v79; // [sp+80h] [bp-50h]
  int v80; // [sp+84h] [bp-4Ch]
  unsigned int v81; // [sp+88h] [bp-48h]
  int v82; // [sp+8Ch] [bp-44h]
  int v83; // [sp+90h] [bp-40h]
  _BYTE _98[60]; // [sp+98h] [bp-38h] BYREF
  int varg_r0; // [sp+D8h] [bp+8h]
  unsigned int varg_r1; // [sp+DCh] [bp+Ch]
  int varg_r2; // [sp+E0h] [bp+10h]
  unsigned int *varg_r3; // [sp+E4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v66 = a4;
  v72 = a3;
  varg_r2 = a3;
  v61 = a2;
  v71 = a1;
  v76[2] = a4;
  v76[0] = a6;
  v63 = 0;
  v67 = 0;
  v68 = 0;
  if ( a3 )
  {
    if ( a3 != 3 )
    {
      switch ( a3 )
      {
        case 1:
        case 5:
          v10 = a5;
          if ( a5 >= 4 )
            goto LABEL_16;
          v11 = -1073741820;
          break;
        case 2:
          v10 = a5;
          goto LABEL_16;
        case 4:
          v10 = a5;
          if ( a5 >= 8 )
            goto LABEL_16;
          v11 = -1073741820;
          break;
        case 6:
          v10 = a5;
          if ( a5 >= 0xC )
            goto LABEL_16;
          v11 = -1073741820;
          break;
        default:
          v11 = -1073741821;
          break;
      }
      return v11;
    }
    v10 = a5;
    if ( a5 < 0x10 )
      return -1073741820;
  }
  else
  {
    v10 = a5;
    if ( a5 < 0x1C )
      return -1073741820;
  }
LABEL_16:
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v64 = v12;
  v65 = (_DWORD *)v12;
  v13 = *(char *)(v12 + 0x15A);
  v70 = v13;
  if ( v13 )
  {
    ProbeForWrite((unsigned int)a4, v10, 4);
    if ( a6 )
    {
      v14 = a6;
      if ( (unsigned int)a6 >= MmUserProbeAddress )
        v14 = (_DWORD *)MmUserProbeAddress;
      *v14 = *v14;
    }
    a2 = v61;
    v12 = v64;
    v13 = v70;
  }
  v15 = MmHighestUserAddress;
  if ( a2 > MmHighestUserAddress )
    return -1073741811;
  v16 = MmHighestUserAddress - 0x10000;
  v68 = MmHighestUserAddress - 0x10000;
  if ( a1 == -1 )
  {
    v17 = *(_DWORD *)(v12 + 116);
    v60 = (_DWORD *)v17;
    v65 = (_DWORD *)v17;
  }
  else
  {
    v18 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v13, 1834380621, (int *)&v65, 0);
    if ( v18 < 0 )
      return v18;
    v60 = v65;
    v17 = (int)v65;
    if ( v65 == (_DWORD *)PsInitialSystemProcess )
    {
      ObfDereferenceObjectWithTag((int)v65);
      return -1073741790;
    }
    a2 = v61;
    v16 = v68;
  }
  if ( a2 > v16 || (a2 & 0xFFFFF000) == 2147352576 && (*(_DWORD *)(v17 + 736) & 1) == 0 )
  {
    v59 = -1073741503;
    if ( !a3 )
    {
      a4[1] = v16 + 1;
      a4[2] = 2;
      *a4 = a2 & 0xFFFFF000;
      a4[3] = v15 - (a2 & 0xFFFFF000) + 1;
      a4[4] = 0x2000;
      a4[5] = 1;
      a4[6] = 0x20000;
      if ( a6 )
        *a6 = 28;
      if ( (a2 & 0xFFFFF000) == 2147352576 )
      {
        a4[1] = 2147352576;
        a4[5] = 2;
        a4[3] = 4096;
        a4[4] = 4096;
      }
      v59 = 0;
    }
    if ( a1 != -1 )
      ObfDereferenceObjectWithTag((int)v60);
    return v59;
  }
  v19 = v72;
  switch ( v72 )
  {
    case 4:
      v11 = MiGetWorkingSetInfoList((int)a4, a5, v17, a7);
      if ( a1 != -1 )
        ObfDereferenceObjectWithTag(v17);
      if ( v11 >= 0 )
      {
        if ( a6 )
          *a6 = a5;
        return 0;
      }
      return v11;
    case 5:
      v20 = *(_DWORD *)(v17 + 864);
      __dmb(0xBu);
      if ( a1 != -1 )
        ObfDereferenceObjectWithTag((int)v65);
      *a4 = v20;
      if ( a6 )
        *a6 = 4;
      return 0;
    case 1:
      v11 = MiGetWorkingSetInfo((int)a4, v76, a5, v17);
      if ( a1 != -1 )
        ObfDereferenceObjectWithTag(v17);
      if ( v11 >= 0 )
      {
        if ( a6 )
          *a6 = 4 * (v76[0] + 1);
        return 0;
      }
      return v11;
  }
  if ( a1 == -1 )
  {
    memset(_98, 0, 24);
    v21 = 0;
  }
  else
  {
    KiStackAttachProcess(v17, 0, (int)_98);
    v21 = 1;
    v63 = 1;
  }
  while ( 1 )
  {
    LOCK_ADDRESS_SPACE_SHARED(v64, v17);
    if ( (v60[48] & 0x20) != 0 )
    {
      UNLOCK_ADDRESS_SPACE_SHARED(v64, (int)v60);
      if ( (v21 & 1) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)_98, 0);
        ObfDereferenceObjectWithTag((int)v60);
      }
      return -1073741558;
    }
    v22 = 0;
    v23 = 0;
    if ( v60[161] )
    {
      v22 = v60[159];
      v23 = v61 >> 12;
      while ( v22 )
      {
        v24 = *(_DWORD *)(v22 + 12);
        if ( v23 < v24 )
          goto LABEL_67;
        if ( v23 <= *(_DWORD *)(v22 + 16) )
        {
          v21 |= 2u;
          v63 = v21;
          break;
        }
        if ( v23 >= v24 )
        {
          if ( !*(_DWORD *)(v22 + 4) )
            break;
          v22 = *(_DWORD *)(v22 + 4);
        }
        else
        {
LABEL_67:
          if ( !*(_DWORD *)v22 )
            break;
          v22 = *(_DWORD *)v22;
        }
      }
    }
    if ( (v21 & 2) == 0 )
    {
      if ( !v22 )
      {
        v25 = v61 & 0xFFFFF000;
        v26 = v68 - (v61 & 0xFFFFF000) + 1;
        goto LABEL_87;
      }
      v27 = *(_DWORD *)(v22 + 12);
      if ( v27 >= v23 )
      {
        v25 = v61 & 0xFFFFF000;
        v26 = (v27 << 12) - (v61 & 0xFFFFF000);
LABEL_87:
        v62 = v25;
      }
      else
      {
        i = *(_DWORD *)(v22 + 4);
        if ( i )
        {
          v29 = *(_DWORD **)i;
          if ( *(_DWORD *)i )
          {
            do
            {
              i = (unsigned int)v29;
              v29 = (_DWORD *)*v29;
            }
            while ( v29 );
          }
        }
        else
        {
          for ( i = *(_DWORD *)(v22 + 8) & 0xFFFFFFFC; i; i = *(_DWORD *)(i + 8) & 0xFFFFFFFC )
          {
            if ( *(_DWORD *)i == v22 )
              break;
            v22 = i;
          }
        }
        v30 = v61 & 0xFFFFF000;
        v62 = v61 & 0xFFFFF000;
        if ( i )
          v26 = (*(_DWORD *)(i + 12) << 12) - v30;
        else
          v26 = v68 - v30 + 1;
      }
      UNLOCK_ADDRESS_SPACE_SHARED(v64, (int)v60);
      if ( (v21 & 1) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)_98, 0);
        ObfDereferenceObjectWithTag((int)v60);
      }
      if ( !v19 )
      {
        a4[1] = 0;
        a4[2] = 0;
        *a4 = v62;
        a4[3] = v26;
        a4[4] = 0x10000;
        a4[5] = 1;
        a4[6] = 0;
        if ( a6 )
          *a6 = 28;
        return 0;
      }
      return -1073741503;
    }
    MiReferenceVad(v22);
    --*(_WORD *)(v64 + 308);
    UNLOCK_ADDRESS_SPACE_SHARED(v64, (int)v60);
    MiLockVad(v64, v22);
    v31 = *(_WORD *)(v64 + 308);
    *(_WORD *)(v64 + 308) = v31 + 1;
    if ( v31 == -1 && *(_DWORD *)(v64 + 100) != v64 + 100 && !*(_WORD *)(v64 + 310) )
      KiCheckForKernelApcDelivery(v64);
    if ( MiVadDeleted(v22) )
    {
      MiWaitForVadDeletion(v22);
      goto LABEL_101;
    }
    v32 = *(_DWORD *)(v22 + 12);
    if ( v23 >= v32 && v23 <= *(_DWORD *)(v22 + 16) )
      break;
LABEL_101:
    MiUnlockAndDereferenceVad(v22);
    v21 &= 0xFFFFFFFD;
    v63 = v21;
    v17 = (int)v60;
  }
  v77 = v61 & 0xFFFFF000;
  v33 = v32 << 12;
  v78 = v32 << 12;
  v34 = *(_DWORD *)(v22 + 28);
  v35 = MmProtectToValue[(unsigned __int8)v34 >> 3];
  v79 = v35;
  if ( (v34 & 0x8000) != 0 )
  {
    v36 = 0x20000;
    v83 = 0x20000;
    goto LABEL_119;
  }
  if ( (v34 & 7) == 2 )
  {
    v36 = 0x1000000;
    goto LABEL_113;
  }
  v36 = 0x40000;
  v83 = 0x40000;
  if ( v19 == 3 && a5 >= 0x14 && !*(_DWORD *)(**(_DWORD **)(v22 + 44) + 32) && (v34 & 7) != 1 )
  {
    v36 = 0x8000000;
LABEL_113:
    v83 = v36;
  }
  if ( v19 == 2 )
  {
    v37 = **(_DWORD **)(v22 + 44);
    v38 = *(_DWORD *)(v37 + 32) & 0xFFFFFFF8;
    v67 = v38;
    if ( v38 )
    {
      v38 = MI_REFERENCE_CONTROL_AREA_FILE(v37);
      v67 = v38;
    }
    if ( !v38 )
      v67 = 1;
  }
LABEL_119:
  switch ( v19 )
  {
    case 3:
      v39 = (*(_DWORD *)(v22 + 16) - *(_DWORD *)(v22 + 12) + 1) << 12;
      v40 = *(_DWORD *)(v22 + 32) & 0x7FFFFFFF;
      if ( v40 >= 0x7FFFE )
        v40 = 0;
      MiUnlockAndDereferenceVad(v22);
      if ( (v63 & 1) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)_98, 0);
        ObfDereferenceObjectWithTag((int)v60);
      }
      v41 = v66;
      *v66 = v33;
      v41[1] = v35;
      v41[2] = v36;
      v41[3] = v39;
      if ( a5 < 0x14 )
      {
        v42 = 16;
      }
      else
      {
        v41[4] = v40 << 12;
        v42 = 20;
      }
      v69 = v42;
      if ( a6 )
        *a6 = v42;
      return 0;
    case 6:
      v73 = 0;
      v74 = 0;
      v43 = 0;
      v75 = 0;
      if ( (*(_DWORD *)(v22 + 28) & 0x8000) == 0 && (*(_DWORD *)(v22 + 28) & 7) == 2 )
      {
        v44 = ***(_DWORD ***)(v22 + 44);
        v73 = *(_DWORD *)(v22 + 12) << 12;
        __dmb(0xBu);
        v45 = (unsigned __int64 *)(v44 + 16);
        do
          v46 = __ldrexd(v45);
        while ( v46 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v45) );
        v76[1] = HIDWORD(v46);
        __dmb(0xBu);
        v74 = v46;
        if ( (*(_DWORD *)(v22 + 28) & 0xF8) == 8 )
        {
          v43 = 2;
          v75 = 2;
        }
        if ( *(_DWORD *)(v22 + 16) - *(_DWORD *)(v22 + 12) + 1 != ((v46 & 0xFFF) != 0) + ((unsigned int)v46 >> 12) )
          v75 = v43 | 1;
      }
      MiUnlockAndDereferenceVad(v22);
      if ( (v63 & 1) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)_98, 0);
        ObfDereferenceObjectWithTag((int)v60);
      }
      v69 = 12;
      v47 = v66;
      v48 = v74;
      v49 = v75;
      *v66 = v73;
      v47[1] = v48;
      v47[2] = v49;
      if ( a6 )
        *a6 = 12;
      return 0;
    case 0:
      v50 = MiQueryAddressSpan((int)&v77, v61 & 0xFFFFF000, v22);
      v80 = v50 - v77;
      break;
  }
  MiUnlockAndDereferenceVad(v22);
  if ( (v63 & 1) != 0 )
  {
    KiUnstackDetachProcess((unsigned int)_98, 0);
    ObfDereferenceObjectWithTag((int)v60);
  }
  if ( !v19 )
  {
    v51 = v66;
    v52 = v78;
    v53 = v79;
    v54 = v80;
    *v66 = v77;
    v51[1] = v52;
    v51[2] = v53;
    v51[3] = v54;
    v51 += 4;
    v55 = v82;
    v56 = v83;
    *v51 = v81;
    v51[1] = v55;
    v51[2] = v56;
    if ( a6 )
      *a6 = 28;
    return 0;
  }
  v57 = v67;
  if ( !v67 )
    return -1073741503;
  if ( v67 == 1 )
    return -1073741672;
  v59 = ObQueryNameStringMode(v67, (int)v66, a5, &v69, v70);
  ObfDereferenceObject(v57);
  if ( a6 )
  {
    *a6 = v69;
    return v59;
  }
  return v59;
}
