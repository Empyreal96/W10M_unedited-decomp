// IoReadDiskSignature 
 
int __fastcall IoReadDiskSignature(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r4
  int v6; // r5
  int v7; // r6
  int v8; // r4
  int v9; // r0
  int v10; // r2
  int v11; // r0
  int *v12; // r1
  int v13; // t1

  v3 = a2;
  if ( a2 < 0x200 )
    v3 = 512;
  v6 = ExAllocatePoolWithTag(516, v3, 1114927942);
  if ( !v6 )
    return -1073741801;
  v7 = FstubReadSectors(a1, v3, 0i64, 1, v6);
  if ( v7 >= 0 )
  {
    if ( *(unsigned __int8 *)(v6 + 450) != 238 || *(_BYTE *)(v6 + 466) || *(_BYTE *)(v6 + 482) || *(_BYTE *)(v6 + 498) )
    {
      v10 = 0;
      v11 = 128;
      v12 = (int *)v6;
      do
      {
        v13 = *v12++;
        v10 += v13;
        --v11;
      }
      while ( v11 );
      *a3 = 0;
      a3[1] = *(_DWORD *)(v6 + 440);
      a3[2] = -v10;
    }
    else
    {
      v7 = FstubReadSectors(a1, v3, 1i64, 1, v6);
      if ( v7 >= 0 )
      {
        if ( *(_DWORD *)v6 == 541673029
          && *(_DWORD *)(v6 + 4) == 1414676816
          && *(_DWORD *)(v6 + 8) == 0x10000
          && *(_DWORD *)(v6 + 12) == 92
          && (v8 = *(_DWORD *)(v6 + 16),
              *(_DWORD *)(v6 + 16) = 0,
              v9 = RtlComputeCrc32(0, v6, 0x5Cu),
              *(_DWORD *)(v6 + 16) = v8,
              v9 == v8) )
        {
          *a3 = 1;
          a3[1] = *(_DWORD *)(v6 + 56);
          a3[2] = *(_DWORD *)(v6 + 60);
          a3[3] = *(_DWORD *)(v6 + 64);
          a3[4] = *(_DWORD *)(v6 + 68);
        }
        else
        {
          v7 = -1073741774;
        }
      }
    }
  }
  ExFreePoolWithTag(v6);
  return v7;
}
