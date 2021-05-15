// _PnpCtxSetNtPlugPlayRoutine 
 
int __fastcall PnpCtxSetNtPlugPlayRoutine(int a1, int a2, unsigned int a3)
{
  int v3; // r4
  unsigned int *v4; // r1
  unsigned int v5; // r0

  v3 = 0;
  if ( a2 >= 6 )
    return -1073741811;
  __dmb(0xBu);
  v4 = (unsigned int *)(a1 + 4 * (a2 + 10));
  do
    v5 = __ldrex(v4);
  while ( __strex(a3, v4) );
  __dmb(0xBu);
  return v3;
}
