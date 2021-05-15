// CmUnlockHiveSecurity 
 
unsigned int __fastcall CmUnlockHiveSecurity(int a1)
{
  unsigned int *v1; // r4
  int v2; // r1
  unsigned int v3; // r0
  unsigned int v4; // r2

  v1 = (unsigned int *)(a1 + 1928);
  __pld((void *)(a1 + 1928));
  v2 = *(_DWORD *)(a1 + 1928);
  if ( (v2 & 0xFFFFFFF0) > 0x10 )
    v3 = v2 - 16;
  else
    v3 = 0;
  if ( (v2 & 2) != 0 )
    goto LABEL_10;
  __dmb(0xBu);
  do
    v4 = __ldrex(v1);
  while ( v4 == v2 && __strex(v3, v1) );
  if ( v4 != v2 )
LABEL_10:
    ExfReleasePushLock(v1, v2);
  return KeAbPostRelease((unsigned int)v1);
}
