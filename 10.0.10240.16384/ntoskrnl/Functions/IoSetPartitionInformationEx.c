// IoSetPartitionInformationEx 
 
int __fastcall IoSetPartitionInformationEx(int a1, unsigned int a2, _DWORD *a3, int a4)
{
  int v7; // r4
  unsigned int v8; // r5
  int v9; // r0
  int v11; // [sp+0h] [bp-20h] BYREF
  int v12[7]; // [sp+4h] [bp-1Ch] BYREF

  v12[0] = (int)a3;
  v12[1] = a4;
  v11 = 0;
  v7 = FstubAllocateDiskInformation(a1, (unsigned int *)&v11);
  if ( v7 < 0 )
    return v7;
  v8 = v11;
  v7 = FstubDetectPartitionStyle(v11, v12);
  if ( v7 >= 0 )
  {
    if ( v12[0] != *a3 )
    {
      v7 = -1073741811;
      goto LABEL_11;
    }
    if ( v12[0] )
    {
      if ( v12[0] != 1 )
      {
        v7 = -1073741637;
        goto LABEL_11;
      }
      v9 = FstubSetPartitionInformationEFI((int *)v8, a2, a3 + 2);
    }
    else
    {
      v9 = IoSetPartitionInformation(a1, *(_DWORD *)(v8 + 4), a2, *((unsigned __int8 *)a3 + 8));
    }
    v7 = v9;
  }
LABEL_11:
  if ( v8 )
    FstubFreeDiskInformation(v8);
  return v7;
}
