// AlpcpAllocateBlob 
 
int __fastcall AlpcpAllocateBlob(_DWORD *a1, int a2, int a3)
{
  unsigned int v3; // r1
  int (__fastcall **v5)(int, unsigned int, int); // r6
  int v6; // r4
  char v7; // r6
  int v9; // r2
  __int64 v10; // kr00_8
  int (__fastcall *v11)(int, unsigned int, int); // r0

  v3 = a2 + 24;
  if ( a3 || a1[7] < v3 )
  {
    v9 = a1[1];
    if ( a1[7] )
      v6 = AlpcpLookasides[32 * a1[2] + 10](1, v3, v9);
    else
      v6 = ExAllocatePoolWithTag(1, v3, v9);
    v7 = 0;
  }
  else
  {
    v5 = &AlpcpLookasides[32 * a1[2]];
    v5[3] = (int (__fastcall *)(int, unsigned int, int))((char *)v5[3] + 1);
    v6 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v5);
    if ( !v6 )
    {
      v10 = *((_QWORD *)v5 + 4);
      v11 = v5[7];
      v5[4] = (int (__fastcall *)(int, unsigned int, int))((char *)v5[4] + 1);
      v6 = v5[10]((int)v11, HIDWORD(v10), v10);
    }
    v7 = 1;
  }
  if ( !v6 )
    return 0;
  memset((_BYTE *)v6, 0, 24);
  *(_DWORD *)(v6 + 20) = 0;
  *(_BYTE *)(v6 + 9) = *a1;
  *(_DWORD *)v6 = v6;
  *(_DWORD *)(v6 + 4) = v6;
  *(_BYTE *)(v6 + 8) ^= (*(_BYTE *)(v6 + 8) ^ (2 * v7)) & 2;
  *(_DWORD *)(v6 + 12) = 1;
  return v6 + 24;
}
