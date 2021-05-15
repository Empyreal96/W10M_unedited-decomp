// CreateMiniNtBootKey 
 
unsigned int CreateMiniNtBootKey()
{
  int v0; // r4
  int v1; // r0
  unsigned __int16 *v2; // r5
  unsigned int result; // r0
  int v4; // r3
  int v5; // r4
  int v6; // r0
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r1
  __int16 v10; // r3
  int v11; // [sp+10h] [bp-60h]
  char v12[8]; // [sp+20h] [bp-50h] BYREF
  int v13; // [sp+28h] [bp-48h]
  int v14; // [sp+2Ch] [bp-44h]
  char *v15; // [sp+30h] [bp-40h]
  int v16; // [sp+34h] [bp-3Ch]
  int v17; // [sp+38h] [bp-38h]
  int v18; // [sp+3Ch] [bp-34h]
  unsigned __int8 v19[4]; // [sp+40h] [bp-30h] BYREF
  unsigned int v20; // [sp+44h] [bp-2Ch]
  int v21; // [sp+5Ch] [bp-14h]

  v0 = 0;
  v1 = ExAllocatePoolWithTag(1, 512, 1953066569);
  v2 = (unsigned __int16 *)v1;
  if ( !v1 )
    goto LABEL_21;
  swprintf_s(v1, 256, (int)L"%s\\Control", dword_9206A4);
  v2[255] = 0;
  RtlInitUnicodeString((unsigned int)v12, v2);
  v13 = 24;
  v14 = 0;
  v16 = 64;
  v15 = v12;
  v17 = 0;
  v18 = 0;
  v0 = ZwOpenKey();
  if ( v0 < 0 )
    goto LABEL_21;
  RtlInitUnicodeString((unsigned int)v12, L"MiniNT");
  v13 = 24;
  v14 = v11;
  v16 = 64;
  v15 = v12;
  v17 = 0;
  v18 = 0;
  v0 = ZwCreateKey();
  if ( v0 >= 0 )
    ZwClose();
  ZwClose();
  if ( v0 < 0 )
LABEL_21:
    KeBugCheckEx(50, v0, 6, 0, 0);
  result = ExFreePoolWithTag((unsigned int)v2);
  v4 = (unsigned __int8)InitForceInline;
  __dmb(0xBu);
  if ( v4 == 1 )
  {
    v5 = KeAbPreAcquire((unsigned int)v19, 0, 1);
    v6 = KfRaiseIrql(1);
    do
      v7 = __ldrex(v19);
    while ( __strex(v7 & 0xFE, v19) );
    __dmb(0xBu);
    if ( (v7 & 1) != 0 )
    {
      if ( v5 )
        *(_BYTE *)(v5 + 14) |= 1u;
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = v6;
    }
    else
    {
      v6 = KfLowerIrql(v6);
      if ( v5 )
        v6 = KeAbPostReleaseEx((int)v19, v5);
      __dmb(0xAu);
      __yield();
    }
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 0x136);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x136) + 1;
    *(_WORD *)(v9 + 310) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 )
      KiCheckForKernelApcDelivery(v6);
    __mrc(15, 0, 13, 0, 3);
    result = KfRaiseIrql(2);
    VpPoolHitTag = (int)&PoolHitTag;
  }
  return result;
}
