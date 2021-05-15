// IoReadPartitionTableEx 
 
int __fastcall IoReadPartitionTableEx(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  int v8; // [sp+0h] [bp-18h] BYREF
  int v9[5]; // [sp+4h] [bp-14h] BYREF

  v8 = a2;
  v9[0] = a3;
  v9[1] = a4;
  v5 = FstubAllocateDiskInformation(a1, (unsigned int *)&v8);
  if ( v5 < 0 )
    return v5;
  v6 = v8;
  v5 = FstubDetectPartitionStyle(v8, v9);
  if ( v5 < 0 )
  {
LABEL_5:
    if ( v6 )
      FstubFreeDiskInformation(v6);
    return v5;
  }
  if ( !v9[0] )
  {
LABEL_4:
    v5 = FstubReadPartitionTableMBR(v6);
    goto LABEL_5;
  }
  if ( v9[0] == 1 )
  {
    v5 = FstubReadPartitionTableEFI(v6, 0, a2);
    if ( v5 >= 0 )
      goto LABEL_5;
    v5 = FstubReadPartitionTableEFI(v6, 1, a2);
    if ( v5 >= 0 )
      goto LABEL_5;
    goto LABEL_4;
  }
  return sub_7D5DD0();
}
