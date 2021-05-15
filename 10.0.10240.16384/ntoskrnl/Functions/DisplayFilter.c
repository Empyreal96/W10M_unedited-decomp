// DisplayFilter 
 
unsigned int __fastcall DisplayFilter(int *a1)
{
  unsigned int result; // r0

  if ( byte_64B004 || (result = strcmp(*a1, (unsigned int *)".")) != 0 )
  {
    byte_64B004 = 1;
    dword_637604 = 0;
    result = DisplayBootBitmap(1);
  }
  else
  {
    *a1 = (int)&dword_415194;
  }
  return result;
}
