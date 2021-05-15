// sub_7D6018 
 
void sub_7D6018()
{
  unsigned int *v0; // r4
  _DWORD *v1; // r6
  unsigned int v2; // r8
  unsigned int v3; // r7
  unsigned int v4; // r0
  unsigned int v5; // r9
  int v6; // r0
  unsigned int *v7; // r5

  if ( v2 + 3 >= v2 )
  {
    v3 = (v2 + 3) & 0xFFFFFFFC;
    v4 = WmipStaticInstanceNameSize(v1);
    v5 = v4;
    if ( v4 <= -1 - v3 )
    {
      v6 = ExAllocatePoolWithTag(1, v4 + v3, 1885957463);
      v7 = (unsigned int *)v6;
      if ( v6 )
      {
        memmove(v6, (int)v0, *v0);
        WmipInsertStaticNames(v7, v5 + v3, (int)v1);
        JUMPOUT(0x6DBAB8);
      }
    }
  }
  JUMPOUT(0x6DBA14);
}
