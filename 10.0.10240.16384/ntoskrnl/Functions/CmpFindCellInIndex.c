// CmpFindCellInIndex 
 
unsigned int __fastcall CmpFindCellInIndex(unsigned __int16 *a1, int a2)
{
  unsigned int v3; // r5
  unsigned int result; // r0
  int v5; // r4
  unsigned __int16 *v6; // r3

  v3 = a1[1];
  result = 0;
  if ( v3 )
  {
    v5 = *a1;
    do
    {
      if ( v5 == 26220 || v5 == 26732 )
        v6 = &a1[4 * result];
      else
        v6 = &a1[2 * result];
      if ( *((_DWORD *)v6 + 1) == a2 )
        break;
      result = (unsigned __int16)(result + 1);
    }
    while ( result < v3 );
  }
  return result;
}
