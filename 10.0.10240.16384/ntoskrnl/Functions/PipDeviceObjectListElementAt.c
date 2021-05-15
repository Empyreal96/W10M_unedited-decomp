// PipDeviceObjectListElementAt 
 
int __fastcall PipDeviceObjectListElementAt(unsigned int *a1, unsigned int a2, unsigned int *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int *v5; // r1

  if ( !a1 )
    return -1073741811;
  if ( a2 >= *a1 )
    return -1073741684;
  v5 = &a1[4 * a2 + 4];
  *a3 = *v5;
  if ( a4 )
    *a4 = v5[1];
  if ( a5 )
    *a5 = (v5[3] & 1) != 0;
  return 0;
}
