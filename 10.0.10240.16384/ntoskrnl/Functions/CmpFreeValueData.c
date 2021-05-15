// CmpFreeValueData 
 
int __fastcall CmpFreeValueData(int a1, unsigned int a2, unsigned int a3)
{
  if ( a3 < 0x80000000 && a2 != -1 )
  {
    if ( *(_DWORD *)(a1 + 148) >= 4u && a3 - 16345 <= 0x7FFFC026 )
      return sub_805E7C();
    HvFreeCell(a1, a2);
  }
  return 1;
}
