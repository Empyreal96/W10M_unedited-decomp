// CMFSystemThreadRoutine 
 
int __fastcall CMFSystemThreadRoutine(int *a1)
{
  int result; // r0
  unsigned int v3; // r7
  int v4; // r9
  int v5; // r8
  int v6; // r4
  const char *v7; // r9
  const __int16 *v8; // r2
  int v9; // r4
  char *v10; // r10
  int v11; // r0
  int v12; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r7
  int v16; // r3
  int v17; // r3
  int v18; // r3
  int v19; // r0
  int v20; // r0
  int *v21; // r3
  int v22; // [sp+28h] [bp-280h]
  int v23; // [sp+30h] [bp-278h] BYREF
  int v24; // [sp+34h] [bp-274h]
  char *v25; // [sp+38h] [bp-270h]
  unsigned int v26; // [sp+3Ch] [bp-26Ch] BYREF
  int v27; // [sp+40h] [bp-268h]
  int v28; // [sp+44h] [bp-264h]
  char *v29; // [sp+48h] [bp-260h]
  int v30; // [sp+4Ch] [bp-25Ch]
  int v31; // [sp+50h] [bp-258h]
  int v32; // [sp+54h] [bp-254h]
  int v33; // [sp+58h] [bp-250h]
  int v34; // [sp+5Ch] [bp-24Ch]
  int v35; // [sp+68h] [bp-240h] BYREF
  char v36[8]; // [sp+70h] [bp-238h] BYREF
  char v37[8]; // [sp+78h] [bp-230h] BYREF
  unsigned __int16 v38[276]; // [sp+80h] [bp-228h] BYREF

  result = 0;
  v3 = 0;
  v4 = 0;
  v34 = 0;
  v5 = 0;
  v22 = 0;
  v26 = 0;
  if ( !a1 )
    return result;
  v6 = a1[10];
  if ( v6 == 16 )
  {
    v7 = "RESCDIR";
    v8 = L"%s\\rc%04u\\rescache.dir";
LABEL_11:
    v25 = v37;
    v10 = v37;
    v11 = RtlStringCchPrintfW(v38, 0x104u, (int)v8, (int)L"\\SystemRoot\\Rescache");
    goto LABEL_12;
  }
  if ( v6 != 32 )
  {
    if ( v6 != 256 )
    {
      v9 = -1073741811;
      goto LABEL_65;
    }
    v7 = "RESCHIT";
    v8 = L"%s\\rc%04u\\rescache.hit";
    goto LABEL_11;
  }
  v5 = ExAllocatePoolWithTag(1, 4192, 1668114000);
  if ( !v5 )
  {
    v9 = -1073741801;
    goto LABEL_7;
  }
  v7 = "RESCSEG";
  v25 = (char *)v5;
  v10 = (char *)v5;
  v11 = RtlStringCchPrintfW(v38, 0x104u, (int)L"%s\\rc%04u\\segment%u.cmf", (int)L"\\SystemRoot\\Rescache");
LABEL_12:
  v9 = v11;
  if ( (v11 & 0xC0000000) != -1073741824 )
  {
    RtlInitUnicodeString((unsigned int)v36, v38);
    v27 = 24;
    v28 = 0;
    v30 = 576;
    v29 = v36;
    v31 = 0;
    v32 = 0;
    v9 = ZwOpenFile();
    if ( (v9 & 0xC0000000) != -1073741824 )
    {
      v27 = 24;
      v28 = 0;
      v30 = 512;
      v29 = 0;
      v31 = 0;
      v32 = 0;
      v9 = ZwCreateEvent();
      if ( (v9 & 0xC0000000) != -1073741824 )
      {
        v23 = 0;
        v24 = 0;
        v9 = ZwReadFile();
        if ( v9 >= 0 )
        {
          v12 = ZwWaitForSingleObject();
          v9 = v12;
          if ( v12 )
          {
            v4 = 0;
            if ( v12 >= 0 )
            {
              v9 = -1073741823;
              goto LABEL_7;
            }
            goto LABEL_47;
          }
          if ( *(_QWORD *)v10 == *(_QWORD *)v7 )
          {
            v13 = a1[10];
            if ( v13 == 32 && *(_DWORD *)(v5 + 76) )
            {
              v34 = 1;
              *((_BYTE *)a1 + 12) = 1;
              a1[5] |= 4u;
            }
            v14 = *((unsigned __int8 *)a1 + 12);
            v15 = 0;
            v25 = 0;
            if ( !v14 )
              goto LABEL_34;
            v24 = 0;
            v25 = 0;
            v23 = 0;
            if ( v13 != 16 && v13 != 256 )
            {
              v15 = *(_DWORD *)(v5 + 32);
              v23 = v15;
              v24 = 0;
LABEL_30:
              if ( CMFGetLargePageSectionSize((int)&v23, &v35) >= 0 && (*a1 & 0x80000000) != 0 )
              {
                v33 = v35;
              }
              else
              {
                v16 = *a1;
                v33 = v15;
                *a1 = v16 & 0x7FFFFFFF;
              }
LABEL_34:
              if ( a1[10] == 256 )
              {
                v17 = 0;
              }
              else
              {
                v9 = CMFCreateSecurityDescriptor(&v26, 0);
                if ( (v9 & 0xC0000000) == -1073741824 )
                {
                  v3 = v26;
                  v4 = 0;
                  goto LABEL_65;
                }
                v17 = v26;
                v22 = v26;
              }
              v27 = 24;
              v28 = 0;
              v31 = v17;
              v30 = 576;
              v32 = 0;
              v29 = 0;
              v9 = ZwCreateSection();
              if ( v9 < 0 )
              {
                while ( *((_BYTE *)a1 + 12) )
                {
                  v18 = *a1;
                  if ( (*a1 & 0x80000000) == 0 )
                    break;
                  v27 = 24;
                  v28 = 0;
                  v30 = 576;
                  v29 = 0;
                  *a1 = v18 & 0x7FFFFFFF;
                  v31 = v22;
                  v32 = 0;
                  v33 = v15;
                  v9 = ZwCreateSection();
                  if ( v9 >= 0 )
                    goto LABEL_43;
                }
                v4 = 0;
                goto LABEL_47;
              }
LABEL_43:
              v19 = ObReferenceObjectByHandle(0, 983071, MmSectionObjectType, 0, (int)&v26, 0);
              v4 = v26;
              v9 = v19;
              if ( (v19 & 0xC0000000) != -1073741824 )
              {
                if ( *((_BYTE *)a1 + 12) )
                {
                  v23 = 0;
                  v24 = 0;
                  v9 = ZwMapViewOfSection();
                  if ( (v9 & 0xC0000000) == -1073741824 )
                    goto LABEL_47;
                  if ( v34 )
                  {
                    *(_DWORD *)(v5 + 76) = 0;
                    v9 = CMFReadCompressedSegment(0, 0, v15, v5);
                    if ( v9 < 0 )
                      goto LABEL_47;
                  }
                  else
                  {
                    v23 = 0;
                    v24 = 0;
                    v9 = ZwReadFile();
                    if ( v9 < 0 )
                      goto LABEL_47;
                    v20 = ZwWaitForSingleObject();
                    v9 = v20;
                    if ( v20 )
                    {
                      if ( v20 >= 0 )
                        v9 = -1073741823;
                      goto LABEL_47;
                    }
                  }
                  ZwUnmapViewOfSection();
                }
                v21 = (int *)a1[9];
                if ( v21 )
                {
                  *v21 = v4;
                  v4 = 0;
                  if ( a1[10] == 16 && CMFCacheIndex == 10000 )
                  {
                    CMFFlagsCache |= a1[5] & 0xF;
                    CMFCacheIndex = a1[1];
                  }
                }
                goto LABEL_47;
              }
              v4 = 0;
LABEL_47:
              v3 = v22;
              goto LABEL_65;
            }
            v9 = CMFGetFileSizeEx(0, &v23);
            if ( (v9 & 0xC0000000) != -1073741824 )
            {
              v15 = v23;
              goto LABEL_30;
            }
          }
          else
          {
            v9 = -1073700864;
          }
        }
      }
    }
  }
  v4 = 0;
LABEL_7:
  v3 = 0;
LABEL_65:
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( v4 )
    ObfDereferenceObject(v4);
  if ( v5 )
    ExFreePoolWithTag(v5);
  result = a1[4];
  a1[8] = v9;
  if ( result )
    result = KeSetEvent(result, 1, 0);
  return result;
}
