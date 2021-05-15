// AslpImageRvaToVa 
 
unsigned int __fastcall AslpImageRvaToVa(int a1, int a2, unsigned int a3)
{
  int v6; // r0
  unsigned int v7; // r2

  if ( *(_BYTE *)(a2 + 31) )
  {
    if ( a3 < *(_DWORD *)(a2 + 20) )
      return *(_DWORD *)(a2 + 16) + a3;
  }
  else
  {
    v6 = AslpImageRvaToSection(a1, a3);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v6 + 20) - *(_DWORD *)(v6 + 12) + a3;
      if ( (unsigned __int64)v7 < *(_QWORD *)(a2 + 8) )
        return *(_DWORD *)(a2 + 16) + v7;
    }
  }
  return 0;
}
