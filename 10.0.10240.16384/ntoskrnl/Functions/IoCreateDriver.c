// IoCreateDriver 
 
int __fastcall IoCreateDriver(int *a1, int (__fastcall *a2)(_BYTE *, _DWORD))
{
  int v4; // r4
  _BYTE *v5; // r5
  int (__fastcall **v6)(int, int); // r3
  unsigned int v7; // r2
  int *i; // r2
  unsigned int v9; // r0
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  int v13; // r7
  unsigned int v14; // r4
  int v15; // r2
  int v16; // r0
  int v17; // r3
  int v18; // r0
  int v19; // r3
  int v20; // [sp+18h] [bp-C8h] BYREF
  int v21; // [sp+1Ch] [bp-C4h]
  int v22; // [sp+20h] [bp-C0h] BYREF
  _BYTE *v23[2]; // [sp+28h] [bp-B8h] BYREF
  int v24[44]; // [sp+30h] [bp-B0h] BYREF

  if ( !a1 )
    return sub_80C388();
  v20 = *a1;
  v21 = a1[1];
  v24[0] = 24;
  v24[1] = 0;
  v24[3] = 592;
  v24[2] = (int)&v20;
  v24[4] = 0;
  v24[5] = 0;
  v4 = ObCreateObject(0, (_DWORD *)IoDriverObjectType, (int)v24, 0, 0, 208, 0, 0, v23);
  if ( v4 >= 0 )
  {
    v5 = v23[0];
    memset(v23[0], 0, 208);
    *((_DWORD *)v5 + 6) = v5 + 168;
    *((_DWORD *)v5 + 42) = v5;
    *(_WORD *)v5 = 4;
    *((_WORD *)v5 + 1) = 168;
    v6 = (int (__fastcall **)(int, int))(v5 + 56);
    *((_DWORD *)v5 + 2) = 4;
    do
      *v6++ = IopInvalidDeviceRequest;
    while ( v6 != (int (__fastcall **)(int, int))(v5 + 168) );
    *((_DWORD *)v5 + 11) = a2;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
    for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
    {
      v9 = i[6];
      if ( (unsigned int)a2 >= v9 && (unsigned int)a2 < i[8] + v9 )
      {
        *((_DWORD *)v5 + 3) = i[6];
        break;
      }
    }
    v10 = ExReleaseResourceLite((int)&PsLoadedModuleResource);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v17 = 40;
      else
        v17 = 32;
      v16 = ExAllocatePoolWithTagPriority(1, (unsigned __int16)v20 + 2, 538996553, v17);
    }
    else
    {
      v16 = ExAllocatePoolWithTag(1, (unsigned __int16)v20 + 2, 538996553);
    }
    v13 = v16;
    if ( !v16 )
    {
      v4 = -1073741670;
LABEL_40:
      ObMakeTemporaryObject((int)v5);
      ObfDereferenceObject((int)v5);
      return v4;
    }
    v14 = (unsigned __int16)v20;
    HIWORD(v23[0]) = v20 + 2;
    LOWORD(v23[0]) = v20;
    memmove(v16, v21, (unsigned __int16)v20);
    *(_WORD *)(v13 + 2 * (v14 >> 1)) = 0;
    v15 = *((_DWORD *)v5 + 6);
    *(_BYTE **)(v15 + 12) = v23[0];
    *(_DWORD *)(v15 + 16) = v13;
    v4 = ObInsertObject((int)v5, 0, 1, 0, 0, (int)&v22);
    if ( v4 >= 0 )
    {
      v4 = ObReferenceObjectByHandle(v22, 0, IoDriverObjectType, 0, (int)v23, 0);
      v5 = v23[0];
      if ( v4 >= 0 )
      {
        ZwClose();
        if ( ViVerifierDriverAddedThunkListHead )
        {
          if ( (MmVerifierData & 0x10) != 0 )
            v19 = 40;
          else
            v19 = 32;
          v18 = ExAllocatePoolWithTagPriority(512, HIWORD(v20), 538996553, v19);
        }
        else
        {
          v18 = ExAllocatePoolWithTag(512, HIWORD(v20), 538996553);
        }
        *((_DWORD *)v5 + 8) = v18;
        if ( v18 )
        {
          *((_DWORD *)v5 + 7) = v20;
          memmove(*((_DWORD *)v5 + 8), v21, HIWORD(v20));
        }
        v4 = a2(v5, 0);
        if ( v4 >= 0 )
          return v4;
        goto LABEL_40;
      }
      ZwMakeTemporaryObject();
      ZwClose();
    }
  }
  return v4;
}
