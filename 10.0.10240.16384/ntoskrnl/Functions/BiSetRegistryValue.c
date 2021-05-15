// BiSetRegistryValue 
 
int __fastcall BiSetRegistryValue(int a1, unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  int v6; // r5
  int v7; // r4
  _DWORD v9[2]; // [sp+8h] [bp-38h] BYREF
  int v10; // [sp+10h] [bp-30h]
  _DWORD _18[16]; // [sp+18h] [bp-28h] BYREF

  v9[1] = a4;
  _18[15] = a4;
  _18[14] = a3;
  _18[13] = a2;
  _18[12] = a1;
  RtlInitUnicodeString((unsigned int)_18, a2);
  v9[0] = 0;
  if ( a3 )
  {
    v6 = BiOpenKey(a1, a3, 131103, v9);
    v10 = v6;
    v7 = v9[0];
    if ( v6 < 0 )
      goto LABEL_6;
  }
  else
  {
    v7 = a1;
  }
  v6 = BiZwSetValueKey();
  v10 = v6;
LABEL_6:
  if ( v7 != a1 && v7 )
    BiCloseKey();
  if ( v6 == -1073741443 )
    __debugbreak();
  return v6;
}
