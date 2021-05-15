// PspLockJobsAndProcessExclusive 
 
int __fastcall PspLockJobsAndProcessExclusive(int result, int a2, int a3)
{
  unsigned int *v3; // r6
  unsigned __int8 *v4; // r5
  unsigned int v5; // r5
  unsigned int *v6; // r4

  v3 = (unsigned int *)result;
  --*(_WORD *)(a3 + 310);
  if ( a2 )
  {
    v4 = (unsigned __int8 *)(a2 + 168);
    result = KeAbPreAcquire(a2 + 168, 0, 0);
    do
      a3 = __ldrex(v4);
    while ( __strex(a3 | 1, v4) );
    __dmb(0xBu);
    if ( (a3 & 1) != 0 )
      return sub_7C22B8(result);
    if ( result )
      *(_BYTE *)(result + 14) |= 1u;
  }
  v5 = 0;
  if ( *v3 )
  {
    v6 = v3;
    do
    {
      if ( *((_BYTE *)v6 + 8) )
        result = PspLockJobChain(v6[1], 0);
      else
        result = ExAcquireResourceExclusiveLite(v6[1] + 32, 1, a3, v6[1]);
      ++v5;
      v6 += 2;
    }
    while ( v5 < *v3 );
  }
  return result;
}
