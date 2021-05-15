// BiOpenKey 
 
int __fastcall BiOpenKey(int a1, unsigned __int16 *a2, int a3, _DWORD *a4)
{
  _BYTE *v7; // r8
  BOOL v8; // r9
  int v9; // r4
  int v10; // r0
  int v12; // [sp+10h] [bp-48h]
  _DWORD _18[20]; // [sp+18h] [bp-40h] BYREF
  int varg_r2; // [sp+68h] [bp+10h]
  _DWORD *varg_r3; // [sp+6Ch] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  _18[19] = a2;
  _18[18] = a1;
  v7 = 0;
  RtlInitUnicodeString((unsigned int)_18, a2);
  varg_r2 = a3 | 0x40000;
  v8 = (varg_r2 & 0x60019) != varg_r2;
  _18[2] = 24;
  _18[3] = a1;
  _18[5] = 576;
  _18[4] = _18;
  _18[6] = 0;
  _18[7] = 0;
  v9 = BiZwOpenKey();
  if ( v9 < 0 )
    goto LABEL_8;
  if ( !v8 )
  {
    v10 = 0;
    goto LABEL_7;
  }
  v7 = BiCreateKeySecurityDescriptor(983103);
  v9 = BiZwSetSecurityObject();
  if ( v9 < 0 || (v9 = BiZwOpenKey(), v9 < 0) )
  {
LABEL_8:
    v10 = 0;
    goto LABEL_9;
  }
  BiZwClose();
  v10 = v12;
LABEL_7:
  *a4 = v10;
LABEL_9:
  if ( v9 < 0 && v10 )
    BiZwClose();
  if ( v7 )
    ExFreePoolWithTag((unsigned int)v7);
  if ( v9 == -1073741443 )
    __debugbreak();
  return v9;
}
