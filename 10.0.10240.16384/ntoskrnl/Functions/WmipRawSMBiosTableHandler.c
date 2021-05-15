// WmipRawSMBiosTableHandler 
 
int __fastcall WmipRawSMBiosTableHandler(_DWORD *a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r2
  int v5; // r3
  int v6; // r3
  int v7[2]; // [sp+0h] [bp-8h] BYREF

  v7[0] = 0;
  if ( !a1 )
    return -1073741585;
  v2 = a1[1];
  if ( !v2 )
    return sub_52850C();
  if ( v2 != 1 )
    return -1073741585;
  v4 = WmipGetSMBiosTableData(0, v7, 0);
  result = -1073741789;
  if ( v4 != -1073741789 || !v7[0] )
  {
    v6 = 0;
    result = v4;
LABEL_13:
    a1[3] = v6;
    return result;
  }
  if ( a1[3] >= (unsigned int)(v7[0] + 8) )
  {
    result = WmipGetSMBiosTableData(a1 + 6, v7, a1 + 4);
    v5 = v7[0];
    if ( result >= 0 )
      a1[5] = v7[0];
    v6 = v5 + 8;
    goto LABEL_13;
  }
  a1[3] = v7[0] + 8;
  return result;
}
