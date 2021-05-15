// CcUnpinData 
 
int __fastcall CcUnpinData(int a1)
{
  int v1; // r1

  if ( (a1 & 1) != 0 )
  {
    v1 = 1;
    a1 &= 0xFFFFFFFE;
    return CcUnpinFileDataEx(a1, v1, 0);
  }
  if ( *(_WORD *)a1 != 762 )
  {
    v1 = 0;
    return CcUnpinFileDataEx(a1, v1, 0);
  }
  return sub_8064F0();
}
