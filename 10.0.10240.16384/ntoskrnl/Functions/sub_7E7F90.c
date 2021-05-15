// sub_7E7F90 
 
void sub_7E7F90()
{
  int *v0; // r5
  int v1; // r1
  unsigned int v2; // r0
  unsigned int v3; // r2

  __pld(v0);
  v1 = *v0;
  if ( (*v0 & 0xFFFFFFF0) <= 0x10 )
    v2 = 0;
  else
    v2 = v1 - 16;
  if ( (v1 & 2) != 0 )
    goto LABEL_9;
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)v0);
  while ( v3 == v1 && __strex(v2, (unsigned int *)v0) );
  if ( v3 != v1 )
LABEL_9:
    ExfReleasePushLock(v0, v1);
  KeAbPostRelease((unsigned int)v0);
  JUMPOUT(0x6F9CD8);
}
