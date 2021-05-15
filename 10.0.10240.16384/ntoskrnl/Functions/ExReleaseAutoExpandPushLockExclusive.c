// ExReleaseAutoExpandPushLockExclusive 
 
unsigned int __fastcall ExReleaseAutoExpandPushLockExclusive(int *a1, int a2, int a3)
{
  char v3; // r5
  int v5; // r3
  int v6; // r2
  int v7; // r1
  unsigned int result; // r0
  unsigned int v9; // r2

  v3 = a2;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    sub_521630(a1, a2, a3, a2 & 0xFFFFFFFC);
  v5 = a1[1];
  if ( (v5 & 1) != 0 )
  {
    ExpReleaseFannedOutPushLockExclusive(v5 & 0xFFFFFFF8);
  }
  else
  {
    v6 = a1[2];
    if ( (v6 & 0xF0000u) < 0xF0000 )
      a1[2] = v6 + 0x10000;
  }
  __pld(a1);
  v7 = *a1;
  if ( (*a1 & 0xFFFFFFF0) > 0x10 )
    result = v7 - 16;
  else
    result = 0;
  if ( (v7 & 2) != 0 )
    goto LABEL_17;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)a1);
  while ( v9 == v7 && __strex(result, (unsigned int *)a1) );
  if ( v9 != v7 )
LABEL_17:
    result = ExfReleasePushLock(a1);
  if ( (v3 & 2) == 0 )
    result = KeAbPostRelease(a1);
  return result;
}
