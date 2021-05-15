// FstubReadPartitionTableMBR 
 
int __fastcall FstubReadPartitionTableMBR(__int64 *a1, int a2, _DWORD *a3, int a4)
{
  __int64 v4; // r0
  int v6; // r4
  unsigned int *v7; // r6
  int v8; // r7
  _BYTE *v9; // r0
  _DWORD *v10; // r5
  unsigned int v11; // r7
  _DWORD *v12; // r2
  int v13; // r1
  int v14; // r1
  int v15; // r2
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = (int)a3;
  v17[1] = a4;
  *a3 = 0;
  v4 = *a1;
  v17[0] = 0;
  v6 = IoReadPartitionTable(v4, HIDWORD(v4), 0, v17);
  if ( v6 >= 0 )
  {
    v7 = (unsigned int *)v17[0];
    v8 = 144 * *(_DWORD *)v17[0];
    v9 = (_BYTE *)ExAllocatePoolWithTag(512, v8 + 48, 1114927942);
    v10 = v9;
    if ( v9 )
    {
      memset(v9, 0, v8 + 48);
      *v10 = 0;
      v11 = 0;
      v10[1] = *v7;
      v10[2] = v7[1];
      if ( *v7 )
      {
        v12 = v7 + 2;
        v13 = (int)(v10 + 12);
        do
        {
          *(_DWORD *)v13 = 0;
          *(_DWORD *)(v13 + 8) = *v12;
          *(_DWORD *)(v13 + 12) = v12[1];
          *(_DWORD *)(v13 + 16) = v12[2];
          *(_DWORD *)(v13 + 20) = v12[3];
          *(_BYTE *)(v13 + 28) = *((_BYTE *)v12 + 27);
          *(_DWORD *)(v13 + 24) = v12[5];
          *(_BYTE *)(v13 + 32) = *((_BYTE *)v12 + 24);
          *(_BYTE *)(v13 + 33) = *((_BYTE *)v12 + 25);
          *(_BYTE *)(v13 + 34) = *((_BYTE *)v12 + 26);
          *(_DWORD *)(v13 + 36) = v12[4];
          FstubSetPartitionGuidMBR(v7[1], v13);
          ++v11;
          v13 = v14 + 144;
          v12 = (_DWORD *)(v15 + 32);
        }
        while ( v11 < *v7 );
      }
      ExFreePoolWithTag((unsigned int)v7);
      *a3 = v10;
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
