// FstubWritePartitionTableMBR 
 
int __fastcall FstubWritePartitionTableMBR(int a1, _DWORD *a2)
{
  _DWORD *v4; // r6
  int v5; // r5
  int v6; // r1
  int v7; // r2
  int v8; // r1

  v4 = FstubConvertExtendedToLayout(a2);
  if ( !v4 )
    return -1073741670;
  v5 = IoWritePartitionTable(*(_DWORD *)a1, *(_DWORD *)(a1 + 4), *(_DWORD *)(a1 + 24), *(_DWORD *)(a1 + 20), (int)v4);
  if ( v5 >= 0 && a2[1] )
  {
    v6 = (int)(a2 + 12);
    do
    {
      FstubSetPartitionGuidMBR(a2[2], v6);
      v6 = v8 + 144;
    }
    while ( (unsigned int)(v7 + 1) < a2[1] );
  }
  ExFreePoolWithTag((unsigned int)v4);
  return v5;
}
