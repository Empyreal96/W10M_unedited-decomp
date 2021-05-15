// SePrivilegePolicyCheck 
 
int __fastcall SePrivilegePolicyCheck(_DWORD *a1, _DWORD *a2, int *a3, int a4, int **a5, char a6)
{
  int v6; // lr
  _DWORD *v7; // r8
  int v9; // r6
  int v10; // r7
  int *v12; // r0
  int *v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r2
  int v17; // [sp+8h] [bp-48h]
  int v18; // [sp+Ch] [bp-44h]
  int v19; // [sp+10h] [bp-40h]
  __int64 v21; // [sp+20h] [bp-30h] BYREF
  int v22; // [sp+28h] [bp-28h]

  v17 = a4;
  v6 = a4;
  v7 = a2;
  v9 = 0;
  v18 = 0;
  v19 = 0;
  if ( a3 )
  {
    v6 = *a3;
    v17 = *a3;
    if ( !*a3 )
      return sub_51D678();
  }
  if ( (*a1 & 0x1000000) != 0 )
  {
    v21 = SeSecurityPrivilege;
    v22 = 0;
    if ( !SepPrivilegeCheck(v6, (int *)&v21, 1, 1, a6) )
      return -1073741727;
    v19 = 1;
    v9 = 1;
    v6 = v17;
    *a1 &= 0xFEFFFFFF;
    *v7 |= 0x1000000u;
  }
  if ( (*a1 & 0x80000) != 0 )
  {
    v22 = 0;
    v21 = *(_QWORD *)&SeTakeOwnershipPrivilege;
    if ( SepPrivilegeCheck(v6, (int *)&v21, 1, 1, a6) )
    {
      v18 = 1;
      ++v9;
      *a1 &= 0xFFF7FFFF;
      *a2 |= 0x80000u;
    }
    else
    {
      v21 = *(_QWORD *)&SeRelabelPrivilege;
      v22 = 0;
      if ( SepPrivilegeCheck(v17, (int *)&v21, 1, 1, a6) )
      {
        ++v9;
        *a1 &= 0xFFF7FFFF;
        v10 = 1;
        *a2 |= 0x80000u;
        goto LABEL_5;
      }
    }
  }
  v10 = 0;
LABEL_5:
  if ( !v9 )
    return 0;
  v12 = (int *)ExAllocatePoolWithTag(1, 12 * (v9 - 1) + 20, 1917871443);
  *a5 = v12;
  if ( v12 )
  {
    *v12 = v9;
    (*a5)[1] = 0;
    if ( v18 )
    {
      v13 = *a5;
      v14 = 1;
      v13[2] = SeTakeOwnershipPrivilege;
      v13[3] = MEMORY[0x922A14];
      (*a5)[4] = 0x80000000;
    }
    else
    {
      v14 = 0;
    }
    if ( v19 )
    {
      v15 = 3 * v14++;
      *(_QWORD *)&(*a5)[v15 + 2] = SeSecurityPrivilege;
      (*a5)[v15 + 4] = 0x80000000;
    }
    if ( v10 )
    {
      v16 = (int)&(*a5)[3 * v14];
      *(_DWORD *)(v16 + 8) = SeRelabelPrivilege;
      *(_DWORD *)(v16 + 12) = MEMORY[0x922BBC];
      (*a5)[3 * v14 + 4] = 0x80000000;
    }
    return 0;
  }
  return -1073741670;
}
