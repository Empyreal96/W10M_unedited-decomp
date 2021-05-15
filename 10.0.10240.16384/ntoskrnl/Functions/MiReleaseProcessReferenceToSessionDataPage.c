// MiReleaseProcessReferenceToSessionDataPage 
 
int __fastcall MiReleaseProcessReferenceToSessionDataPage(int result, int a2, int a3, int a4, char a5, int a6, int a7, int a8, char a9)
{
  unsigned int *v9; // r2
  unsigned int v10; // r1
  unsigned int v11; // r1

  __dmb(0xBu);
  v9 = (unsigned int *)(result + 12);
  do
  {
    v10 = __ldrex(v9);
    v11 = v10 - 1;
  }
  while ( __strex(v11, v9) );
  if ( !v11 )
    result = sub_7C0984(result, 0, (int)v9, 0, a5, a6, a7, a8, a9);
  return result;
}
