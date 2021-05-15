// AslpFileGetChecksumAttributes 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AslpFileGetChecksumAttributes(int a1, int a2)
{
  int v4; // r0
  int v5; // r4
  int *v6; // r6
  unsigned int v7; // r3
  int v8; // r7 OVERLAPPED
  int v9; // r8 OVERLAPPED
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v13[2]; // [sp+8h] [bp-40h] BYREF
  int v14[14]; // [sp+10h] [bp-38h] BYREF

  memset(v14, 0, 32);
  v4 = AslFileMappingEnsureMappedAs(a2);
  v5 = v4;
  if ( v4 >= 0 )
  {
    v6 = (int *)(a2 + 520);
  }
  else
  {
    if ( v4 != -1073741554 )
    {
      AslLogCallPrintf(1, (int)"AslpFileGetChecksumAttributes", 3199, "AslFileMappingEnsureMappedAs failed [%x]", v4);
      goto LABEL_13;
    }
    memset(v14, 0, 32);
    LOBYTE(v14[7]) = 0;
    v14[0] = *(_DWORD *)(a2 + 520);
    v5 = RtlFileMapMapView((int)v14, 0);
    if ( v5 < 0 )
    {
      AslLogCallPrintf(1, (int)"AslpFileGetChecksumAttributes", 3217, "RtlFileMapMapView failed [%x]", v5);
      goto LABEL_13;
    }
    v6 = v14;
  }
  v13[0] = 0;
  v5 = AslpFileGetChecksum(v13, (int)v6);
  if ( v5 >= 0 )
  {
    v7 = v13[0];
    v8 = 2;
    v9 = 4;
    *(_DWORD *)(a1 + 52) = 4;
    *(_DWORD *)(a1 + 56) = v7;
    v10 = *(_DWORD *)(a1 + 64) | 1;
    *(_DWORD *)(a1 + 60) = 0;
    *(_DWORD *)(a1 + 64) = v10;
    v13[0] = 0;
    *(_DWORD *)(a1 + 48) = 2;
    v5 = AslpFileGetCrcChecksum(v13, v6);
    if ( v5 >= 0 )
    {
      v11 = v13[0];
      *(_QWORD *)(a1 + 624) = *(_QWORD *)&v8;
      *(_DWORD *)(a1 + 632) = v11;
      *(_DWORD *)(a1 + 636) = 0;
      v5 = 0;
      *(_DWORD *)(a1 + 640) |= 1u;
    }
    else
    {
      AslLogCallPrintf(1, (int)"AslpFileGetChecksumAttributes", 3250, "AslpFileGetCrcChecksum failed [%x]", v5);
    }
  }
  else
  {
    AslLogCallPrintf(1, (int)"AslpFileGetChecksumAttributes", 3233, "AslpFileGetChecksum failed [%x]", v5);
  }
LABEL_13:
  RtlFileMapFree(v14);
  return v5;
}
