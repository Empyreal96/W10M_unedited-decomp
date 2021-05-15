// ViGenericDriverStartIo 
 
int __fastcall ViGenericDriverStartIo(int a1)
{
  int v1; // r4
  int v2; // r3
  int (*v3)(void); // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(_DWORD *)(*(_DWORD *)(v1 + 24) + 32);
  if ( !v2 || (v3 = *(int (**)(void))(v2 + 4)) == 0 )
    KeBugCheckEx(196, 4115, v1, v2, 0);
  if ( pXdvDriverStartIo )
    result = pXdvDriverStartIo();
  else
    result = v3();
  return result;
}
