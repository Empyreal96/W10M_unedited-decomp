// PnpQueryDeviceText 
 
int __fastcall PnpQueryDeviceText(int a1, int a2, int a3, _DWORD *a4)
{
  int v8; // r4
  int result; // r0
  int v10; // r0
  int v11[2]; // [sp+8h] [bp-40h] BYREF
  _DWORD v12[14]; // [sp+10h] [bp-38h] BYREF

  v11[0] = 0;
  *a4 = 0;
  memset(v12, 0, 40);
  LOWORD(v12[0]) = 3099;
  v12[2] = a2;
  v12[3] = a3;
  v8 = IopSynchronousCall(a1, (int)v12, -1073741637, 0, v11);
  if ( !v11[0] )
    v8 = -1073741637;
  if ( v8 >= 0 && (v10 = v11[0], *a4 = v11[0], PiNormalizeDeviceText(v10, v11) >= 0) && v11[0] )
    result = sub_7CB6DC();
  else
    result = v8;
  return result;
}
