// SepLocateTokenIntegrity 
 
int __fastcall SepLocateTokenIntegrity(int a1)
{
  int v1; // r2
  int result; // r0

  v1 = *(_DWORD *)(a1 + 184);
  if ( v1 == -1 )
    result = 0;
  else
    result = *(_DWORD *)(a1 + 148) + 8 * v1;
  return result;
}
