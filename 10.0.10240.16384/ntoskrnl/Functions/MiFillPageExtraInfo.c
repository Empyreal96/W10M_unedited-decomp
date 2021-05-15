// MiFillPageExtraInfo 
 
unsigned int *__fastcall MiFillPageExtraInfo(unsigned int *result, int a2, int a3)
{
  unsigned int v3; // r2
  char v4; // r3

  v3 = a3 & 0xFFFFF000;
  *result = v3;
  if ( a2 )
  {
    if ( a2 == 1 )
      v4 = 1;
    else
      v4 = 2;
    *result = v3 & 0xFFFFFFFC | v4 & 3;
  }
  else
  {
    *result = v3 & 0xFFFFFFFC;
  }
  return result;
}
