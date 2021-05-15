// sub_7CE4E0 
 
void sub_7CE4E0()
{
  int v0; // r6

  KsepStringFree((_DWORD *)(v0 + 8));
  KsepPoolFreePaged(*(_DWORD *)(v0 + 24));
  KsepPoolFreePaged(v0);
  JUMPOUT(0x787A7E);
}
