// ExpWnfDeletePermanentName 
 
int __fastcall ExpWnfDeletePermanentName(__int64 a1)
{
  int v1; // r4
  int result; // r0
  __int16 v3; // [sp+0h] [bp-40h]
  __int16 v4; // [sp+2h] [bp-3Eh]
  char *v5; // [sp+4h] [bp-3Ch]
  int v6; // [sp+8h] [bp-38h] BYREF
  char v7; // [sp+10h] [bp-30h] BYREF
  __int64 vars8; // [sp+48h] [bp+8h]

  v1 = a1 >> 4;
  vars8 = a1;
  v3 = 0;
  v4 = 34;
  v5 = &v7;
  ExpWnfComposeValueName(a1, HIDWORD(a1));
  result = ExpWnfGetNameStoreRegistryRoot(v1 & 3, &v6);
  if ( result >= 0 )
    result = ZwDeleteValueKey();
  return result;
}
