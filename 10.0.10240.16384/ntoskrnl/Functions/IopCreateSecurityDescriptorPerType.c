// IopCreateSecurityDescriptorPerType 
 
int __fastcall IopCreateSecurityDescriptorPerType(_BYTE *a1, int a2, unsigned __int8 **a3, int *a4)
{
  int v4; // r5
  int v7; // r4
  int result; // r0
  int v9; // r10
  int v10; // r0
  unsigned __int8 *v11; // r8
  int v12; // r1
  int v13; // r3

  v4 = 0;
  if ( a2 == 2 )
  {
    v7 = SePublicDefaultUnrestrictedDacl;
  }
  else
  {
    if ( a2 != 4 )
      return sub_7EE410();
    v7 = SePublicOpenUnrestrictedDacl;
    v4 = 1;
  }
  RtlCreateSecurityDescriptor(a1, 1);
  if ( v4 == 1 )
  {
    v9 = *(unsigned __int8 *)(SeLowMandatorySid + 1) + 6;
    v10 = ExAllocatePoolWithTag(1, 4 * v9, 1699966793);
    v11 = (unsigned __int8 *)v10;
    if ( !v10 )
      return -1073741670;
    RtlCreateAcl(v10, 4 * v9, 2);
    RtlAddMandatoryAce(v11, v12, 0, SeLowMandatorySid, a2, 1);
    RtlSetSaclSecurityDescriptor((int)a1, 1, (int)v11, 0);
    *a3 = v11;
  }
  result = RtlSetDaclSecurityDescriptor((int)a1, 1, v7, 0);
  if ( a4 )
  {
    v13 = *a4 | 4;
    *a4 = v13;
    if ( v4 )
      *a4 = v13 | 0x10;
  }
  return result;
}
