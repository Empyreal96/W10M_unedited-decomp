// IopLiveDumpAllocateDumpBuffers 
 
int __fastcall IopLiveDumpAllocateDumpBuffers(int a1)
{
  unsigned int v2; // r1
  int v3; // r3
  unsigned int v4; // r2
  unsigned int v5; // r6
  int v6; // r0
  __int64 v7; // kr00_8
  int v8; // r5
  unsigned int i; // r5
  int v10; // r0
  __int64 v11; // kr08_8
  __int64 v12; // kr10_8
  __int64 v13; // kr18_8
  unsigned int v14; // r2
  int v15; // r3

  *(_DWORD *)(a1 + 284) = 0;
  *(_DWORD *)(a1 + 300) = 0;
  *(_DWORD *)(a1 + 272) = 0;
  *(_DWORD *)(a1 + 60) = (*(_DWORD *)(a1 + 60) + 63) & 0xFFFFFFC0;
  v2 = (*(_DWORD *)(a1 + 56) + 63) & 0xFFFFFFC0;
  v3 = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a1 + 56) = v2;
  v4 = (v3 + 63) & 0xFFFFFFC0;
  v5 = (v2 >> 6) + (v4 >> 6);
  *(_DWORD *)(a1 + 64) = v4;
  v6 = ExAllocatePoolWithTag(512, (4 * v5 + 4095) & 0xFFFFF000, 1886217292);
  *(_DWORD *)(a1 + 304) = v6;
  if ( !v6 )
  {
LABEL_20:
    v8 = -1073741670;
    goto LABEL_21;
  }
  v7 = *(_QWORD *)(a1 + 324);
  if ( (!(_DWORD)v7 || !*(_DWORD *)(v7 + 4)) && (!HIDWORD(v7) || !*(_DWORD *)(HIDWORD(v7) + 4)) )
  {
    IopLiveDumpDiscardVirtualAddressRange(a1, v6, (4 * v5 + 4095) & 0xFFFFF000);
    memset(*(_BYTE **)(a1 + 304), 0, (4 * v5 + 4095) & 0xFFFFF000);
    for ( i = 0; i < v5; ++i )
    {
      v10 = ExAllocatePoolWithTag(512, 0x40000, 1886217292);
      if ( !v10 )
        break;
      v11 = *(_QWORD *)(a1 + 324);
      if ( (_DWORD)v11 && *(_DWORD *)(v11 + 4) || HIDWORD(v11) && *(_DWORD *)(HIDWORD(v11) + 4) )
        goto LABEL_6;
      *(_DWORD *)(*(_DWORD *)(a1 + 304) + 4 * i) = v10;
      ++*(_DWORD *)(a1 + 300);
      *(_DWORD *)(a1 + 272) += 64;
      IopLiveDumpDiscardVirtualAddressRange(a1, v10, 0x40000);
    }
    v12 = *(_QWORD *)(a1 + 324);
    if ( (!(_DWORD)v12 || !*(_DWORD *)(v12 + 4)) && (!HIDWORD(v12) || !*(_DWORD *)(HIDWORD(v12) + 4)) )
    {
      if ( *(_DWORD *)(a1 + 272) >= *(_DWORD *)(a1 + 60) )
      {
        v8 = 0;
        goto LABEL_22;
      }
      goto LABEL_20;
    }
  }
LABEL_6:
  v8 = -1073741248;
LABEL_21:
  IopLiveDumpFreeDumpBuffers(a1 + 272);
  *(_DWORD *)(a1 + 272) = 0;
LABEL_22:
  v13 = *(_QWORD *)(a1 + 60);
  v14 = *(_DWORD *)(a1 + 272);
  if ( v14 < HIDWORD(v13) + (int)v13 )
  {
    if ( !v14 )
    {
      *(_DWORD *)(a1 + 276) = 0;
      *(_DWORD *)(a1 + 280) = 0;
      return v8;
    }
    *(_DWORD *)(a1 + 276) = v13;
    v15 = v14 - v13;
  }
  else
  {
    *(_DWORD *)(a1 + 276) = v14 - HIDWORD(v13);
    v15 = *(_DWORD *)(a1 + 64);
  }
  *(_DWORD *)(a1 + 280) = v15;
  return v8;
}
