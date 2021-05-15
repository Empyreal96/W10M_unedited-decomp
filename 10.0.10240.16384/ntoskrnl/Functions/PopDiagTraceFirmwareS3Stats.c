// PopDiagTraceFirmwareS3Stats 
 
int PopDiagTraceFirmwareS3Stats()
{
  int result; // r0
  unsigned int v1; // r5
  unsigned int v2; // r4
  int *v3; // r2
  int v4; // r1
  int v5; // r1
  int v6; // [sp+8h] [bp-60h] BYREF
  int v7; // [sp+Ch] [bp-5Ch] BYREF
  int v8; // [sp+10h] [bp-58h] BYREF
  int v9; // [sp+14h] [bp-54h] BYREF
  _DWORD v10[2]; // [sp+18h] [bp-50h] BYREF
  _DWORD v11[2]; // [sp+20h] [bp-48h] BYREF
  int *v12; // [sp+28h] [bp-40h]
  int v13; // [sp+2Ch] [bp-3Ch]
  int v14; // [sp+30h] [bp-38h]
  int v15; // [sp+34h] [bp-34h]
  int *v16; // [sp+38h] [bp-30h]
  int v17; // [sp+3Ch] [bp-2Ch]
  int v18; // [sp+40h] [bp-28h]
  int v19; // [sp+44h] [bp-24h]
  int *v20; // [sp+48h] [bp-20h]
  int v21; // [sp+4Ch] [bp-1Ch]
  int v22; // [sp+50h] [bp-18h]
  int v23; // [sp+54h] [bp-14h]

  result = off_617B54(35, 0, 0, &v6);
  if ( result == -1073741820 )
  {
    if ( v6 )
    {
      result = ExAllocatePoolWithTag(1, v6, 1953510227);
      v1 = result;
      if ( result )
      {
        if ( off_617B54(35, v6, result, &v6) >= 0 )
        {
          v2 = v1 + 8;
          if ( v1 + 8 < *(_DWORD *)(v1 + 4) + v1 )
          {
            while ( *(_WORD *)v2 )
            {
              if ( *(_WORD *)v2 == 1 )
              {
                v10[0] = _rt_udiv64(1000000i64, *(_QWORD *)(v2 + 4));
                v10[1] = v4;
                v11[0] = _rt_udiv64(1000000i64, *(_QWORD *)(v2 + 12));
                v11[1] = v5;
                v12 = v10;
                v13 = 0;
                v14 = 8;
                v15 = 0;
                v16 = v11;
                v17 = 0;
                v18 = 8;
                v19 = 0;
                v3 = POP_ETW_EVENT_S3FWSTATS_SUSPEND;
                goto LABEL_10;
              }
LABEL_11:
              v2 += *(char *)(v2 + 2);
              if ( v2 >= *(_DWORD *)(v1 + 4) + v1 )
                goto LABEL_12;
            }
            v9 = *(_DWORD *)(v2 + 4);
            v8 = _rt_udiv64(1000000i64, *(_QWORD *)(v2 + 8));
            v7 = _rt_udiv64(1000000i64, *(_QWORD *)(v2 + 16));
            v12 = &v9;
            v13 = 0;
            v14 = 4;
            v15 = 0;
            v16 = &v8;
            v17 = 0;
            v18 = 4;
            v19 = 0;
            v20 = &v7;
            v21 = 0;
            v22 = 4;
            v23 = 0;
            v3 = POP_ETW_EVENT_S3FWSTATS_RESUME;
LABEL_10:
            EtwWrite(PopDiagHandle, dword_61E154, (int)v3, 0);
            goto LABEL_11;
          }
        }
LABEL_12:
        result = ExFreePoolWithTag(v1);
      }
    }
  }
  return result;
}
