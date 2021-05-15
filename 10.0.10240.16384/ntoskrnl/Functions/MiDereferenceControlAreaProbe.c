// MiDereferenceControlAreaProbe 
 
int __fastcall MiDereferenceControlAreaProbe(int result)
{
  unsigned __int64 *v1; // r3
  unsigned __int64 v2; // kr00_8

  v1 = (unsigned __int64 *)(result + 64);
  do
    v2 = __ldrexd(v1);
  while ( __strexd(v2 - 1, v1) );
  if ( v2 == 1 )
    result = MiDeleteControlArea();
  return result;
}
