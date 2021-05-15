// sub_7F0CD4 
 
void __fastcall sub_7F0CD4(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v7; // r4
  int v8; // r5
  int v9; // r9

  if ( a7[1] == 4 && a7[3] == 4 )
    v9 = *(_DWORD *)((char *)a7 + a7[2]);
  else
    v7 = -1073741823;
  ExFreePoolWithTag((unsigned int)a7);
  if ( v7 >= 0 && (v9 & 0xB) != 0 && IopGetRegistryValue(v8, L"Start", 0, (int *)&a7) >= 0 )
    JUMPOUT(0x78608C);
  JUMPOUT(0x7860C4);
}
