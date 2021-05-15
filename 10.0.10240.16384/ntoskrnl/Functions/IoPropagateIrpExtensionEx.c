// IoPropagateIrpExtensionEx 
 
int __fastcall IoPropagateIrpExtensionEx(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  int v6; // r6
  int v11; // r2
  int v12; // r3
  int v13; // r2
  _DWORD *v15; // r0
  int v16; // r0
  void (*v17)(void); // r4

  v6 = *(_DWORD *)(a1 + 104);
  if ( !v6 )
    return 0;
  if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
    return sub_51ECFC();
  if ( (a5 & 2) == 0 || (*(_BYTE *)(a1 + 39) & 0x80) != 0 || (*(_WORD *)(v6 + 2) & 1) == 0 )
    goto LABEL_7;
  v15 = (_DWORD *)IopAllocateIrpExtension(a2, 0, 1);
  if ( v15 )
  {
    v15[3] = *(_DWORD *)(v6 + 12);
    v15[4] = *(_DWORD *)(v6 + 16);
    v15[5] = *(_DWORD *)(v6 + 20);
    v15[6] = *(_DWORD *)(v6 + 24);
LABEL_7:
    if ( (a5 & 1) != 0 )
    {
      v11 = *(_DWORD *)(a1 + 104);
      if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 || (v11 && (*(_WORD *)(v11 + 2) & 4) != 0 ? (v12 = 1) : (v12 = 0), v12) )
        *(_DWORD *)(IopAllocateIrpExtension(a2, 2, v11) + 4) = *(_DWORD *)(v6 + 4);
    }
    if ( (a5 & 4) == 0 )
      return 0;
    v13 = *(_DWORD *)(a1 + 104);
    if ( (*(_BYTE *)(a1 + 39) & 0x80) != 0 )
      return 0;
    if ( !v13 || (*(_WORD *)(v13 + 2) & 0x20) == 0 )
      return 0;
    v16 = IopAllocateIrpExtension(a2, 5, v13);
    if ( v16 )
    {
      *(_QWORD *)(v16 + 32) = *(_QWORD *)(v6 + 32) + __PAIR64__(a4, a3);
      *(_DWORD *)(v16 + 28) = *(_DWORD *)(v6 + 28);
      v17 = *(void (**)(void))(*(_DWORD *)(v6 + 28) + 4);
      if ( v17 )
        v17();
      return 0;
    }
  }
  return -1073741670;
}
