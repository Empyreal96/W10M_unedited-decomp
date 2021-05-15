// SeRegisterImageVerificationCallback 
 
int __fastcall SeRegisterImageVerificationCallback(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v7; // r0
  unsigned int v8; // r1

  if ( a1 != 1 )
    return -1073741585;
  if ( a2 )
    return -1073741584;
  if ( a5 )
    return -1073741581;
  v7 = ExRegisterCallback(ExCbSeImageVerificationDriverInfo, a3, a4);
  if ( !v7 )
    return -1073741801;
  __dmb(0xBu);
  do
    v8 = __ldrex(&dword_641DC8);
  while ( __strex(v8 + 1, &dword_641DC8) );
  *a6 = v7;
  return 0;
}
