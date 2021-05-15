// ViGenericDispatchHandler 
 
int __fastcall ViGenericDispatchHandler(int a1, int a2, int (*a3)(void), int a4)
{
  int v4; // r6
  int v6; // r4
  int (*v7)(void); // r2
  int result; // r0

  v4 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(*(_DWORD *)(v4 + 24) + 32);
  if ( !v6 || (v7 = *(int (**)(void))(v6 + 4 * a4 + 16)) == 0 )
    KeBugCheckEx(196, 4115, v4, v6, 0);
  if ( a3 )
    result = a3();
  else
    result = v7();
  return result;
}
