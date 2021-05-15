// RtlpRunOnceWaitForInit 
 
unsigned int __fastcall RtlpRunOnceWaitForInit(unsigned int a1, unsigned int *a2)
{
  unsigned int result; // r0
  unsigned int v5; // [sp+8h] [bp-20h] BYREF
  char v6[28]; // [sp+Ch] [bp-1Ch] BYREF

  KeInitializeEvent((int)v6, 1, 0);
  do
  {
    v5 = a1 & 0xFFFFFFFC;
    __dmb(0xBu);
    do
      result = __ldrex(a2);
    while ( result == a1 && __strex((unsigned int)&v5 + 1, a2) );
    __dmb(0xBu);
    if ( result == a1 )
    {
      KeWaitForSingleObject((unsigned int)v6, 0, 0, 0, 0);
      result = *a2;
    }
    a1 = result;
  }
  while ( (result & 3) == 1 );
  return result;
}
