// sub_80CCF4 
 
void __fastcall sub_80CCF4(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7, int a8)
{
  int v8; // r4
  _DWORD *v9; // r6
  int v10; // r7
  int v11; // r8

  if ( a7 )
  {
    if ( (*(int (__fastcall **)(_DWORD, int, int, int))(a7 + 16))(*(_DWORD *)(a7 + 4), v10, v8, v11) >= 0 && a8 )
      *v9 = *(_DWORD *)(*(_DWORD *)(a8 + 176) + 20);
    (*(void (__fastcall **)(_DWORD))(a7 + 12))(*(_DWORD *)(a7 + 4));
    ExFreePoolWithTag(a7);
    JUMPOUT(0x794134);
  }
  JUMPOUT(0x794132);
}
