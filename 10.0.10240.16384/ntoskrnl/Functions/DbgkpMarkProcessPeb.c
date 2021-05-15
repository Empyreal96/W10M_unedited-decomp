// DbgkpMarkProcessPeb 
 
unsigned __int8 *__fastcall DbgkpMarkProcessPeb(_DWORD *a1)
{
  _DWORD *v2; // r0
  unsigned int v3; // r4
  unsigned int v4; // r1
  unsigned __int8 *result; // r0
  int v6; // r6
  int v7; // r9
  unsigned int v8; // r2
  unsigned __int8 v9; // r6
  unsigned int v10; // r1
  unsigned int v11; // r4
  unsigned int v12; // r1
  _BYTE v13[56]; // [sp+8h] [bp-38h] BYREF

  v2 = a1 + 43;
  __pld(v2);
  v3 = *v2 & 0xFFFFFFFE;
  do
    v4 = __ldrex(v2);
  while ( v4 == v3 && __strex(v3 + 2, v2) );
  __dmb(0xBu);
  if ( v4 == v3 || (result = (unsigned __int8 *)ExfAcquireRundownProtection(v2)) != 0 )
  {
    if ( a1[80] )
    {
      KiStackAttachProcess((int)a1, 0, (int)v13);
      v6 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
      v7 = KfRaiseIrql(1);
      do
        v8 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
      while ( __strex(v8 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
      __dmb(0xBu);
      if ( (v8 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v6);
      if ( v6 )
        *(_BYTE *)(v6 + 14) |= 1u;
      dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_631F7C = v7;
      *(_BYTE *)(a1[80] + 2) = a1[85] != 0;
      dword_631F64 = 0;
      v9 = dword_631F7C;
      __dmb(0xBu);
      do
        v10 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
      while ( !v10 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
      if ( v10 )
        ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v10);
      KfLowerIrql(v9);
      KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
      KiUnstackDetachProcess((unsigned int)v13, 0);
    }
    result = (unsigned __int8 *)(a1 + 43);
    __pld(a1 + 43);
    v11 = a1[43] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)result);
    while ( v12 == v11 && __strex(v11 - 2, (unsigned int *)result) );
    if ( v12 != v11 )
      result = ExfReleaseRundownProtection(result);
  }
  return result;
}
