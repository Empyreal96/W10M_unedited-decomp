// DrvDbGetDriverPackageMappedProperty 
 
int __fastcall DrvDbGetDriverPackageMappedProperty(int a1, int a2, int a3, unsigned int a4, _DWORD *a5, int a6, int a7, unsigned int *a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, _WORD *a17, unsigned int a18)
{
  unsigned int *v18; // r10
  unsigned int v19; // r6
  unsigned int v21; // r8
  int v23; // r2
  int v24; // r4
  unsigned int *i; // r3
  int (**v26)[4]; // r7
  int v27; // r1
  int v28; // r0
  int v29; // r4
  int v30; // r0
  int v31; // r0
  int v32; // r0
  unsigned int v33; // r2
  unsigned int v34; // r0
  int v35; // r0
  _WORD *v36; // r0
  int v38; // [sp+3Ch] [bp-Ch] BYREF
  int **v39; // [sp+40h] [bp-8h]
  int v40; // [sp+44h] [bp-4h] BYREF
  __int64 savedregs; // [sp+48h] [bp+0h] BYREF

  v18 = a8;
  v19 = a4;
  *a5 = 0;
  *v18 = 0;
  v21 = 0;
  if ( *(_DWORD *)(a4 + 16) == 18 )
    return sub_7E2F4C();
  v23 = *(_DWORD *)(a4 + 16);
  v24 = 0;
  for ( i = (unsigned int *)&off_402398; ; i = (unsigned int *)HIDWORD(savedregs) )
  {
    v34 = *i;
    HIDWORD(savedregs) = i + 6;
    if ( *(_DWORD *)(v34 + 16) != v23 )
      goto LABEL_40;
    v35 = memcmp(v34, v19, 16);
    if ( !v35 )
      break;
    v23 = savedregs;
LABEL_40:
    if ( (unsigned int)++v24 >= 0x1A )
      return -1073741802;
  }
  v26 = &off_402398 + 6 * v24;
  if ( !v26 )
    return -1073741802;
  if ( a3 )
  {
    v27 = 0;
  }
  else
  {
    v35 = DrvDbOpenObjectRegKey(v39, 0, 2, v40, 1, 0, (int)&v38, 0);
    v29 = v35;
    if ( v35 < 0 )
      return v29;
    v27 = v38;
  }
  if ( v26[5] )
  {
    v40 = 48;
    v30 = ExAllocatePoolWithTag(1, 48, 1111770192);
    v21 = v30;
    if ( !v30 )
      return -1073741801;
    if ( !a3 )
      a3 = v38;
    v31 = PnpCtxRegQueryValue(v30, a3, L"Version", (_DWORD *)&savedregs + 1, v30, (unsigned int *)&v40);
    v29 = v31;
    if ( v31 == -1073741772 )
    {
      v29 = -1073741275;
    }
    else if ( v31 == -1073741789 )
    {
      v29 = -1073741595;
    }
    else if ( v31 >= 0 )
    {
      if ( HIDWORD(savedregs) == 3 && v40 == 48 )
      {
        v32 = (int)a17;
        *a5 = v26[1];
        v33 = (unsigned int)v26[5];
        *v18 = v33;
        if ( !v32 || a18 < v33 )
          goto LABEL_36;
        memmove(v32, (int)v26[4] + v21, (unsigned int)v26[5]);
      }
      else
      {
        v29 = -1073741823;
      }
    }
LABEL_24:
    if ( v21 )
      ExFreePoolWithTag(v21);
  }
  else
  {
    if ( a3 )
      v27 = a3;
    v28 = DrvDbGetRegValueMappedProperty(v35, v27, v26);
    v29 = v28;
    if ( (v28 == -1073741275 || (!v28 || v28 == -1073741789) && *a5 == 18 && *v18 == 2)
      && *(_DWORD *)(v19 + 16) == 7
      && !memcmp(a4, (unsigned int)DEVPKEY_DriverPackage_SignerName, 16) )
    {
      if ( !a3 )
        a3 = v38;
      if ( DrvDbGetDriverPackageSignerScore(v39, v40, a3, &a6) >= 0 && a6 == 218103811 )
      {
        v36 = a17;
        *a5 = 18;
        *v18 = 36;
        if ( v36 && a18 >= 0x24 )
        {
          v29 = 0;
          RtlStringCchCopyExW(v36, a18 >> 1, L"Microsoft Windows", 0);
          return v29;
        }
LABEL_36:
        v29 = -1073741789;
        goto LABEL_24;
      }
    }
  }
  return v29;
}
