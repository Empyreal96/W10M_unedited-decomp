// PnpResizeTargetDeviceBlock 
 
int __fastcall PnpResizeTargetDeviceBlock(int *a1, int a2)
{
  int v4; // r5
  unsigned int v5; // r7
  unsigned int v6; // r3
  unsigned int v7; // r6
  _BYTE *v8; // r0
  _DWORD *v9; // r8
  int v10; // r4

  v4 = 0;
  v5 = *(_DWORD *)(*a1 + 92) + 64;
  v6 = 2 * (wcslen((unsigned __int16 *)(*a1 + 100)) + 1);
  if ( v6 == 2 )
    v6 = 0;
  v7 = v5 - v6 + 400;
  if ( v7 > v5 )
  {
    v8 = (_BYTE *)PnpAllocateCriticalMemory(a2, 1, v7, 1265659472);
    v9 = v8;
    if ( v8 )
    {
      memset(v8, 0, v7);
      v10 = *a1;
      memmove((int)v9, *a1, v5);
      v9[8] = 1;
      v9[23] = v7 - 64;
      v9[11] = v10;
      *a1 = (int)v9;
    }
    else
    {
      v4 = -1073741670;
    }
  }
  return v4;
}
