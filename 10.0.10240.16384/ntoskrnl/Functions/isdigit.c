// isdigit 
 
int __fastcall isdigit(int a1)
{
  int v1; // r2

  v1 = -1;
  if ( a1 != -1 )
    v1 = (unsigned __int8)a1;
  return off_60E0D8[v1] & 4;
}
