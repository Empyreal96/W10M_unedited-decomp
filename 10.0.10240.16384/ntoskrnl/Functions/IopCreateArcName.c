// IopCreateArcName 
 
int __fastcall IopCreateArcName(int a1, int a2)
{
  void **v3; // r2
  int *v4; // r7
  int v5; // r4
  int v7; // r4
  int v8; // r4
  unsigned int v9; // r1
  const __int16 *v10; // r2
  int v11; // r8
  int v12; // r3
  unsigned int v13; // r5
  int v14; // r3
  unsigned int v15; // r9
  _DWORD *v16; // r4
  int v17; // r8
  int v18; // r4
  int v19; // r4
  int v20; // r1
  int *v21; // r2
  int v22; // t1
  int v23; // r3
  int v24; // r8
  void **i; // r6
  int v26; // r0
  int v27; // r0
  int v28; // r3
  unsigned int v29; // r1
  int *v30; // r2
  int v31; // t1
  unsigned int v32; // [sp+18h] [bp-140h] BYREF
  int v33; // [sp+1Ch] [bp-13Ch]
  unsigned int v34[2]; // [sp+20h] [bp-138h] BYREF
  int v35; // [sp+28h] [bp-130h] BYREF
  char v36[16]; // [sp+30h] [bp-128h] BYREF
  unsigned __int16 v37[4]; // [sp+40h] [bp-118h] BYREF
  char v38[8]; // [sp+48h] [bp-110h] BYREF
  char v39[4]; // [sp+50h] [bp-108h] BYREF
  int v40; // [sp+54h] [bp-104h]
  char v41[20]; // [sp+60h] [bp-F8h] BYREF
  unsigned int v42; // [sp+74h] [bp-E4h]
  char v43[64]; // [sp+78h] [bp-E0h] BYREF
  unsigned __int16 v44[80]; // [sp+B8h] [bp-A0h] BYREF

  v3 = (void **)IoArcTableListHead;
  v4 = 0;
  while ( v3 != &IoArcTableListHead )
  {
    if ( v3[11] == (void *)a1 )
      return 0;
    v3 = (void **)*v3;
  }
  if ( a2 == -1 )
  {
    v5 = IoBuildDeviceIoControlRequest(2953344, a1, 0, 0, (int)v39, 12);
    if ( !v5 )
      return sub_80C6D8();
    KeInitializeEvent((int)v36, 0, 0);
    v7 = IofCallDriver(a1, v5);
    if ( v7 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v36, 0, 0, 0, 0);
      v7 = v35;
    }
    if ( v7 < 0 )
      return v7;
  }
  else
  {
    v40 = a2;
  }
  v8 = IoBuildDeviceIoControlRequest(458752, a1, 0, 0, (int)v41, 24);
  if ( !v8 )
    return sub_80C6D8();
  KeInitializeEvent((int)v36, 0, 0);
  v7 = IofCallDriver(a1, v8);
  if ( v7 == 259 )
  {
    KeWaitForSingleObject((unsigned int)v36, 0, 0, 0, 0);
    v7 = v35;
  }
  if ( v7 >= 0 )
  {
    v9 = v42;
    if ( v42 < 0x200 )
    {
      v9 = 512;
      v42 = 512;
    }
    if ( *(_DWORD *)(a1 + 44) == 2 )
    {
      v32 = 0x8000;
      v33 = 0;
    }
    else
    {
      v32 = 0;
      v33 = 0;
      HalExamineMBR(a1, v9, 85, v34);
      if ( v34[0] )
      {
        v32 = v42;
        v33 = 0;
        ExFreePoolWithTag(v34[0]);
      }
      v9 = v42;
    }
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v28 = 40;
      else
        v28 = 32;
      v27 = ExAllocatePoolWithTagPriority(516, v9, 538996553, v28);
    }
    else
    {
      v27 = ExAllocatePoolWithTag(516, v9, 538996553);
    }
    v15 = v27;
    if ( !v27 )
      return sub_80C6D8();
    v16 = IoBuildSynchronousFsdRequest(3, a1, v27, v42, &v32, (int)v36, (int)&v35);
    if ( !v16 )
    {
      v7 = -1073741670;
      goto LABEL_34;
    }
    KeInitializeEvent((int)v36, 0, 0);
    v7 = IofCallDriver(a1, (int)v16);
    if ( v7 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v36, 0, 0, 0, 0);
      v7 = v35;
    }
    if ( v7 >= 0 )
    {
      if ( *(_DWORD *)(a1 + 44) == 2 )
      {
        v19 = 0;
        v29 = v42 >> 2;
        if ( v42 >> 2 )
        {
          v30 = (int *)v15;
          do
          {
            v31 = *v30++;
            v19 += v31;
            --v29;
          }
          while ( v29 );
        }
      }
      else
      {
        v17 = 4096;
        v34[0] = *(_DWORD *)(v15 + 440);
        v4 = (int *)ExAllocatePoolWithTag(512, 4096, 1866624841);
        if ( !v4 )
        {
LABEL_68:
          v7 = -1073741670;
          goto LABEL_32;
        }
        while ( 1 )
        {
          v18 = IoBuildDeviceIoControlRequest(458832, a1, 0, 0, (int)v4, v17);
          if ( !v18 )
            break;
          KeResetEvent((int)v36);
          v7 = IofCallDriver(a1, v18);
          if ( v7 == 259 )
          {
            KeWaitForSingleObject((unsigned int)v36, 5, 0, 0, 0);
            v7 = v35;
          }
          if ( v7 != -1073741789 )
            goto LABEL_47;
          ExFreePoolWithTag((unsigned int)v4);
          v17 *= 2;
          v4 = (int *)ExAllocatePoolWithTag(512, v17, 1866624841);
          if ( !v4 )
            goto LABEL_68;
        }
        v7 = -1073741670;
LABEL_47:
        if ( v7 < 0 )
          goto LABEL_32;
        v19 = 0;
        v20 = 128;
        v21 = (int *)v15;
        do
        {
          v22 = *v21++;
          v19 += v22;
          --v20;
        }
        while ( v20 );
        v23 = *v4;
        if ( !*v4 )
        {
          v21 = (int *)v34[0];
          if ( !v34[0] )
          {
            v21 = 0;
            v4[2] = 0;
          }
        }
        v24 = 0;
        if ( v23 != 2 && (v23 || v4[1] || v4[2] || IoVerifyPartitionTable(a1, 0, v21) != -1073741637) )
          goto LABEL_56;
      }
      v24 = 1;
LABEL_56:
      for ( i = (void **)IoArcTableListHead; ; i = (void **)*i )
      {
        if ( i == &IoArcTableListHead )
        {
          v7 = -1073741637;
          goto LABEL_32;
        }
        if ( !*((_BYTE *)i + 48) )
        {
          if ( v24 )
          {
            if ( *((_BYTE *)i + 20) || (char *)i[4] + v19 )
              continue;
          }
          else
          {
            v26 = IopVerifyDiskSignature(v4, i, v34);
            if ( !v26 )
              continue;
            if ( i[10] )
              v26 = VhdiVerifyBootDisk(a1);
            if ( !v26 || (char *)i[4] + v19 )
              continue;
          }
          if ( !i[11] )
          {
            i[11] = (void *)a1;
            if ( *(_DWORD *)(a1 + 44) == 2 )
              v10 = L"\\Device\\CdRom%d";
            else
              v10 = L"\\Device\\Harddisk%d\\Partition0";
            RtlStringCchPrintfW(v44, 0x40u, (int)v10, v40);
            RtlInitUnicodeString((unsigned int)v38, v44);
            v11 = (int)i[3];
            RtlStringCchPrintfA(v43, 0x40u, (int)"\\ArcName\\%s", v11);
            RtlInitAnsiString((unsigned int)&v32, (unsigned int)v43);
            v7 = RtlAnsiStringToUnicodeString(v37, (unsigned __int16 *)&v32, 1, v12);
            if ( v7 >= 0 )
            {
              IoCreateSymbolicLink();
              RtlFreeAnsiString(v37);
              if ( *(_DWORD *)(a1 + 44) == 2 )
              {
                if ( (unsigned int)InitializationPhase < 2
                  && !strcmp((int)i[3], *((unsigned int **)KeLoaderBlock_0 + 26)) )
                {
                  *(_DWORD *)(a1 + 28) |= 0x100u;
                }
              }
              else
              {
                v13 = 0;
                if ( v4[1] )
                {
                  v7 = 0;
                  do
                  {
                    ++v13;
                    RtlStringCchPrintfW(v44, 0x40u, (int)L"\\Device\\Harddisk%d\\Partition%d", v40);
                    RtlInitUnicodeString((unsigned int)v38, v44);
                    RtlStringCchPrintfA(v43, 0x40u, (int)"\\ArcName\\%spartition(%d)", v11);
                    RtlInitAnsiString((unsigned int)&v32, (unsigned int)v43);
                    if ( RtlAnsiStringToUnicodeString(v37, (unsigned __int16 *)&v32, 1, v14) >= 0 )
                    {
                      IoCreateSymbolicLink();
                      RtlFreeAnsiString(v37);
                    }
                  }
                  while ( v13 < v4[1] );
                }
              }
            }
LABEL_32:
            if ( v4 )
              ExFreePoolWithTag((unsigned int)v4);
            break;
          }
        }
      }
    }
LABEL_34:
    ExFreePoolWithTag(v15);
  }
  return v7;
}
