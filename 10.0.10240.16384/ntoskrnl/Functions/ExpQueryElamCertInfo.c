// ExpQueryElamCertInfo 
 
int __fastcall ExpQueryElamCertInfo(int a1)
{
  _DWORD *v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r9
  _DWORD *v5; // r8
  _DWORD *v6; // r0
  int v7; // r1
  int v9; // [sp+20h] [bp-50h] BYREF
  _DWORD *v10[3]; // [sp+24h] [bp-4Ch] BYREF
  _DWORD v11[16]; // [sp+30h] [bp-40h] BYREF

  v1 = 0;
  v2 = 0;
  v3 = IoConvertFileHandleToKernelHandle(a1, *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, 0, &v9);
  if ( v3 >= 0 )
  {
    v4 = v9;
    v3 = ObReferenceObjectByHandle(v9, 1, (int)IoFileObjectType, 0, (int)v10, 0);
    v1 = v10[0];
    if ( v3 >= 0 )
    {
      if ( *((_BYTE *)v10[0] + 42) || *((_BYTE *)v10[0] + 39) )
      {
        v3 = -1073741757;
      }
      else
      {
        v3 = FsRtlGetFileSize(v10[0], v11);
        if ( v3 >= 0 )
        {
          v5 = (_DWORD *)v11[0];
          v11[2] = 24;
          v11[3] = 0;
          v11[5] = 576;
          v11[4] = 0;
          v11[6] = 0;
          v11[7] = 0;
          v3 = ZwCreateSection();
          if ( v3 >= 0 )
          {
            v10[1] = v5;
            v3 = ZwMapViewOfSection();
            if ( v3 >= 0 )
            {
              v3 = SeValidateFileAsImageType();
              if ( v3 >= 0 )
              {
                v6 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, (unsigned int)v5, 1296124997);
                v2 = (unsigned int)v6;
                v10[2] = v6;
                if ( v6 )
                {
                  memmove((int)v6, 0, (unsigned int)v5);
                  v3 = SeValidateFileAsImageType();
                  if ( v3 >= 0 )
                  {
                    v3 = SeRegisterElamCertResources(v2, v7, 1);
                    if ( v3 >= 0 )
                      v3 = 0;
                  }
                }
                else
                {
                  v3 = -1073741670;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v1 = 0;
    }
  }
  else
  {
    v4 = 0;
  }
  if ( v2 )
    ExFreePoolWithTag(v2);
  if ( v1 )
    ObfDereferenceObject((int)v1);
  if ( v4 )
    ZwClose();
  return v3;
}
