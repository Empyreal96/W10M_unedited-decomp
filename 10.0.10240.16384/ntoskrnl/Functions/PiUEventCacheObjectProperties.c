// PiUEventCacheObjectProperties 
 
int __fastcall PiUEventCacheObjectProperties(unsigned int *a1)
{
  unsigned int v1; // r7
  unsigned int v3; // r3
  int v5; // r6
  int v6; // r0
  int v7; // r5
  int v8; // r0
  int v9; // [sp+4h] [bp-44h]
  int v10; // [sp+20h] [bp-28h] BYREF
  unsigned int v11; // [sp+24h] [bp-24h] BYREF
  int v12[8]; // [sp+28h] [bp-20h] BYREF

  v1 = 0;
  v10 = 0;
  v11 = 0;
  v12[0] = 0;
  a1[8] = -1;
  v3 = a1[15];
  a1[6] = 0;
  if ( v3 == 2 )
  {
    v7 = PnpGetObjectProperty(
           1500540496,
           200,
           (int)(a1 + 24),
           3,
           0,
           v9,
           (int)DEVPKEY_Device_InstanceId,
           (int)&v10,
           &v11,
           v12,
           0);
    v1 = v11;
    if ( v7 < 0 )
      goto LABEL_11;
    v5 = v11;
  }
  else
  {
    if ( v3 != 1 && v3 != 3 )
      return sub_7E9328();
    v5 = (int)(a1 + 20);
  }
  v6 = PnpGetObjectProperty(1500540496, 512, v5, 1, 0, v9, (int)DEVPKEY_Device_RestrictedSD, (int)&v10, a1 + 6, v12, 0);
  v7 = v6;
  if ( v6 >= 0 )
  {
    if ( v10 != 19 )
    {
      ExFreePoolWithTag(a1[6]);
      a1[6] = 0;
    }
    goto LABEL_8;
  }
  if ( v6 == -1073741275 || v6 == -1073741772 )
  {
LABEL_8:
    v8 = PnpGetObjectProperty(
           PiPnpRtlCtx,
           v5,
           1,
           0,
           0,
           (int)DEVPKEY_Device_SessionId,
           (int)&v10,
           (int)(a1 + 8),
           4,
           (int)v12,
           0);
    v7 = v8;
    if ( v8 < 0 && (v8 == -1073741275 || v8 == -1073741772) )
      v7 = 0;
  }
LABEL_11:
  if ( v1 )
    ExFreePoolWithTag(v1);
  return v7;
}
