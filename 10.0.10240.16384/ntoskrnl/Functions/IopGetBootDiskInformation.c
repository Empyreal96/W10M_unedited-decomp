// IopGetBootDiskInformation 
 
int __fastcall IopGetBootDiskInformation(int a1, unsigned int a2)
{
  int v3; // r8
  int v4; // r9
  _DWORD *v6; // r4
  _DWORD **v7; // r7
  _DWORD *v8; // r3
  unsigned int v9; // r10
  int v10; // r3
  int v11; // r4
  int v12; // r0
  int v13; // r0
  int v14; // r5
  _DWORD *i; // r6
  int v16; // r4
  int v17; // r4
  _DWORD *v18; // r9
  int v19; // r5
  int v20; // r0
  int v21; // r3
  unsigned int v22; // r4
  int v23; // r10
  _DWORD *v24; // r7
  _DWORD *v25; // r2
  int v26; // r1
  int v27; // r2
  int v28; // r3
  int v29; // r2
  int v30; // r1
  int v31; // r2
  int v32; // r3
  unsigned int v33; // r3
  int v34; // [sp+18h] [bp-1A8h]
  int v35; // [sp+1Ch] [bp-1A4h] BYREF
  int v36; // [sp+20h] [bp-1A0h] BYREF
  unsigned int v37; // [sp+24h] [bp-19Ch]
  int v38; // [sp+28h] [bp-198h] BYREF
  char v39[4]; // [sp+30h] [bp-190h] BYREF
  int v40; // [sp+34h] [bp-18Ch]
  int v41[2]; // [sp+38h] [bp-188h] BYREF
  _DWORD *v42; // [sp+40h] [bp-180h]
  unsigned int v43; // [sp+44h] [bp-17Ch]
  unsigned int v44; // [sp+48h] [bp-178h]
  BOOL v45; // [sp+4Ch] [bp-174h]
  _DWORD **v46; // [sp+50h] [bp-170h]
  int v47; // [sp+58h] [bp-168h]
  unsigned __int16 v48[4]; // [sp+60h] [bp-160h] BYREF
  unsigned __int16 v49[4]; // [sp+68h] [bp-158h] BYREF
  unsigned __int16 v50[4]; // [sp+70h] [bp-150h] BYREF
  unsigned __int16 v51[4]; // [sp+78h] [bp-148h] BYREF
  unsigned __int16 v52[4]; // [sp+80h] [bp-140h] BYREF
  char v53[20]; // [sp+88h] [bp-138h] BYREF
  unsigned int v54; // [sp+9Ch] [bp-124h]
  char v55[128]; // [sp+A0h] [bp-120h] BYREF
  char v56[160]; // [sp+120h] [bp-A0h] BYREF

  v3 = a1;
  v42 = (_DWORD *)a1;
  v4 = *IoGetConfigurationInformation();
  v43 = v4;
  v34 = 0;
  v36 = 0;
  if ( (unsigned int)InitializationPhase >= 2 )
    return -1073741431;
  if ( a2 < 0x18 )
    return -1073741811;
  if ( a2 < 0x40 )
    v3 = 0;
  v6 = KeLoaderBlock_0;
  v7 = (_DWORD **)*((_DWORD *)KeLoaderBlock_0 + 32);
  v8 = *v7;
  v46 = v7;
  v45 = *v8 == (_DWORD)v7;
  RtlInitAnsiString((unsigned int)v52, *((_DWORD *)KeLoaderBlock_0 + 26));
  RtlInitAnsiString((unsigned int)v50, v6[27]);
  v9 = 0;
  v44 = 0;
  if ( v4 )
  {
    do
    {
      RtlStringCchPrintfA(v55, 0x80u, (int)"\\Device\\Harddisk%d\\Partition0", v9);
      RtlInitAnsiString((unsigned int)v51, (unsigned int)v55);
      if ( RtlAnsiStringToUnicodeString(v49, v51, 1, v10) < 0 )
        goto LABEL_56;
      v11 = IoGetDeviceObjectPointer((int)v49, 128, &v38, &v35);
      RtlFreeAnsiString(v49);
      if ( v11 < 0 )
        goto LABEL_56;
      v12 = IoBuildDeviceIoControlRequest(458752, v35, 0, 0, (int)v53, 24);
      if ( !v12 )
        goto LABEL_11;
      v39[0] = 0;
      v39[1] = 0;
      v39[2] = 4;
      v40 = 0;
      v41[1] = (int)v41;
      v41[0] = (int)v41;
      v13 = IofCallDriver(v35, v12);
      if ( v13 == 259 )
      {
        KeWaitForSingleObject((unsigned int)v39, 5, 0, 0, 0);
        v13 = v47;
      }
      if ( v13 >= 0 )
      {
        v14 = 4096;
        for ( i = (_DWORD *)ExAllocatePoolWithTag(512, 4096, 1866624841);
              i;
              i = (_DWORD *)ExAllocatePoolWithTag(512, v14, 1866624841) )
        {
          v16 = IoBuildDeviceIoControlRequest(458832, v35, 0, 0, (int)i, v14);
          if ( !v16 )
            break;
          KeResetEvent((int)v39);
          v17 = IofCallDriver(v35, v16);
          if ( v17 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v39, 5, 0, 0, 0);
            v17 = v47;
          }
          if ( v17 != -1073741789 )
            goto LABEL_22;
          ExFreePoolWithTag((unsigned int)i);
          v14 *= 2;
        }
        v17 = -1073741670;
LABEL_22:
        ObfDereferenceObjectWithTag(v38);
        if ( v17 >= 0 )
        {
          if ( v54 < 0x200 )
            v54 = 512;
          v18 = *v7;
          if ( *v7 != v7 )
          {
            v19 = v34;
            do
            {
              if ( v45 && v43 == 1 && !*i
                || (v20 = IopVerifyDiskSignature(i, (int)v18, &v36), v19 = v36, v34 = v36, v20) )
              {
                v21 = i[1];
                v22 = 0;
                v37 = 0;
                if ( v21 )
                {
                  v23 = 0;
                  do
                  {
                    if ( !v19 && !*i )
                    {
                      v19 = i[2];
                      v34 = v19;
                      v36 = v19;
                    }
                    v24 = &i[v23];
                    if ( i[v23 + 18] )
                    {
                      RtlStringCchPrintfA(v56, 0x80u, (int)"%spartition(%d)", v18[3]);
                      RtlInitAnsiString((unsigned int)v48, (unsigned int)v56);
                      if ( RtlEqualString(v48, v52, 1) )
                      {
                        v25 = v42;
                        v42[4] = v19;
                        *v25 = v24[14];
                        v25[1] = v24[15];
                        if ( *i == 1 )
                        {
                          if ( v3 )
                          {
                            *(_BYTE *)(v3 + 56) = 1;
                            v26 = i[3];
                            v27 = i[4];
                            v28 = i[5];
                            *(_DWORD *)(v3 + 24) = i[2];
                            *(_DWORD *)(v3 + 28) = v26;
                            *(_DWORD *)(v3 + 32) = v27;
                            *(_DWORD *)(v3 + 36) = v28;
                            v22 = v37;
                          }
                        }
                        else if ( v3 )
                        {
                          *(_BYTE *)(v3 + 56) = 0;
                        }
                      }
                      v19 = v34;
                      if ( RtlEqualString(v48, v50, 1) )
                      {
                        v29 = (int)v42;
                        v42[5] = v34;
                        *(_DWORD *)(v29 + 8) = v24[14];
                        *(_DWORD *)(v29 + 12) = v24[15];
                        if ( *i == 1 )
                        {
                          if ( v3 )
                          {
                            *(_BYTE *)(v3 + 57) = 1;
                            v30 = i[3];
                            v31 = i[4];
                            v32 = i[5];
                            *(_DWORD *)(v3 + 40) = i[2];
                            *(_DWORD *)(v3 + 44) = v30;
                            *(_DWORD *)(v3 + 48) = v31;
                            *(_DWORD *)(v3 + 52) = v32;
                            v22 = v37;
                            v19 = v34;
                          }
                        }
                        else if ( v3 )
                        {
                          *(_BYTE *)(v3 + 57) = 0;
                        }
                      }
                    }
                    v33 = i[1];
                    v37 = ++v22;
                    v23 += 36;
                  }
                  while ( v22 < v33 );
                  v7 = v46;
                }
              }
              v18 = (_DWORD *)*v18;
            }
            while ( v18 != v7 );
            v9 = v44;
          }
LABEL_55:
          ExFreePoolWithTag((unsigned int)i);
          goto LABEL_56;
        }
        if ( i )
          goto LABEL_55;
      }
      else
      {
LABEL_11:
        ObfDereferenceObjectWithTag(v38);
      }
LABEL_56:
      v44 = ++v9;
    }
    while ( v9 < v43 );
  }
  return 0;
}
