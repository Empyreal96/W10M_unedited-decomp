// sub_7EBCB4 
 
void sub_7EBCB4()
{
  _DWORD *v0; // r7
  int v1; // r2
  int v2; // r3

  if ( !v0[68] || !v0[82] || ZwWriteFile() < 0 )
  {
    v1 = v0[82];
    v2 = v0[47];
    v0[82] = 0;
    v0[78] = 0;
    v0[79] = 0;
    v0[47] = v2 + v1;
    JUMPOUT(0x766266);
  }
  JUMPOUT(0x76627E);
}
