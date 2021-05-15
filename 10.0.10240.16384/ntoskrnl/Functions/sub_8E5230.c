// sub_8E5230 
 
void sub_8E5230()
{
  char *v0; // r4
  int v1; // r5
  char *v2; // r0
  char *v3; // r6
  char *v4; // r2
  int v5; // r0
  int (__fastcall *v6)(int, int); // r1
  int (__fastcall *v7)(int, int); // r2
  int v8; // r0
  int v9; // r1
  int (__fastcall *v10)(int, int); // r2

  if ( (MmVerifierData & 0xA0000) != 0
    && !VfUtilEqualUnicodeString(&VfRdbssServiceName, v1 + 12)
    && !VfUtilEqualUnicodeString(&VfMupServiceName, v1 + 12)
    && !VfUtilEqualUnicodeString(&VfCscServiceName, v1 + 12)
    && !VfUtilEqualUnicodeString(&VfAmdkmpagServiceName, v1 + 12) )
  {
    if ( *(_DWORD *)(v1 + 32) )
      goto LABEL_30;
    v2 = (char *)ExAllocatePoolWithTag(512, 128, 1229940310);
    v3 = v2;
    if ( v2 )
    {
      memset(v2, 0, 128);
      v4 = v3;
      *(_DWORD *)v3 = *((_DWORD *)v0 + 11);
      v5 = 28;
      *((_DWORD *)v3 + 1) = *((_DWORD *)v0 + 12);
      *((_DWORD *)v3 + 2) = *((_DWORD *)v0 + 13);
      *((_DWORD *)v3 + 3) = *(_DWORD *)(v1 + 4);
      do
      {
        v6 = *(int (__fastcall **)(int, int))&v4[v0 - v3 + 56];
        if ( v6 && v6 != IopInvalidDeviceRequest )
          *((_DWORD *)v4 + 4) = v6;
        v4 += 4;
        --v5;
      }
      while ( v5 );
      if ( *((_DWORD *)v0 + 11) )
        *((_DWORD *)v0 + 11) = ViGenericDriverEntry;
      v7 = (int (__fastcall *)(int, int))*((_DWORD *)v0 + 12);
      if ( v7 && v7 != IopInvalidDeviceRequest )
        *((_DWORD *)v0 + 12) = ViGenericDriverStartIo;
      if ( *((_DWORD *)v0 + 13) )
        *((_DWORD *)v0 + 13) = ViGenericDriverUnload;
      if ( *(_DWORD *)(v1 + 4) )
        *(_DWORD *)(v1 + 4) = ViGenericAddDevice;
      v8 = (char *)&ViGenericMajorFunctionList - v0;
      v9 = 28;
      do
      {
        v10 = (int (__fastcall *)(int, int))*((_DWORD *)v0 + 14);
        if ( v10 )
        {
          if ( v10 != IopInvalidDeviceRequest )
            *((_DWORD *)v0 + 14) = *(_DWORD *)&v0[v8];
        }
        v0 += 4;
        --v9;
      }
      while ( v9 );
      *(_DWORD *)(v1 + 32) = v3;
LABEL_30:
      JUMPOUT(0x8E4E9E);
    }
  }
  JUMPOUT(0x8E4E9C);
}
