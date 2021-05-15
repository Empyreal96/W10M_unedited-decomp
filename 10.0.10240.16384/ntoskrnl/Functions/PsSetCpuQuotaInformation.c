// PsSetCpuQuotaInformation 
 
int __fastcall PsSetCpuQuotaInformation(unsigned int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r6
  int v7; // r4
  int v8; // r0
  unsigned int v9; // r6
  int v10; // r0
  _DWORD *v11; // r9
  unsigned int v12; // r3
  _DWORD *v13; // r2
  unsigned int i; // r0
  int *v15; // r1
  int v16; // r3
  _DWORD *v17; // r2
  int v18; // r3
  unsigned int v19; // r5
  _DWORD *v20; // r10
  int v21; // r3
  int v22; // r0
  _DWORD *v23; // r6
  int v24; // t1
  _DWORD *v26; // [sp+8h] [bp-50h]
  int v27; // [sp+Ch] [bp-4Ch]
  int v28; // [sp+14h] [bp-44h]
  int v29; // [sp+30h] [bp-28h]
  _DWORD _34[13]; // [sp+34h] [bp-24h] BYREF
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  _34[11] = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = (char)a3;
  v28 = (char)a3;
  LOBYTE(varg_r2) = a3;
  _34[12] = a2;
  if ( !PsCpuFairShareEnabled )
    return -1073741823;
  if ( a2 < 0x10 || (a2 & 0xF) != 0 )
    return -1073741820;
  if ( (_BYTE)a3 )
  {
    v8 = SeSinglePrivilegeCheck(SeIncreaseQuotaPrivilege, dword_922794, (char)a3);
    if ( !v8 )
      return -1073741727;
    if ( v4 && a2 )
    {
      if ( (a1 & 7) != 0 )
        ExRaiseDatatypeMisalignment(v8);
      if ( a1 + a2 > MmUserProbeAddress || a1 + a2 < a1 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  v9 = a2 >> 4;
  v10 = ExAllocatePoolWithQuotaTag(0x208u, 16 * (a2 >> 4), 1666413392);
  v11 = (_DWORD *)v10;
  if ( !v10 )
    return -1073741670;
  v12 = v10 + 4 * v9;
  v27 = v12;
  v13 = (_DWORD *)(v12 + 4 * v9);
  v26 = v13;
  for ( i = 0; i < v9; ++i )
  {
    v15 = (int *)(a1 + 16 * i);
    v16 = *v15;
    __dmb(0xBu);
    v11[i] = v16;
    v17 = &v13[2 * i];
    v17[1] = 0;
    v17[1] = 0;
    v18 = v15[2];
    __dmb(0xBu);
    *v17 = v18;
    if ( !*(_WORD *)v17 || *(unsigned __int16 *)v17 > 9u )
    {
      v7 = -1073740712;
      goto LABEL_34;
    }
    v12 = v27;
    v13 = v26;
  }
  v7 = 0;
  v19 = 0;
  v20 = v11;
  v21 = v12 - (_DWORD)v11;
  v29 = v21;
  while ( v19 < v9 )
  {
    v7 = ObReferenceObjectByHandle(*v20, 2, MmSessionObjectType, v28, _34, 0);
    *v20 = _34[0];
    if ( v7 < 0 )
      goto LABEL_31;
    v22 = MmGetSessionSchedulingGroup();
    v21 = v29;
    *(_DWORD *)((char *)v20 + v29) = v22;
    if ( !v22 )
    {
      v7 = -1073740715;
      goto LABEL_31;
    }
    ++v19;
    ++v20;
  }
  KeSetSchedulingGroupWeights(v9, v27, v26, v21);
LABEL_31:
  v23 = &v11[v19];
  while ( v19 )
  {
    --v19;
    v24 = *--v23;
    ObfDereferenceObjectWithTag(v24);
  }
LABEL_34:
  ExFreePoolWithTag(v11);
  return v7;
}
