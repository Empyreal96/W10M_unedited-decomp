// DrvDbSetDeviceIdDriverInfMatches 
 
int __fastcall DrvDbSetDeviceIdDriverInfMatches(int a1, int a2, unsigned __int16 *a3)
{
  int v4; // r10
  int v5; // r4
  unsigned int v6; // r8
  int v7; // r3
  unsigned __int16 *v8; // r5
  _WORD *v9; // r0
  unsigned int v10; // r3
  int v11; // r0
  unsigned __int16 *v12; // r5
  int v13; // r9
  unsigned __int16 *v14; // r7
  int v15; // r10
  int v16; // r0
  int v17; // r0
  unsigned int v18; // r7
  int v19; // r0
  int v20; // r6
  int v21; // r0
  unsigned int v24; // [sp+14h] [bp-3Ch] BYREF
  int v25; // [sp+18h] [bp-38h] BYREF
  int v26; // [sp+1Ch] [bp-34h] BYREF
  char v27[8]; // [sp+20h] [bp-30h] BYREF
  char v28[40]; // [sp+28h] [bp-28h] BYREF

  v24 = 0;
  v25 = 0;
  v26 = 0;
  v4 = a2;
  v5 = PnpCtxRegQueryInfoKey(a1, a2, 0, (int)&v24, (int)&v24);
  if ( v5 >= 0 )
  {
    v6 = v25 + 1;
    if ( a3 )
    {
      v7 = *a3;
      v8 = a3;
      while ( v7 )
      {
        v9 = wcschr(v8, 92);
        if ( v9 )
          v10 = v9 - v8 + 1;
        else
          v10 = wcslen(v8) + 1;
        if ( v10 > v6 )
          v6 = v10;
        v8 += wcslen(v8) + 1;
        v7 = *v8;
      }
      v11 = ExAllocatePoolWithTag(1, 2 * v6, 1111770192);
      v12 = (unsigned __int16 *)v11;
      if ( !v11 )
        return -1073741801;
      v13 = 0;
      if ( v24 )
      {
        while ( 1 )
        {
          v25 = v6;
          v11 = PnpCtxRegEnumValue(v11, a2, v13, (int)v12, (int)&v25, (int)&v26, 0, 0);
          v5 = v11;
          if ( v11 < 0 )
            break;
          if ( v26 == 3 || !v26 )
          {
            v14 = a3;
            if ( *a3 )
            {
              v15 = v25;
              do
              {
                v11 = wcsncmp(v14, v12, v15);
                if ( !v11 && (v14[v15] == 92 || !v14[v15]) )
                  break;
                v11 = wcslen(v14);
                v14 += v11 + 1;
              }
              while ( *v14 );
            }
            if ( !*v14 )
            {
              v11 = RtlInitUnicodeStringEx((int)v28, v12);
              v5 = v11;
              if ( v11 >= 0 )
              {
                v11 = ZwDeleteValueKey();
                v5 = v11;
              }
              if ( v5 == -1073741772 )
              {
                v5 = 0;
              }
              else if ( v5 < 0 )
              {
                goto LABEL_58;
              }
            }
          }
          if ( ++v13 >= v24 )
            goto LABEL_33;
        }
        if ( v11 == -2147483622 )
          v5 = 0;
LABEL_33:
        v4 = a2;
      }
      if ( v5 >= 0 )
      {
        while ( *a3 )
        {
          v16 = DrvDbSplitDeviceIdDriverInfMatch(a3, v12, v6, (int)v27);
          v5 = v16;
          if ( v16 < 0 )
            break;
          v17 = v27[0] ? PnpCtxRegSetValue(v16, v4, (int)v12, 3, (int)v27, 4) : PnpCtxRegSetValue(
                                                                                  v16,
                                                                                  v4,
                                                                                  (int)v12,
                                                                                  0,
                                                                                  0,
                                                                                  0);
          v5 = v17;
          if ( v17 < 0 )
            break;
          a3 += wcslen(a3) + 1;
        }
      }
    }
    else
    {
      v18 = v24;
      if ( !v24 )
        return 0;
      v19 = ExAllocatePoolWithTag(1, 2 * v6, 1111770192);
      v12 = (unsigned __int16 *)v19;
      if ( !v19 )
        return -1073741801;
      v20 = 0;
      if ( v18 )
      {
        while ( 1 )
        {
          v25 = v6;
          v21 = PnpCtxRegEnumValue(v19, a2, v20, (int)v12, (int)&v25, 0, 0, 0);
          v5 = v21;
          if ( v21 < 0 )
            break;
          v19 = RtlInitUnicodeStringEx((int)v28, v12);
          v5 = v19;
          if ( v19 >= 0 )
          {
            v19 = ZwDeleteValueKey();
            v5 = v19;
          }
          if ( v5 == -1073741772 )
          {
            v5 = 0;
          }
          else if ( v5 < 0 )
          {
            goto LABEL_58;
          }
          if ( ++v20 >= v18 )
            goto LABEL_58;
        }
        if ( v21 == -2147483622 )
          v5 = 0;
      }
    }
LABEL_58:
    ExFreePoolWithTag((unsigned int)v12);
  }
  return v5;
}
