// MiCompressedRvaListFirst 
 
int __fastcall MiCompressedRvaListFirst(_DWORD *a1, _DWORD *a2)
{
  int result; // r0

  if ( !*a1 )
    return 0;
  result = a1[1];
  *a2 = result;
  a2[1] = 4;
  return result;
}
