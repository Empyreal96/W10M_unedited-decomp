// NtCreateSection 
 
int __fastcall NtCreateSection(_DWORD *a1, int a2, int a3, int *a4, int a5, int a6, int a7)
{
  int v9; // lr
  int result; // r0
  BOOL v11; // r0
  int v12; // r3
  int v13; // r2
  _DWORD *v14; // r1
  int v15; // r10
  int v16; // r3
  int v17; // r0
  int v18; // r5
  int v19; // r4
  int v20; // [sp+10h] [bp-48h]
  int v23; // [sp+20h] [bp-38h] BYREF
  int v24; // [sp+24h] [bp-34h]
  int v25; // [sp+28h] [bp-30h] BYREF
  _DWORD _30[16]; // [sp+30h] [bp-28h] BYREF

  _30[15] = a4;
  _30[14] = a3;
  _30[13] = a2;
  _30[12] = a1;
  v9 = 0;
  if ( (a6 & 0x3000000) == 50331648 )
    return -1073741580;
  if ( (a6 & 0x1100000) == 17825792 )
    v9 = 1;
  v11 = (a6 & 0x2100000) != 0 && !v9;
  if ( (a6 & 0x208FFF80) != 0 || (a6 & 0xF100000) == 0 )
    return -1073741580;
  if ( (a6 & 0x3100000) != 0 )
  {
    v12 = -868220928;
    if ( (a6 & 0x2100000) != 0 )
      v12 = -872415232;
    if ( (v12 & a6) != 0 )
      return -1073741580;
  }
  if ( (a6 & 0xC000000) == 201326592 )
    return -1073741580;
  v13 = a5;
  if ( (a5 & 0x701) != 0 )
    return -1073741755;
  if ( !*(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
  {
    if ( a4 )
    {
      v16 = *a4;
      v20 = *a4;
      v15 = a4[1];
    }
    else
    {
      v16 = 0;
      v20 = 0;
      v15 = 0;
    }
    goto LABEL_30;
  }
  if ( v11 )
    return -1073741580;
  v14 = a1;
  if ( (unsigned int)a1 >= MmUserProbeAddress )
    v14 = (_DWORD *)MmUserProbeAddress;
  *v14 = *v14;
  if ( a4 )
  {
    if ( ((unsigned __int8)a4 & 7) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v20 = *a4;
    v23 = *a4;
    v15 = a4[1];
    v24 = v15;
  }
  else
  {
    v20 = 0;
    v23 = 0;
    v15 = 0;
    v24 = 0;
  }
  v13 = a5;
  v16 = v20;
LABEL_30:
  while ( 1 )
  {
    _30[0] = v16;
    _30[1] = v15;
    result = MmCreateSection(&v23, a2, a3, _30, v13, a6, a7, 0);
    if ( result >= 0 )
      break;
    if ( result != -1073741740 )
      return result;
    KeDelayExecutionThread(0, 0, (unsigned int *)MiHalfSecond);
    v16 = v20;
    v13 = a5;
  }
  v17 = MiSectionControlArea(v23);
  v18 = v17;
  if ( v17 && *(_DWORD *)(v17 + 32) )
  {
    v19 = MI_REFERENCE_CONTROL_AREA_FILE(v17);
    CcZeroEndOfLastPage(v19);
    MI_DEREFERENCE_CONTROL_AREA_FILE(v18, v19);
  }
  result = ObInsertObjectEx(v23, 0, a2, 0, 0, 0, &v25);
  v23 = result;
  if ( result >= 0 )
    *a1 = v25;
  return result;
}
