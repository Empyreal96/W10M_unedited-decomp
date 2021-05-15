// PsUnregisterMonitorServerSilo 
 
unsigned __int8 *__fastcall PsUnregisterMonitorServerSilo(int a1)
{
  unsigned int *v2; // r6
  unsigned int v3; // r1
  unsigned __int8 *result; // r0
  unsigned int v5; // r4
  unsigned int v6; // r1
  unsigned int *v7; // r5
  unsigned int v8; // r0
  unsigned int v9; // r1
  unsigned int v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  int v13[4]; // [sp+8h] [bp-38h] BYREF
  char v14[16]; // [sp+18h] [bp-28h] BYREF
  int (__fastcall *v15)(_DWORD); // [sp+28h] [bp-18h]
  int v16; // [sp+2Ch] [bp-14h]
  int v17; // [sp+30h] [bp-10h]

  __dmb(0xBu);
  v2 = (unsigned int *)(a1 + 20);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 2, v2) );
  __dmb(0xBu);
  if ( (v3 & 2) != 0 )
  {
    result = (unsigned __int8 *)(a1 + 28);
    __pld(result);
    v5 = *(_DWORD *)result & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v6 = __ldrex((unsigned int *)result);
    while ( v6 == v5 && __strex(v5 - 2, (unsigned int *)result) );
    if ( v6 != v5 )
      result = ExfReleaseRundownProtection(result);
  }
  else
  {
    if ( PsIsSystemProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)) )
    {
      PspUnregisterMonitorDeferred(a1);
    }
    else
    {
      KeInitializeEvent((int)v14, 1, 0);
      v15 = PspUnregisterMonitorDeferred;
      v16 = a1;
      v17 = 0;
      v13[2] = (int)PspDeferredWorkerRoutine;
      v13[3] = (int)v14;
      v13[0] = 0;
      ExQueueWorkItem(v13, 1);
      KeWaitForSingleObject((unsigned int)v14, 6, 0, 0, 0);
    }
    v7 = (unsigned int *)(a1 + 28);
    __pld((void *)(a1 + 28));
    v8 = *(_DWORD *)(a1 + 28) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v9 = __ldrex(v7);
    while ( v9 == v8 && __strex(v8 - 2, v7) );
    if ( v9 != v8 )
      ExfReleaseRundownProtection((unsigned __int8 *)(a1 + 28));
    do
      v10 = __ldrex(v7);
    while ( !v10 && __strex(1u, v7) );
    __dmb(0xBu);
    if ( v10 && v10 != 1 )
      ExfWaitForRundownProtectionRelease((unsigned int *)(a1 + 28), v10);
    if ( *(_BYTE *)(a1 + 68) )
      ObfDereferenceObject(*(_DWORD *)(a1 + 60));
    v11 = *v2 | 4;
    __dmb(0xBu);
    *v2 = v11;
    __dmb(0xBu);
    do
      v12 = __ldrex(v7);
    while ( __strex(1u, v7) );
    __dmb(0xBu);
    result = (unsigned __int8 *)PspPointerDereferenceMonitorServerSilo(a1, 1, v12);
  }
  return result;
}
