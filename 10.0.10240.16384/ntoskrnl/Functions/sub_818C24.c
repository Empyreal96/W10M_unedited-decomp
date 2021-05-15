// sub_818C24 
 
void sub_818C24()
{
  _DWORD *v0; // r5
  int v1; // r8
  int v2; // r10

  if ( v2 == v1 )
  {
    PipClearDevNodeFlags((int)v0, 16);
    PipSetDevNodeState(v0, 787);
    JUMPOUT(0x7B3EC8);
  }
  JUMPOUT(0x7B3E3A);
}
