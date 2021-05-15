// CmpUnlockNameHashEntry 
 
unsigned int __fastcall CmpUnlockNameHashEntry(unsigned int a1)
{
  int *v1; // r4
  int v2; // r1
  unsigned int v3; // r0
  unsigned int v4; // r2

  v1 = (int *)(CmpNameCacheTable
             + 8
             * (((unsigned __int16)(-30045 * (a1 ^ (a1 >> 9))) ^ (unsigned __int16)((101027 * (a1 ^ (a1 >> 9))) >> 9)) & 0x7FF));
  __pld(v1);
  v2 = *v1;
  if ( (*v1 & 0xFFFFFFF0) > 0x10 )
    v3 = v2 - 16;
  else
    v3 = 0;
  if ( (v2 & 2) != 0 )
    goto LABEL_10;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)v1);
  while ( v4 == v2 && __strex(v3, (unsigned int *)v1) );
  if ( v4 != v2 )
LABEL_10:
    ExfReleasePushLock(v1, v2);
  return KeAbPostRelease((unsigned int)v1);
}
