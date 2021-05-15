// wcscpy 
 
int __fastcall wcscpy(int result, unsigned __int16 *a2)
{
  int v2; // r2
  int v3; // r3

  v2 = result - (_DWORD)a2;
  do
  {
    v3 = *a2;
    *(unsigned __int16 *)((char *)a2++ + v2) = v3;
  }
  while ( v3 );
  return result;
}
