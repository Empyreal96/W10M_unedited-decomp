// PopBatteryDeviceState 
 
int __fastcall PopBatteryDeviceState(unsigned __int16 *a1, _DWORD *a2)
{
  unsigned int v3; // r5
  __int16 v4; // r7
  unsigned __int16 *v5; // r8
  int v7; // r4
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  int *v16; // r4
  int *v17; // r8
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // r1
  unsigned int v22; // r0
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r2
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  int v34[2]; // [sp+0h] [bp-30h] BYREF
  unsigned __int16 v35; // [sp+8h] [bp-28h] BYREF
  __int16 v36; // [sp+Ah] [bp-26h]
  unsigned __int16 *v37; // [sp+Ch] [bp-24h]

  v3 = 0;
  v4 = 0;
  v35 = 0;
  v36 = 0;
  v5 = 0;
  v37 = 0;
  if ( a1 )
  {
    v7 = sub_455E68(a1, (int)a2, v34);
    if ( v7 < 0 )
      return v7;
    v5 = a1;
    v37 = a1;
    v3 = (unsigned __int16)(2 * LOWORD(v34[0]));
    v4 = 2 * LOWORD(v34[0]) + 2;
    v36 = v4;
    v35 = 2 * LOWORD(v34[0]);
  }
  if ( v3 <= 8
    || !RtlPrefixUnicodeString((unsigned __int16 *)&PopDevicePrefixNt, &v35, 0)
    && !RtlPrefixUnicodeString(L"\b\n", &v35, 0) )
  {
    return -1073741773;
  }
  v35 = v3 - 8;
  v36 = v4 - 8;
  v37 = v5 + 4;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)&PopPolicyDeviceLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( !v11 && __strex(0x11u, (unsigned int *)&PopPolicyDeviceLock) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(&PopPolicyDeviceLock, v9, (unsigned int)&PopPolicyDeviceLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v12 + 308);
  v13 = KeAbPreAcquire((unsigned int)PopCB, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex((unsigned int *)PopCB);
  while ( !v15 && __strex(0x11u, (unsigned int *)PopCB) );
  __dmb(0xBu);
  if ( v15 )
    ExfAcquirePushLockSharedEx(PopCB, v13, (unsigned int)PopCB);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = (int *)dword_61ED74;
  if ( (int *)dword_61ED74 == &dword_61ED74 )
    goto LABEL_29;
  do
  {
    v34[0] = v16[4];
    v17 = v16;
    v34[1] = v16[5] + 8;
    LOWORD(v34[0]) -= 8;
    HIWORD(v34[0]) -= 8;
    if ( RtlEqualUnicodeString(&v35, (unsigned __int16 *)v34, 1) )
      break;
    v16 = (int *)*v16;
    v17 = 0;
  }
  while ( v16 != &dword_61ED74 );
  if ( !v17 )
  {
LABEL_29:
    v7 = -1073741772;
  }
  else if ( v17[14] == 3 )
  {
    memmove((int)a2, (int)(v17 + 16), 0x24u);
    v18 = v17[26];
    v19 = v17[27];
    v20 = v17[28];
    a2[9] = v17[25];
    a2[10] = v18;
    a2[11] = v19;
    a2[12] = v20;
    v7 = 0;
  }
  else
  {
    v7 = -1073741661;
  }
  dword_61ED64 = 0;
  __pld(PopCB);
  v21 = PopCB[0];
  v22 = PopCB[0] - 16;
  if ( (PopCB[0] & 0xFFFFFFF0) <= 0x10 )
    v22 = 0;
  if ( (PopCB[0] & 2) != 0 )
    goto LABEL_37;
  __dmb(0xBu);
  do
    v23 = __ldrex((unsigned int *)PopCB);
  while ( v23 == v21 && __strex(v22, (unsigned int *)PopCB) );
  if ( v23 != v21 )
LABEL_37:
    ExfReleasePushLock(PopCB, v21);
  v24 = KeAbPostRelease((unsigned int)PopCB);
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v26 = *(_WORD *)(v25 + 0x134) + 1;
  *(_WORD *)(v25 + 308) = v26;
  if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
    KiCheckForKernelApcDelivery(v24);
  dword_61E614 = 0;
  __pld(&PopPolicyDeviceLock);
  v27 = PopPolicyDeviceLock;
  v28 = PopPolicyDeviceLock - 16;
  if ( (PopPolicyDeviceLock & 0xFFFFFFF0) <= 0x10 )
    v28 = 0;
  if ( (PopPolicyDeviceLock & 2) != 0 )
    goto LABEL_49;
  __dmb(0xBu);
  do
    v29 = __ldrex((unsigned int *)&PopPolicyDeviceLock);
  while ( v29 == v27 && __strex(v28, (unsigned int *)&PopPolicyDeviceLock) );
  if ( v29 != v27 )
LABEL_49:
    ExfReleasePushLock(&PopPolicyDeviceLock, v27);
  v30 = KeAbPostRelease((unsigned int)&PopPolicyDeviceLock);
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(v30);
  return v7;
}
