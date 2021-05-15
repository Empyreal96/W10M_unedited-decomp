// IopCreateDefaultDeviceSecurityDescriptor 
 
int __fastcall IopCreateDefaultDeviceSecurityDescriptor(unsigned int a1, char a2, int a3, _BYTE *a4, int *a5, int a6, _DWORD *a7)
{
  _BYTE *v7; // r5
  bool v8; // zf
  int v9; // r1
  int v10; // r0
  __int16 v12; // r8
  unsigned __int16 v13; // r8
  int v14; // r0
  int v15; // r7
  _BYTE *v16; // [sp+0h] [bp-20h]

  v16 = a4;
  v7 = a4;
  if ( a7 )
    *a7 = 0;
  *a5 = 0;
  if ( a1 > 0x14 )
  {
    if ( a1 == 45 )
      goto LABEL_20;
    if ( a1 != 32 )
    {
      if ( a1 == 36 )
        goto LABEL_20;
      v8 = a1 == 53;
      goto LABEL_8;
    }
    goto LABEL_16;
  }
  switch ( a1 )
  {
    case 0x14u:
      goto LABEL_20;
    case 3u:
      goto LABEL_16;
    case 2u:
      goto LABEL_22;
  }
  if ( a1 != 7 )
  {
    if ( a1 <= 7 )
      goto LABEL_9;
    if ( a1 > 9 )
    {
      v8 = a1 == 18;
LABEL_8:
      if ( !v8 )
      {
LABEL_9:
        v9 = 4;
LABEL_17:
        v10 = IopCreateSecurityDescriptorPerType(a4, v9, a6, a7);
LABEL_18:
        if ( v10 >= 0 )
          return (int)v7;
        return 0;
      }
      goto LABEL_20;
    }
LABEL_16:
    v9 = 2;
    goto LABEL_17;
  }
LABEL_20:
  if ( a1 != 7 || (a2 & 1) == 0 )
    goto LABEL_16;
LABEL_22:
  v12 = *(_WORD *)(SePublicDefaultUnrestrictedDacl + 2);
  if ( !RtlGetNtProductType() )
    return 0;
  if ( v16 == (_BYTE *)1 )
  {
    v13 = v12 + 4 * (*(unsigned __int8 *)(SeInteractiveSid + 1) + 4);
    v14 = ExAllocatePoolWithTag(1, v13, 1699966793);
    v15 = v14;
    if ( !v14 )
      return 0;
    memmove(v14, SePublicDefaultUnrestrictedDacl, *(unsigned __int16 *)(SePublicDefaultUnrestrictedDacl + 2));
    *(_WORD *)(v15 + 2) = v13;
    RtlAddAccessAllowedAce(v15, 2, -1073676288, SeInteractiveSid);
    RtlCreateSecurityDescriptor(v7, 1);
    RtlSetDaclSecurityDescriptor((int)v7, 1, v15, 0);
    if ( a7 )
      *a7 |= 4u;
    v10 = 0;
    *a5 = v15;
    goto LABEL_18;
  }
  return sub_7EE3E4();
}
