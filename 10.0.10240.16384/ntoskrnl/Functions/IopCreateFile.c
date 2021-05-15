// IopCreateFile 
 
int __fastcall IopCreateFile(_DWORD *a1, int a2, int a3, int *a4, int *a5, int a6, int a7, unsigned int a8, int a9, unsigned int a10, unsigned int a11, int a12, _DWORD *a13, int a14, int a15, _DWORD *a16)
{
  int v16; // r10
  int v17; // r8
  unsigned int v18; // r3
  unsigned int v19; // r6
  int v20; // r4
  int v21; // r5
  int v22; // r4
  int v23; // r2
  int v24; // r8
  unsigned int v25; // r3
  int v26; // r4
  int v27; // r4
  unsigned int v28; // r3
  int v29; // r4
  _DWORD *v30; // r2
  int *v31; // r2
  int v32; // r0
  int v33; // r0
  int v34; // r3
  int v35; // r3
  int v36; // r0
  unsigned int v37; // r3
  int v38; // r4
  unsigned int v39; // r3
  int v40; // r6
  int v41; // r4
  int v42; // r1
  int v43; // r2
  int v44; // r3
  unsigned __int64 *v45; // r3
  unsigned __int64 v46; // kr00_8
  unsigned int *v47; // r2
  unsigned int v48; // r1
  unsigned int v49; // r0
  BOOL v50; // r8
  int v51; // r2
  int v52; // r1
  int v53; // r2
  int v54; // r0
  unsigned int v55; // r3
  int v57; // [sp+14h] [bp-4Ch]
  int v59; // [sp+24h] [bp-3Ch]
  int v63; // [sp+38h] [bp-28h] BYREF
  int v64; // [sp+3Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int *varg_r3; // [sp+74h] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v16 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v17 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v57 = v17;
  v59 = a14;
  if ( (a14 & 0x100) != 0 )
  {
    v17 = 0;
    v57 = 0;
  }
  v18 = (unsigned int)KeGetPcr();
  v19 = (v18 & 0xFFFFF000) + 1408;
  v20 = *(_DWORD *)((v18 & 0xFFFFF000) + 0xB40);
  ++*(_DWORD *)(v20 + 12);
  v21 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v20);
  if ( !v21 )
  {
    ++*(_DWORD *)(v20 + 16);
    v22 = *(_DWORD *)(v19 + 1476);
    ++*(_DWORD *)(v22 + 12);
    v21 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v22);
    if ( !v21 )
    {
      ++*(_DWORD *)(v22 + 16);
      v21 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD))(v22 + 40))(
              *(_DWORD *)(v22 + 28),
              *(_DWORD *)(v22 + 36),
              *(_DWORD *)(v22 + 32));
      if ( !v21 )
        return -1073741670;
    }
  }
  *(_DWORD *)v21 = *(_DWORD *)(v19 + 20);
  if ( v17 || (v23 = a14, (a14 & 0x200) != 0) )
  {
    if ( (a6 & 0xFFFD0048) != 0 )
      goto LABEL_48;
    if ( (a7 & 0xFFFFFFF8) != 0 )
      goto LABEL_48;
    if ( a8 > 5 )
      goto LABEL_48;
    v24 = a9;
    if ( (a9 & 0xFF000000) != 0 || (a9 & 0x30) != 0 && (v16 & 0x100000) == 0 )
      goto LABEL_48;
    if ( (a9 & 0x1000) != 0 && (v16 & 0x10000) == 0
      || (a9 & 0x30) == 48
      || (a9 & 1) != 0 && (a9 & 0x40) == 0 && ((a9 & 0xFF5E0ACC) != 0 || a8 != 2 && a8 != 1 && a8 != 3)
      || (a9 & 0x100) != 0 && (a9 & 0x100000) != 0
      || (a9 & 0x100) != 0 && (a9 & 0x10000) != 0
      || (a9 & 0x100000) != 0 && (a9 & 0x10000) != 0
      || (a9 & 8) != 0 && (v16 & 4) != 0 )
    {
      goto LABEL_48;
    }
    if ( IopFailZeroAccessCreate && !v16 )
    {
      v25 = (unsigned int)KeGetPcr();
      v26 = *(_DWORD *)((v25 & 0xFFFFF000) + 0xB40);
      ++*(_DWORD *)(v26 + 20);
      if ( *(unsigned __int16 *)(v26 + 4) < (unsigned int)*(unsigned __int16 *)(v26 + 8)
        || (++*(_DWORD *)(v26 + 24),
            v26 = *(_DWORD *)((v25 & 0xFFFFF000) + 0xB44),
            ++*(_DWORD *)(v26 + 20),
            *(unsigned __int16 *)(v26 + 4) < (unsigned int)*(unsigned __int16 *)(v26 + 8)) )
      {
        RtlpInterlockedPushEntrySList((unsigned __int64 *)v26, (_DWORD *)v21);
      }
      else
      {
        ++*(_DWORD *)(v26 + 24);
        (*(void (__fastcall **)(int))(v26 + 44))(v21);
      }
      return -1073741790;
    }
    if ( a12 )
    {
      if ( a12 == 1 )
      {
        if ( !a13
          || (*a13 & 0xFFFFFFFC) != 0
          || a13[1] > 1u
          || a13[2] > 1u
          || (a7 & 4) != 0
          || a8 - 1 > 2
          || (a9 & 0xFFFFFFCD) != 0 )
        {
          goto LABEL_48;
        }
      }
      else if ( a12 == 2 && (!a13 || (a7 & 4) != 0 || (a7 & 0xFFFFFFFD) == 0 || a8 != 2 || (a9 & 0xFFFFFFCD) != 0) )
      {
        goto LABEL_48;
      }
    }
    v23 = a14;
  }
  else
  {
    v24 = a9;
  }
  if ( v57 )
  {
    *(_DWORD *)(v21 + 48) = 0;
    v30 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v30 = (_DWORD *)MmUserProbeAddress;
    *v30 = *v30;
    v31 = a4;
    if ( (unsigned int)a4 >= MmUserProbeAddress )
      v31 = (int *)MmUserProbeAddress;
    *v31 = *v31;
    if ( a5 )
    {
      if ( ((unsigned __int8)a5 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&IoFileObjectType);
      v63 = *a5;
      v64 = a5[1];
      if ( v64 < 0 )
        RtlRaiseStatus(-1073741811);
    }
    else
    {
      v63 = 0;
      v64 = 0;
    }
    if ( a10 && a11 )
    {
      if ( (a10 & 3) != 0 )
        ExRaiseDatatypeMisalignment(&IoFileObjectType);
      if ( a10 + a11 > MmUserProbeAddress || a10 + a11 < a10 )
        *(_BYTE *)MmUserProbeAddress = 0;
      v32 = ExAllocatePoolWithQuotaTag(0x200u, a11, 1631940425);
      *(_DWORD *)(v21 + 48) = v32;
      *(_DWORD *)(v21 + 52) = a11;
      memmove(v32, a10, a11);
      v33 = IoCheckEaBufferValidity(*(_DWORD *)(v21 + 48), a11, a4 + 1);
      if ( v33 < 0 )
      {
        *a4 = v33;
        RtlRaiseStatus(v33);
      }
LABEL_102:
      *(_WORD *)v21 = 8;
      *(_WORD *)(v21 + 2) = 112;
      *(_DWORD *)(v21 + 16) = 0;
      *(_DWORD *)(v21 + 12) = 0;
      *(_DWORD *)(v21 + 32) = v63;
      *(_DWORD *)(v21 + 36) = v64;
      *(_DWORD *)(v21 + 40) = v24;
      *(_WORD *)(v21 + 44) = a6;
      *(_WORD *)(v21 + 46) = a7;
      *(_DWORD *)(v21 + 60) = a8;
      *(_BYTE *)(v21 + 80) = 0;
      *(_BYTE *)(v21 + 81) = 0;
      *(_BYTE *)(v21 + 82) = 0;
      *(_DWORD *)(v21 + 56) = v59;
      *(_DWORD *)(v21 + 20) = 0;
      *(_DWORD *)(v21 + 24) = a3;
      *(_DWORD *)(v21 + 72) = a12;
      *(_DWORD *)(v21 + 76) = a13;
      *(_DWORD *)(v21 + 88) = a15;
      v41 = v57;
      *(_BYTE *)(v21 + 92) = v57;
      if ( a16 )
      {
        v42 = a16[1];
        v43 = a16[2];
        v44 = a16[3];
        *(_DWORD *)(v21 + 96) = *a16;
        *(_DWORD *)(v21 + 100) = v42;
        *(_DWORD *)(v21 + 104) = v43;
        *(_DWORD *)(v21 + 108) = v44;
        v41 = v57;
      }
      else
      {
        *(_DWORD *)(v21 + 96) = 0;
        *(_DWORD *)(v21 + 100) = 0;
        *(_DWORD *)(v21 + 104) = 0;
        *(_DWORD *)(v21 + 108) = 0;
        *(_WORD *)(v21 + 96) = 16;
      }
      *(_DWORD *)(v21 + 8) = 0;
      *(_DWORD *)(v21 + 4) = 0;
      if ( IoCountOperations == 1 )
      {
        v45 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
        do
          v46 = __ldrexd(v45);
        while ( __strexd(v46 + 1, v45) );
        v47 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
        do
          v48 = __ldrex(v47);
        while ( __strex(v48 + 1, v47) );
      }
      v27 = ObOpenObjectByName(a3, (int)IoFileObjectType, v41, 0, a2, v21, &v63);
      v49 = *(_DWORD *)(v21 + 48);
      if ( v49 )
        ExFreePoolWithTag(v49);
      if ( *(_DWORD *)(v21 + 100) && FsRtlpCleanupEcps() )
        *(_DWORD *)(v21 + 100) = 0;
      v50 = *(_DWORD *)(v21 + 16) == -1096154543;
      if ( v27 >= 0 )
      {
        if ( *(_DWORD *)(v21 + 16) == -1096154543 )
        {
          *(_DWORD *)(*(_DWORD *)(v21 + 4) + 44) |= 0x40000u;
          *(_DWORD *)(*(_DWORD *)(v21 + 4) + 44) &= 0xFDFFFFFF;
          *a1 = v63;
          a4[1] = *(_DWORD *)(v21 + 12);
          *a4 = *(_DWORD *)(v21 + 8);
          v27 = *(_DWORD *)(v21 + 8);
          goto LABEL_134;
        }
        ObCloseHandle(v63);
        v27 = -1073741788;
      }
      v51 = *(_DWORD *)(v21 + 8);
      if ( v51 >= 0 )
      {
        v52 = *(_DWORD *)(v21 + 4);
        if ( v52 )
        {
          if ( v50 )
          {
            if ( (*(_DWORD *)(v52 + 44) & 0x40000) == 0 )
              IopCloseFile(0, (_DWORD *)v52, 1, 1);
          }
          else
          {
            if ( *(_WORD *)(v52 + 48) )
              ExFreePoolWithTag(*(_DWORD *)(v52 + 52));
            *(_DWORD *)(*(_DWORD *)(v21 + 4) + 4) = 0;
            ObfDereferenceObject(*(_DWORD *)(v21 + 4));
          }
        }
      }
      else
      {
        v27 = *(_DWORD *)(v21 + 8);
        if ( (v51 & 0xC0000000) == 0x80000000 )
        {
          *a4 = v51;
          a4[1] = *(_DWORD *)(v21 + 12);
        }
      }
      if ( v27 == -1073741772 )
      {
        v53 = *(_DWORD *)(v21 + 12);
        if ( v53 == -1610612733 || v53 == -1610612724 || v53 == -2147483623 )
          v27 = -1073741184;
      }
LABEL_134:
      if ( v50 )
      {
        v54 = *(_DWORD *)(v21 + 4);
        if ( v54 )
          ObfDereferenceObject(v54);
      }
      v55 = (unsigned int)KeGetPcr();
      v40 = *(_DWORD *)((v55 & 0xFFFFF000) + 0xB40);
      ++*(_DWORD *)(v40 + 20);
      if ( *(unsigned __int16 *)(v40 + 4) >= (unsigned int)*(unsigned __int16 *)(v40 + 8) )
      {
        ++*(_DWORD *)(v40 + 24);
        v40 = *(_DWORD *)((v55 & 0xFFFFF000) + 0xB44);
        ++*(_DWORD *)(v40 + 20);
        if ( *(unsigned __int16 *)(v40 + 4) >= (unsigned int)*(unsigned __int16 *)(v40 + 8) )
        {
          ++*(_DWORD *)(v40 + 24);
          (*(void (__fastcall **)(int))(v40 + 44))(v21);
          return v27;
        }
      }
      goto LABEL_99;
    }
LABEL_101:
    *(_DWORD *)(v21 + 52) = 0;
    *(_DWORD *)(v21 + 48) = 0;
    goto LABEL_102;
  }
  if ( v24 < 0 )
  {
    v59 = v23 | 0x400;
    v24 &= 0x7FFFFFFFu;
  }
  if ( a5 )
  {
    v34 = a5[1];
    if ( v34 > 0 || v34 >= 0 )
    {
      v63 = *a5;
      v35 = a5[1];
      goto LABEL_87;
    }
LABEL_48:
    v28 = (unsigned int)KeGetPcr();
    v29 = *(_DWORD *)((v28 & 0xFFFFF000) + 0xB40);
    ++*(_DWORD *)(v29 + 20);
    if ( *(unsigned __int16 *)(v29 + 4) < (unsigned int)*(unsigned __int16 *)(v29 + 8)
      || (++*(_DWORD *)(v29 + 24),
          v29 = *(_DWORD *)((v28 & 0xFFFFF000) + 0xB44),
          ++*(_DWORD *)(v29 + 20),
          *(unsigned __int16 *)(v29 + 4) < (unsigned int)*(unsigned __int16 *)(v29 + 8)) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v29, (_DWORD *)v21);
    }
    else
    {
      ++*(_DWORD *)(v29 + 24);
      (*(void (__fastcall **)(int))(v29 + 44))(v21);
    }
    return -1073741811;
  }
  v35 = 0;
  v63 = 0;
LABEL_87:
  v64 = v35;
  if ( !a10 || !a11 )
    goto LABEL_101;
  v36 = ExAllocatePoolWithTag(512, a11, 1631940425);
  *(_DWORD *)(v21 + 48) = v36;
  if ( !v36 )
  {
    v37 = (unsigned int)KeGetPcr();
    v38 = *(_DWORD *)((v37 & 0xFFFFF000) + 0xB40);
    ++*(_DWORD *)(v38 + 20);
    if ( *(unsigned __int16 *)(v38 + 4) < (unsigned int)*(unsigned __int16 *)(v38 + 8)
      || (++*(_DWORD *)(v38 + 24),
          v38 = *(_DWORD *)((v37 & 0xFFFFF000) + 0xB44),
          ++*(_DWORD *)(v38 + 20),
          *(unsigned __int16 *)(v38 + 4) < (unsigned int)*(unsigned __int16 *)(v38 + 8)) )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)v38, (_DWORD *)v21);
    }
    else
    {
      ++*(_DWORD *)(v38 + 24);
      (*(void (__fastcall **)(int))(v38 + 44))(v21);
    }
    return -1073741670;
  }
  *(_DWORD *)(v21 + 52) = a11;
  memmove(v36, a10, a11);
  v27 = IoCheckEaBufferValidity(*(_DWORD *)(v21 + 48), a11, a4 + 1);
  if ( v27 >= 0 )
    goto LABEL_102;
  ExFreePoolWithTag(*(_DWORD *)(v21 + 48));
  *a4 = v27;
  v39 = (unsigned int)KeGetPcr();
  v40 = *(_DWORD *)((v39 & 0xFFFFF000) + 0xB40);
  ++*(_DWORD *)(v40 + 20);
  if ( *(unsigned __int16 *)(v40 + 4) < (unsigned int)*(unsigned __int16 *)(v40 + 8)
    || (++*(_DWORD *)(v40 + 24),
        v40 = *(_DWORD *)((v39 & 0xFFFFF000) + 0xB44),
        ++*(_DWORD *)(v40 + 20),
        *(unsigned __int16 *)(v40 + 4) < (unsigned int)*(unsigned __int16 *)(v40 + 8)) )
  {
LABEL_99:
    RtlpInterlockedPushEntrySList((unsigned __int64 *)v40, (_DWORD *)v21);
    return v27;
  }
  ++*(_DWORD *)(v40 + 24);
  (*(void (__fastcall **)(int))(v40 + 44))(v21);
  return v27;
}
