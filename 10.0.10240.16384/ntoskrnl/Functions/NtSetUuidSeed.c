// NtSetUuidSeed 
 
int __fastcall NtSetUuidSeed(int *a1, int a2, int a3)
{
  int v4; // r0
  _BYTE *v5; // r10
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r5
  int v9; // r0
  unsigned __int8 *v10; // r9
  int v11; // r0
  int v12; // r0
  int v13; // r0
  int v14; // r0
  int v15; // r0
  int v16; // r6
  __int16 v17; // r5
  unsigned int v18; // r9
  int v19; // r1
  unsigned int v20; // r2
  bool v21; // zf
  unsigned int v22; // r1
  int v23; // r0
  __int16 v24; // r3
  int v26; // [sp+1Ch] [bp-9Ch] BYREF
  _BYTE v27[8]; // [sp+20h] [bp-98h] BYREF
  int *v28; // [sp+28h] [bp-90h]
  char v29; // [sp+2Ch] [bp-8Ch]
  int v30; // [sp+30h] [bp-88h]
  int v31; // [sp+34h] [bp-84h]
  int v32; // [sp+38h] [bp-80h]
  int v33; // [sp+3Ch] [bp-7Ch]
  unsigned int v34; // [sp+40h] [bp-78h]
  int v35; // [sp+44h] [bp-74h] BYREF
  int v36; // [sp+48h] [bp-70h]
  _DWORD v37[4]; // [sp+50h] [bp-68h] BYREF
  _BYTE v38[24]; // [sp+60h] [bp-58h] BYREF
  _DWORD v39[6]; // [sp+78h] [bp-40h]
  int v40; // [sp+90h] [bp-28h]
  __int16 v41; // [sp+94h] [bp-24h]

  v28 = a1;
  v39[0] = 80;
  v39[1] = 521322694;
  v39[2] = 906040134;
  v39[3] = -430256637;
  v39[4] = 1525148216;
  v39[5] = -843743134;
  v27[0] = 0;
  v27[1] = 0;
  v27[2] = 0;
  v27[3] = 0;
  v27[4] = 0;
  v27[5] = 5;
  v31 = 0;
  v33 = 0;
  SeCaptureSubjectContext(v37, a2, a3, 0);
  v32 = 1;
  v36 = RtlLengthRequiredSid(6u);
  v4 = ExAllocatePoolWithTag(1, v36, 1684624725);
  v5 = (_BYTE *)v4;
  v30 = v4;
  if ( !v4 )
    RtlRaiseStatus(-1073741670);
  v6 = RtlInitializeSid(v4, (int)v27, 6u);
  v26 = v6;
  if ( v6 < 0 )
    RtlRaiseStatus(v6);
  v7 = 0;
  v34 = 0;
  while ( v7 < 6 )
  {
    *(_DWORD *)RtlSubAuthoritySid((int)v5, v7) = v39[v7];
    v34 = ++v7;
  }
  v8 = RtlLengthSid((int)v5) + 20;
  v33 = v8;
  v9 = ExAllocatePoolWithTag(1, v8, 1684624725);
  v10 = (unsigned __int8 *)v9;
  v31 = v9;
  if ( !v9 )
    RtlRaiseStatus(-1073741670);
  v11 = RtlCreateAcl(v9, v8, 2);
  v26 = v11;
  if ( v11 < 0 )
    RtlRaiseStatus(v11);
  v12 = RtlpAddKnownAce(v10, 2u, 0, 1, v5, 0);
  v26 = v12;
  if ( v12 < 0 )
    RtlRaiseStatus(v12);
  v13 = RtlCreateSecurityDescriptor(v38, 1);
  v26 = v13;
  if ( v13 < 0 )
    RtlRaiseStatus(v13);
  v14 = RtlSetDaclSecurityDescriptor((int)v38, 1, (int)v10, 0);
  v26 = v14;
  if ( v14 < 0 )
    RtlRaiseStatus(v14);
  v15 = SeAccessCheck((int)v38, (int)v37, 0, 1, 0, 0, (int)ExpUuidSeedGenericMapping, 1, (int)&v35, (int)&v26);
  v29 = v15;
  if ( !v15 )
    RtlRaiseStatus(-1073741790);
  v16 = *a1;
  v40 = v16;
  v17 = *((_WORD *)v28 + 2);
  v41 = v17;
  v26 = 0;
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  if ( v10 )
    ExFreePoolWithTag((unsigned int)v10);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v18 + 308);
  v19 = KeAbPreAcquire((unsigned int)&ExpUuidLock, 0, 0);
  v28 = (int *)v19;
  do
    v20 = __ldrex((unsigned __int8 *)&ExpUuidLock);
  while ( __strex(v20 | 1, (unsigned __int8 *)&ExpUuidLock) );
  __dmb(0xBu);
  if ( (v20 & 1) != 0 )
  {
    ExfAcquirePushLockExclusiveEx(&ExpUuidLock, v19, (unsigned int)&ExpUuidLock);
    v19 = (int)v28;
  }
  if ( v19 )
    *(_BYTE *)(v19 + 14) |= 1u;
  *(int *)((char *)&dword_9203CC + 2) = v16;
  word_9203D2 = v17;
  v21 = (v40 & 0x80) == 0;
  __dmb(0xBu);
  ExpUuidCacheValid = v21;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)&ExpUuidLock);
  while ( __strex(v22 - 1, (unsigned int *)&ExpUuidLock) );
  if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpUuidLock);
  v23 = KeAbPostRelease((unsigned int)&ExpUuidLock);
  v24 = *(_WORD *)(v18 + 308) + 1;
  *(_WORD *)(v18 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v23);
  if ( v32 )
    SeReleaseSubjectContext((int)v37);
  return 0;
}
