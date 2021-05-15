// sub_8AB264 
 
int __fastcall sub_8AB264(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7, int *a8)
{
  int v11; // r4
  int v12; // r6
  int v13; // r0
  int v15; // [sp+18h] [bp-38h] BYREF
  int v16[3]; // [sp+1Ch] [bp-34h] BYREF
  char v17[40]; // [sp+28h] [bp-28h] BYREF

  v16[0] = 0;
  v11 = IoGetDeviceObjectPointer(a1, 128, v16, &v15);
  v12 = v16[0];
  if ( v11 >= 0 )
  {
    KeInitializeEvent((int)v17, 0, 0);
    v13 = IoBuildDeviceIoControlRequest(a2, v15, a3, a4, a5, a6);
    if ( v13 )
    {
      *(_DWORD *)(*(_DWORD *)(v13 + 96) - 12) = v12;
      *(_DWORD *)(v13 + 24) = -1073741637;
      v11 = IofCallDriver(v15, v13);
      if ( v11 == 259 )
      {
        KeWaitForSingleObject((unsigned int)v17, 0, 0, 0, 0);
        v11 = v16[1];
      }
      if ( v11 >= 0 )
      {
        if ( a7 )
          *a7 = v16[2];
        if ( a8 )
          *a8 = sub_8AAD14(v15);
      }
    }
    else
    {
      v11 = -1073741670;
    }
  }
  if ( v12 )
    ObfDereferenceObject(v12);
  return v11;
}
