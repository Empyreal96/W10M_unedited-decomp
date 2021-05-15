// CmpGetIndexElementSize 
 
int __fastcall CmpGetIndexElementSize(unsigned __int16 *a1)
{
  int v1; // r2
  int result; // r0

  v1 = *a1;
  if ( v1 == 26220 || v1 == 26732 )
    result = 8;
  else
    result = 4;
  return result;
}
