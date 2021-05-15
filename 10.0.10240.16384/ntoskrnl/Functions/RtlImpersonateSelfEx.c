// RtlImpersonateSelfEx 
 
int __fastcall RtlImpersonateSelfEx(int a1, int a2, _DWORD *a3)
{
  int v4; // r4
  int v5; // r0
  int v7; // [sp+8h] [bp-40h]

  if ( !a3 && a2 )
    return -1073741584;
  v4 = ZwOpenProcessTokenEx();
  if ( v4 >= 0 )
  {
    v4 = ZwDuplicateToken();
    if ( v4 >= 0 )
    {
      v5 = ZwSetInformationThread();
      v4 = v5;
      if ( a3 && v5 >= 0 )
        *a3 = v7;
      else
        ZwClose();
    }
    ZwClose();
  }
  return v4;
}
