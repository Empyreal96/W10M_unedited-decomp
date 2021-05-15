// NtTranslateFilePath 
 
int __fastcall NtTranslateFilePath(unsigned int a1, int a2, int a3, unsigned int *a4)
{
  int v6; // r4
  unsigned int v7; // r3
  int v8; // r10
  unsigned int *v9; // r3
  unsigned int v10; // r4
  unsigned int v11; // r3
  unsigned int *v12; // r2
  unsigned int v13; // r5
  int v14; // r0
  unsigned int v15; // r8
  int v16; // r6
  unsigned int v17; // r3
  int v18; // r0
  unsigned int v20; // [sp+0h] [bp-40h] BYREF
  int v21; // [sp+4h] [bp-3Ch]
  int v22; // [sp+8h] [bp-38h]
  int v23; // [sp+Ch] [bp-34h]
  unsigned int v24; // [sp+10h] [bp-30h]
  unsigned int v25; // [sp+14h] [bp-2Ch]
  unsigned int v26; // [sp+18h] [bp-28h]
  int v27; // [sp+1Ch] [bp-24h]
  unsigned int *v28; // [sp+20h] [bp-20h]
  unsigned int varg_r0; // [sp+48h] [bp+8h]
  int varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  unsigned int *varg_r3; // [sp+54h] [bp+14h]

  varg_r0 = a1;
  v28 = a4;
  varg_r3 = a4;
  v25 = a3;
  varg_r2 = a3;
  v27 = a2;
  varg_r1 = a2;
  v23 = 0;
  if ( dword_61A1F0 != 2 )
    return -1073741822;
  if ( (unsigned int)(a2 - 1) > 4 )
    return -1073741811;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(char *)(v7 + 346);
  if ( *(_BYTE *)(v7 + 346) )
  {
    v9 = (unsigned int *)(a1 + 4);
    if ( a1 + 4 >= MmUserProbeAddress )
      v9 = (unsigned int *)MmUserProbeAddress;
    v10 = *v9;
    v26 = *v9;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 4);
    v26 = v10;
  }
  v24 = v10;
  if ( v10 < 0xC )
  {
    v6 = -1073741811;
    v22 = -1073741811;
    return v6;
  }
  if ( v8 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v11 = MmUserProbeAddress;
    if ( v10 + a1 > MmUserProbeAddress || v10 + a1 < a1 )
    {
      *(_BYTE *)MmUserProbeAddress = 0;
      v11 = MmUserProbeAddress;
    }
    v12 = a4;
    if ( (unsigned int)a4 >= v11 )
      v12 = (unsigned int *)v11;
    *v12 = *v12;
    v13 = *a4;
    v20 = *a4;
    if ( !v25 )
    {
      v13 = 0;
      v20 = 0;
    }
    if ( v13 )
      ProbeForWrite(v25, v13, 4);
    if ( !SeSinglePrivilegeCheck(SeSystemEnvironmentPrivilege, dword_9229F4, v8, (int)&SeSystemEnvironmentPrivilege) )
    {
      v6 = -1073741727;
      v22 = -1073741727;
      return v6;
    }
  }
  else
  {
    v13 = *a4;
    v20 = *a4;
    if ( !a3 )
    {
      v13 = 0;
      v20 = 0;
    }
  }
  v14 = ExAllocatePoolWithTag(512, v10, 1920364101);
  v15 = v14;
  v23 = v14;
  if ( !v14 )
  {
    v6 = -1073741670;
    v22 = -1073741670;
    return v6;
  }
  memmove(v14, a1, v10);
  *(_DWORD *)(v15 + 4) = v10;
  if ( v13 )
  {
    v16 = ExAllocatePoolWithTag(512, v13, 1920364101);
    v21 = v16;
    if ( !v16 )
    {
      ExFreePoolWithTag(v15);
      v23 = 0;
      v6 = -1073741670;
      v22 = -1073741670;
      return v6;
    }
  }
  else
  {
    v16 = 0;
    v21 = 0;
  }
  v6 = ExpVerifyFilePath(v15);
  if ( v6 >= 0 )
  {
    v17 = *(_DWORD *)(v15 + 8);
    if ( v27 == v17 )
    {
      if ( v13 < v24 )
        v6 = -1073741789;
      else
        memmove(v16, v15, v24);
      v13 = v24;
      goto LABEL_48;
    }
    if ( v17 )
    {
      if ( v17 <= 2 )
      {
        v18 = ExpTranslateArcPath(v15, v27, v16, &v20);
        goto LABEL_46;
      }
      if ( v17 == 3 )
      {
        v18 = ExpTranslateNtPath(v15, v27, v16, &v20);
        goto LABEL_46;
      }
      if ( v17 == 4 )
      {
        v18 = ExpTranslateEfiPath(v15, v27, v16, &v20);
LABEL_46:
        v6 = v18;
        v13 = v20;
        goto LABEL_48;
      }
    }
    v6 = -1073741811;
  }
LABEL_48:
  ExFreePoolWithTag(v15);
  if ( v6 < 0 )
    goto LABEL_51;
  if ( v16 )
  {
    memmove(v25, v16, v13);
LABEL_51:
    if ( v16 )
    {
      ExFreePoolWithTag(v16);
      v21 = 0;
    }
  }
  if ( v28 )
    *v28 = v13;
  v22 = v6;
  return v6;
}
