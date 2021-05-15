// PfQuerySuperfetchInformation 
 
int __fastcall PfQuerySuperfetchInformation(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // r9
  int v6; // r6
  int v7; // r0
  int v8; // r4
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r4
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  _BYTE *v18; // r0
  int v19; // r3
  _BYTE *v20; // r2
  _BYTE *v21; // r2
  int v22; // r3
  _DWORD *v23; // r4
  int v25; // [sp+8h] [bp-88h] BYREF
  int v26; // [sp+Ch] [bp-84h]
  int v27; // [sp+10h] [bp-80h]
  unsigned int v28; // [sp+14h] [bp-7Ch]
  int v29; // [sp+18h] [bp-78h]
  int v30; // [sp+20h] [bp-70h]
  int v31; // [sp+24h] [bp-6Ch]
  int v32; // [sp+28h] [bp-68h]
  _DWORD v33[8]; // [sp+30h] [bp-60h] BYREF
  _DWORD _50[21]; // [sp+50h] [bp-40h] BYREF
  int varg_r3; // [sp+A4h] [bp+14h]

  _50[18] = a1;
  _50[19] = a2;
  _50[20] = a3;
  varg_r3 = a4;
  v5 = (char)a4;
  LOBYTE(varg_r3) = a4;
  if ( a3 != 20 )
    return -1073741820;
  v6 = 0;
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v7 = memmove((int)&v25, a2, 0x14u);
  if ( v25 != 45 || v26 != 1802856515 )
    return -1073741811;
  v8 = v27;
  if ( v27 != 16 && v27 != 8 && v27 != 28 )
  {
    v7 = SeSinglePrivilegeCheck(
           SeProfileSingleProcessPrivilege,
           dword_922B94,
           v5,
           (int)&SeProfileSingleProcessPrivilege);
    if ( !v7 )
      return -1073741790;
  }
  v9 = v8 - 1;
  switch ( v8 )
  {
    case 1:
      v10 = PfGetCompletedTrace(v28, v29, v5, a5, a5);
      goto LABEL_12;
    case 2:
      if ( v29 != 28 )
        return -1073741306;
      v6 = 0;
      v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v11 + 308);
      v12 = KeAbPreAcquire((unsigned int)dword_637278, 0, 0);
      do
        v13 = __ldrex(dword_637278);
      while ( !v13 && __strex(0x11u, dword_637278) );
      __dmb(0xBu);
      if ( v13 )
        ExfAcquirePushLockSharedEx(dword_637278, v12, (unsigned int)dword_637278);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      v33[0] = dword_6370C4;
      v33[1] = unk_6370C8;
      v33[2] = dword_6370CC;
      v33[3] = dword_6370D0;
      v33[4] = dword_6370D4;
      v33[5] = dword_6370D8;
      v33[6] = dword_6370DC;
      __dmb(0xBu);
      do
        v14 = __ldrex(dword_637278);
      while ( v14 == 17 && __strex(0, dword_637278) );
      if ( v14 != 17 )
        ExfReleasePushLockShared(dword_637278);
      v15 = KeAbPostRelease((unsigned int)dword_637278);
      v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v17 = *(_WORD *)(v16 + 0x134) + 1;
      *(_WORD *)(v16 + 308) = v17;
      if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
        KiCheckForKernelApcDelivery(v15);
      v18 = (_BYTE *)v28;
      if ( v5 )
      {
        if ( (v28 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v28);
        if ( v28 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *v18 = *v18;
        v18[24] = v18[24];
      }
      memmove((int)v18, (int)v33, 0x1Cu);
      v19 = 28;
      goto LABEL_38;
    case 6:
      v10 = PfpPfnPrioRequest(&v25, v5, a5);
      goto LABEL_12;
    case 8:
      v10 = PfpPrivSourceEnum((int)&v25, v5, a5, v9);
      goto LABEL_12;
    case 9:
      v6 = 0;
      if ( v29 != 4 )
        return -1073741306;
      v20 = (_BYTE *)v28;
      if ( v5 )
      {
        if ( (v28 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v7);
        if ( v28 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *v20 = *v20;
      }
      *(_DWORD *)v20 = dword_643B68;
      v19 = 4;
      goto LABEL_38;
    case 12:
      v10 = PfpQueryScenarioInformation(&v25, v5, a5);
      goto LABEL_12;
    case 16:
      v10 = PfpMemoryListQuery((int)&v25, v5, a5);
      goto LABEL_12;
    case 17:
      v10 = PfpMemoryRangesQuery((int)&v25, v5, a5, v9);
      goto LABEL_12;
    case 20:
      if ( v29 != 8 )
        return -1073741306;
      v6 = 0;
      v30 = 0;
      v31 = 0;
      v21 = (_BYTE *)v28;
      if ( v5 )
      {
        if ( (v28 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v7);
        if ( v28 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *v21 = *v21;
        v21[4] = v21[4];
      }
      v30 = *(_DWORD *)v21;
      v31 = *((_DWORD *)v21 + 1);
      if ( v30 == 1 )
      {
        v22 = dword_637368;
        *(_DWORD *)v21 = 1;
        *((_DWORD *)v21 + 1) = v22;
        v19 = 8;
LABEL_38:
        *a5 = v19;
      }
      else
      {
        v6 = -1073741735;
      }
      break;
    case 23:
      v10 = PfpVirtualQuery(&v25, v5, a5);
      goto LABEL_12;
    case 24:
      if ( v29 != 16 )
        return -1073741306;
      MmLogQueryCombineStats(0, _50);
      v23 = (_DWORD *)v28;
      if ( v5 )
        ProbeForWrite(v28, 16, 4);
      if ( *v23 == 1 )
      {
        v23[1] = _50[1];
        v23[2] = _50[6];
        v23[3] = _50[7];
      }
      else
      {
        v6 = -1073741811;
        v32 = -1073741811;
      }
      return v6;
    case 27:
      v10 = PfpQueryFileExtentsRequest(&v25, v5, a5);
      goto LABEL_12;
    case 28:
      v10 = PfpQueryGpuUtilization(&v25, v5, a5);
LABEL_12:
      v6 = v10;
      break;
    default:
      v6 = -1073741821;
      break;
  }
  return v6;
}
