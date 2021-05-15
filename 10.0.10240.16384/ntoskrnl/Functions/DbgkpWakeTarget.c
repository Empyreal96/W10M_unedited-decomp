// DbgkpWakeTarget 
 
unsigned int __fastcall DbgkpWakeTarget(int *a1)
{
  int v2; // r4
  unsigned int *v3; // r0
  unsigned int v4; // r4
  unsigned int v5; // r1
  unsigned int result; // r0

  v2 = a1[9];
  if ( (a1[11] & 0x20) != 0 )
    PsResumeThread(a1[9], 0);
  if ( (a1[11] & 8) != 0 )
  {
    v3 = (unsigned int *)(v2 + 940);
    __pld((void *)(v2 + 940));
    v4 = *(_DWORD *)(v2 + 940) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v5 = __ldrex(v3);
    while ( v5 == v4 && __strex(v4 - 2, v3) );
    if ( v5 != v4 )
      ExfReleaseRundownProtection((unsigned __int8 *)v3);
  }
  if ( (a1[11] & 2) != 0 )
    result = DbgkpFreeDebugEvent(a1);
  else
    result = KeSetEvent((int)(a1 + 2), 0, 0);
  return result;
}
