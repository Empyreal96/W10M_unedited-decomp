// ViGenericAddDevice 
 
int __fastcall ViGenericAddDevice(int a1)
{
  int v1; // r3
  int (*v2)(void); // r2
  int result; // r0

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 32);
  if ( !v1 || (v2 = *(int (**)(void))(v1 + 12)) == 0 )
    KeBugCheckEx(196, 4115, a1, v1, 0);
  if ( pXdvAddDevice )
    result = pXdvAddDevice();
  else
    result = v2();
  return result;
}
