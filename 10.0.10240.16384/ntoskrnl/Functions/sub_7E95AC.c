// sub_7E95AC 
 
void sub_7E95AC()
{
  int v0; // r4
  int v1; // r5
  unsigned int *v2; // r8
  unsigned int v3; // r9
  unsigned int i; // r10
  unsigned int v5; // r7
  unsigned int v6; // t1
  _DWORD *v7; // r6
  _DWORD *v8; // r1
  _DWORD *v9; // t1
  unsigned int v10; // [sp+0h] [bp+0h]

  for ( i = 0; i < 0x20; ++i )
  {
    v6 = *v2++;
    v5 = v6;
    if ( !v6 )
      break;
    v10 = 0;
    v7 = (_DWORD *)v5;
    do
    {
      v9 = (_DWORD *)*v7++;
      v8 = v9;
      if ( !v9 )
        break;
      ExpFreeLowLevelTable(v0, v8);
      ++v10;
    }
    while ( v10 < v3 );
    ExpFreeTablePagedPool(v0, v5, 0x1000u);
  }
  ExpFreeTablePagedPool(v0, v1 & 0xFFFFFFFC, 0x80u);
  JUMPOUT(0x7023F8);
}
