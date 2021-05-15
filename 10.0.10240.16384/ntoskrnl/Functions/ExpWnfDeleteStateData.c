// ExpWnfDeleteStateData 
 
unsigned int __fastcall ExpWnfDeleteStateData(int a1)
{
  unsigned __int8 *v1; // r4
  int v3; // r0
  unsigned int v4; // r2
  unsigned int v5; // r5
  unsigned int v6; // r1
  unsigned int result; // r0

  v1 = (unsigned __int8 *)(a1 + 48);
  v3 = KeAbPreAcquire(a1 + 48, 0, 0);
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 | 1, v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7BFEE0(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = *(_DWORD *)(a1 + 52);
  *(_DWORD *)(a1 + 52) = 0;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)v1);
  while ( __strex(v6 - 1, (unsigned int *)v1) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v1);
  result = KeAbPostRelease((unsigned int)v1);
  if ( v5 )
  {
    if ( v5 != 1 )
      result = ExFreePoolWithTag(v5);
  }
  return result;
}
