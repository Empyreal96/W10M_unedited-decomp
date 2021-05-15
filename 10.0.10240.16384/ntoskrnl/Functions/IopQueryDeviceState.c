// IopQueryDeviceState 
 
int __fastcall IopQueryDeviceState(int a1, _DWORD *a2)
{
  int result; // r0
  int v5; // [sp+8h] [bp-38h] BYREF
  char v6[48]; // [sp+10h] [bp-30h] BYREF

  v5 = 0;
  memset(v6, 0, 40);
  v6[0] = 27;
  v6[1] = 20;
  result = IopSynchronousCall(a1, (int)v6, -1073741637, 0, &v5);
  if ( result >= 0 )
    *a2 = v5;
  return result;
}
