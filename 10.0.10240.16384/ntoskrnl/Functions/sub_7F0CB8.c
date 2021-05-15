// sub_7F0CB8 
 
void __fastcall sub_7F0CB8(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r5

  memmove(v5, *(_DWORD *)(v4 + 2524), 4 * a4);
  ExFreePoolWithTag(*(_DWORD *)(v4 + 2524));
  JUMPOUT(0x785FE2);
}
