// IopLiveDumpInitiateCorralStateChange 
 
int __fastcall IopLiveDumpInitiateCorralStateChange(unsigned int *a1, unsigned int a2)
{
  unsigned int *v3; // r6
  unsigned int v4; // r2
  unsigned int *v5; // r2
  unsigned int v6; // r4
  int result; // r0
  unsigned int v8; // r2
  unsigned int v9; // r3

  __dmb(0xBu);
  v3 = a1 + 3;
  do
    v4 = __ldrex(v3);
  while ( __strex(0, v3) );
  __dmb(0xBu);
  v5 = a1 + 2;
  do
    v6 = __ldrex(v5);
  while ( __strex(a2, v5) );
  __dmb(0xBu);
  result = IopLiveDumpProcessCorralStateChange(a1, a1 + 17);
  while ( 1 )
  {
    v8 = *v3;
    __dmb(0xBu);
    v9 = a1[4];
    __dmb(0xBu);
    if ( v8 == v9 )
      break;
    __dmb(0xAu);
    __yield();
  }
  return result;
}
