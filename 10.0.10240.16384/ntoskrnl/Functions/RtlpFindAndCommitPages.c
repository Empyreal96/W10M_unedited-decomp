// RtlpFindAndCommitPages 
 
int __fastcall RtlpFindAndCommitPages(char *a1, int *a2, int a3, int a4)
{
  int v6; // r0
  int v7; // r7
  char *v9; // r4
  int v10; // r2
  int v11; // r0
  unsigned int v12; // r2
  unsigned int v13; // r0
  int v14; // r1
  int v15; // r3
  char *v16; // r1
  char v17; // r3
  signed int v18; // r7
  int v19; // [sp+0h] [bp-28h]
  int v21[8]; // [sp+8h] [bp-20h] BYREF

  v19 = (int)a2;
  v21[0] = a4;
  v6 = RtlpFindUCREntry(a1, *a2);
  v7 = v6;
  if ( (char *)v6 != a1 + 140 )
  {
    if ( RtlpHeapErrorHandlerThreshold >= 1 )
      return sub_553E24();
    v9 = (char *)(v6 - 8);
    if ( *(_BYTE *)(v6 - 2) )
      JUMPOUT(0x553E38);
    v10 = *((_DWORD *)a1 + 51);
    v21[0] = *(_DWORD *)(v6 + 16);
    if ( RtlpHeapKey != v10 )
    {
      v11 = ((int (__fastcall *)(char *, int *, int *))(RtlpHeapKey ^ v10))(a1, v21, a2);
    }
    else
    {
      a3 = 4;
      v19 = 4096;
      v11 = ZwAllocateVirtualMemory();
      ++*((_DWORD *)a1 + 130);
    }
    if ( v11 >= 0 )
    {
      if ( (dword_682608 & 0x20) != 0 )
        RtlpLogHeapCommit(a1, v21[0], *a2, 2, v19, a3);
      if ( *((_DWORD *)a1 + 19) )
      {
        *(_DWORD *)v9 ^= *((_DWORD *)a1 + 20);
        if ( *(unsigned __int8 *)(v7 - 5) != (*(unsigned __int8 *)(v7 - 6) ^ *(unsigned __int8 *)(v7 - 7) ^ *(unsigned __int8 *)(v7 - 8)) )
          RtlpAnalyzeHeapFailure(a1, v7 - 8);
      }
      *(_BYTE *)(v7 - 6) = 0;
      *(_BYTE *)(v7 - 1) = 0;
      RtlpRemoveUCRBlock();
      --*((_DWORD *)a1 + 12);
      *((_DWORD *)a1 + 11) -= *(_DWORD *)(v7 + 20) >> 12;
      *((_DWORD *)a1 + 121) += *(_DWORD *)(v7 + 20);
      ++*((_DWORD *)a1 + 126);
      --*((_DWORD *)a1 + 125);
      v12 = *(_DWORD *)(v7 + 20);
      if ( v12 >= 0x7F000 )
        *((_DWORD *)a1 + 122) -= v12;
      v13 = *(_DWORD *)(v7 + 20);
      v14 = *a2;
      if ( v13 > *a2 || v13 + *(_DWORD *)(v7 + 16) == *((_DWORD *)a1 + 10) )
      {
        RtlpCreateUCREntry(a1, a1, *(_DWORD *)(v7 + 16) + v14 - 24, v13 - v14);
        v15 = 8 * *a2;
      }
      else
      {
        v15 = v14 + 8 * *(unsigned __int16 *)v9;
      }
      *a2 = v15;
      *(_BYTE *)(v7 - 5) = 0;
      v16 = (char *)*((_DWORD *)a1 + 6);
      if ( v16 == a1 )
      {
        v17 = 0;
      }
      else
      {
        v18 = ((unsigned int)(v9 - a1) >> 16) + 1;
        if ( v18 <= 0 || v18 >= 254 )
          RtlpLogHeapFailure(3, v16);
        v17 = ((unsigned int)(v9 - a1) >> 16) + 1;
      }
      v9[6] = v17;
      if ( (dword_682608 & 0x20) != 0 )
        RtlpLogHeapExtendEvent(a1, v9, *a2, 8 * *((_DWORD *)a1 + 29));
      return (int)v9;
    }
    ++*((_DWORD *)a1 + 132);
  }
  return 0;
}
