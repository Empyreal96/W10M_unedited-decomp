// sub_7FA788 
 
void sub_7FA788()
{
  unsigned int *v0; // r4
  _DWORD *v1; // r5
  _DWORD *v2; // r7
  unsigned int v3; // r2

  while ( 1 )
  {
    v3 = v1[10];
    if ( v3 >= *v0
      && v3 + 8 <= v0[1]
      && v0[4] == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74)
      && IopQueueIrpToFileObject(v1, v2) )
    {
      break;
    }
    v0 = (unsigned int *)v0[5];
    if ( !v0 )
      JUMPOUT(0x72B934);
  }
  v1[10] = v0[3] + v1[10] - *v0;
  JUMPOUT(0x72B93A);
}
