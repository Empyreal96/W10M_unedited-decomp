// ExpPrepareNewSvmDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpPrepareNewSvmDevice(int a1, int a2, int *a3)
{
  _BYTE *v6; // r0
  int v7; // r5
  int v8; // r4
  unsigned int v9; // r2
  unsigned int v10; // r2
  int *v11; // r2
  int v12; // r1 OVERLAPPED
  unsigned int v13; // r2
  int v15; // [sp+10h] [bp-28h] BYREF
  int v16; // [sp+14h] [bp-24h]

  *a3 = 0;
  v6 = (_BYTE *)ExAllocatePoolWithTag(512, 56);
  v7 = (int)v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 56);
  *(_DWORD *)(v7 + 8) = a1;
  *(_DWORD *)(v7 + 12) = 1;
  v8 = IoQueryInterface(a1, 0, &GUID_IOMMU_BUS_INTERFACE, 32, 1, 0, v7 + 16);
  if ( v8 >= 0 )
  {
    v8 = (*(int (__fastcall **)(_DWORD, int))(v7 + 44))(*(_DWORD *)(v7 + 20), v7 + 48);
    if ( v8 >= 0 )
    {
      v8 = (*(int (__fastcall **)(_DWORD, int *))(v7 + 32))(*(_DWORD *)(v7 + 20), &v15);
      if ( v8 >= 0 )
      {
        if ( (v15 & 7) != 7 || 1 << (v16 & 0x1F) < (unsigned int)ExpSvmAgents )
        {
          v8 = -1073741585;
          goto LABEL_19;
        }
        __dmb(0xBu);
        do
          v9 = __ldrex((unsigned int *)&ExTbFlushActive);
        while ( __strex(v9 + 1, (unsigned int *)&ExTbFlushActive) );
        __dmb(0xBu);
        v8 = ((int (__fastcall *)(int, _DWORD, int *, int))HalIommuDispatch[3])(a2, *(_DWORD *)(v7 + 48), &v15, v7 + 52);
        if ( v8 < 0 )
        {
          __dmb(0xBu);
          do
            v10 = __ldrex((unsigned int *)&ExTbFlushActive);
          while ( __strex(v10 - 1, (unsigned int *)&ExTbFlushActive) );
          __dmb(0xBu);
          goto LABEL_19;
        }
        v8 = (*(int (__fastcall **)(_DWORD, int *, int (*)(), _DWORD))(v7 + 36))(
               *(_DWORD *)(v7 + 20),
               &v15,
               ExSvmDevicePowerCallback,
               *(_DWORD *)(v7 + 52));
        if ( v8 >= 0 )
        {
          v11 = &ExpSvmDevices;
          v12 = ExpSvmDevices;
          *(_QWORD *)v7 = *(_QWORD *)&v12;
          if ( *(int **)(v12 + 4) != &ExpSvmDevices )
            __fastfail(3u);
          *(_DWORD *)(v12 + 4) = v7;
          ExpSvmDevices = v7;
          *a3 = v7;
LABEL_19:
          if ( v8 >= 0 )
            return v8;
          goto LABEL_20;
        }
      }
    }
LABEL_20:
    (*(void (__fastcall **)(_DWORD))(v7 + 28))(*(_DWORD *)(v7 + 20));
  }
  if ( *(_DWORD *)(v7 + 52) )
  {
    ((void (__cdecl *)())HalIommuDispatch[7])();
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&ExTbFlushActive);
    while ( __strex(v13 - 1, (unsigned int *)&ExTbFlushActive) );
    __dmb(0xBu);
  }
  ExFreePoolWithTag(v7);
  return v8;
}
