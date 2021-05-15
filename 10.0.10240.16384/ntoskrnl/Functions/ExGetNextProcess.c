// ExGetNextProcess 
 
int __fastcall ExGetNextProcess(int a1, int a2, int a3, int a4, int a5)
{
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3

  do
  {
    v7 = PsGetNextProcess(a1);
    a1 = v7;
    if ( !v7 )
      return 0;
    v10 = *(_DWORD *)(v7 + 192);
  }
  while ( (v10 & 0x4000000) == 0 );
  if ( !a2 )
    return a1;
  return sub_7C36FC(v7, v8, v9, v10, a5);
}
