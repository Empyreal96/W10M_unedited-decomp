// AlpcpValidateAndSetPortAttributes 
 
int __fastcall AlpcpValidateAndSetPortAttributes(int a1, int a2, int a3, int *a4, unsigned int a5, char a6, char a7)
{
  int *v7; // r5
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r3
  int result; // r0
  unsigned int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18[18]; // [sp+0h] [bp-48h] BYREF

  v7 = (int *)a2;
  if ( a2 )
  {
    v11 = *(_DWORD *)(a2 + 16);
    if ( v11 < 0x18
      || v11 > 0xFFEF
      || (*v7 & 0x100000) != 0 && *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      return -1073741811;
    }
    v12 = v7[10];
    *v7 &= 0x1FF0000u;
    v7[10] = v12 & 0xFFD;
  }
  else
  {
    AlpcpInitializeDefaultPortAttributes(v18);
    v7 = v18;
    if ( a7 )
      v18[0] |= 0x1000u;
  }
  v13 = (*(_DWORD *)(a1 + 244) >> 1) & 3;
  if ( v13 == 2 )
  {
    if ( v7 == v18 )
      *v7 |= 0x10000u;
    if ( !a7 )
    {
      v15 = *(_DWORD *)(a3 + 168);
      if ( v7[4] > v15 )
        v7[4] = v15;
      goto LABEL_9;
    }
    *v7 |= 0x20000u;
    if ( a4 )
    {
      v16 = a4[1];
      v17 = a4[2];
      v7[1] = *a4;
      v7[2] = v16;
      v7[3] = v17;
    }
LABEL_26:
    v7[4] = *(_DWORD *)(a3 + 168);
    goto LABEL_9;
  }
  if ( v13 != 1 )
  {
    *v7 &= 0xFFFDFFFF;
    if ( !a7 )
      goto LABEL_9;
    goto LABEL_26;
  }
  *v7 |= 0x20000u;
  if ( a7 )
  {
    if ( a5 > LpcLegacyMaxMessageLength )
      return -1073741811;
    if ( a6 )
      return sub_7F45AC();
    v7[4] = a5;
  }
LABEL_9:
  result = SeValidateSecurityQos(v7 + 1);
  if ( result >= 0 )
  {
    memmove(a1 + 152, (int)v7, 0x2Cu);
    result = 0;
  }
  return result;
}
