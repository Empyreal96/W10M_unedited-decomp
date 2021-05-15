// ExpWnfDeletePermanentStateData 
 
int __fastcall ExpWnfDeletePermanentStateData(_DWORD *a1, int a2, __int64 a3)
{
  int v3; // r5
  int v4; // r7
  int v6; // r4
  int v7; // r1
  int result; // r0
  unsigned int v9[2]; // [sp+0h] [bp-48h] BYREF
  unsigned __int16 v10[2]; // [sp+8h] [bp-40h] BYREF
  char *v11; // [sp+Ch] [bp-3Ch]
  char v12; // [sp+10h] [bp-38h] BYREF
  _DWORD *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  __int64 varg_r2; // [sp+58h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  v3 = a3 >> 4;
  v4 = a3 >> 6;
  varg_r2 = a3;
  v10[0] = 0;
  v10[1] = 34;
  v11 = &v12;
  ExpWnfComposeValueName(a3, SHIDWORD(a3), v10, SHIDWORD(a3));
  v6 = 0;
  v7 = v3 & 3;
  if ( a1 )
    result = ExpWnfGetPermanentDataStoreHandle(a1, v7, 0, v9);
  else
    result = ExpWnfEnumeratePermanentDataStores(v4 & 0xF, v7, 0, v9);
  if ( result >= 0 )
  {
    while ( 1 )
    {
      result = ZwDeleteValueKey();
      if ( a1 )
        break;
      ZwClose();
      if ( ExpWnfEnumeratePermanentDataStores(v4 & 0xF, v3 & 3, ++v6, v9) < 0 )
        return 0;
    }
  }
  return result;
}
