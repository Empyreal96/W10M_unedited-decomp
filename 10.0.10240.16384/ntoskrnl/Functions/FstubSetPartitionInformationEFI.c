// FstubSetPartitionInformationEFI 
 
int __fastcall FstubSetPartitionInformationEFI(int *a1, int a2, _DWORD *a3)
{
  int v5; // r4
  unsigned int v6; // r5
  unsigned int v7; // r8
  _DWORD *v8; // r7
  int v9; // r2
  int v10; // r3
  int v11; // r4
  int v12; // r2
  int v13; // r3
  int v14; // r4
  unsigned int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = 0;
  if ( !a2 )
    return -1073741811;
  v6 = a2 - 1;
  v5 = IoReadPartitionTableEx(*a1, (int)v16, (int)a3, 0);
  if ( v5 >= 0 )
  {
    v7 = v16[0];
    if ( v6 < *(_DWORD *)(v16[0] + 4) )
    {
      v8 = (_DWORD *)(v16[0] + 144 * v6 + 80);
      v9 = a3[1];
      v10 = a3[2];
      v11 = a3[3];
      *v8 = *a3;
      v8[1] = v9;
      v8[2] = v10;
      v8[3] = v11;
      v12 = a3[5];
      v13 = a3[6];
      v14 = a3[7];
      v8[4] = a3[4];
      v8[5] = v12;
      v8[6] = v13;
      v8[7] = v14;
      v8[8] = a3[8];
      v8[9] = a3[9];
      memmove((int)(v8 + 10), (int)(a3 + 10), 0x48u);
      v5 = IoWritePartitionTableEx(*a1, v7);
    }
    else
    {
      v5 = -1073741811;
    }
    ExFreePoolWithTag(v7);
  }
  return v5;
}
