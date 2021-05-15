// WmipAddMofResource 
 
int __fastcall WmipAddMofResource(int a1, unsigned __int16 *a2, int a3, unsigned __int16 *a4, _BYTE *a5)
{
  _DWORD *v9; // r4
  _DWORD *v10; // r0
  unsigned int v11; // r0
  unsigned int v12; // r0
  int v13; // r0
  int v14; // r3
  int v16; // r5

  v9 = (_DWORD *)WmipFindMRByNames(a2, a4);
  if ( v9 )
  {
    *a5 = 0;
    if ( !a1 )
      return 0;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v16 = WmipInsertMofResource(a1, v9);
    KeReleaseMutex((int)&WmipSMMutex);
  }
  else
  {
    v10 = WmipAllocEntry((int *)&WmipMRChunkInfo);
    v9 = v10;
    if ( !v10 )
      return -1073741670;
    if ( a3 )
      v10[2] |= 1u;
    v11 = wcslen(a2);
    v9[5] = ExAllocatePoolWithTag(1, 2 * (v11 + 1), 1885957463);
    v12 = wcslen(a4);
    v13 = ExAllocatePoolWithTag(1, 2 * (v12 + 1), 1885957463);
    v14 = v9[5];
    v9[6] = v13;
    if ( v14 && v13 )
      return sub_80C490();
    v16 = -1073741670;
  }
  WmipUnreferenceEntry((int *)&WmipMRChunkInfo, v9);
  return v16;
}
