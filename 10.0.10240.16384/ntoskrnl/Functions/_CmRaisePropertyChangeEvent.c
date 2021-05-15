// _CmRaisePropertyChangeEvent 
 
int __fastcall CmRaisePropertyChangeEvent(int result, int a2, int a3, int a4, int (*a5)[5])
{
  int v6; // r8
  int (**v7)[5]; // r4
  unsigned int i; // r5
  int (**v9)[5]; // r2
  int v10; // r0
  int v11; // r1
  int v12; // r3
  int (__fastcall *v13)(int, int, int, int, _DWORD *); // r4
  int v14; // [sp+8h] [bp-30h]
  _DWORD v15[10]; // [sp+10h] [bp-28h] BYREF

  v14 = a2;
  v6 = result;
  if ( a3 != 1 )
    return sub_7EF10C();
  v7 = &CmDeviceRegPropMap;
  for ( i = 0; i < 0x21; ++i )
  {
    v9 = v7;
    if ( v7[2] == a5 )
      break;
    v9 = 0;
    v7 += 4;
  }
  if ( v9 && *v9 )
  {
    v10 = CmMapCmObjectTypeToPnpObjectType(1);
    result = PnpObjectRaisePropertyChangeEvent(v6, v11, v10, a4, 0, v12);
    a2 = v14;
  }
  v13 = *(int (__fastcall **)(int, int, int, int, _DWORD *))(v6 + 164);
  if ( v13 )
  {
    v15[0] = a4;
    v15[1] = a5;
    result = v13(v6, a2, 1, 4, v15);
  }
  return result;
}
