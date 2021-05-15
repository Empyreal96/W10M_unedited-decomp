// MiCreateZeroThreadContext 
 
int __fastcall MiCreateZeroThreadContext(int a1, int a2, int a3)
{
  int *v5; // r4
  int v6; // r0

  v5 = (int *)ExAllocatePoolWithTag(512, 8);
  if ( !v5 )
LABEL_7:
    JUMPOUT(0x50F0FE);
  if ( !MiAcquireNonPagedResources(a1, 1024) )
  {
    ExFreePoolWithTag(v5, 0);
    goto LABEL_7;
  }
  v6 = MiReservePtes(&dword_634D58, 0x400u);
  if ( !v6 )
    return sub_50F0EC();
  *v5 = v6;
  v5[1] = a3;
  return (int)v5;
}
