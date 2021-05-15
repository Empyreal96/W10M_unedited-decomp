// sub_51E6FC 
 
void sub_51E6FC()
{
  _DWORD *v0; // r4

  __mrc(15, 0, 13, 0, 3);
  ReadTimeStampCounter();
  *v0 = 0;
  v0[1] = 0;
  JUMPOUT(0x44D522);
}
