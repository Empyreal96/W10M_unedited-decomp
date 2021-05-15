// sub_80CE54 
 
void sub_80CE54()
{
  int *v0; // r4
  int *v1; // r5
  int v2; // r7
  int v3; // r0
  unsigned int v4; // r8
  int v5; // r0
  _DWORD *v6; // r6

  if ( v0 )
  {
    v2 = PnpDetermineResourceListSize(v1);
    v3 = PnpDetermineResourceListSize(v0);
    if ( v2 )
    {
      if ( v3 )
      {
        v4 = v3 - 4;
        v5 = ExAllocatePoolWithTag(1, v3 - 4 + v2, 538996816);
        v6 = (_DWORD *)v5;
        if ( v5 )
        {
          memmove(v5, (int)v1, v2);
          memmove((int)v6 + v2, (int)(v0 + 1), v4);
          *v6 += *v0;
        }
      }
    }
  }
  JUMPOUT(0x79421A);
}
