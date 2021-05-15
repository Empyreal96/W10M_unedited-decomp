// sub_808E78 
 
void __fastcall sub_808E78(_DWORD *a1)
{
  int v1; // r6
  _DWORD *v2; // r2
  _DWORD *v3; // r2
  unsigned int v4; // r5

  while ( 1 )
  {
    while ( 1 )
    {
      v2 = (_DWORD *)*a1;
      if ( !*a1 )
        break;
      *a1 = v1;
      a1 = v2;
    }
    v3 = (_DWORD *)a1[1];
    if ( v3 )
    {
      a1[1] = v1;
      a1 = v3;
    }
    else
    {
      v4 = a1[2] & 0xFFFFFFFC;
      ExFreePoolWithTag((unsigned int)a1);
      if ( !v4 )
        JUMPOUT(0x75C802);
      a1 = (_DWORD *)v4;
    }
  }
}
