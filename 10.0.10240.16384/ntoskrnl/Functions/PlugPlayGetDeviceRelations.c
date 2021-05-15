// PlugPlayGetDeviceRelations 
 
int __fastcall PlugPlayGetDeviceRelations(int *a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6)
{
  int result; // r0
  unsigned int v11; // r3
  int v12[5]; // [sp+0h] [bp-28h] BYREF

  if ( !a1 || !a5 || a6 )
    return -1073741811;
  memset(v12, 0, sizeof(v12));
  v12[0] = *a1;
  v12[1] = a1[1];
  v12[2] = a2;
  v12[3] = a4;
  v12[4] = a3;
  result = ZwPlugPlayControl();
  if ( result < 0 )
  {
    if ( result == -1073741789 )
    {
      *a5 = v12[3];
      return result;
    }
    return -1073741772;
  }
  v11 = v12[3];
  *a5 = v12[3];
  if ( !v11 )
    return -1073741772;
  if ( v11 > a4 )
    result = -1073741789;
  return result;
}
