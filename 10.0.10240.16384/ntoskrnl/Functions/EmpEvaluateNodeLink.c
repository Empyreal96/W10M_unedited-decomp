// EmpEvaluateNodeLink 
 
int __fastcall EmpEvaluateNodeLink(int *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int v10; // r7
  int v11; // r6
  _DWORD *v12; // r5
  int v13; // r4
  int v15; // r9
  int v16; // r10
  unsigned int v17; // r1
  unsigned int v18; // r2
  int v19; // r3
  int v20; // r1
  int v21; // r7
  unsigned int v22; // r3
  int v23; // r0
  _DWORD *v25; // r6
  int v26; // r0
  int v27; // r5
  int v28; // r3
  int v29; // r0
  int v30; // r3
  int v31; // r0
  int v32; // [sp+28h] [bp-48h] BYREF
  unsigned int v33; // [sp+2Ch] [bp-44h]
  unsigned int v34; // [sp+30h] [bp-40h]
  int v35; // [sp+34h] [bp-3Ch]
  int v36; // [sp+38h] [bp-38h]
  int v37; // [sp+3Ch] [bp-34h]
  int v38; // [sp+40h] [bp-30h]
  int v39; // [sp+44h] [bp-2Ch]
  int v40; // [sp+48h] [bp-28h]
  int v41; // [sp+4Ch] [bp-24h]

  v10 = *a1;
  v11 = 0;
  v12 = 0;
  v13 = 1;
  v38 = a4;
  v35 = a3;
  v36 = a2;
  v15 = 0;
  v16 = 0;
  v41 = 0;
  if ( !v10 )
  {
    v12 = (_DWORD *)a1[1];
    if ( !v12[4] )
      return v13;
    v17 = v12[11];
    v18 = v12[10];
    v19 = v12[9];
LABEL_4:
    v33 = v17;
    v34 = v18;
    v20 = a1[2];
    v37 = v19;
    v39 = v20;
    if ( !v20 || (v40 = a1[3]) == 0 )
    {
      v39 = a9;
      v40 = a8;
      if ( !a8 )
      {
        if ( v10 )
          v31 = EmpEvaluateNodeLink(*(_DWORD *)(v11 + 64), v36, v35, a4, a5, a6, a7, 0, 0);
        else
          v31 = ((int (__fastcall *)(int, int, int, int, int, int, _DWORD))v12[4])(a6, a7, v36, v35, a4, a5, v12[6]);
        return v31;
      }
    }
    if ( v19 )
    {
      if ( RtlULongLongToULong(4 * v19, (unsigned __int64)(unsigned int)v19 >> 30, &v32) < 0 )
        return v13;
      v15 = ExAllocatePoolWithTag(1, v32, 1986350405);
      if ( !v15 )
        return v13;
    }
    if ( v34 )
    {
      if ( RtlULongLongToULong(4 * v34, (unsigned __int64)v34 >> 30, &v32) < 0 )
        goto LABEL_18;
      v21 = ExAllocatePoolWithTag(1, v32, 1986350405);
      v41 = v21;
      if ( !v21 )
        goto LABEL_18;
    }
    else
    {
      v21 = 0;
    }
    v22 = v33;
    if ( !v33 )
      goto LABEL_14;
    if ( RtlULongLongToULong(4 * v33, (unsigned __int64)v33 >> 30, &v32) >= 0 )
    {
      v16 = ExAllocatePoolWithTag(1, v32, 1986350405);
      if ( v16 )
      {
        v22 = v33;
LABEL_14:
        if ( EmpEvaluateParseNodeMapping(v40, v39, v36, v35, v38, a5, a6, a7, v15, v37, v21, v34, v16, v22) )
        {
          if ( *a1 )
            v23 = EmpEvaluateNodeLink(*(_DWORD *)(v11 + 64), v15, v37, v21, v34, v16, v33, 0, 0);
          else
            v23 = ((int (__fastcall *)(int, unsigned int, int, int, int, unsigned int, _DWORD))v12[4])(
                    v16,
                    v33,
                    v15,
                    v37,
                    v21,
                    v34,
                    v12[6]);
          v13 = v23;
        }
        goto LABEL_18;
      }
    }
LABEL_18:
    if ( v15 )
      ExFreePoolWithTag(v15, 1986350405);
    if ( v41 )
      ExFreePoolWithTag(v41, 1986350405);
    if ( v16 )
      ExFreePoolWithTag(v16, 1986350405);
    return v13;
  }
  if ( v10 == 1 )
  {
    v11 = a1[1];
    if ( !*(_BYTE *)(v11 + 20) )
      return v13;
    v17 = *(_DWORD *)(v11 + 40);
    v18 = *(_DWORD *)(v11 + 36);
    v19 = *(_DWORD *)(v11 + 32);
    goto LABEL_4;
  }
  if ( v10 != 2 )
    return v13;
  v25 = (_DWORD *)a1[1];
  v26 = EmpEvaluateNodeLink(v25[1], a2, a3, a4, a5, a6, a7, v25[3], v25[2]);
  v27 = v26;
  if ( v26 == 1 )
    return 1;
  v28 = *(char *)v25;
  if ( !v26 && v28 == 38 )
    return 0;
  if ( v28 != 124 )
  {
    v29 = EmpEvaluateNodeLink(v25[4], v36, v35, v38, a5, a6, a7, v25[6], v25[5]);
    if ( v29 != 1 )
    {
      v30 = *(char *)v25;
      if ( v30 == 38 )
      {
        if ( v29 && v27 )
          v13 = 2;
        else
          v13 = 0;
      }
      if ( v30 != 124 )
        return v13;
      if ( v27 || v29 )
        JUMPOUT(0x51F88E);
      return 0;
    }
    return 1;
  }
  return sub_51F888();
}
