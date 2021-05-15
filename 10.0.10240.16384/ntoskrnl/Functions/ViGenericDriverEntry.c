// ViGenericDriverEntry 
 
int __fastcall ViGenericDriverEntry(int a1)
{
  int (**v1)(void); // r3
  int result; // r0

  v1 = *(int (***)(void))(*(_DWORD *)(a1 + 24) + 32);
  if ( !v1 || !*v1 )
    KeBugCheckEx(196, 4115, a1, (int)v1, 0);
  if ( pXdvDriverEntry )
    result = pXdvDriverEntry();
  else
    result = (*v1)();
  return result;
}
