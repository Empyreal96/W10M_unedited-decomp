// NtGetNextThread 
 
int __fastcall NtGetNextThread(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  int v7; // r2
  int v8; // r3
  _DWORD *v9; // r2
  int v10; // r4
  int v11; // r0
  int v12; // r6
  unsigned int *v13; // r5
  int v14; // r0
  int v15; // r2
  int v16; // r2
  unsigned int *v18; // [sp+14h] [bp-184h] BYREF
  _DWORD *v19; // [sp+18h] [bp-180h] BYREF
  int v20; // [sp+1Ch] [bp-17Ch]
  BOOL v21; // [sp+20h] [bp-178h]
  int v22; // [sp+24h] [bp-174h]
  int v23; // [sp+28h] [bp-170h]
  int v24; // [sp+30h] [bp-168h] BYREF
  int v25; // [sp+34h] [bp-164h]
  char v26[16]; // [sp+38h] [bp-160h] BYREF
  int v27; // [sp+48h] [bp-150h]
  int v28; // [sp+4Ch] [bp-14Ch]
  int v29; // [sp+54h] [bp-144h] BYREF
  _DWORD _B0[63]; // [sp+B0h] [bp-E8h] BYREF
  int varg_r3; // [sp+1ACh] [bp+14h]

  _B0[60] = a1;
  _B0[61] = a2;
  varg_r3 = a4;
  v23 = a3;
  _B0[62] = a3;
  v18 = (unsigned int *)a1;
  v21 = a2;
  v19 = a6;
  v7 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v20 = v7;
  if ( v7 )
    v8 = a4 & 0xDF2;
  else
    v8 = a4 & 0x10FF2;
  v22 = v8;
  varg_r3 = v8;
  if ( v7 )
  {
    v9 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
    v7 = v20;
  }
  *a6 = 0;
  if ( a5 )
    return -1073741811;
  v10 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v7, 1850045264, (int *)&v19, 0);
  if ( v10 < 0 )
    return v10;
  if ( !a2 )
  {
    v11 = 0;
    v12 = (int)v19;
    goto LABEL_16;
  }
  v10 = ObReferenceObjectByHandleWithTag(a2, 0, PsThreadType, v20, 1850045264, (int *)&v18, 0);
  v12 = (int)v19;
  if ( v10 < 0 )
  {
LABEL_18:
    v14 = v12;
LABEL_19:
    ObfDereferenceObjectWithTag(v14);
    return v10;
  }
  v11 = (int)v18;
  if ( (_DWORD *)v18[84] != v19 )
  {
    ObfDereferenceObjectWithTag((int)v18);
    v10 = -1073741811;
    goto LABEL_18;
  }
LABEL_16:
  v13 = PsGetNextProcessThread(v12, v11);
  v18 = v13;
  if ( !v13 )
  {
    v10 = -2147483622;
    goto LABEL_18;
  }
  v21 = SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v20, (int)&SeDebugPrivilege) != 0;
  v15 = __mrc(15, 0, 13, 0, 3);
  v25 = v15;
  do
  {
    if ( (v13[240] & 2) != 0 || (PsSynchronizeWithThreadInsertion(v13, v15 & 0xFFFFFFC0), (v13[240] & 2) != 0) )
    {
      v10 = SeCreateAccessState((int)v26, (int)_B0, v23, (_DWORD *)(PsProcessType + 52));
      if ( v10 < 0 )
        goto LABEL_33;
      if ( v21 )
      {
        v16 = v27;
        if ( (v27 & 0x2000000) != 0 )
          v16 = 0x1FFFFF;
        v28 |= v16;
        v27 = 0;
      }
      v10 = ObOpenObjectByPointer((int)v13, v22, v26, 0, PsThreadType, v20, &v24);
      SepDeleteAccessState((int)v26);
      SeReleaseSubjectContext((int)&v29);
      if ( v10 >= 0 )
      {
        *a6 = v24;
        goto LABEL_33;
      }
      if ( v10 != -1073741790 )
        goto LABEL_33;
    }
    v13 = PsGetNextProcessThread(v12, (int)v13);
    v18 = v13;
    v15 = v25;
  }
  while ( v13 );
  v10 = -2147483622;
LABEL_33:
  ObfDereferenceObjectWithTag(v12);
  if ( v13 )
  {
    v14 = (int)v13;
    goto LABEL_19;
  }
  return v10;
}
