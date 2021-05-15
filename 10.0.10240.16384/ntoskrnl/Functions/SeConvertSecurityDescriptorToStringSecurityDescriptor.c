// SeConvertSecurityDescriptorToStringSecurityDescriptor 
 
signed int __fastcall SeConvertSecurityDescriptorToStringSecurityDescriptor(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  _WORD *v6; // r0
  signed int result; // r0

  if ( a1 && a3 || !a4 )
  {
    if ( a1 && a4 && a3 )
      result = LocalConvertSDToStringSD_Rev1(a1, a2, a3, a1, a3, a4, a5);
    else
      result = 87;
    if ( result > 0 )
      result = (unsigned __int16)result | 0xC0070000;
  }
  else
  {
    v6 = (_WORD *)SddlpAlloc(2);
    *a4 = v6;
    if ( v6 )
    {
      *v6 = 0;
      if ( a5 )
        *a5 = 0;
      result = 0;
    }
    else
    {
      result = -1073283064;
    }
  }
  return result;
}
