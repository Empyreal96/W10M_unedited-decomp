// sub_7BBFAC 
 
int sub_7BBFAC()
{
  int result; // r0
  unsigned int v1; // r2
  unsigned int v2; // r0
  unsigned int v3; // r1

  if ( off_920350
    && (dword_982168 != 3
     || (unsigned int)dword_98216C < 0x18
     || (v1 = *off_920350, dword_98216C < (unsigned int)*off_920350)
     || v1 < 0x18
     || (v2 = off_920350[1], dword_98216C < v2)
     || v1 < v2
     || (v3 = off_920350[2], dword_98216C < v3)
     || v1 < v3
     || v3 + v2 > v1) )
  {
    result = -1073741762;
  }
  else
  {
    result = 0;
  }
  return result;
}
