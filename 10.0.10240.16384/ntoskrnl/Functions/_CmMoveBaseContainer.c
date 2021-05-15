// _CmMoveBaseContainer 
 
int __fastcall CmMoveBaseContainer(int *a1, int a2, int a3, int a4)
{
  int v7; // r7
  unsigned int v8; // r5
  unsigned __int16 *v9; // r6
  int v10; // r4
  unsigned __int16 *v12; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+Ch] [bp-24h]

  v13 = a4;
  v12 = 0;
  v7 = CmGetDevicesInBaseContainerList(a1, a3, a2, (unsigned int *)&v12);
  v8 = (unsigned int)v12;
  if ( v7 >= 0 )
  {
    v9 = v12;
    if ( *v12 )
    {
      v10 = v13;
      do
      {
        v7 = CmRemoveDeviceFromContainer(a1, a3, a2, v9);
        if ( v7 < 0 )
          break;
        v7 = CmAddDeviceToContainer((int)a1, v10, a2, (int)v9, 0);
        if ( v7 < 0 )
          break;
        v9 += wcslen(v9) + 1;
      }
      while ( *v9 );
    }
  }
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
