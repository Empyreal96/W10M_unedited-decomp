// sub_7E2E38 
 
void sub_7E2E38()
{
  int v0; // r4
  int v1; // r5
  unsigned int v2; // r8
  int v3; // r6

  if ( (*(_DWORD *)(v1 + 28) & 2) == 0 )
    goto LABEL_8;
  v2 = 0;
  v3 = v1;
  do
  {
    if ( *(_DWORD *)(v3 + 48) )
    {
      v0 = ZwClose();
      if ( v0 < 0 )
        goto LABEL_10;
      *(_DWORD *)(v3 + 48) = 0;
    }
    ++v2;
    v3 += 4;
  }
  while ( v2 < 6 );
  if ( v0 >= 0 )
  {
LABEL_8:
    if ( ZwClose() >= 0 )
      *(_DWORD *)(v1 + 44) = 0;
  }
LABEL_10:
  JUMPOUT(0x77B5BC);
}
