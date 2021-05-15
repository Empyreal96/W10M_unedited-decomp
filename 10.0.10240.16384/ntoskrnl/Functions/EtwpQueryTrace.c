// EtwpQueryTrace 
 
int __fastcall EtwpQueryTrace(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r0
  int *v8; // r5
  unsigned int v10; // r1
  __int16 v11; // r3
  int *v12; // [sp+0h] [bp-10h] BYREF

  v12 = (int *)a4;
  v5 = EtwpValidateLoggerInfo(a1);
  if ( v5 >= 0 )
  {
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = EtwpAcquireLoggerContext(a1, &v12);
    v5 = v7;
    if ( v7 >= 0 )
    {
      v8 = v12;
      v5 = EtwpCheckLoggerControlAccess(1, v12);
      if ( v5 >= 0 )
      {
        if ( (v8[152] & 0x4000) != 0 )
          return sub_8097E8();
        v5 = EtwpGetLoggerInfoFromContext((int)a1, v8);
      }
      v7 = EtwpReleaseLoggerContext(v8, 1);
    }
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v11 = *(_WORD *)(v10 + 0x134) + 1;
    *(_WORD *)(v10 + 308) = v11;
    if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
      KiCheckForKernelApcDelivery(v7);
  }
  return v5;
}
