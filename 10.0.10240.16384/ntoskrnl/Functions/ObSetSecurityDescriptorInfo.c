// ObSetSecurityDescriptorInfo 
 
int __fastcall ObSetSecurityDescriptorInfo(int a1, _DWORD *a2, int a3)
{
  int v3; // r8
  int v4; // r9
  unsigned int v6; // r4
  unsigned __int8 *v7; // r7
  int v8; // r0
  unsigned int v9; // r4
  unsigned int v10; // r6
  int v11; // r4
  unsigned int v12; // r5
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r7
  __int16 v18; // r3
  int v20; // r0
  unsigned int *v21; // r1
  unsigned int v22; // r2
  int v23; // [sp+10h] [bp-30h] BYREF
  unsigned int v24; // [sp+14h] [bp-2Ch]
  _DWORD *v25; // [sp+18h] [bp-28h]
  int v26[9]; // [sp+1Ch] [bp-24h] BYREF

  v3 = 0;
  v4 = 0;
  v23 = 0;
  v25 = a2;
  v26[0] = a3;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = (unsigned __int8 *)(a1 - 16);
  v8 = KeAbPreAcquire(a1 - 16, 0, 0);
  do
    v9 = __ldrex(v7);
  while ( __strex(v9 | 1, v7) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    return sub_7C044C(v8);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = *(_DWORD *)(a1 - 4) & 0xFFFFFFF8;
  v24 = v10;
  if ( v10 )
  {
    v11 = RtlpSetSecurityObject(v8, *v25, v26[0]);
    if ( v11 >= 0 )
    {
      v12 = v24;
      v11 = ObLogSecurityDescriptor(v24, &v23, 8);
      if ( v11 >= 0
        && (v11 = SeComputeQuotaInformationSize(v12, v26), v11 >= 0)
        && (v11 = ObAdjustSecurityQuota(a1, v26[0]), v11 >= 0) )
      {
        if ( v23 )
          v20 = v23 | 7;
        else
          v20 = 0;
        __dmb(0xBu);
        v21 = (unsigned int *)(a1 - 4);
        do
          v22 = __ldrex(v21);
        while ( __strex(v20, v21) );
        __dmb(0xBu);
        v3 = (v22 & 7) + 1;
        v4 = 0;
      }
      else
      {
        v4 = v23;
      }
      goto LABEL_12;
    }
  }
  else
  {
    v11 = -1073741609;
  }
  v12 = 0;
LABEL_12:
  __pld(v7);
  v13 = *(_DWORD *)v7;
  if ( (*(_DWORD *)v7 & 0xFFFFFFF0) > 0x10 )
    v14 = v13 - 16;
  else
    v14 = 0;
  if ( (v13 & 2) != 0 )
    goto LABEL_32;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v7);
  while ( v15 == v13 && __strex(v14, (unsigned int *)v7) );
  if ( v15 != v13 )
LABEL_32:
    ExfReleasePushLock(v7, v13);
  v16 = KeAbPostRelease((unsigned int)v7);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  if ( v4 )
    ObDereferenceSecurityDescriptor(v4, 8);
  if ( v10 && v3 )
    ObDereferenceSecurityDescriptor(v10, v3);
  if ( v12 )
    ExFreePoolWithTag(v12);
  return v11;
}
