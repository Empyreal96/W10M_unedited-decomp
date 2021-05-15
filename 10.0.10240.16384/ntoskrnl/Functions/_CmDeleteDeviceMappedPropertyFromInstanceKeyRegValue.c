// _CmDeleteDeviceMappedPropertyFromInstanceKeyRegValue 
 
int __fastcall CmDeleteDeviceMappedPropertyFromInstanceKeyRegValue(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r3
  int v6; // r4
  int (**v7)[5]; // r9
  unsigned int i; // r8
  int (**v10)[5]; // r6
  unsigned int v11; // r1
  int (*v12)[5]; // t1
  int v13; // r0
  int v15; // [sp+10h] [bp-38h] BYREF
  int v16; // [sp+14h] [bp-34h]
  int v17; // [sp+18h] [bp-30h]
  int v18[10]; // [sp+20h] [bp-28h] BYREF

  v5 = *(_DWORD *)(a4 + 16);
  v6 = 0;
  v7 = &off_8C94D0;
  v16 = v5;
  v17 = a2;
  v18[0] = a1;
  v15 = 0;
  for ( i = 0; i < 2; ++i )
  {
    v10 = v7;
    v12 = *v7;
    v7 += 4;
    v11 = (unsigned int)v12;
    if ( v5 == (*v12)[4] )
    {
      if ( !memcmp(a4, v11, 16) )
        break;
      v5 = v16;
    }
    v10 = 0;
  }
  if ( !v10 )
    return -1073741264;
  if ( a3 || (v6 = CmOpenDeviceRegKey(v18[0], v17, 16, 0, 2, 0, (int)&v15, 0), v6 >= 0) )
  {
    v13 = RtlInitUnicodeStringEx((int)v18, (unsigned __int16 *)v10[2]);
    if ( v13 >= 0 )
      v13 = ZwDeleteValueKey();
    if ( v13 != -1073741772 && v13 != -1073741444 && v13 < 0 )
      v6 = v13;
  }
  if ( v15 )
    ZwClose();
  return v6;
}
