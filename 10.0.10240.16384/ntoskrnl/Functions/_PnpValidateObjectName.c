// _PnpValidateObjectName 
 
int __fastcall PnpValidateObjectName(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v8)(int, int, int); // r5
  int v10[9]; // [sp+Ch] [bp-44h] BYREF

  memset(v10, 0, sizeof(v10));
  v8 = *(int (__fastcall **)(int, int, int))(a1 + 152);
  v10[1] = a4;
  if ( v8 )
  {
    if ( v8(a1, a2, a3) != -1073741822 )
      return sub_7C9150();
    a4 = v10[1];
  }
  return PnpValidateObjectNameDispatch(a1, a2, a3, a4);
}
