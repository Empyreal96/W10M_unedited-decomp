// MiSelectSystemImageAddress 
 
int __fastcall MiSelectSystemImageAddress(int a1)
{
  int v1; // r0
  int result; // r0

  v1 = MiReserveDriverPtes(a1 == 2);
  if ( v1 )
    result = v1 << 10;
  else
    result = 0;
  return result;
}
