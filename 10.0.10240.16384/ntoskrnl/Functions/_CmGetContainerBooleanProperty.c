// _CmGetContainerBooleanProperty 
 
int __fastcall CmGetContainerBooleanProperty(int a1, int a2, int a3, int a4, _DWORD *a5, _BYTE *a6, int a7, _DWORD *a8)
{
  int result; // r0
  int v9; // [sp+8h] [bp-10h] BYREF
  int v10; // [sp+Ch] [bp-Ch]

  v9 = 0;
  v10 = 0;
  *a8 = 1;
  *a5 = 17;
  if ( !a7 )
    return -1073741789;
  v9 = a4;
  LOBYTE(v10) = 0;
  result = CmEnumDevicesInContainerWithCallback(a1, a2, a3, (int)CmGetContainerBooleanPropertyCallback, (int)&v9);
  *a6 = v10;
  return result;
}
