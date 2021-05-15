// ViGenericDriverUnload 
 
int __fastcall ViGenericDriverUnload(int a1)
{
  int v1; // r3
  int (*v2)(void); // r1
  int result; // r0

  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 32);
  if ( !v1 || (v2 = *(int (**)(void))(v1 + 8)) == 0 )
    KeBugCheckEx(196, 4115, a1, v1, 0);
  if ( pXdvDriverUnload )
    result = pXdvDriverUnload();
  else
    result = v2();
  return result;
}
