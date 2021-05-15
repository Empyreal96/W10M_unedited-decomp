// sub_527AD0 
 
void sub_527AD0(int a1, int a2, int a3, int a4, ...)
{
  unsigned __int16 *v4; // r6
  int v5; // r3
  unsigned int v6; // r5
  int v7; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  *((_DWORD *)v4 + 1) |= 1u;
  KeReleaseInStackQueuedSpinLock((int)va);
  MiDeletePartitionResources(v4);
  v5 = *((_DWORD *)v4 + 3);
  v6 = 0;
  if ( v5 )
    v6 = *(_DWORD *)(v5 + 156);
  v7 = *v4;
  ExFreePoolWithTag(v4, 0);
  MiFreePartitionId(v7);
  if ( v6 )
    ObDereferenceObjectDeferDeleteWithTag(v6);
  JUMPOUT(0x4DC444);
}
