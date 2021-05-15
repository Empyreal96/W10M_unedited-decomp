// BiCreateFileDeviceElement 
 
int __fastcall BiCreateFileDeviceElement(int a1, unsigned int *a2, int *a3)
{
  int v6; // r5
  int v7; // r6
  unsigned __int16 *v8; // r0
  unsigned __int16 *v9; // r7
  unsigned int v10; // r6
  int v11; // r0
  unsigned __int16 *v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r0
  int v15; // r4
  _BYTE *v16; // r0
  unsigned int v17; // r6
  unsigned int v18; // r0
  unsigned int v19; // r0
  int v21; // [sp+0h] [bp-28h]

  v6 = 0;
  v7 = wcslen(L"\\Device\\HarddiskVolume");
  if ( wcsnicmp(a1, L"\\Device\\HarddiskVolume", v7) )
    return -1073741811;
  v8 = wcschr((_WORD *)(a1 + 2 * v7), 92);
  v9 = v8;
  if ( !v8 )
    return -1073741811;
  v10 = 2 * (((int)v8 - a1) >> 1);
  v11 = ExAllocatePoolWithTag(1, v10 + 2, 1262764866);
  v12 = (unsigned __int16 *)v11;
  if ( !v11 )
    return -1073741670;
  memmove(v11, a1, v10);
  v12[v10 / 2] = 0;
  v13 = wcslen(v12) + 11;
  v14 = wcslen(v9);
  v15 = 2 * (v14 + 23) + 2 * v13;
  v21 = 2 * (v14 + 23);
  v16 = (_BYTE *)ExAllocatePoolWithTag(1, v15, 1262764866);
  v17 = (unsigned int)v16;
  if ( v16 )
  {
    memset(v16, 0, v15);
    *(_DWORD *)(v17 + 20) = v21;
    *(_DWORD *)v17 = 3;
    v18 = wcslen(v9);
    wcscpy_s((char *)(v17 + 24), v18 + 1, (char *)v9);
    *(_DWORD *)(v21 + v17) = 2;
    v19 = wcslen(v12);
    wcscpy_s((char *)(v21 + v17 + 20), v19 + 1, (char *)v12);
    *a2 = v17;
    *a3 = v15;
  }
  else
  {
    v6 = -1073741670;
  }
  ExFreePoolWithTag((unsigned int)v12);
  if ( v6 < 0 && v17 )
    ExFreePoolWithTag(v17);
  return v6;
}
