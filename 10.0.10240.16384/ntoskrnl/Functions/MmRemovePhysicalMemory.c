// MmRemovePhysicalMemory 
 
int __fastcall MmRemovePhysicalMemory(__int64 *a1, int a2)
{
  unsigned int v3; // r1
  __int64 v4; // r2
  unsigned int v5; // r4
  int v6; // r5
  int v8; // [sp+Ch] [bp-1Ch]
  unsigned int v9[4]; // [sp+18h] [bp-10h] BYREF

  v3 = *a1 >> 12;
  v4 = *(_QWORD *)a2;
  v9[0] = v3;
  v5 = v4 >> 12;
  if ( v3 >= v5 + v3 )
    return -1073741585;
  v6 = MiFindContiguousPages(MiSystemPartition, v3, v5 + v3 - 1, 0, v5, 1, 0x80000000, v8, 203423744, v9);
  if ( v6 >= 0 )
  {
    v6 = MiRemovePhysicalMemory(v9[0], v5, 0);
    if ( v6 < 0 )
    {
      MiFreeContiguousPages((int)MiSystemPartition, v9[0], v5);
    }
    else
    {
      *(_DWORD *)a2 = v5 << 12;
      *(_DWORD *)(a2 + 4) = v5 >> 20;
    }
  }
  return v6;
}
