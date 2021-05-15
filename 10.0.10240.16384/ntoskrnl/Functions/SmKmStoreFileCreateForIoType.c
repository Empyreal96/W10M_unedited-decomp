// SmKmStoreFileCreateForIoType 
 
int __fastcall SmKmStoreFileCreateForIoType(_DWORD *a1, unsigned __int16 *a2, int *a3)
{
  BOOL v6; // r5
  int v7; // r7
  int v8; // r8
  int v9; // r4
  int v10; // r2
  int v12; // r1
  int v13; // r2
  int v14; // r3
  _DWORD *v15; // r9
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned int v19; // [sp+28h] [bp-90h] BYREF
  int v20; // [sp+2Ch] [bp-8Ch] BYREF
  int v21; // [sp+30h] [bp-88h] BYREF
  int v22; // [sp+34h] [bp-84h] BYREF
  char v23[8]; // [sp+38h] [bp-80h] BYREF
  char v24[4]; // [sp+40h] [bp-78h] BYREF
  int v25; // [sp+44h] [bp-74h]
  char v26[24]; // [sp+48h] [bp-70h] BYREF
  int v27[6]; // [sp+60h] [bp-58h] BYREF
  int v28[16]; // [sp+78h] [bp-40h] BYREF

  v6 = 0;
  memset(v28, 0, 32);
  v19 = 0;
  if ( a3 )
  {
    v7 = 0;
  }
  else
  {
    v7 = 1;
    a3 = &v20;
    v20 = 0;
  }
  v8 = IoSetThreadHardErrorMode(0);
  RtlInitUnicodeString((unsigned int)v23, a2);
  v9 = SmKmStoreFileMakeSecurityDescriptor(v26, &v19);
  if ( v9 >= 0 )
  {
    v27[0] = 24;
    v27[1] = 0;
    v27[3] = 576;
    v27[2] = (int)v23;
    v27[4] = (int)v26;
    v27[5] = 0;
    while ( 1 )
    {
      v10 = 256;
      if ( !*a3 )
        v10 = 258;
      v9 = IoCreateFile((int)v28, 1310723, (int)v27, (int)v24, 0, 0x2000, 0, 0, 32778, 0, 0, 0, 0, v10);
      if ( v9 < 0 )
        break;
      v9 = ObReferenceObjectByHandle(v28[0], 65539, 0, 0, (int)&v21, 0);
      v28[1] = v21;
      if ( v9 < 0 )
        break;
      v6 = !*a3 || v25 == 2 || !v25;
      v9 = ZwSetSecurityObject();
      if ( v9 < 0 )
        break;
      if ( *a3 )
        goto LABEL_29;
      v9 = SmKmIsVolumeIoPossible((int)v28, &v22);
      if ( v9 < 0 )
        break;
      if ( v22 )
      {
LABEL_29:
        v12 = v28[1];
        v13 = v28[2];
        v14 = v28[3];
        *a1 = v28[0];
        a1[1] = v12;
        a1[2] = v13;
        a1[3] = v14;
        v15 = a1 + 4;
        v16 = v28[5];
        v17 = v28[6];
        v18 = v28[7];
        *v15 = v28[4];
        v15[1] = v16;
        v15[2] = v17;
        v15[3] = v18;
        memset(v28, 0, 32);
        v9 = 0;
        goto LABEL_26;
      }
      if ( v7 )
      {
        v9 = -1073741637;
        break;
      }
      *a3 = 1;
      if ( v6 )
      {
        SmKmStoreFileDelete(v28);
        v6 = 0;
      }
      SmKmFileInfoCleanup(v28);
      memset(v28, 0, 32);
    }
    if ( v6 )
      SmKmStoreFileDelete(v28);
  }
LABEL_26:
  SmKmFileInfoCleanup(v28);
  if ( v19 )
    ExFreePoolWithTag(v19);
  IoSetThreadHardErrorMode(v8);
  return v9;
}
