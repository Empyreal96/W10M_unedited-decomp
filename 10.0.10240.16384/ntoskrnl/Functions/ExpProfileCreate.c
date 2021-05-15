// ExpProfileCreate 
 
int __fastcall ExpProfileCreate(_DWORD *a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, unsigned int a7, int a8, unsigned __int16 a9, unsigned int a10, unsigned __int8 a11)
{
  int *v13; // r4
  int v14; // r9
  _DWORD *v15; // r2
  int v16; // r1
  int v17; // r6
  int *v18; // r5
  unsigned int v19; // r3
  int v20; // r2
  int v21; // r3
  int v22; // r2
  int v23; // r3
  int v24; // r5
  int v25; // r0
  int *v26; // r0
  int v27; // r2
  int v28; // r3
  int v30; // [sp+1Ch] [bp-94h] BYREF
  int *v31; // [sp+20h] [bp-90h] BYREF
  unsigned int v32; // [sp+28h] [bp-88h]
  unsigned int v33; // [sp+2Ch] [bp-84h]
  int v34; // [sp+30h] [bp-80h]
  int v35; // [sp+34h] [bp-7Ch]
  _DWORD *v36; // [sp+38h] [bp-78h]
  int v37; // [sp+3Ch] [bp-74h]
  int v38; // [sp+40h] [bp-70h] BYREF
  int v39; // [sp+48h] [bp-68h]
  int v40; // [sp+4Ch] [bp-64h]
  int v41; // [sp+50h] [bp-60h]
  int v42; // [sp+58h] [bp-58h]
  int v43; // [sp+5Ch] [bp-54h]
  int v44; // [sp+60h] [bp-50h]
  int v45; // [sp+64h] [bp-4Ch] BYREF
  _DWORD v46[6]; // [sp+68h] [bp-48h] BYREF
  int v47; // [sp+80h] [bp-30h] BYREF
  char v48; // [sp+84h] [bp-2Ch]
  _DWORD *varg_r0; // [sp+B8h] [bp+8h]
  int varg_r1; // [sp+BCh] [bp+Ch]
  int varg_r2; // [sp+C0h] [bp+10h]
  unsigned int varg_r3; // [sp+C4h] [bp+14h]

  varg_r3 = a4;
  v32 = a3;
  varg_r2 = a3;
  v30 = a2;
  varg_r1 = a2;
  v36 = a1;
  varg_r0 = a1;
  v35 = 0;
  v31 = 0;
  if ( !a7 )
    return -1073741579;
  if ( (unsigned int)(a5 - 2) > 0x1D )
    return -1073741811;
  if ( a4 >> (a5 - 2) > a7 )
    return -1073741789;
  if ( a3 + a4 < a4 )
    return -2147483643;
  v47 = a8;
  v38 = 0;
  if ( off_617B54(1, 16, &v47, &v38) < 0 || v38 != 16 || !v48 )
    return -1073741637;
  v14 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v14 )
  {
    v15 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v15 = (_DWORD *)MmUserProbeAddress;
    *v15 = *v15;
    v33 = a6;
    ProbeForWrite(a6, a7, 4);
    v16 = a11;
    v34 = a11;
    v17 = a9;
    v18 = (int *)a10;
    if ( !a11 && 12 * a9 )
    {
      if ( (a10 & 3) != 0 )
        ExRaiseDatatypeMisalignment();
      v19 = 12 * a9 + a10;
      if ( v19 > MmUserProbeAddress || v19 < a10 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
  }
  else
  {
    v16 = a11;
    v34 = a11;
    v18 = (int *)a10;
    v17 = a9;
    v33 = a6;
  }
  v42 = 65537;
  v43 = 0;
  v37 = 0;
  v44 = 0;
  while ( v17 )
  {
    if ( !v14 || v16 )
    {
      v22 = v18[1];
      v23 = v18[2];
      v39 = *v18;
      v40 = v22;
      v41 = v23;
    }
    else
    {
      v20 = v18[1];
      v21 = v18[2];
      v39 = *v18;
      v40 = v20;
      v41 = v21;
    }
    if ( (unsigned __int16)v40 >= (unsigned int)KeQueryActiveGroupCount()
      || !v39
      || (dword_681D78[(unsigned __int16)v40] & v39) != v39
      || HIWORD(v41) | (unsigned __int16)v41 | HIWORD(v40) )
    {
      return -1073741811;
    }
    v37 |= v39;
    v44 = v37;
    v17 = (unsigned __int16)(v17 - 1);
    v18 += 3;
    v16 = v34;
  }
  if ( !v30 )
  {
    if ( !v35 )
    {
      if ( v32 <= MmHighestUserAddress
        && v14
        && !SeSinglePrivilegeCheck(SeSystemProfilePrivilege, dword_922A0C, v14, (int)&SeSystemProfilePrivilege) )
      {
        return -1073741727;
      }
      v24 = 0;
      v30 = 0;
      goto LABEL_44;
    }
    return -1073741811;
  }
  v25 = ObReferenceObjectByHandleWithTag(v30, 1024, PsProcessType, v14, 1716549701, &v30, 0);
  if ( v25 < 0 )
    return v25;
  v24 = v30;
LABEL_44:
  if ( ExIsRestrictedCaller(v14) && a4 && (v32 + a4 > MmUserProbeAddress || v32 + a4 < v32) )
    *(_BYTE *)MmUserProbeAddress = 0;
  v46[0] = 24;
  v46[1] = 0;
  v46[3] = 32;
  v46[2] = 0;
  v46[4] = 0;
  v46[5] = 0;
  v13 = (int *)ObCreateObject(0, (_DWORD *)ExProfileObjectType, (int)v46, v14, 0, 56, 0, 108, &v31);
  if ( (int)v13 < 0 )
  {
    if ( v24 )
      ObfDereferenceObjectWithTag(v24);
  }
  else
  {
    v26 = v31;
    *v31 = v24;
    v26[1] = v32;
    v26[2] = a4;
    v26[3] = v33;
    v26[4] = a7;
    v26[5] = a5;
    v26[7] = 0;
    v26[9] = v35;
    v26[10] = a8;
    v27 = v43;
    v28 = v44;
    v26[11] = v42;
    v26[12] = v27;
    v26[13] = v28;
    v13 = (int *)ObInsertObject((int)v26, 0, 1, 0, 0, (int)&v45);
    v31 = v13;
    if ( (int)v13 >= 0 )
      *v36 = v45;
  }
  return (int)v13;
}
