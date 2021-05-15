// sub_53DB5C 
 
void sub_53DB5C()
{
  _DWORD *v0; // r5
  char v1; // r9
  _DWORD *v2; // r4

  if ( (v1 & 2) == 0 )
  {
    MiWaitForFreePage(MiSystemPartition);
    JUMPOUT(0x4A48DA);
  }
  if ( v0 )
  {
    do
    {
      v2 = (_DWORD *)*v0;
      MiReleaseFreshPage((int)v0);
      v0 = v2;
    }
    while ( v2 );
  }
  JUMPOUT(0x4A49AE);
}
