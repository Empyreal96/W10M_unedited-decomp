// KeSignalCallDpcSynchronize 
 
int __fastcall KeSignalCallDpcSynchronize(unsigned int *a1)
{
  unsigned int v1; // r2
  unsigned int v2; // r2
  unsigned int v3; // r1
  int v4; // r3
  int result; // r0

  __dmb(0xBu);
  do
  {
    v1 = __ldrex(a1);
    v2 = v1 - 1;
  }
  while ( __strex(v2, a1) );
  __dmb(0xBu);
  v3 = ~v2 & 0x80000000;
  if ( (v2 & 0x7FFFFFFF) != 0 )
  {
    while ( (*a1 & 0x80000000) != v3 )
    {
      __dmb(0xAu);
      __yield();
    }
    __dmb(0xBu);
    result = 0;
  }
  else
  {
    v4 = a1[1] | v3;
    __dmb(0xBu);
    *a1 = v4;
    result = 1;
  }
  return result;
}
