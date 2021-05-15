// FindFilterOperatorClose 
 
int __fastcall FindFilterOperatorClose(unsigned int a1, int a2, int *a3)
{
  int v3; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r3

  v3 = 0;
  v4 = 0;
  *a3 = 0;
  if ( !a1 )
    return -1073741811;
  while ( 1 )
  {
    v5 = *a3;
    v6 = *(_DWORD *)(44 * *a3 + a2) & 0xFF00000;
    if ( v6 != 0x100000 )
    {
      if ( v6 == 0x200000 )
        goto LABEL_11;
      if ( v6 != 3145728 )
      {
        if ( v6 == 0x400000 )
          goto LABEL_11;
        if ( v6 != 5242880 )
        {
          if ( v6 != 6291456 )
            goto LABEL_8;
LABEL_11:
          ++v4;
          goto LABEL_8;
        }
      }
    }
    ++v3;
LABEL_8:
    if ( v3 == v4 )
      return 0;
    *a3 = v5 + 1;
    if ( v5 + 1 >= a1 )
      return -1073741811;
  }
}
