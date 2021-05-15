// PiGetDeviceRegistryProperty 
 
int __fastcall PiGetDeviceRegistryProperty(int a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  int *v6; // r6
  char *v7; // r7
  char *v9; // r8
  int v10; // r2
  int v11; // r3
  int v12; // r4
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  unsigned int v17; // r5
  char *v18; // r9
  int v19; // r0
  char *v20; // r0
  int v21; // r2
  unsigned int v22; // r10
  _WORD *v23; // r0
  int *v24; // r3
  _WORD *v25; // r0
  int v26; // r1
  unsigned int *v27; // r10
  int *v29; // [sp+18h] [bp-A8h] BYREF
  int v30; // [sp+1Ch] [bp-A4h]
  char *v31; // [sp+20h] [bp-A0h] BYREF
  int v32; // [sp+24h] [bp-9Ch]
  int v33; // [sp+28h] [bp-98h]
  unsigned int *v34; // [sp+2Ch] [bp-94h]
  int v35; // [sp+30h] [bp-90h]
  int v36; // [sp+34h] [bp-8Ch]
  char *v37; // [sp+38h] [bp-88h]
  int v38; // [sp+3Ch] [bp-84h]
  int v39; // [sp+40h] [bp-80h]
  int v40; // [sp+44h] [bp-7Ch]
  char v41[8]; // [sp+48h] [bp-78h] BYREF
  int v42[28]; // [sp+50h] [bp-70h] BYREF

  v6 = 0;
  v7 = 0;
  v31 = 0;
  v32 = a5;
  v34 = a6;
  v29 = 0;
  v9 = 0;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(__int16 *)(v10 + 0x134) - 1;
  *(_WORD *)(v10 + 308) = v11;
  ExAcquireResourceExclusiveLite((int)&PnpRegistryDeviceResource, 1, v10, v11);
  v12 = PnpDeviceObjectToDeviceInstance(a1);
  if ( v12 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v41, L"LogConf");
    v33 = 0;
    v35 = 24;
    v36 = v30;
    v38 = 576;
    v37 = v41;
    v39 = 0;
    v40 = 0;
    v12 = ZwOpenKey();
    if ( v12 >= 0 )
    {
      ZwClose();
      v30 = v33;
      v13 = IopGetRegistryValue(v33, L"BootConfig", 320, (int *)&v29);
      v6 = v29;
      v12 = v13;
    }
    ZwClose();
  }
  v14 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  if ( v12 >= 0 )
  {
    v17 = v6[3];
    v18 = (char *)v6 + v6[2];
    if ( v6[1] != 1 )
      goto LABEL_18;
    v19 = PnpFindAlternateStringData(v18, v17, &v31, &v29);
    v7 = v31;
    if ( !v19 )
      goto LABEL_18;
    v17 = (unsigned int)v29;
    v18 = v31;
    v20 = wcsstr(v31, (char *)L";(");
    v21 = (v17 >> 1) - 2;
    v9 = v20;
    if ( !v20 )
      goto LABEL_18;
    if ( *(_WORD *)&v7[2 * v21] == 41
      && (*(_WORD *)v20 = 0,
          *(_WORD *)&v7[2 * v21] = 0,
          v9 = v20 + 4,
          memset(v42, 0, 80),
          v42[0] = (int)v9,
          v22 = 1,
          (v23 = wcschr(v9, 44)) != 0) )
    {
      v24 = &v42[1];
      while ( 1 )
      {
        *v23 = 0;
        v25 = v23 + 1;
        if ( v22 >= 0x13 )
          break;
        *v24 = (int)v25;
        v29 = v24 + 1;
        ++v22;
        v23 = wcschr(v25, 44);
        v24 = v29;
        if ( !v23 )
          goto LABEL_18;
      }
      v26 = 1;
    }
    else
    {
LABEL_18:
      v26 = 0;
    }
    v27 = v34;
    if ( *v34 < v17 )
    {
      v12 = -1073741789;
    }
    else if ( v6[1] == 8 )
    {
      if ( v9 )
      {
        if ( v26 )
          v12 = -1073741619;
        else
          v12 = RtlFormatMessage(v7, 0, 0, 0, 1, v42, v32, *v34, v34);
      }
      else
      {
        memmove(v32, (int)v18, v17);
      }
    }
    else
    {
      v12 = -1073741584;
    }
    *v27 = v17;
    ExFreePoolWithTag((unsigned int)v6);
  }
  return v12;
}
