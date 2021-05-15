// IoVolumeDeviceToGuidPath 
 
int __fastcall IoVolumeDeviceToGuidPath(int a1, unsigned __int16 *a2)
{
  int v3; // r10
  int *v4; // r5
  int v7; // r0
  int v8; // r4
  int v9; // r8
  _BYTE *v10; // r0
  unsigned int v11; // r9
  int v12; // r0
  int v13; // r4
  int v14; // r0
  unsigned int v15; // r8
  int *v16; // r7
  int v17; // r10
  unsigned __int16 v18; // r3
  int v19; // r0
  int v20; // [sp+18h] [bp-270h] BYREF
  int v21; // [sp+1Ch] [bp-26Ch]
  int v22; // [sp+20h] [bp-268h]
  int v23; // [sp+28h] [bp-260h]
  int v24; // [sp+2Ch] [bp-25Ch] BYREF
  char v25[16]; // [sp+30h] [bp-258h] BYREF
  char v26[8]; // [sp+40h] [bp-248h] BYREF
  int v27[8]; // [sp+48h] [bp-240h] BYREF
  unsigned __int16 v28; // [sp+68h] [bp-220h] BYREF
  char v29[542]; // [sp+6Ah] [bp-21Eh] BYREF

  v23 = 0;
  v24 = 0;
  v3 = 0;
  v4 = 0;
  if ( *(_DWORD *)(a1 + 44) != 7 )
    return sub_81627C();
  KeInitializeEvent((int)v25, 0, 0);
  v7 = IoBuildDeviceIoControlRequest(5046280, a1, 0, 0, (int)&v28, 512);
  if ( v7 )
  {
    v8 = IofCallDriver(a1, v7);
    if ( v8 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v25, 0, 0, 0, 0);
      v8 = v22;
    }
    if ( v8 < 0 )
      return v8;
    v9 = v28;
    v10 = (_BYTE *)ExAllocatePoolWithTag(1, v28 + 26, 541536836);
    v11 = (unsigned int)v10;
    if ( v10 )
    {
      memset(v10, 0, v9 + 26);
      *(_DWORD *)v11 = 0;
      *(_WORD *)(v11 + 4) = 0;
      *(_DWORD *)(v11 + 8) = 0;
      *(_WORD *)(v11 + 12) = 0;
      *(_DWORD *)(v11 + 16) = 24;
      *(_WORD *)(v11 + 20) = v28;
      memmove(v11 + 24, (int)v29, v28);
      RtlInitUnicodeString((unsigned int)v26, L"\\Device\\MountPointManager");
      v8 = IoGetDeviceObjectPointer((int)v26, 128, &v24, &v20);
      if ( v8 >= 0 )
      {
        v3 = 1;
        v21 = 1;
        v4 = v27;
        KeInitializeEvent((int)v25, 0, 0);
        v12 = IoBuildDeviceIoControlRequest(7143432, v20, v11, v9 + 26, (int)v27, 32);
        if ( v12 )
        {
          v8 = IofCallDriver(v20, v12);
          if ( v8 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v25, 0, 0, 0, 0);
            v8 = v22;
          }
          if ( v8 < 0 && v8 != -2147483643 )
            goto LABEL_14;
          v13 = v27[0] + 32;
          if ( (unsigned int)(v27[0] + 32) > 0xFFFF )
          {
            v8 = -1073741306;
            goto LABEL_14;
          }
          v4 = (int *)ExAllocatePoolWithTag(1, v27[0] + 32, 541536836);
          if ( v4 )
          {
            v23 = 1;
            KeInitializeEvent((int)v25, 0, 0);
            v14 = IoBuildDeviceIoControlRequest(7143432, v20, v11, v9 + 26, (int)v4, v13);
            if ( v14 )
            {
              v8 = IofCallDriver(v20, v14);
              if ( v8 == 259 )
              {
                KeWaitForSingleObject((unsigned int)v25, 0, 0, 0, 0);
                v8 = v22;
              }
              if ( v8 >= 0 )
              {
                v8 = -1073741275;
                v15 = 0;
                if ( v4[1] )
                {
                  v16 = v4 + 2;
                  while ( 1 )
                  {
                    v17 = *v16;
                    if ( !wcsnicmp((int)L"\\??\\Volume", (unsigned __int16 *)((char *)v4 + *v16), 10) )
                      break;
                    ++v15;
                    v16 += 6;
                    if ( v15 >= v4[1] )
                      goto LABEL_30;
                  }
                  v18 = *((_WORD *)v16 + 2);
                  *a2 = v18;
                  v18 += 2;
                  a2[1] = v18;
                  v19 = ExAllocatePoolWithTag(1, v18, 541536836);
                  *((_DWORD *)a2 + 1) = v19;
                  if ( v19 )
                  {
                    memmove(v19, (int)v4 + v17, *a2);
                    v8 = 0;
                    *(_WORD *)(*((_DWORD *)a2 + 1) + 2 * (*a2 >> 1)) = 0;
                  }
                  else
                  {
                    v8 = -1073741670;
                    *a2 = 0;
                    a2[1] = 0;
                  }
LABEL_30:
                  v3 = v21;
                }
              }
              goto LABEL_14;
            }
          }
        }
        v8 = -1073741670;
      }
LABEL_14:
      ExFreePoolWithTag(v11);
      if ( v23 )
        ExFreePoolWithTag((unsigned int)v4);
      if ( v3 )
        ObfDereferenceObject(v24);
      return v8;
    }
  }
  return -1073741670;
}
