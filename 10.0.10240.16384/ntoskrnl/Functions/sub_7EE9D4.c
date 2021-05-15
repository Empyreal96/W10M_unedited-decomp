// sub_7EE9D4 
 
void sub_7EE9D4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r4
  int *v9; // r7
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r6
  int v14; // r0
  int v15; // r5
  int v16; // r2
  int v17; // r3
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  v10 = MmGetSessionById(*(_DWORD *)(v8 + 12), a2, a3, a4);
  v13 = v10;
  if ( v10 )
  {
    v14 = MmAttachSession(v10, (int)va, v11, v12);
    if ( v14 >= 0 )
    {
      KeGetCurrentIrql(v14);
      __mrc(15, 0, 13, 0, 3);
      v15 = (*(int (__fastcall **)(int, _DWORD))(v8 + 20))(a8, *(_DWORD *)(v8 + 24));
      KeGetCurrentIrql(v15);
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( v9 )
        *v9 = v15;
      MmDetachSession(v13, (int)va, v16, v17);
    }
    ObfDereferenceObject(v13);
  }
  JUMPOUT(0x780922);
}
