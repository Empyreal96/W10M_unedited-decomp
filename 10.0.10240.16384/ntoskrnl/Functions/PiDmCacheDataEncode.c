// PiDmCacheDataEncode 
 
int __fastcall PiDmCacheDataEncode(int a1, _BYTE *a2, unsigned int a3, int a4, int a5, int *a6)
{
  int v7; // r6
  int v9; // r8
  int v11; // r3
  int v12; // r0
  int v13; // r0
  _BYTE v14[112]; // [sp-4h] [bp-70h] BYREF

  v7 = 0;
  v9 = (int)a2;
  if ( !a1 )
  {
    v11 = 1;
    goto LABEL_9;
  }
  if ( !a5 || a1 != a4 )
    goto LABEL_3;
  if ( a1 == 13 )
  {
    v7 = PnpStringFromGuid((int)a2, (int)v14);
    if ( v7 < 0 )
      return v7;
    a2 = v14;
  }
  else if ( a1 != 18 )
  {
    goto LABEL_3;
  }
  if ( a2 )
  {
    v12 = PiDmGetObject(a5, (int)a2, a6 + 2);
    v7 = v12;
    if ( v12 != -1073741772 )
    {
      if ( v12 < 0 )
        return v7;
      v11 = 5;
      goto LABEL_8;
    }
    v7 = 0;
  }
LABEL_3:
  if ( a1 == 13 )
    return sub_7C9024();
  if ( a3 > 4 )
  {
    v13 = ExAllocatePoolWithTag(1, a3, 1517317712);
    a6[3] = v13;
    if ( !v13 )
      return -1073741670;
    memmove(v13, v9, a3);
    v11 = 4;
  }
  else
  {
    memmove((int)(a6 + 3), v9, a3);
    v11 = 2;
  }
  a6[2] = a3;
LABEL_8:
  a6[1] = a1;
LABEL_9:
  *a6 = v11;
  return v7;
}
