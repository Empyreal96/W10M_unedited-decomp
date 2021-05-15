// ExpWnfRegisterPermanentName 
 
int __fastcall ExpWnfRegisterPermanentName(__int64 a1, _DWORD *a2, int a3)
{
  int v4; // r4
  int v5; // r0
  unsigned int v6; // r7
  int v7; // r4
  int v8; // r0
  unsigned int v9; // r5
  unsigned __int16 v11[2]; // [sp+8h] [bp-48h] BYREF
  char *v12; // [sp+Ch] [bp-44h]
  int v13; // [sp+10h] [bp-40h] BYREF
  char var38[60]; // [sp+18h] [bp-38h] BYREF
  __int64 varg_r0; // [sp+58h] [bp+8h]
  _DWORD *varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r2 = a2;
  varg_r3 = a3;
  varg_r0 = a1;
  v11[0] = 0;
  v11[1] = 34;
  v12 = var38;
  ExpWnfComposeValueName(a1, SHIDWORD(a1), v11, (int)var38);
  v4 = ExpWnfGetNameStoreRegistryRoot((varg_r0 >> 4) & 3, &v13);
  if ( v4 >= 0 )
  {
    v5 = RtlLengthSecurityDescriptor(a2[2]);
    v6 = v5;
    v7 = v5 + 4;
    if ( a2[1] )
      v7 = v5 + 20;
    v8 = ExAllocatePoolWithTag(1, v7, 543583831);
    v9 = v8;
    if ( v8 )
    {
      memmove(v8, a2[2], v6);
      *(_DWORD *)(v6 + v9) = *a2;
      if ( a2[1] )
        return sub_7E76E8();
      v4 = ZwSetValueKey();
      ExFreePoolWithTag(v9);
    }
    else
    {
      v4 = -1073741670;
    }
  }
  return v4;
}
