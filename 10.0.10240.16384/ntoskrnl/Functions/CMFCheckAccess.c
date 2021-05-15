// CMFCheckAccess 
 
int CMFCheckAccess(int a1, ...)
{
  char v1; // r8
  int v2; // r4
  _DWORD *v3; // r6
  unsigned int v4; // r0
  unsigned int v5; // r2
  int v6; // r7
  int v7; // r0
  _DWORD *v8; // r4
  int v9; // r6
  unsigned int v11; // [sp+18h] [bp-180h] BYREF
  int v12; // [sp+1Ch] [bp-17Ch] BYREF
  _DWORD *v13; // [sp+20h] [bp-178h] BYREF
  int v14[6]; // [sp+28h] [bp-170h] BYREF
  char v15[28]; // [sp+40h] [bp-158h] BYREF
  int v16[23]; // [sp+5Ch] [bp-13Ch] BYREF
  char v17[224]; // [sp+B8h] [bp-E0h] BYREF
  int varg_r1; // [sp+1A4h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+1A4h] [bp+Ch]
  int varg_r2; // [sp+1A8h] [bp+10h]
  va_list varg_r3; // [sp+1ACh] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, _DWORD);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r2;
  if ( !a1 )
    return -1073741811;
  v3 = (_DWORD *)(ObTypeIndexTable[*(unsigned __int8 *)(a1 - 12) ^ (unsigned __int8)((unsigned __int16)(a1 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie]
                + 52);
  RtlMapGenericMask((int *)varg_r1a, v3);
  if ( !CMFSecurityDescriptor )
  {
    v11 = 0;
    v2 = CMFCreateSecurityDescriptor(&v11, v3);
    if ( (v2 & 0xC0000000) == -1073741824 )
      return v2;
    __dmb(0xBu);
    v4 = v11;
    do
      v5 = __ldrex((unsigned int *)&CMFSecurityDescriptor);
    while ( !v5 && __strex(v4, (unsigned int *)&CMFSecurityDescriptor) );
    __dmb(0xBu);
    if ( v5 )
      ExFreePoolWithTag(v4);
  }
  v2 = SeCreateAccessState((int)v15, (int)v17, varg_r1, v3);
  if ( (v2 & 0xC0000000) != -1073741824 )
  {
    SeLockSubjectContext(v16);
    v14[0] = 1;
    v14[1] = 0;
    v14[3] = 0;
    v14[4] = 0;
    v14[2] = 18;
    v6 = SePrivilegeCheck(v14, v16, v1);
    v2 = 0;
    v11 = 0;
    v12 = 0;
    if ( v6 )
    {
      v9 = varg_r1;
    }
    else
    {
      v13 = 0;
      v7 = SeAccessCheck(CMFSecurityDescriptor, (int)v16, 1, varg_r1, 0, (int)&v13, (int)v3, v1, (int)&v11, (int)&v12);
      v8 = v13;
      v6 = v7;
      if ( v13 )
      {
        SeAppendPrivileges((int)v15, v13);
        ST_STORE<SM_TRAITS>::StDmSparseBitmapFree((int)v8);
      }
      v9 = v11;
      v2 = v12;
    }
    SeUnlockSubjectContext(v16);
    if ( (v2 & 0xC0000000) != -1073741824 )
    {
      if ( v6 && RtlAreAllAccessesGranted(v9, varg_r1) )
        v2 = 0;
      else
        v2 = -1073741790;
    }
    SepDeleteAccessState((int)v15);
    SeReleaseSubjectContext((int)v16);
  }
  return v2;
}
