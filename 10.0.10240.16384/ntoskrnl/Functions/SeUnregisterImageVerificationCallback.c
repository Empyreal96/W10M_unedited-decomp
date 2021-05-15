// SeUnregisterImageVerificationCallback 
 
int __fastcall SeUnregisterImageVerificationCallback(int a1)
{
  unsigned int v1; // r1

  do
    v1 = __ldrex(&dword_641DC8);
  while ( __strex(v1 - 1, &dword_641DC8) );
  __dmb(0xBu);
  return ExUnregisterCallback(a1);
}
