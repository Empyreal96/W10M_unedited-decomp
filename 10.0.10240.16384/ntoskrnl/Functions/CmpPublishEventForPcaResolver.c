// CmpPublishEventForPcaResolver 
 
unsigned __int16 *__fastcall CmpPublishEventForPcaResolver(int a1)
{
  unsigned __int16 *result; // r0
  unsigned int v3; // r5
  unsigned __int16 *v4; // r2
  int v5; // r1
  int v6; // r1
  __int16 v7; // [sp+8h] [bp-58h] BYREF
  __int16 v8; // [sp+Ah] [bp-56h] BYREF
  __int16 *v9; // [sp+10h] [bp-50h]
  int v10; // [sp+14h] [bp-4Ch]
  int v11; // [sp+18h] [bp-48h]
  int v12; // [sp+1Ch] [bp-44h]
  int v13; // [sp+20h] [bp-40h]
  int v14; // [sp+24h] [bp-3Ch]
  int v15; // [sp+28h] [bp-38h]
  int v16; // [sp+2Ch] [bp-34h]
  __int16 *v17; // [sp+30h] [bp-30h]
  int v18; // [sp+34h] [bp-2Ch]
  int v19; // [sp+38h] [bp-28h]
  int v20; // [sp+3Ch] [bp-24h]
  int v21; // [sp+40h] [bp-20h]
  int v22; // [sp+44h] [bp-1Ch]
  int v23; // [sp+48h] [bp-18h]
  int v24; // [sp+4Ch] [bp-14h]

  result = (unsigned __int16 *)EtwAppCompatProvRegHandle;
  if ( EtwAppCompatProvRegHandle )
  {
    result = (unsigned __int16 *)EtwEventEnabled(
                                   EtwAppCompatProvRegHandle,
                                   SHIDWORD(EtwAppCompatProvRegHandle),
                                   (int)APPCOMPAT_REG_WRP_ACCESS_DENIED);
    if ( result )
    {
      result = (unsigned __int16 *)CmpConstructName(a1);
      v3 = (unsigned int)result;
      if ( result )
      {
        v4 = *(unsigned __int16 **)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 380);
        v8 = *v4 >> 1;
        v7 = *result >> 1;
        v9 = &v8;
        v10 = 0;
        v11 = 2;
        v12 = 0;
        v5 = *v4;
        v13 = *((_DWORD *)v4 + 1);
        v14 = 0;
        v15 = v5;
        v16 = 0;
        v17 = &v7;
        v18 = 0;
        v19 = 2;
        v20 = 0;
        v6 = *result;
        v21 = *((_DWORD *)result + 1);
        v22 = 0;
        v23 = v6;
        v24 = 0;
        EtwWrite(
          EtwAppCompatProvRegHandle,
          SHIDWORD(EtwAppCompatProvRegHandle),
          (int)APPCOMPAT_REG_WRP_ACCESS_DENIED,
          0);
        result = (unsigned __int16 *)ExFreePoolWithTag(v3);
      }
    }
  }
  return result;
}
