// _RegRtlCopyTreeInternal 
 
int __fastcall RegRtlCopyTreeInternal(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4, unsigned __int8 a5, unsigned int a6, unsigned __int8 a7)
{
  int v10; // r10
  char v11; // r8
  unsigned __int16 *v12; // r7
  unsigned int v13; // r4
  int v14; // r4
  int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r9
  unsigned int v18; // r5
  int v19; // r6
  int v20; // r0
  unsigned int v21; // r6
  int v22; // r0
  int v23; // r8
  int v24; // r6
  int v26; // [sp+Ch] [bp-6Ch]
  unsigned int v27; // [sp+18h] [bp-60h] BYREF
  unsigned int v28; // [sp+1Ch] [bp-5Ch] BYREF
  int v29; // [sp+20h] [bp-58h] BYREF
  unsigned int v30; // [sp+24h] [bp-54h] BYREF
  unsigned int v31; // [sp+28h] [bp-50h] BYREF
  int v32; // [sp+2Ch] [bp-4Ch]
  unsigned int v33; // [sp+30h] [bp-48h] BYREF
  int v34; // [sp+34h] [bp-44h] BYREF
  int v35; // [sp+38h] [bp-40h]
  int v36; // [sp+3Ch] [bp-3Ch] BYREF
  int v37; // [sp+4Ch] [bp-2Ch]

  v28 = a6;
  v29 = 0;
  v34 = 0;
  v35 = 0;
  v10 = 0;
  v11 = 0;
  v32 = 0;
  v33 = 0;
  v31 = a3;
  v12 = 0;
  if ( RtlpGetStackLimits((int)&v30, (int)&v27, a3, 0) )
    v13 = v30;
  else
    v13 = 0;
  if ( (unsigned int)&v27 - v13 < 0x400 )
  {
    v14 = -1073741670;
    goto LABEL_82;
  }
  v14 = RegRtlOpenKeyTransacted(a1, a2, 8, 131097, (int)&v29, v28);
  if ( v14 >= 0 )
  {
    if ( !ZwQueryKey() )
    {
      if ( (v37 & 2) != 0 )
      {
        v14 = -2147483603;
        goto LABEL_82;
      }
      if ( (v37 & 1) != 0 )
        v11 = 1;
    }
    if ( !a5 )
      goto LABEL_91;
    while ( ZwQuerySecurityObject() == -1073741789 )
    {
      if ( v10 )
        ExFreePoolWithTag(v10);
      v10 = ExAllocatePoolWithTag(1, v35, 1279739218);
      if ( !v10 )
      {
        v14 = -1073741801;
        break;
      }
    }
    if ( v14 >= 0 )
    {
LABEL_91:
      if ( a7 )
      {
        v15 = v10;
        if ( !a5 )
          v15 = 0;
      }
      else
      {
        v15 = v10;
        if ( !a5 )
          v15 = 0;
      }
      v14 = RegRtlCreateKeyTransacted(v31, a4, v11, 393247, v15, 0, (int)&v34, (int)&v36, v28);
      if ( v14 >= 0 )
      {
        if ( a5 && v10 && v36 == 2 )
          ZwSetSecurityObject();
        if ( RegRtlQueryInfoKey(v29, 0, &v30, 0, &v31, &v27) )
        {
          v18 = 0;
          v33 = 0;
          v17 = 0;
        }
        else
        {
          v16 = v30;
          if ( v30 <= v31 )
            v16 = v31;
          if ( v16 )
          {
            if ( v16 + 1 < v16 )
            {
              v14 = -1073741675;
              goto LABEL_82;
            }
            ++v16;
          }
          v14 = RtlULongLongToULong(2 * v16, v16 >> 31, &v33);
          if ( v14 < 0 )
            goto LABEL_82;
          v17 = v27;
          v18 = v33;
        }
        if ( !v18 || (v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v18, 1279739218)) != 0 )
        {
          if ( !v17 || (v32 = ExAllocatePoolWithTag(1, v17, 1279739218)) != 0 )
          {
            v30 = -2147483603;
            v19 = 0;
            v31 = -2147483622;
            while ( 1 )
            {
              v27 = v18 >> 1;
              v20 = RegRtlEnumKey(v29, v19++, (int)v12, &v27);
              if ( v20 == v31 )
                break;
              if ( v20 == -1073741789 )
              {
                v14 = RtlULongLongToULong(2 * v27, v27 >> 31, &v33);
                if ( v14 < 0 )
                  goto LABEL_78;
                if ( v12 )
                  ExFreePoolWithTag((unsigned int)v12);
                v18 = v33;
                v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v33, 1279739218);
                if ( !v12 )
                {
LABEL_76:
                  v14 = -1073741801;
                  goto LABEL_78;
                }
                --v19;
              }
              else if ( v20
                     || (v12[(v18 >> 1) - 1] = 0,
                         v20 = RegRtlCopyTreeInternal(v29, v12, v34, v12, a5, v28, a7, v26),
                         v20 != v30)
                     && v20 )
              {
                v14 = v20;
                break;
              }
            }
            if ( v14 >= 0 )
            {
              v21 = v18 >> 1;
              v27 = v18 >> 1;
              v28 = v17;
              v22 = RegRtlEnumValue(v29, 0, (int)v12, &v27, &v30, v32, &v28);
              v23 = 1;
              while ( v22 != v31 )
              {
                if ( v22 == -1073741789 )
                {
                  if ( v27 > v21 )
                  {
                    v14 = RtlULongLongToULong(2 * v27, v27 >> 31, &v33);
                    if ( v14 < 0 )
                      break;
                    if ( v12 )
                      ExFreePoolWithTag((unsigned int)v12);
                    v18 = v33;
                    v12 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v33, 1279739218);
                    if ( !v12 )
                      goto LABEL_76;
                  }
                  v24 = v28;
                  if ( v28 > v17 )
                  {
                    v17 = v28;
                    if ( v32 )
                      ExFreePoolWithTag(v32);
                    v32 = ExAllocatePoolWithTag(1, v24, 1279739218);
                    if ( !v32 )
                      goto LABEL_45;
                  }
                  --v23;
                }
                else if ( v22 || (v12[v21 - 1] = 0, (v22 = RegRtlSetValue(v34, v12)) != 0) )
                {
                  v14 = v22;
                  break;
                }
                v21 = v18 >> 1;
                v27 = v18 >> 1;
                v28 = v17;
                v22 = RegRtlEnumValue(v29, v23++, (int)v12, &v27, &v30, v32, &v28);
              }
            }
LABEL_78:
            if ( v32 )
              ExFreePoolWithTag(v32);
          }
          else
          {
LABEL_45:
            v14 = -1073741801;
          }
          if ( v12 )
            ExFreePoolWithTag((unsigned int)v12);
        }
        else
        {
          v14 = -1073741801;
        }
      }
    }
  }
LABEL_82:
  if ( v29 )
    ZwClose();
  if ( v34 )
    ZwClose();
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v14;
}
