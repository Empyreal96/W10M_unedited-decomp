// UNLOCK_POST_LIST 
 
unsigned int __fastcall UNLOCK_POST_LIST(int a1)
{
  unsigned int v1; // r1
  unsigned int result; // r0

  dword_632444 = 0;
  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&CmpPostLock);
  while ( !v1 && __strex(1u, (unsigned int *)&CmpPostLock) );
  if ( v1 )
    result = sub_806A48(a1, v1, 1);
  else
    result = KeAbPostRelease((unsigned int)&CmpPostLock);
  return result;
}
