// NtCreateProcess 
 
int __fastcall NtCreateProcess(int a1, int a2, int a3, int a4, char a5, int a6, int a7, int a8)
{
  int v8; // r5

  v8 = (a6 & 1) != 0;
  if ( (a7 & 1) != 0 )
    v8 |= 2u;
  if ( a5 )
    v8 |= 4u;
  return NtCreateProcessEx(a1, a2, a3, a4, v8, a6, a7, a8, 0);
}
