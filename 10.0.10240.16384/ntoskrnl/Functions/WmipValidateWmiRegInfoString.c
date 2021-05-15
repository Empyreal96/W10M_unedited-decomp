// WmipValidateWmiRegInfoString 
 
int __fastcall WmipValidateWmiRegInfoString(int a1, unsigned int a2, unsigned int a3, _DWORD *a4)
{
  if ( a3 <= a2 && (a3 & 1) == 0 )
  {
    if ( !a3 )
    {
      *a4 = 0;
      return 0;
    }
    if ( a3 + *(unsigned __int16 *)(a1 + a3) <= a2 )
    {
      *a4 = a1 + a3;
      return 0;
    }
  }
  return -1073741811;
}
