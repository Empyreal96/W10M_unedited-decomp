// sub_51BFE0 
 
void __fastcall sub_51BFE0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, _DWORD *a12)
{
  int v12; // r5
  int v13; // r6

  if ( a3 == 3
    && (*(unsigned __int8 *)(v12 + 1052) != *(unsigned __int16 *)(a2 + 4)
     || (*(_DWORD *)a2 & *(_DWORD *)(v12 + 1048)) == 0) )
  {
    KiSelectNextThread(v12, a12);
    *(_BYTE *)(v13 + 132) = 7;
    *(_DWORD *)(v13 + 144) = *a12;
    *a12 = v13 + 144;
  }
  JUMPOUT(0x4461E8);
}
