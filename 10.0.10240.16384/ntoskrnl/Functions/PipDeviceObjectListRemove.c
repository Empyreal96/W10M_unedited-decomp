// PipDeviceObjectListRemove 
 
int __fastcall PipDeviceObjectListRemove(unsigned int *a1, unsigned int a2)
{
  int *v5; // r6

  if ( a2 >= *a1 )
    return -1073741684;
  v5 = (int *)&a1[4 * a2 + 4];
  ObfDereferenceObject(*v5);
  if ( (v5[3] & 1) != 0 )
    --a1[2];
  if ( a2 < *a1 - 1 )
    memmove((int)&a1[4 * a2 + 4], (int)&a1[4 * a2 + 8], 16 * (*a1 - a2 - 1));
  --*a1;
  return 0;
}
