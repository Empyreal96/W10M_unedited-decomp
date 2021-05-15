// IopLoadUnloadDriver 
 
int __fastcall IopLoadUnloadDriver(_DWORD *a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r0
  int v8; // [sp+0h] [bp-18h]
  int v9; // [sp+8h] [bp-10h] BYREF
  int v10[3]; // [sp+Ch] [bp-Ch] BYREF

  v9 = a3;
  v10[0] = a4;
  if ( a1[8] )
    return sub_7EF598();
  v6 = IopOpenRegistryKey(&v9, 0, a1[9], 131097, 0);
  if ( v6 >= 0 )
  {
    v7 = IopLoadDriver(v9, 1, 0, v10);
    v6 = v7;
    if ( v7 == -1073740955 )
    {
      v6 = v10[0];
    }
    else if ( v7 == -1073740914 )
    {
      v6 = -1073741772;
    }
    IopCallDriverReinitializationRoutines(0);
  }
  a1[10] = v6;
  KeSetEvent((int)(a1 + 4), 0, 0);
  return v8;
}
