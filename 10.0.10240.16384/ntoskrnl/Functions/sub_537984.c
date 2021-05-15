// sub_537984 
 
void sub_537984()
{
  int v0; // r6
  int v1; // r3

  v1 = *(_DWORD *)(v0 + 3512);
  if ( !v1 || !*(_BYTE *)(v1 + 44) )
    MiObtainFreePages(v0);
  JUMPOUT(0x495380);
}
