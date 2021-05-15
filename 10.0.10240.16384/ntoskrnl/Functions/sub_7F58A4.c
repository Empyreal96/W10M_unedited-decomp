// sub_7F58A4 
 
int sub_7F58A4(int a1, int a2, int a3, int a4, ...)
{
  int v5; // r1
  int v6; // t1
  int v7; // r7
  int v8; // r8
  int v9; // r9
  void **v10; // r6
  int i; // r4
  _DWORD v12[16]; // [sp-40h] [bp-40h] BYREF
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KiStackAttachProcess(v7, 0, (int)va);
  v10 = &PspSystemDlls;
  for ( i = 0; i < 2; ++i )
  {
    v6 = (int)*v10++;
    v5 = v6;
    if ( v6 )
    {
      v8 = PspMapSystemDll(v7, v5, v9, 0);
      if ( v8 < 0 )
        break;
    }
  }
  KiUnstackDetachProcess((unsigned int)v12, 0);
  return ((int (__fastcall *)(int))v12[15])(v8);
}
