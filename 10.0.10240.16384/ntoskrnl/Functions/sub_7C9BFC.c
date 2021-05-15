// sub_7C9BFC 
 
void __fastcall sub_7C9BFC(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, _DWORD *a9, int a10)
{
  _DWORD *v10; // r5
  int v11; // r4
  unsigned int v12; // r0

  v11 = IopGetRegistryValue(a10, L"CSConfigFlags", 0, (int *)&a9);
  ZwClose();
  if ( v11 >= 0 )
  {
    v12 = (unsigned int)a9;
    if ( a9[1] == 4 && a9[3] >= 4u )
      *v10 = *(_DWORD *)((char *)a9 + a9[2]);
    ExFreePoolWithTag(v12);
  }
  JUMPOUT(0x76928E);
}
