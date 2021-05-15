// sub_969740 
 
void sub_969740()
{
  int v0; // r4
  int v1; // r5
  int v2; // r6
  unsigned int v3; // r7
  int v4; // r0
  int *v5; // r0
  unsigned int v6; // r0
  int v7; // r3

  if ( !*(_DWORD *)(v0 + 360) )
  {
    v4 = ExAllocatePoolWithTag(1, v3, 538996816);
    *(_DWORD *)(v0 + 360) = v4;
    if ( !v4 )
      goto LABEL_13;
    memmove(v4, v1, v3);
  }
  v5 = (int *)ExAllocatePoolWithTag(1, 12, 538996816);
  if ( v5 )
  {
    if ( v0 )
      v5[2] = *(_DWORD *)(v0 + 360);
    else
      v5[2] = v1;
    v5[1] = v2;
    v7 = IopInitReservedResourceList;
    IopInitReservedResourceList = (int)v5;
    *v5 = v7;
    JUMPOUT(0x95293A);
  }
  if ( v0 )
  {
    v6 = *(_DWORD *)(v0 + 360);
    if ( v6 )
    {
      ExFreePoolWithTag(v6);
      *(_DWORD *)(v0 + 360) = 0;
    }
  }
LABEL_13:
  JUMPOUT(0x952936);
}
