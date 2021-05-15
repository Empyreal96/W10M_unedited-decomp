// SepAdtCopyToLsaSharedMemory 
 
int __fastcall SepAdtCopyToLsaSharedMemory(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r4

  v6 = ZwAllocateVirtualMemory();
  if ( v6 >= 0 )
  {
    v6 = ZwWriteVirtualMemory();
    if ( v6 >= 0 )
    {
      if ( !a3 )
      {
        *a4 = 0;
        return v6;
      }
      v6 = -1073741823;
    }
    ZwFreeVirtualMemory();
  }
  return v6;
}
