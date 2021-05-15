// PiPnpRtlObjectActionCallback 
 
int __fastcall PiPnpRtlObjectActionCallback(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v6; // r4
  int *v10; // r5
  int v11; // r0
  int v13; // r1
  int v14; // r9
  int v15; // r4
  int v16; // [sp+20h] [bp-28h] BYREF
  int v17[8]; // [sp+28h] [bp-20h] BYREF

  v6 = -1073741822;
  if ( a4 != 8 )
  {
    if ( a4 == 5 )
    {
      if ( a5 == 1 && (a6[7] & 0x10000) == 0 )
        return sub_7C6828();
    }
    else
    {
      if ( a4 != 9 )
        return v6;
      if ( a5 != 1 )
      {
        if ( *a6 < 0 )
          return v6;
LABEL_14:
        PiDmObjectUpdateCachedObjectProperty(a3, a2);
        return 0;
      }
      v10 = a6;
      v6 = 0;
      if ( (a6[8] & 0x20000) != 0 )
        goto LABEL_9;
      v13 = a6[7];
      v14 = 0;
      if ( v13 )
      {
        v14 = ExAllocatePoolWithTag(1, v13, 1198550608);
        if ( !v14 )
          return 0;
      }
      v15 = PnpGetObjectProperty(PiPnpRtlCtx, a2, a3, a6[2], a6[3], a6[4], (int)&v16, v14, a6[7], (int)v17, 0);
      if ( v15 >= 0 && v16 == a6[5] && v17[0] == a6[7] && !memcmp(v14, a6[6], v17[0])
        || v15 == -1073741275 && !a6[5] && !a6[7] )
      {
        *a6 = v15;
        v6 = -1073741536;
      }
      else
      {
        v6 = 0;
      }
      if ( v14 )
        ExFreePoolWithTag(v14);
      if ( !v6 )
      {
LABEL_9:
        if ( !v10[2] )
        {
          PiPnpRtlCacheObjectBaseKey(a1, a2, a3, v10 + 2);
          return 0;
        }
        return v6;
      }
    }
    return v6;
  }
  if ( a5 != 1 )
  {
    if ( (a6[9] & 0x10000) == 0 )
    {
      if ( *a6 < 0 && *a6 != -1073741275 )
        return 0;
      goto LABEL_14;
    }
    return v6;
  }
  v10 = a6;
  v11 = PiDmObjectGetAggregatedBooleanPropertyData(a3, a2);
  if ( v11 == -1073741802 )
  {
    v6 = 0;
    if ( (a6[9] & 0x10000) != 0 )
      goto LABEL_9;
    v11 = PiDmObjectGetCachedObjectProperty(a3);
    if ( v11 < 0 && v11 != -1073741789 && v11 != -1073741275 && v11 != -1073741772 )
      goto LABEL_9;
  }
  *a6 = v11;
  return -1073741536;
}
