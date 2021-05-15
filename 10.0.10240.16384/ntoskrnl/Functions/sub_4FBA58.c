// sub_4FBA58 
 
int __fastcall sub_4FBA58(int result, int a2, int a3, int *a4)
{
  int v6; // r5
  unsigned __int16 *v7; // r8
  int v8; // t1

  v6 = a2;
  v7 = (unsigned __int16 *)result;
  if ( (*(_DWORD *)(a3 + 12) & 0x40) == 0 || *(_DWORD *)(a3 + 8) )
  {
    if ( a2 > 0 )
    {
      do
      {
        v8 = *v7++;
        --v6;
        result = sub_4FBA18(v8, a3, a4);
        if ( *a4 == -1 )
        {
          if ( gbl_errno != 42 )
            return result;
          result = sub_4FBA18(63, a3, a4);
        }
      }
      while ( v6 > 0 );
    }
  }
  else
  {
    *a4 += a2;
  }
  return result;
}
