// ExpCovResetInformation 
 
int __fastcall ExpCovResetInformation(unsigned int a1, unsigned int a2)
{
  int v3; // r1
  int v4; // r4
  int v5; // r6
  int v6; // r10
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r1
  int *i; // r5
  int v11; // r9
  unsigned int v12; // r1
  __int16 v13; // r3
  int v15; // [sp+0h] [bp-88h] BYREF
  int v16; // [sp+4h] [bp-84h]
  int v17; // [sp+8h] [bp-80h] BYREF
  _DWORD v18[6]; // [sp+10h] [bp-78h] BYREF
  int v19; // [sp+28h] [bp-60h] BYREF
  int v20; // [sp+34h] [bp-54h] BYREF
  int v21; // [sp+38h] [bp-50h]
  int v22; // [sp+3Ch] [bp-4Ch]
  int v23; // [sp+40h] [bp-48h]
  int v24; // [sp+44h] [bp-44h]
  int v25; // [sp+48h] [bp-40h]
  int v26; // [sp+4Ch] [bp-3Ch]
  _DWORD v27[12]; // [sp+58h] [bp-30h] BYREF

  v3 = a1;
  v16 = 0;
  LOWORD(v15) = 0;
  v21 = 0;
  LOWORD(v20) = 0;
  if ( !ExCovMaxPagedPoolToUse )
    return -1073741790;
  if ( a2 < 0x14 )
    return -1073741820;
  if ( a1 >= MmUserProbeAddress )
    v3 = MmUserProbeAddress;
  memmove((int)v18, v3, 0x14u);
  v4 = ExpCovReadRequestBuffer(v18, (int)&v15, v27, &v17);
  v5 = v16;
  if ( v4 >= 0 )
  {
    v6 = v17;
    v26 = v17;
    v22 = v27[0];
    v23 = v27[1];
    v24 = v27[2];
    v25 = v27[3];
    if ( !v16 || (v4 = RtlDuplicateUnicodeString(1, (int)&v15, (int)&v20), v4 >= 0) )
    {
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 308);
      v8 = MmEnumerateSystemImages(ExpCovResetInfoCallBack, (int)&v19);
      v4 = v8;
      if ( v8 >= 0 )
      {
        ExfAcquirePushLockExclusive((int)&ExpCovPushLock);
        for ( i = (int *)ExpCovUnloadedModuleList; i != &ExpCovUnloadedModuleList; i = (int *)*i )
        {
          v11 = (int)i;
          if ( i[7] && ExpCovIsUnLoadedModulePresent((int)i, v6, (unsigned __int16 *)&v15, (unsigned __int8 *)v27) == 1 )
          {
            i = (int *)i[1];
            ExpCovDeleteUnloadedModuleEntry(v11);
          }
        }
        v8 = ExfReleasePushLock(&ExpCovPushLock, v9);
      }
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = *(_WORD *)(v12 + 0x134) + 1;
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v8);
    }
  }
  if ( v5 )
    RtlFreeAnsiString(&v15);
  if ( v21 )
    RtlFreeAnsiString(&v20);
  return v4;
}
