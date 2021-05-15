// PerfLogSpinLockAcquire 
 
int __fastcall PerfLogSpinLockAcquire(int result, int a2, int a3, int a4, int a5, int a6, int a7, char a8)
{
  int v9; // r1
  unsigned int v10; // r4
  unsigned int v11; // r2

  v9 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x138C) + 1600;
  v10 = *(unsigned __int8 *)(v9 + 256);
  if ( v10 < 8 )
  {
    *(_BYTE *)(v9 + 256) = v10 + 1;
    v11 = v9 + 32 * v10;
    *(_DWORD *)v11 = a3;
    *(_DWORD *)(v11 + 4) = a4;
    *(_DWORD *)(v11 + 16) = a6;
    *(_DWORD *)(v11 + 8) = result;
    *(_DWORD *)(v11 + 12) = a5;
    *(_DWORD *)(v11 + 20) = a7;
    *(_BYTE *)(v11 + 24) = a8;
  }
  else
  {
    ++*(_DWORD *)(v9 + 260);
  }
  return result;
}
