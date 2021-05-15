// SeAdjustObjectAppContainerSecurity 
 
int __fastcall SeAdjustObjectAppContainerSecurity(unsigned __int16 *a1, int a2, int a3, _DWORD *a4, _BYTE *a5)
{
  int v9; // r4
  int v10; // r1
  unsigned __int16 *v11; // r0
  unsigned __int16 *v12; // r5
  char v14[8]; // [sp+0h] [bp-30h] BYREF
  int v15[10]; // [sp+8h] [bp-28h] BYREF

  *a5 = 0;
  *a4 = 0;
  v9 = 0;
  SepCheckForAllAppPackagesAceRemoval(a2, a3, 0, v14);
  v10 = *a1 + 2;
  v15[0] = *a1;
  v11 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v10, 1732535635);
  v12 = v11;
  if ( !v11 )
    return -1073741801;
  memset(v11, 0, v15[0] + 2);
  memmove((int)v12, *((_DWORD *)a1 + 1), *a1);
  RtlInitUnicodeString((unsigned int)v15, v12);
  if ( SepAppContainerAceProtectionApplies(v15) )
  {
    v9 = SepBuildObjectSecurityDescriptor(a2, a3, (unsigned __int8)v14[0], v15);
    if ( v9 >= 0 )
    {
      *a4 = v15[0];
      *a5 = 1;
    }
  }
  else if ( !v14[0] )
  {
    SepSqmInformation(v15);
  }
  ExFreePoolWithTag((unsigned int)v12);
  return v9;
}
