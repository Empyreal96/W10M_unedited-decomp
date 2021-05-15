// BiCreateKey 
 
int __fastcall BiCreateKey(int a1, unsigned __int16 *a2, int a3, int a4, _DWORD *a5, bool *a6)
{
  char v6; // r6
  int v8; // r5
  int v9; // r2
  int v10; // r8
  int v11; // r10
  int v12; // r0
  unsigned int v13; // r6
  int v14; // r4
  int v15; // r0
  int v18; // [sp+24h] [bp-4Ch]
  int v19; // [sp+28h] [bp-48h]
  _DWORD _30[20]; // [sp+30h] [bp-40h] BYREF
  int varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r2 = a3;
  v6 = a4;
  varg_r3 = a4;
  _30[19] = a2;
  _30[18] = a1;
  RtlInitUnicodeString((unsigned int)_30, a2);
  v8 = a3 | 0x40000;
  varg_r2 = v8;
  v9 = 64;
  v10 = 0;
  if ( (v6 & 1) != 0 )
  {
    v9 = 192;
    if ( (v8 & 0x60019) != v8 )
      v10 = 1;
  }
  v11 = v9 | 0x200;
  v12 = BiCreateKeySecurityDescriptor(983103);
  v13 = v12;
  if ( v12 )
  {
    _30[2] = 24;
    _30[3] = a1;
    _30[5] = v11;
    _30[4] = _30;
    _30[6] = v12;
    _30[7] = 0;
    v14 = BiZwCreateKey();
    if ( v14 >= 0 )
    {
      v15 = 0;
      if ( !v10 )
      {
LABEL_11:
        if ( a6 )
          *a6 = v19 == 1;
        *a5 = v15;
LABEL_15:
        if ( v14 >= 0 )
          goto LABEL_18;
        goto LABEL_16;
      }
      v14 = BiZwSetSecurityObject();
      if ( v14 >= 0 )
      {
        v14 = BiZwOpenKey();
        if ( v14 >= 0 )
        {
          BiZwClose();
          v15 = v18;
          goto LABEL_11;
        }
      }
    }
    v15 = 0;
    goto LABEL_15;
  }
  v14 = -1073741703;
  v15 = 0;
LABEL_16:
  if ( v15 )
    BiZwClose();
LABEL_18:
  if ( v13 )
    ExFreePoolWithTag(v13);
  if ( v14 == -1073741443 )
    __debugbreak();
  return v14;
}
