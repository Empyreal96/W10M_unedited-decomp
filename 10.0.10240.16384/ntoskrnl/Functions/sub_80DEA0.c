// sub_80DEA0 
 
void __fastcall sub_80DEA0(int a1, _DWORD *a2)
{
  int v2; // r5

  v2 = a2[5];
  if ( (*(int (__fastcall **)(_DWORD, _DWORD, int, _DWORD))(*(_DWORD *)(a2[44] + 12) + 16))(
         *(_DWORD *)(*(_DWORD *)(a2[44] + 12) + 4),
         a2[17],
         1,
         *(_DWORD *)(v2 + 32)) >= 0 )
    IopParentToRawTranslation(v2);
  JUMPOUT(0x79590C);
}
