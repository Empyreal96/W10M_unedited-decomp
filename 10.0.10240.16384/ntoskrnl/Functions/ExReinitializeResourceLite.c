// ExReinitializeResourceLite 
 
int __fastcall ExReinitializeResourceLite(int a1)
{
  int v1; // r8
  int v2; // r4
  int v3; // r10
  unsigned int v4; // r7
  int v5; // r3
  unsigned int v6; // r5
  int v7; // r3
  unsigned int v8; // r1
  int *v10; // r6
  unsigned int v11; // r9
  int v12; // r2
  int v13; // r5

  v1 = *(_DWORD *)(a1 + 8);
  v2 = a1;
  v3 = 0;
  if ( v1 )
  {
    v4 = *(_DWORD *)(v1 + 4);
    v10 = *(int **)(a1 + 8);
    if ( v4 > 1 )
    {
      v11 = v4 - 1;
      do
      {
        v10 += 2;
        v12 = v10[1];
        if ( (v12 & 2) != 0 )
          return sub_520B80();
        v13 = *v10;
        if ( (*v10 & 3) != 0 )
          v13 = 0;
        if ( v13 )
        {
          ++v3;
          if ( (v12 & 1) != 0 )
            PsBoostThreadIoEx(v13, 1, 0);
          if ( (v10[1] & 2) != 0 )
            ObDereferenceObjectDeferDeleteWithTag(v13, 1953261124);
        }
        --v11;
      }
      while ( v11 );
      v2 = a1;
    }
    memset((_BYTE *)(v1 + 8), 0, 8 * (*(_DWORD *)(v1 + 4) - 1));
  }
  else
  {
    v4 = 0;
  }
  v5 = *(_DWORD *)(v2 + 24);
  if ( v5 )
  {
    ++v4;
    if ( (v5 & 3) == 0 )
      ++v3;
  }
  if ( (*(_DWORD *)(v2 + 28) & 2) != 0 )
  {
    v6 = *(_DWORD *)(v2 + 24) & 0xFFFFFFFC;
  }
  else
  {
    v6 = *(_DWORD *)(v2 + 24);
    if ( (v6 & 3) != 0 )
      v6 = 0;
  }
  if ( v6 )
  {
    if ( (*(_DWORD *)(v2 + 28) & 1) != 0 )
      PsBoostThreadIoEx(v6, 1, 0);
    if ( (*(_DWORD *)(v2 + 28) & 2) != 0 )
      ObDereferenceObjectDeferDeleteWithTag(v6, 1953261124);
  }
  v7 = *(_DWORD *)(v2 + 20);
  *(_WORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 32) = 0;
  *(_WORD *)(v2 + 14) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  if ( v7 )
  {
    *(_BYTE *)(v7 + 2) = 4;
    *(_BYTE *)v7 = 1;
    *(_BYTE *)(v7 + 1) = 0;
    *(_DWORD *)(v7 + 4) = 0;
    *(_DWORD *)(v7 + 8) = v7 + 8;
    *(_DWORD *)(v7 + 12) = v7 + 8;
  }
  *(_DWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 36) = 0;
  *(_DWORD *)(v2 + 40) = 0;
  *(_DWORD *)(v2 + 44) = 0;
  v8 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v8 & 0xFFFFF000) + 0x141C);
  if ( (dword_682604 & 0x20000) != 0 )
    PerfLogExecutiveResourceInitialize(65560, v2, v4, v3);
  return 0;
}
