// MiAllocateImportList 
 
int __fastcall MiAllocateImportList(int *a1, unsigned int **a2)
{
  unsigned int v3; // r4
  int v4; // t1
  unsigned int *v5; // r0
  unsigned int *v6; // r5

  *a2 = 0;
  v3 = 0;
  if ( !a1[3] )
    goto LABEL_10;
  do
  {
    v4 = *a1;
    a1 += 5;
    if ( !v4 )
      break;
    ++v3;
  }
  while ( a1[3] );
  if ( !v3 )
  {
LABEL_10:
    v6 = 0;
    goto LABEL_8;
  }
  if ( v3 <= 0x3FFFFFFE )
  {
    v5 = (unsigned int *)ExAllocatePoolWithTag(257, 4 * (v3 + 1), 1413770573);
    v6 = v5;
    if ( v5 )
    {
      memset(v5, 0, 4 * (v3 + 1));
      *v6 = v3;
LABEL_8:
      *a2 = v6;
      return 0;
    }
  }
  return -1073741670;
}
