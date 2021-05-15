// ViGenericBuildIrpLogEntry 
 
int __fastcall ViGenericBuildIrpLogEntry(int a1, int a2, int a3, int a4)
{
  int v4; // r1

  v4 = *(_DWORD *)(a1 + 96);
  if ( *(_BYTE *)(v4 - 40) != 14 )
    return 0;
  *(_DWORD *)a4 = 1;
  *(_BYTE *)(a4 + 4) = *(_BYTE *)(v4 - 40);
  *(_BYTE *)(a4 + 5) = *(_BYTE *)(v4 - 39);
  *(_BYTE *)(a4 + 6) = *(_BYTE *)(v4 - 38);
  *(_BYTE *)(a4 + 7) = *(_BYTE *)(v4 - 37);
  *(_QWORD *)(a4 + 8) = *(int *)(v4 - 32);
  *(_QWORD *)(a4 + 16) = *(int *)(v4 - 28);
  *(_QWORD *)(a4 + 24) = *(int *)(v4 - 24);
  *(_QWORD *)(a4 + 32) = *(int *)(v4 - 20);
  return 1;
}
