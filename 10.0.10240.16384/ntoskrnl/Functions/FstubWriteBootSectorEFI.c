// FstubWriteBootSectorEFI 
 
int __fastcall FstubWriteBootSectorEFI(int *a1)
{
  int v2; // r4
  int v3; // r6

  v2 = a1[10];
  v3 = 0;
  if ( FstubReadSectors(*a1, a1[1], 0i64, 1, v2) >= 0 && *(unsigned __int16 *)(v2 + 510) == 43605 )
    v3 = *(_DWORD *)(v2 + 440);
  memset((_BYTE *)v2, 0, a1[1]);
  *(_WORD *)(v2 + 510) = -21931;
  *(_BYTE *)(v2 + 448) = 2;
  *(_BYTE *)(v2 + 450) = -18;
  *(_BYTE *)(v2 + 451) = -1;
  *(_BYTE *)(v2 + 452) = -1;
  *(_BYTE *)(v2 + 453) = -1;
  *(_DWORD *)(v2 + 458) = -1;
  *(_BYTE *)(v2 + 446) = 0;
  *(_BYTE *)(v2 + 447) = 0;
  *(_BYTE *)(v2 + 449) = 0;
  *(_DWORD *)(v2 + 454) = 1;
  *(_DWORD *)(v2 + 440) = v3;
  *(_DWORD *)(v2 + 462) = 0;
  *(_DWORD *)(v2 + 466) = 0;
  *(_DWORD *)(v2 + 470) = 0;
  *(_DWORD *)(v2 + 474) = 0;
  *(_DWORD *)(v2 + 478) = 0;
  *(_DWORD *)(v2 + 482) = 0;
  *(_DWORD *)(v2 + 486) = 0;
  *(_DWORD *)(v2 + 490) = 0;
  *(_DWORD *)(v2 + 494) = 0;
  *(_DWORD *)(v2 + 498) = 0;
  *(_DWORD *)(v2 + 502) = 0;
  *(_DWORD *)(v2 + 506) = 0;
  return FstubWriteSector(*a1, a1[1], 0, 0);
}
