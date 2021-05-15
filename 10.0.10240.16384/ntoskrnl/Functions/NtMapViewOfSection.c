// NtMapViewOfSection 
 
int __fastcall NtMapViewOfSection(int a1, int a2, int *a3, unsigned int a4, int a5, unsigned int a6, _DWORD *a7, int a8, int a9, int a10)
{
  int v11; // r4
  int v12; // r0
  int v13; // r8
  int *v14; // r2
  _DWORD *v15; // r1
  _DWORD *v16; // r2
  int v17; // r2
  int v18; // r9
  int v19; // r6
  int v20; // r3
  int v21; // r8
  int v22; // r3
  int v23; // r6
  int v25; // [sp+24h] [bp-64h] BYREF
  unsigned int v26; // [sp+28h] [bp-60h]
  int v27; // [sp+2Ch] [bp-5Ch] BYREF
  __int64 v28; // [sp+30h] [bp-58h]
  unsigned int v29; // [sp+38h] [bp-50h]
  int v30; // [sp+3Ch] [bp-4Ch] BYREF
  unsigned int v31; // [sp+40h] [bp-48h]
  _DWORD *v32; // [sp+44h] [bp-44h]
  int v33; // [sp+48h] [bp-40h]
  int v34; // [sp+4Ch] [bp-3Ch]
  int v35; // [sp+50h] [bp-38h]
  int *v36; // [sp+54h] [bp-34h]
  int v37; // [sp+58h] [bp-30h] BYREF
  unsigned int v38; // [sp+60h] [bp-28h] BYREF
  int v39; // [sp+64h] [bp-24h]
  int varg_r0; // [sp+90h] [bp+8h]
  int varg_r1; // [sp+94h] [bp+Ch]
  int *varg_r2; // [sp+98h] [bp+10h]
  unsigned int varg_r3; // [sp+9Ch] [bp+14h]

  v29 = a4;
  varg_r3 = a4;
  v36 = a3;
  varg_r2 = a3;
  v33 = a2;
  varg_r1 = a2;
  v35 = a1;
  varg_r0 = a1;
  if ( a4 <= 0x15 )
  {
    if ( (unsigned int)(a8 - 1) > 1 )
      return -1073741578;
    if ( (a9 & 0x9F2FDF80) != 0 )
      return -1073741577;
    v12 = MiMakeProtectionMask(a10 & 0xBFFFFFFF);
    if ( v12 == -1 )
      return -1073741755;
    v34 = MmMakeSectionAccess[v12 & 7];
    v37 = v34;
    v13 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
    if ( v13 )
    {
      v14 = a3;
      if ( (unsigned int)a3 >= MmUserProbeAddress )
        v14 = (int *)MmUserProbeAddress;
      *v14 = *v14;
      v15 = a7;
      v32 = a7;
      v16 = a7;
      if ( (unsigned int)a7 >= MmUserProbeAddress )
        v16 = (_DWORD *)MmUserProbeAddress;
      *v16 = *v16;
    }
    else
    {
      v15 = a7;
      v32 = a7;
    }
    if ( a6 )
    {
      if ( v13 )
      {
        if ( (a6 & 7) != 0 )
          ExRaiseDatatypeMisalignment(v12);
        if ( a6 >= MmUserProbeAddress )
          *(_BYTE *)MmUserProbeAddress = 0;
        *(_BYTE *)a6 = *(_BYTE *)a6;
      }
      v26 = *(_DWORD *)a6;
      v38 = v26;
      v17 = *(_DWORD *)(a6 + 4);
    }
    else
    {
      v17 = 0;
      v26 = 0;
      v38 = 0;
    }
    v39 = v17;
    HIDWORD(v28) = v17;
    v31 = *a3;
    v27 = v31;
    LODWORD(v28) = *v15;
    v30 = v28;
    if ( v31 > MmHighestUserAddress - 0x10000 || (unsigned int)v28 > MmHighestUserAddress - v31 - 0xFFFF )
      return -1073741583;
    if ( (unsigned int)v28 + v31 <= 0xFFFFFFFF >> v29 )
    {
      v11 = ObReferenceObjectByHandleWithTag(v33, 8, PsProcessType, v13, 2002152781, &v25, 0);
      if ( v11 < 0 )
        return v11;
      v11 = ObReferenceObjectByHandle(v35, v34, MmSectionObjectType, v13, (int)&v37, 0);
      if ( v11 < 0 )
      {
        v21 = v25;
        goto LABEL_49;
      }
      v18 = v37;
      v19 = MiSectionControlArea(v37);
      v20 = *(_DWORD *)(v19 + 28);
      if ( (v20 & 0x20) == 0 && (a9 & 0x800000) != 0 )
      {
        v11 = -1073741577;
        v21 = v25;
LABEL_47:
        ObfDereferenceObject(v18);
LABEL_49:
        ObfDereferenceObjectWithTag(v21);
        return v11;
      }
      if ( (v20 & 0x400) != 0 )
      {
        v38 = v26 & 0xFFFFF000;
        if ( v13
          && v28 + (unsigned __int64)(v26 & 0xFFFFF000) > __PAIR64__(
                                                            (unsigned int)dword_640504 >> 20,
                                                            dword_640504 << 12) )
        {
          v11 = -1073741580;
          v21 = v25;
          goto LABEL_47;
        }
      }
      else if ( (a9 & 0x40000000) == 0 && ((_WORD)v31 || a6 && (_WORD)v26) )
      {
        v11 = -1073741280;
        v21 = v25;
        goto LABEL_47;
      }
      v21 = v25;
      v11 = MiMapViewOfSection(v18, v25, &v27, v29, a5, &v38, &v30, a8, a9, a10, 2, 0);
      v35 = v11;
      if ( v11 >= 0 )
      {
        v22 = *(_DWORD *)(v19 + 28);
        v23 = v27;
        if ( (v22 & 0x20) != 0 )
          DbgkMapViewOfSection(v21, v18, v27);
        *v32 = v30;
        *v36 = v23;
        if ( a6 )
        {
          *(_DWORD *)a6 = v38;
          *(_DWORD *)(a6 + 4) = v39;
        }
      }
      goto LABEL_47;
    }
  }
  return -1073741582;
}
